#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "RPGCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UInputMappingContext;
class UInputAction;

UCLASS()
class UE5_RPG_COMBAT_API ARPGCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ARPGCharacter();
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	virtual void BeginPlay() override;
	
	// Input Actions
	UPROPERTY(EditAnywhere, Category = "Enhanced Input")
	TObjectPtr<UInputMappingContext> InputMapping;
	
	UPROPERTY(EditAnywhere, Category = "Enhanced Input")
	TObjectPtr<UInputAction> MoveAction;
	
	// Movement
	void Move(const FInputActionValue& InputValue);
	
private:
	// Spring Arm Component
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = true))
	TObjectPtr<USpringArmComponent> SpringArmComponent;
	
	// Camera Component
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = true))
	TObjectPtr<UCameraComponent> FollowCameraComponent;
};