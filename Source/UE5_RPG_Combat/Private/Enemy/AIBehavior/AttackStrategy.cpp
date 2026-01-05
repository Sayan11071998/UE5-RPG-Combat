#include "Enemy/AIBehavior/AttackStrategy.h"

#include "RPGDebugHelper.h"

AttackStrategy::AttackStrategy()
{
}

void AttackStrategy::Execute(TObjectPtr<AEnemy> Enemy)
{
	Debug::Print(TEXT("Inside Execute Attack Strategy"));
	
	// Move to player and Enemy attack logic
}