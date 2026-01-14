#pragma once

#include "CoreMinimal.h"
#include "ProjectilePool.generated.h"

class AEnemyProjectile;

UCLASS()
class UE5_RPG_COMBAT_API UProjectilePool : public UObject
{
	GENERATED_BODY()

public:
	UProjectilePool();
	
	// Initialize the pool with a specific size
	void InitializePool(UWorld* World, TSubclassOf<AEnemyProjectile> ProjectileClass, int32 PoolSize = 10);
	
	// Get a projectile from the pool
	AEnemyProjectile* GetProjectile();
	
	// Return a projectile to the pool
	void ReturnProjectile(AEnemyProjectile* Projectile);
	
	// Clean up the pool
	void ClearPool();

private:
	// All projectiles in the pool
	UPROPERTY()
	TArray<TObjectPtr<AEnemyProjectile>> ProjectilePool;
	
	// Available projectiles (inactive)
	UPROPERTY()
	TArray<TObjectPtr<AEnemyProjectile>> AvailableProjectiles;
	
	// Currently active projectiles
	UPROPERTY()
	TArray<TObjectPtr<AEnemyProjectile>> ActiveProjectiles;
	
	// Reference to the world
	UPROPERTY()
	TObjectPtr<UWorld> CachedWorld;
	
	// Projectile class to spawn
	UPROPERTY()
	TSubclassOf<AEnemyProjectile> CachedProjectileClass;
	
	// Create a new projectile instance
	AEnemyProjectile* CreateProjectile();
	
public:
	FORCEINLINE int32 GetPoolSize() const { return ProjectilePool.Num(); }
	FORCEINLINE int32 GetAvailableCount() const { return AvailableProjectiles.Num(); }
	FORCEINLINE int32 GetActiveCount() const { return ActiveProjectiles.Num(); }
};