#pragma once

#include "Enemy/AIBehavior/ICombatStrategy.h"

struct FPathFollowingResult;
struct FAIRequestID;
class AEnemy;

class AttackStrategy : public ICombatStrategy
{
public:
	AttackStrategy();
	
	// ~ Begin ICombatStrategy interface
	virtual void Execute(TObjectPtr<AEnemy> Enemy) override;
	// ~ End ICombatStrategy interface
	
	virtual void OnMoveCompleted(FAIRequestID, const FPathFollowingResult& Result, TObjectPtr<AEnemy> Enemy);
};
