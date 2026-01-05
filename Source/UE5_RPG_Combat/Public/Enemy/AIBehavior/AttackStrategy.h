#pragma once

#include "Enemy/AIBehavior/ICombatStrategy.h"

class AEnemy;

class AttackStrategy : public ICombatStrategy
{
public:
	AttackStrategy();
	
	// ~ Begin ICombatStrategy interface
	virtual void Execute(TObjectPtr<AEnemy> Enemy) override;
	// ~ End ICombatStrategy interface
};
