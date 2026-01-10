#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Interfaces/HitInterface.h"
#include "Enemy.generated.h"

// List of AI State
UENUM(BlueprintType)
enum class EAIState : uint8
{
	Idle	UMETA(DisplayName = "Idle"),
	Patrol	UMETA(DisplayName = "Patrol"),
	Attack	UMETA(DisplayName = "Attack"),
	Combat	UMETA(DisplayName = "Combat"),
	Strafe	UMETA(DisplayName = "Strafe"),
	Dead	UMETA(DisplayName = "Dead"),
};

class UAnimMontage;
class UBoxComponent;
class AEnemyAIController;
class UStrafeStrategy;
class UAttackStrategy;
class UPatrolStrategy;
class USoundCue;
class UNiagaraSystem;
class AEnemyProjectile;

UCLASS()
class UE5_RPG_COMBAT_API AEnemy : public ACharacter, public IHitInterface
{
	GENERATED_BODY()

public:
	AEnemy();
	virtual void Tick(float DeltaTime) override;
	
	// Enter and exit combat
	void EnterCombat();
	void ExitCombat();
	
	// Attack section
	void Attack();
	void ResetAttack();
	
	// Spawn Projectile for enemy Projectile
	void SpawnProjectile();
	
	// ~ Begin IHitInterface interface
	// Override hit interface
	virtual void HitInterface_Implementation(FHitResult HitResult) override;
	// ~ End IHitInterface interface
	
	// ~ Begin APawn interface
	virtual float TakeDamage(
		float DamageAmount,
		struct FDamageEvent const& DamageEvent,
		class AController* EventInstigator,
		AActor* DamageCauser	
	) override;
	// ~ End APawn interface
	
	// Activate and Deactivate weapon boxes
	virtual void ActivateRightWeapon();
	virtual void DeactivateRightWeapon();
	
	// Used for AI States
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
	EAIState CurrentState;

protected:
	virtual void BeginPlay() override;
	
	// Enemy AI Controller
	UPROPERTY()
	TObjectPtr<AEnemyAIController> EnemyAIController;
	
	// Right weapon overlap
	UFUNCTION()
	void OnRightWeaponOverlap(
		UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult
	);
	
	UFUNCTION(BlueprintImplementableEvent)
	void EnemyDeath();
	
	FName GetAttackSectionName(int32 SectionCount);
	
private:
	// Combat strategy logic
	TWeakObjectPtr<UPatrolStrategy> PatrolStrategy;
	TWeakObjectPtr<UAttackStrategy> AttackStrategy;
	TWeakObjectPtr<UStrafeStrategy> StrafeStrategy;
	
	// Used in Tick for patrolling
	bool bIsWaiting;
	FTimerHandle PatrolDelayTimer;
	
	void EnemyPatrol();
	void EnemyAttack();
	void EnemyStrafe();
	
	// Timer attack handle
	FTimerHandle TimerAttack;
	
	// Base damage
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat", meta = (AllowPrivateAccess = "true"))
	float BaseDamage;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat", meta = (AllowPrivateAccess = "true"))
	float Health;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat", meta = (AllowPrivateAccess = "true"))
	float MaxHealth;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat", meta = (AllowPrivateAccess = "true"))
	float AttackRange;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat", meta = (AllowPrivateAccess = "true"))
	float AcceptanceRange;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat", meta = (AllowPrivateAccess = "true"))
	float AttackSpeed;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat", meta = (AllowPrivateAccess = "true"))
	float StrafeDelayTime;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UAnimMontage> AttackMontage;
	
	// Right weapon collision
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UBoxComponent> RightWeaponCollision;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat", meta = (AllowPrivateAccess = "true"))
	FName RightWeaponSocketName = FName("RightWeaponSocket");
	
	// Projectile blueprint. Set is enemy blueprint
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<AEnemyProjectile> ProjectileBP;
	
	// Sounds
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USoundCue> ImpactSound;
	
	// Effects
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UNiagaraSystem> ImpactNiagara;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat", meta = (AllowPrivateAccess = "true"))
	FName ImpactBoneLocation;
	
public:
	FORCEINLINE float GetAttackRange() const { return AttackRange; }
	FORCEINLINE float GetAcceptanceRange() const { return AcceptanceRange; }
	
	FORCEINLINE float SetAttackRange(const float AttackRangeSet)
	{
		AttackRange = AttackRangeSet;
		return AttackRange;
	}
};