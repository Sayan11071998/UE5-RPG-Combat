#pragma once

class AEnemy;

class ICombatStrategy
{
public:
	virtual void Execute(TObjectPtr<AEnemy> Enemy) = 0;
};