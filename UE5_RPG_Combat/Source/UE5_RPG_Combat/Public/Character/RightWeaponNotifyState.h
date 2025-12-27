#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"
#include "RightWeaponNotifyState.generated.h"

class ARPGCharacter;

UCLASS()
class UE5_RPG_COMBAT_API URightWeaponNotifyState : public UAnimNotifyState
{
	GENERATED_BODY()
	
public:
	// ~ Begin UAnimNotifyState interface
	virtual void NotifyBegin(
		USkeletalMeshComponent* MeshComp,
		UAnimSequenceBase* Animation,
		float TotalDuration,
		const FAnimNotifyEventReference& EventReference	
	) override;
	
	virtual void NotifyEnd(
		USkeletalMeshComponent* MeshComp,
		UAnimSequenceBase* Animation,
		const FAnimNotifyEventReference& EventReference	
	) override;
	// ~ End UAnimNotifyState interface
	
	UPROPERTY()
	TObjectPtr<ARPGCharacter> RPGCharacter;
};