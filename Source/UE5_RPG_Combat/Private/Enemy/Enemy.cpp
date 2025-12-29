#include "Enemy/Enemy.h"

#include "RPGDebugHelper.h"

AEnemy::AEnemy() :
	BaseDamage(5.f), Health(100.f), MaxHealth(100.f)
{
	PrimaryActorTick.bCanEverTick = true;
}

void AEnemy::BeginPlay()
{
	Super::BeginPlay();
}

void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
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