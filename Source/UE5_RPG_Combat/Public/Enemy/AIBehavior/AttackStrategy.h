#pragma once

#include "Enemy/AIBehavior/ICombatStrategy.h"
#include "AttackStrategy.generated.h"

struct FPathFollowingResult;
struct FAIRequestID;
class AEnemy;

UCLASS()
class UAttackStrategy : public UObject, public ICombatStrategy
{
	GENERATED_BODY()
	
public:
	UAttackStrategy();
	
	// ~ Begin ICombatStrategy interface
	virtual void Execute(TObjectPtr<AEnemy> Enemy) override;
	// ~ End ICombatStrategy interface
	
	virtual void OnMoveCompleted(FAIRequestID, const FPathFollowingResult& Result, TObjectPtr<AEnemy> Enemy);
};
