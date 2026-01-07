#include "Enemy/AIBehavior/StrafeStrategy.h"
#include "Enemy/Enemy.h"
#include "NavigationSystem.h"
#include "AIController.h"
#include "Enemy/EnemyAIController.h"
#include "Math/UnrealMathUtility.h"
#include "Navigation/PathFollowingComponent.h"

UStrafeStrategy::UStrafeStrategy()
{
}

void UStrafeStrategy::Execute(TObjectPtr<AEnemy> Enemy)
{
	// Get NavMesh data
	FNavAgentProperties NavAgentProperties;
	const ANavigationData* NavData = UNavigationSystemV1::GetCurrent(Enemy->GetWorld())->GetNavDataForProps(NavAgentProperties);
	
	if (NavData != nullptr)
	{
		FNavLocation ResultLocation;
		UNavigationSystemV1* NavSystem = FNavigationSystem::GetCurrent<UNavigationSystemV1>(Enemy->GetWorld());
		
		if (NavSystem)
		{
			// Get current rotation of the actor
			const FRotator Rotation = Enemy->GetActorRotation();
			
			// Create a 180 degree rotated rotator
			const FRotator TargetRotation(0.f, Rotation.Yaw + 180.f, 0.f);
			
			// Convert the rotator to a vector
			const FVector Dir = TargetRotation.Vector();
			
			// Generate a destination point in the opposite direction
			FVector OppositeDirection = Enemy->GetActorLocation() + (Dir * 500.f);
			
			if (NavSystem->GetRandomPointInNavigableRadius(OppositeDirection, 500.f, ResultLocation))
			{
				// Get AI Controller move to location
				AEnemyAIController* AIController = Cast<AEnemyAIController>(Enemy->GetController());
				
				if (AIController != nullptr)
				{
					AIController->MoveToLocation(ResultLocation.Location);
				}
			}
		}
	}
}

bool UStrafeStrategy::HasReachedDestination(TObjectPtr<AEnemy> Enemy)
{
	AEnemyAIController* AIController = Cast<AEnemyAIController>(Enemy->GetController());
	
	if (AIController != nullptr)
	{
		EPathFollowingStatus::Type Status = AIController->GetMoveStatus();
		
		if (Status == EPathFollowingStatus::Idle || Status == EPathFollowingStatus::Waiting)
		{
			return true;
		}
	}
	
	return false;
}