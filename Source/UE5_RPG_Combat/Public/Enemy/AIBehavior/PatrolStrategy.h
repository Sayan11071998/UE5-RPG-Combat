#pragma once

#include "Enemy/AIBehavior/ICombatStrategy.h"
#include "PatrolStrategy.generated.h"

class AEnemy;

UCLASS()
class UPatrolStrategy : public UObject, public ICombatStrategy
{
	GENERATED_BODY()
	
public:
	UPatrolStrategy();
	
	// ~ Begin ICombatStrategy interface
	virtual void Execute(TObjectPtr<AEnemy> Enemy) override;
	// ~ End ICombatStrategy interface
	
	bool HasReachedDestination(TObjectPtr<AEnemy> Enemy);
};