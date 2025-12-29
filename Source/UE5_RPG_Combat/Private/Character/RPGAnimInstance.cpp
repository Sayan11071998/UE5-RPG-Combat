#include "Character/RPGAnimInstance.h"
#include "Character/RPGCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"

// Acts like tick for animations and get speed
void URPGAnimInstance::UpdateAnimationProperties(float DeltaTime)
{
	if (RPGCharacter == nullptr)
	{
		RPGCharacter = Cast<ARPGCharacter>(TryGetPawnOwner());
	}
	
	if (RPGCharacter)
	{
		// Get speed of character from velocity
		FVector Velocity = RPGCharacter->GetVelocity();
		Velocity.Z = 0.f;
		Speed = Velocity.Size();
		
		bIsInAir = RPGCharacter->GetCharacterMovement()->IsFalling();
		
		// Get offset yaw for player and blend spaces
		const FRotator AimRotation = RPGCharacter->GetBaseAimRotation();
		const FRotator MovementRotation = UKismetMathLibrary::MakeRotFromX(RPGCharacter->GetVelocity());
		
		Direction = UKismetMathLibrary::NormalizedDeltaRotator(MovementRotation, AimRotation).Yaw;
	}
}

// Acts like begin play to create a reference to character
void URPGAnimInstance::NativeInitializeAnimation()
{
	RPGCharacter = Cast<ARPGCharacter>(TryGetPawnOwner());
}