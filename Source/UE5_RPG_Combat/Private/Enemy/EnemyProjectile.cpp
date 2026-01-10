#include "Enemy/EnemyProjectile.h"
#include "Character/RPGCharacter.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Kismet/GameplayStatics.h"

AEnemyProjectile::AEnemyProjectile() :
	ProjectileDamage(10.f), ProjectileLife(5.f)
{
	PrimaryActorTick.bCanEverTick = true;
	
	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere"));
	SetRootComponent(SphereComponent);
	
	ProjectileMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Projectile Mesh"));
	ProjectileMesh->SetupAttachment(SphereComponent);
	
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Projectile Movement"));
	ProjectileMovement->InitialSpeed = 3000.f;
	ProjectileMovement->MaxSpeed = 3000.f;
}

void AEnemyProjectile::BeginPlay()
{
	Super::BeginPlay();
	
	// Bind function to overlap events for collision boxes
	SphereComponent->OnComponentBeginOverlap.AddDynamic(this, &AEnemyProjectile::OnProjectileOverlap);
}

void AEnemyProjectile::DestroyProjectile()
{
	Destroy();
}

void AEnemyProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AEnemyProjectile::OnProjectileOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// Check if it hits the player
	if (OtherActor == nullptr) return;
	
	ARPGCharacter* Character = Cast<ARPGCharacter>(OtherActor);
	
	if (Character)
	{
		UGameplayStatics::ApplyDamage(
			Character,
			ProjectileDamage, 
			nullptr,
			this,
			UDamageType::StaticClass()	
		);
	}
	else
	{
		GetWorldTimerManager().SetTimer(ProjectileTimer, this, &AEnemyProjectile::DestroyProjectile, ProjectileLife, false);
	}
}