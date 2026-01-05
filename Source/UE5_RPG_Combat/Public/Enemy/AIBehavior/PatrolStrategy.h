#pragma once

#include "Enemy/AIBehavior/ICombatStrategy.h"

class AEnemy;

class PatrolStrategy : public ICombatStrategy
{
public:
	PatrolStrategy();
	
	// ~ Begin ICombatStrategy interface
	virtual void Execute(TObjectPtr<AEnemy> Enemy) override;
	// ~ End ICombatStrategy interface
};