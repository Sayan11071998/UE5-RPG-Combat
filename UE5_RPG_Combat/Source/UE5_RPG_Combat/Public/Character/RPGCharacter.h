#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "RPGCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;

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
	
private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = true))
	TObjectPtr<USpringArmComponent> SpringArmComponent;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = true))
	TObjectPtr<UCameraComponent> FollowCameraComponent;
};