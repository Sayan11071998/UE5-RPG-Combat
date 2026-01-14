#include "Enemy/EnemyProjectile.h"
#include "Character/RPGCharacter.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Enemy/ProjectilePool.h"

AEnemyProjectile::AEnemyProjectile() :
	ProjectileDamage(10.f), ProjectileLife(5.f), bHasHit(false)
{
	PrimaryActorTick.bCanEverTick = true;
	
	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere"));
	SetRootComponent(SphereComponent);
	
	ProjectileMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Projectile Mesh"));
	ProjectileMesh->SetupAttachment(SphereComponent);
	
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Projectile Movement"));
	ProjectileMovement->InitialSpeed = 3000.f;
	ProjectileMovement->MaxSpeed = 3000.f;
	ProjectileMovement->bShouldBounce = false;
}

void AEnemyProjectile::BeginPlay()
{
	Super::BeginPlay();
	
	// Bind function to overlap events for collision boxes
	SphereComponent->OnComponentBeginOverlap.AddDynamic(this, &AEnemyProjectile::OnProjectileOverlap);
}

void AEnemyProjectile::InitializeProjectile(const FVector& StartLocation, const FVector& Direction)
{
	// Reset state
	bHasHit = false;
	
	// Set location
	SetActorLocation(StartLocation);
	SetActorRotation(Direction.Rotation());
	
	// Set velocity
	if (ProjectileMovement)
	{
		ProjectileMovement->Velocity = Direction * ProjectileMovement->InitialSpeed;
	}
	
	// Start lifetime timer
	GetWorldTimerManager().ClearTimer(ProjectileTimer);
	GetWorldTimerManager().SetTimer(ProjectileTimer, this, &AEnemyProjectile::DestroyProjectile, ProjectileLife, false);
}

void AEnemyProjectile::ResetProjectile()
{
	// Clear timer
	GetWorldTimerManager().ClearTimer(ProjectileTimer);
	
	// Reset state
	bHasHit = false;
	
	// Stop movement
	if (ProjectileMovement)
	{
		ProjectileMovement->Velocity = FVector::ZeroVector;
		ProjectileMovement->StopMovementImmediately();
	}
}

void AEnemyProjectile::SetOwnerPool(UProjectilePool* Pool)
{
	OwnerPool = Pool;
}

void AEnemyProjectile::DestroyProjectile()
{
	// If we have an owner pool, return to it instead of destroying
	if (OwnerPool)
	{
		OwnerPool->ReturnProjectile(this);
	}
	else
	{
		// Fallback: destroy if no pool
		Destroy();
	}
}

void AEnemyProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AEnemyProjectile::OnProjectileOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// Prevent multiple hits
	if (bHasHit) return;
	
	// Check if it hits the player
	if (OtherActor == nullptr) return;
	
	ARPGCharacter* Character = Cast<ARPGCharacter>(OtherActor);
	
	if (Character)
	{
		bHasHit = true;
		
		UGameplayStatics::ApplyDamage(
			Character,
			ProjectileDamage, 
			nullptr,
			this,
			UDamageType::StaticClass()	
		);
		
		DestroyProjectile();
	}
	else
	{
		// Hit something else (wall, ground, etc.)
		if (OtherComp && OtherComp->Mobility == EComponentMobility::Static)
		{
			bHasHit = true;
			DestroyProjectile();
		}
	}
}