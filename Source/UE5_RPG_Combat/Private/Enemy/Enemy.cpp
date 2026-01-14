#include "Enemy/Enemy.h"
#include "Components/BoxComponent.h"
#include "Character/RPGCharacter.h"
#include "Enemy/EnemyAIController.h"
#include "Kismet/GameplayStatics.h"
#include "Enemy/AIBehavior/AttackStrategy.h"
#include "Enemy/AIBehavior/PatrolStrategy.h"
#include "Enemy/AIBehavior/StrafeStrategy.h"
#include "Enemy/EnemyProjectile.h"
#include "Enemy/ProjectilePool.h"
#include "Sound/SoundCue.h"
#include "NiagaraFunctionLibrary.h"
#include "GameFramework/CharacterMovementComponent.h"

// Initialize static projectile pool
UProjectilePool* AEnemy::ProjectilePool = nullptr;

AEnemy::AEnemy() :
	BaseDamage(5.f), Health(100.f), MaxHealth(100.f), AttackRange(300.f), AcceptanceRange(200.f), AttackSpeed(1.f)
{
	PrimaryActorTick.bCanEverTick = true;
	
	// Right weapon collision box
	RightWeaponCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("RightWeaponBox"));
	RightWeaponCollision->SetupAttachment(GetMesh(), RightWeaponSocketName);
}

void AEnemy::BeginPlay()
{
	Super::BeginPlay();
	
	// Caching reference of Anim Instance
	CachedAnimInstance = GetMesh()->GetAnimInstance();
	
	// Strategy Creation
	PatrolStrategy = NewObject<UPatrolStrategy>(this);
	AttackStrategy = NewObject<UAttackStrategy>(this);
	StrafeStrategy = NewObject<UStrafeStrategy>(this);
	
	// Setup enemy controller
	EnemyAIController = Cast<AEnemyAIController>(GetController());
	
	// Bind function to overlap for weapon box
	RightWeaponCollision->OnComponentBeginOverlap.AddDynamic(this, &AEnemy::OnRightWeaponOverlap);
	
	// Setup right weapon collision
	RightWeaponCollision->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	RightWeaponCollision->SetCollisionObjectType(ECollisionChannel::ECC_WorldDynamic);
	RightWeaponCollision->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	RightWeaponCollision->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Overlap);
	
	// Initialize projectile pool if needed
	if (!ProjectilePool && ProjectileBP)
	{
		ProjectilePool = GetProjectilePool(GetWorld());
	}
	
	// Can enemy Patrol
	CurrentState = EAIState::Patrol;
}

void AEnemy::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	
	// Note: We don't clear the pool here since it's shared across all enemies
	// The pool will be cleaned up when the world is destroyed
}

void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	switch (CurrentState)
	{
	case EAIState::Attack:
		if (!bIsWaiting)
		{
			bIsWaiting = true;
			float AttackDelay = FMath::RandRange(0.75f, 2.f);
			FTimerHandle AttackDelayTimer;
			GetWorldTimerManager().SetTimer(AttackDelayTimer, this, &AEnemy::EnemyAttack, AttackDelay, false);
		}
		break;
		
	case  EAIState::Strafe:
		if (StrafeStrategy.IsValid() && StrafeStrategy->HasReachedDestination(this) && !bIsWaiting)
		{
			bIsWaiting = true;
			StrafeStrategy->Execute(this);
			
			float StrafeDelay = FMath::RandRange(1.f, StrafeDelayTime);
			FTimerHandle StrafeDelayTimer;
			GetWorldTimerManager().SetTimer(StrafeDelayTimer, this, &AEnemy::EnemyStrafe, StrafeDelay, false);
		}
		break;
	
	case EAIState::Patrol:
		if (PatrolStrategy.IsValid() && PatrolStrategy->HasReachedDestination(this) && !bIsWaiting)
		{
			bIsWaiting = true;
			float PatrolDelay = FMath::RandRange(1.f, 5.f);
			GetWorldTimerManager().SetTimer(PatrolDelayTimer, this, &AEnemy::EnemyPatrol, PatrolDelay, false);
		}
		break;
	}
}

