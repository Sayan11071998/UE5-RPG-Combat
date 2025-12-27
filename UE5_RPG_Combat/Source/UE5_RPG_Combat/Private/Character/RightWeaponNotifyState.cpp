#include "Character/RightWeaponNotifyState.h"
#include "Character/RPGCharacter.h"

void URightWeaponNotifyState::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation,
                                          float TotalDuration, const FAnimNotifyEventReference& EventReference)
{
	if (MeshComp && MeshComp->GetOwner())
	{
		RPGCharacter = Cast<ARPGCharacter>(MeshComp->GetOwner());
		
		if (RPGCharacter)
		{
			RPGCharacter->ActivateRightWeapon();
		}
	}
}

void URightWeaponNotifyState::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation,
	const FAnimNotifyEventReference& EventReference)
{
	if (MeshComp && MeshComp->GetOwner())
	{
		if (RPGCharacter)
		{
			RPGCharacter->DeactivateRightWeapon();
		}
	}
}