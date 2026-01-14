#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemyProjectile.generated.h"

class UStaticMeshComponent;
class UProjectileMovementComponent;
class USphereComponent;
class UProjectilePool;

UCLASS()
class UE5_RPG_COMBAT_API AEnemyProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	AEnemyProjectile();
	virtual void Tick(float DeltaTime) override;
	
	UFUNCTION()
	void OnProjectileOverlap(
		UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult
	);
	
	// Initialize projectile with direction and position
	void InitializeProjectile(const FVector& StartLocation, const FVector& Direction);
	
	// Reset projectile state for reuse
	void ResetProjectile();
	
	// Set the owner pool
	void SetOwnerPool(UProjectilePool* Pool);

protected:
	virtual void BeginPlay() override;
	
	// Destroy or return to pool when timer is complete
	void DestroyProjectile();
	
private:
	// Sphere component
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USphereComponent> SphereComponent;
	
	// Projectile component
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UStaticMeshComponent> ProjectileMesh;
	
	// Projectile movement
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UProjectileMovementComponent> ProjectileMovement;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat", meta = (AllowPrivateAccess = "true"))
	float ProjectileDamage;
	
	// Projectile lifetime
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat", meta = (AllowPrivateAccess = "true"))
	float ProjectileLife;
	
	// Setup projectile timer
	FTimerHandle ProjectileTimer;
	
	// Reference to the pool that owns this projectile
	UPROPERTY()
	TObjectPtr<UProjectilePool> OwnerPool;
	
	// Track if projectile has hit something
	bool bHasHit;
	
public:
	FORCEINLINE UProjectileMovementComponent* GetProjectileMovement() const { return ProjectileMovement; }
};