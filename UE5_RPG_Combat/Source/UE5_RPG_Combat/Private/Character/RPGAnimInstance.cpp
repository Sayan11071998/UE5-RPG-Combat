#include "Character/RPGAnimInstance.h"
#include "Character/RPGCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"

// Acts Like Tick for Animations and Get Speed
void URPGAnimInstance::UpdateAnimationProperties(float DeltaTime)
{
	if (RPGCharacter == nullptr)
	{
		RPGCharacter = Cast<ARPGCharacter>(TryGetPawnOwner());
	}
	
	if (RPGCharacter)
	{
		// Get Speed of Character from Velocity
		FVector Velocity = RPGCharacter->GetVelocity();
		Velocity.Z = 0.f;
		Speed = Velocity.Size();
		
		bIsInAir = RPGCharacter->GetCharacterMovement()->IsFalling();
		
		// Get Offset Yaw for Player and Blend spaces
		const FRotator AimRotation = RPGCharacter->GetBaseAimRotation();
		const FRotator MovementRotation = UKismetMathLibrary::MakeRotFromX(RPGCharacter->GetVelocity());
		
		Direction = UKismetMathLibrary::NormalizedDeltaRotator(MovementRotation, AimRotation).Yaw;
	}
}

// Acts Like Begin Play to Create a Reference to Character
void URPGAnimInstance::NativeInitializeAnimation()
{
	RPGCharacter = Cast<ARPGCharacter>(TryGetPawnOwner());
}