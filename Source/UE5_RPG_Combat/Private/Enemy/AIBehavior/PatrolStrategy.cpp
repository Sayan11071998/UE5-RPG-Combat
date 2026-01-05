#include "Enemy/AIBehavior/PatrolStrategy.h"
#include "Enemy/EnemyAIController.h"
#include "NavigationSystem.h"
#include "AIController.h"
#include "Math/UnrealMathUtility.h"
#include "Enemy/Enemy.h"

#include "RPGDebugHelper.h"

PatrolStrategy::PatrolStrategy()
{
}

void PatrolStrategy::Execute(TObjectPtr<AEnemy> Enemy)
{
	Debug::Print(TEXT("Inside Execute Patrol Strategy"));
	
	// Enemy patrol logic
	
	// Get NavMesh data
	FNavAgentProperties NavAgentProps;
	const ANavigationData* NavData = UNavigationSystemV1::GetCurrent(Enemy->GetWorld())->GetNavDataForProps(NavAgentProps);
	
	if (NavData != nullptr)
	{
		// Placeholder for our result
		FNavLocation ResultLocation;
		
		// Get random point in radius
		UNavigationSystemV1* NavSystem = FNavigationSystem::GetCurrent<UNavigationSystemV1>(Enemy->GetWorld());
		
		if (NavSystem && NavSystem->GetRandomReachablePointInRadius(Enemy->GetActorLocation(), 800.f, ResultLocation))
		{
			// Use the AI controller to move to the result location
			AEnemyAIController* AIController = Cast<AEnemyAIController>(Enemy->GetController());
			
			// Check if we got controller and move to the point
			if (AIController != nullptr)
			{
				AIController->MoveToLocation(ResultLocation.Location);
			}
		}
	}
}