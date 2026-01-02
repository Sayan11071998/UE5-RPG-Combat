#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Interfaces/HitInterface.h"
#include "Enemy.generated.h"

class UAnimMontage;
class UBoxComponent;

UCLASS()
class UE5_RPG_COMBAT_API AEnemy : public ACharacter, public IHitInterface
{
	GENERATED_BODY()

public:
	AEnemy();
	virtual void Tick(float DeltaTime) override;
	
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

protected:
	virtual void BeginPlay() override;
	
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
	
	UFUNCTION(BlueprintCallable)
	void MeleeAttack();
	
	void ResetAttack();
	
	FName GetAttackSectionName(int32 SectionCount);
	
private:
	// Base damage
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat", meta = (AllowPrivateAccess = "true"))
	float BaseDamage;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat", meta = (AllowPrivateAccess = "true"))
	float Health;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat", meta = (AllowPrivateAccess = "true"))
	float MaxHealth;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UAnimMontage> AttackMontage;
	
	// Right weapon collision
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UBoxComponent> RightWeaponCollision;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat", meta = (AllowPrivateAccess = "true"))
	FName RightWeaponSocketName = FName("RightWeaponSocket");
	
	FTimerHandle TimerAttack;
};