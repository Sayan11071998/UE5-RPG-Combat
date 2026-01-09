#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "EnemyProjectileAttack.generated.h"

UCLASS()
class UE5_RPG_COMBAT_API UEnemyProjectileAttack : public UAnimNotify
{
	GENERATED_BODY()
	
public:
	// ~ Begin UAnimNotify interface
	virtual void Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation) override;
	// ~ End UAnimNotify interface
};