void AEnemy::EnterCombat()
{
	CurrentState = EAIState::Attack;
}

void AEnemy::ExitCombat()
{
	bIsWaiting = false;
	CurrentState = EAIState::Combat;
	
	if (EnemyAIController != nullptr)
	{
		EnemyAIController->ClearFocus(EAIFocusPriority::Gameplay);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Enemy AI Controller is null, and ExitCombat"));
	}
}

void AEnemy::Attack()
{
	if (CachedAnimInstance && AttackMontage)
	{
		if (!CachedAnimInstance->Montage_IsPlaying(AttackMontage))
		{
			// Get number of montage sections
			const int32 SectionCount = AttackMontage->CompositeSections.Num();
		
			// Get random animation to play
			// Get section index and playtime to use for timer
			const FName SectionName = GetAttackSectionName(SectionCount);
			const int32 SectionIndex = AttackMontage->GetSectionIndex(SectionName);
			const float SectionLength = AttackMontage->GetSectionLength(SectionIndex);
		
			// Play montage section
			CachedAnimInstance->Montage_Play(AttackMontage, AttackSpeed);
			CachedAnimInstance->Montage_JumpToSection(SectionName, AttackMontage);
			GetWorldTimerManager().SetTimer(TimerAttack, this, &AEnemy::ResetAttack, SectionLength, false);
			
			// Call reset melee attack
			FTimerHandle TimerResetAttack;
			GetWorldTimerManager().SetTimer(TimerResetAttack, this, &AEnemy::ResetAttack, SectionLength, false);
		}
	}
}

void AEnemy::ResetAttack()
{
	float RandomChance = FMath::FRand();
	
	if (RandomChance <= StrafeChance)
	{
		CurrentState = EAIState::Strafe;
	}
	else
	{
		// Go back to attacking instead of staying in undefined state
		CurrentState = EAIState::Attack;
	}
}

void AEnemy::SpawnProjectile()
{
	if (!ProjectilePool)
	{
		UE_LOG(LogTemp, Warning, TEXT("ProjectilePool is null! Cannot spawn projectile."));
		return;
	}
	
	// Get socket transform
	FTransform SocketTransform = GetMesh()->GetSocketTransform(FName(TEXT("ProjectileSocket")));
	
	// Get projectile from pool
	AEnemyProjectile* Projectile = ProjectilePool->GetProjectile();
	
	if (Projectile)
	{
		// Get the target (player character)
		ARPGCharacter* PlayerCharacter = Cast<ARPGCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
		
		if (PlayerCharacter)
		{
			// Get target location with height offset (aim for chest/torso)
			FVector TargetLocation = PlayerCharacter->GetActorLocation();
			TargetLocation.Z += 80.f; // Add 80 units upward
			
			// Calculate direction from projectile to target
			FVector Direction = (TargetLocation - SocketTransform.GetLocation()).GetSafeNormal();
			
			// Initialize the projectile
			Projectile->InitializeProjectile(SocketTransform.GetLocation(), Direction);
		}
		else
		{
			// If no player, shoot forward
			FVector Direction = GetActorForwardVector();
			Projectile->InitializeProjectile(SocketTransform.GetLocation(), Direction);
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Failed to get projectile from pool!"));
	}
}

UProjectilePool* AEnemy::GetProjectilePool(UWorld* World)
{
	if (!ProjectilePool && World)
	{
		// Create a new pool
		ProjectilePool = NewObject<UProjectilePool>();
		
		// We can adjust pool size here (default is 10)
		// Larger pool = less dynamic allocation but more memory
		const int32 InitialPoolSize = 20;
		
		// We need a valid projectile class - this should be set in the first enemy that spawns
		// For now, we'll initialize it later when an enemy with a ProjectileBP is created
		UE_LOG(LogTemp, Log, TEXT("ProjectilePool created, awaiting initialization"));
	}
	
	return ProjectilePool;
}

void AEnemy::HitInterface_Implementation(FHitResult HitResult)
{
	// Impact Sound
	if (ImpactSound)
	{
		UGameplayStatics::PlaySoundAtLocation(this, ImpactSound, GetActorLocation());
	}
	
	// Impact Niagara
	const FVector SpawnLocation = GetMesh()->GetBoneLocation(ImpactBoneLocation, EBoneSpaces::WorldSpace);
	UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), ImpactNiagara, SpawnLocation, GetActorRotation());
	
	// Hit Montage
}

