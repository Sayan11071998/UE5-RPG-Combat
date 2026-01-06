#include "Enemy/Enemy.h"
#include "Components/BoxComponent.h"
#include "Character/RPGCharacter.h"
#include "Enemy/EnemyAIController.h"
#include "Kismet/GameplayStatics.h"
#include "Enemy/AIBehavior/AttackStrategy.h"
#include "Enemy/AIBehavior/PatrolStrategy.h"

#include "RPGDebugHelper.h"
#include "Enemy/AIBehavior/StrafeStrategy.h"

AEnemy::AEnemy() :
	BaseDamage(5.f), Health(100.f), MaxHealth(100.f), AttackRange(300.f), AcceptanceRange(200.f)
{
	PrimaryActorTick.bCanEverTick = true;
	
	// Right weapon collision box
	RightWeaponCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("RightWeaponBox"));
	RightWeaponCollision->SetupAttachment(GetMesh(), RightWeaponSocketName);
}

void AEnemy::BeginPlay()
{
	Super::BeginPlay();
	
	// Setup enemy controller
	EnemyAIController = Cast<AEnemyAIController>(GetController());
	
	// Bind function to overlap for weapon box
	RightWeaponCollision->OnComponentBeginOverlap.AddDynamic(this, &AEnemy::OnRightWeaponOverlap);
	
	// Setup right weapon collision
	RightWeaponCollision->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	RightWeaponCollision->SetCollisionObjectType(ECollisionChannel::ECC_WorldDynamic);
	RightWeaponCollision->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	RightWeaponCollision->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Overlap);
	
	// Can enemy Patrol
	CurrentState = EAIState::Patrol;
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
		if (StrafeStrategy->HasReachedDestination(this) && !bIsWaiting)
		{
			bIsWaiting = true;
			StrafeStrategy = NewObject<UStrafeStrategy>();
			StrafeStrategy->Execute(this);
			float StrafeDelay = FMath::RandRange(1.f, StrafeDelayTime);
			FTimerHandle StrafeDelayTimer;
			GetWorldTimerManager().SetTimer(StrafeDelayTimer, this, &AEnemy::EnemyStrafe, StrafeDelay, false);
		}
		break;
	
	case EAIState::Patrol:
		if (PatrolStrategy->HasReachedDestination(this) && !bIsWaiting)
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
	EnemyAIController->ClearFocus(EAIFocusPriority::Gameplay);
	bIsWaiting = false;
	CurrentState = EAIState::Combat;
}

void AEnemy::MeleeAttack()
{
	UAnimInstance* AnimInstance = GetMesh()->GetAnimInstance();
	
	if (AnimInstance && AttackMontage)
	{
		if (!AnimInstance->Montage_IsPlaying(AttackMontage))
		{
			// Get number of montage sections
			const int32 SectionCount = AttackMontage->CompositeSections.Num();
		
			// Get random animation to play
			// Get section index and playtime to use for timer
			const FName SectionName = GetAttackSectionName(SectionCount);
			const int32 SectionIndex = AttackMontage->GetSectionIndex(SectionName);
			const float SectionLength = AttackMontage->GetSectionLength(SectionIndex);
		
			// Play montage section
			AnimInstance->Montage_Play(AttackMontage);
			AnimInstance->Montage_JumpToSection(SectionName, AttackMontage);
			GetWorldTimerManager().SetTimer(TimerAttack, this, &AEnemy::ResetAttack, SectionLength, false);
			
			// Call reset melee attack
			FTimerHandle TimerResetAttack;
			GetWorldTimerManager().SetTimer(TimerResetAttack, this, &AEnemy::ResetMeleeAttack, SectionLength, false);
		}
	}
}

void AEnemy::ResetMeleeAttack()
{
	float RandomChance = FMath::FRand();
	
	if (RandomChance <= 0.3f)
	{
		CurrentState = EAIState::Strafe;
	}
}

void AEnemy::HitInterface_Implementation(FHitResult HitResult)
{
	// Impact Sound
	// Impact Niagara
	// Hit Montage
}

float AEnemy::TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator,
	AActor* DamageCauser)
{
	if (Health - DamageAmount <= 0.f)
	{
		Health = 0.f;
		
		//Call blueprint function to play death montage and clean things up
		Debug::Print(TEXT("Enemy Died!!"));
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

void AEnemy::ResetAttack()
{
	// Update state here
	// MeleeAttack();
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
	PatrolStrategy = NewObject<UPatrolStrategy>();
	PatrolStrategy->Execute(this);
	
	bIsWaiting = false;
}

void AEnemy::EnemyAttack()
{
	AttackStrategy = NewObject<UAttackStrategy>();
	AttackStrategy->Execute(this);
	
	bIsWaiting = false;
}

void AEnemy::EnemyStrafe()
{
	bIsWaiting = false;
	CurrentState = EAIState::Attack;
}