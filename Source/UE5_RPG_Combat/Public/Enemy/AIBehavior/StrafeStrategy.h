#pragma once

#include "CoreMinimal.h"
#include "Enemy/AIBehavior/ICombatStrategy.h"
#include "StrafeStrategy.generated.h"

class AEnemy;

UCLASS()
class UE5_RPG_COMBAT_API UStrafeStrategy : public UObject, public ICombatStrategy
{
	GENERATED_BODY()
	
public:
	UStrafeStrategy();
	
	// ~ Begin ICombatStrategy interface
	virtual void Execute(AEnemy* Enemy) override;
	// ~ End ICombatStrategy interface
	
	bool HasReachedDestination(AEnemy* Enemy) const;
};