float AEnemy::TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator,
	AActor* DamageCauser)
{
	if (Health - DamageAmount <= 0.f)
	{
		Health = 0.f;
		
		EnemyAIController->UnPossess();
		SetActorEnableCollision(false);
		EnemyDeath();
	}
	else
	{
		Health -= DamageAmount;
	}
	
	return DamageAmount;
}

void AEnemy::ActivateRightWeapon()
{
	RightWeaponCollision->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
}

void AEnemy::DeactivateRightWeapon()
{
	RightWeaponCollision->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void AEnemy::OnRightWeaponOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor == nullptr) return;
	
	auto Character = Cast<ARPGCharacter>(OtherActor);
	
	if (Character)
	{
		UGameplayStatics::ApplyDamage(
			Character,
			BaseDamage,
			EnemyAIController,
			this,
			UDamageType::StaticClass()
		);
	}
}

FName AEnemy::GetAttackSectionName(int32 SectionCount)
{
	FName SectionName;
	
	// Get random section in montage
	const int32 Section { FMath::RandRange(1, SectionCount) };

	switch (Section)
	{
	case 1:
		SectionName = FName("Attack1");
		break;
	case 2:
		SectionName = FName("Attack2");
		break;
	default:
		SectionName = FName("Attack2");
		break;
	}
	
	return SectionName;
}

void AEnemy::EnemyPatrol()
{
	if (PatrolStrategy.IsValid())
	{
		PatrolStrategy->Execute(this);
	}
	
	bIsWaiting = false;
}

void AEnemy::EnemyAttack()
{
	if (AttackStrategy.IsValid())
	{
		AttackStrategy->Execute(this);
	}
	
	// Initialize pool if we have a projectile BP and pool isn't initialized yet
	if (ProjectileBP && ProjectilePool && ProjectilePool->GetPoolSize() == 0)
	{
		const int32 InitialPoolSize = 20;
		ProjectilePool->InitializePool(GetWorld(), ProjectileBP, InitialPoolSize);
		UE_LOG(LogTemp, Log, TEXT("ProjectilePool initialized with %d projectiles"), InitialPoolSize);
	}
	
	bIsWaiting = false;
}

void AEnemy::EnemyStrafe()
{
	bIsWaiting = false;
	CurrentState = EAIState::Attack;
}

void AEnemy::EnemyDeath()
{
	// Set state to death
	CurrentState = EAIState::Dead;
	
	// Unpossess AI Controller
	if (EnemyAIController)
	{
		EnemyAIController->UnPossess();
	}
	
	// Disable collision
	SetActorEnableCollision(false);
	
	// Disable character movement
	GetCharacterMovement()->DisableMovement();
	GetCharacterMovement()->StopMovementImmediately();
	
	// Play death montage
	if (CachedAnimInstance && DeathMontage)
	{
		CachedAnimInstance->Montage_Play(DeathMontage, 1.0f);
		
		// Get montage length for destroy delay
		float DeathMontageLength = DeathMontage->GetPlayLength();
		
		// Destroy actor after animation complete
		FTimerHandle DeathTimerHandle;
		GetWorldTimerManager().SetTimer(
			DeathTimerHandle,
			[this]()
			{
				Destroy();
			},
			DeathMontageLength - 0.5f,
			false
		);
	}
	else
	{
		// If no montages destroy immediately
		Destroy();
	}
}