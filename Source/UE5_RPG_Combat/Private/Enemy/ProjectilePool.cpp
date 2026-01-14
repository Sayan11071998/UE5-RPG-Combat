#include "Enemy/ProjectilePool.h"
#include "Enemy/EnemyProjectile.h"
#include "Engine/World.h"

UProjectilePool::UProjectilePool()
{
}

void UProjectilePool::InitializePool(UWorld* World, TSubclassOf<AEnemyProjectile> ProjectileClass, int32 PoolSize)
{
	if (!World || !ProjectileClass)
	{
		UE_LOG(LogTemp, Warning, TEXT("ProjectilePool: Invalid World or ProjectileClass"));
		return;
	}
	
	CachedWorld = World;
	CachedProjectileClass = ProjectileClass;
	
	// Pre-allocate arrays
	ProjectilePool.Reserve(PoolSize);
	AvailableProjectiles.Reserve(PoolSize);
	
	// Initial pool of projectiles
	for (int32 i = 0; i < PoolSize; ++i)
	{
		AEnemyProjectile* Projectile = CreateProjectile();
		if (Projectile)
		{
			ProjectilePool.Add(Projectile);
			AvailableProjectiles.Add(Projectile);
		}
	}
}

AEnemyProjectile* UProjectilePool::GetProjectile()
{
	AEnemyProjectile* Projectile = nullptr;
	
	// Try to get from available pool
	if (AvailableProjectiles.Num() > 0)
	{
		Projectile = AvailableProjectiles.Pop();
	}
	else
	{
		// Pool is empty, create a new one (dynamic expansion)
		Projectile = CreateProjectile();
		if (Projectile)
		{
			ProjectilePool.Add(Projectile);
			UE_LOG(LogTemp, Warning, TEXT("ProjectilePool: Pool exhausted, creating new projectile. Total: %d"), ProjectilePool.Num());
		}
	}
	
	if (Projectile)
	{
		// Activate the projectile
		Projectile->SetActorHiddenInGame(false);
		Projectile->SetActorEnableCollision(true);
		Projectile->SetActorTickEnabled(true);
		
		ActiveProjectiles.Add(Projectile);
	}
	
	return Projectile;
}

void UProjectilePool::ReturnProjectile(AEnemyProjectile* Projectile)
{
	if (!Projectile) return;
	
	// Remove from active list
	ActiveProjectiles.Remove(Projectile);
	
	// Reset projectile state
	Projectile->SetActorHiddenInGame(true);
	Projectile->SetActorEnableCollision(false);
	Projectile->SetActorTickEnabled(false);
	Projectile->ResetProjectile();
	
	// Return to available pool
	AvailableProjectiles.Add(Projectile);
}

void UProjectilePool::ClearPool()
{
	// Destroy all projectiles
	for (AEnemyProjectile* Projectile : ProjectilePool)
	{
		if (Projectile && IsValid(Projectile))
		{
			Projectile->Destroy();
		}
	}
	
	ProjectilePool.Empty();
	AvailableProjectiles.Empty();
	ActiveProjectiles.Empty();
	
	UE_LOG(LogTemp, Log, TEXT("ProjectilePool: Pool cleared"));
}

AEnemyProjectile* UProjectilePool::CreateProjectile()
{
	if (!CachedWorld || !CachedProjectileClass) return nullptr;
	
	FActorSpawnParameters SpawnParams;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	
	AEnemyProjectile* Projectile = CachedWorld->SpawnActor<AEnemyProjectile>(
		CachedProjectileClass,
		FVector::ZeroVector,
		FRotator::ZeroRotator,
		SpawnParams
	);
	
	if (Projectile)
	{
		// Initialize in inactive state
		Projectile->SetActorHiddenInGame(true);
		Projectile->SetActorEnableCollision(false);
		Projectile->SetActorTickEnabled(false);
		Projectile->SetOwnerPool(this);
	}
	
	return Projectile;
}