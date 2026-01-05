#include "Enemy/AIBehavior/PatrolStrategy.h"

#include "RPGDebugHelper.h"

PatrolStrategy::PatrolStrategy()
{
}

void PatrolStrategy::Execute(TObjectPtr<AEnemy> Enemy)
{
	Debug::Print(TEXT("Inside Execute Patrol Strategy"));
	
	// Enemy patrol logic
}