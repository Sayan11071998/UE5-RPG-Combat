#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "RPGAnimInstance.generated.h"

class ARPGCharacter;

UCLASS()
class UE5_RPG_COMBAT_API URPGAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
	
public:
	// Used in Animation Blueprints
	UFUNCTION(BlueprintCallable)
	void UpdateAnimationProperties(float DeltaTime);
	
	// ~ Begin UAnimInstance interface
	
	// We can Initialize Variables and Use them in Blueprints
	virtual void NativeInitializeAnimation() override;
	
	// ~ End UAnimInstance interface
	
private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Movement", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<ARPGCharacter> RPGCharacter;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Movement", meta = (AllowPrivateAccess = "true"))
	float Speed;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Movement", meta = (AllowPrivateAccess = "true"))
	float Direction;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Movement", meta = (AllowPrivateAccess = "true"))
	bool bIsInAir;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Movement", meta = (AllowPrivateAccess = "true"))
	bool bIsBlocking;
};