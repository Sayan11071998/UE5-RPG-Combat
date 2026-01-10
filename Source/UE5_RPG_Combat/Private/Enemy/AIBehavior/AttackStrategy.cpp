#include "Enemy/AIBehavior/AttackStrategy.h"
#include "Navigation/PathFollowingComponent.h"
#include "Character/RPGCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "Enemy/EnemyAIController.h"
#include "AIController.h"
#include "Enemy/Enemy.h"

UAttackStrategy::UAttackStrategy()
{
}

void UAttackStrategy::Execute(TObjectPtr<AEnemy> Enemy)
{
	// Move to player and Enemy attack logic
	APawn* Pawn = UGameplayStatics::GetPlayerPawn(Enemy->GetWorld(), 0);
	ARPGCharacter* RPGCharacter = Cast<ARPGCharacter>(Pawn);
	
	if (RPGCharacter)
	{
		AEnemyAIController* EnemyAIController = Cast<AEnemyAIController>(Enemy->GetController());
		
		if (EnemyAIController)
		{
			// Set focus on the player
			EnemyAIController->SetFocus(RPGCharacter);
			
			// Check player and enemy distance for acceptance range to attack
			if (PlayerEnemyDistance(Enemy, RPGCharacter) <= Enemy->GetAcceptanceRange())
			{
				Enemy->Attack();
			}
			
			EPathFollowingRequestResult::Type MoveResult = EnemyAIController->MoveToActor(
				RPGCharacter, 
				Enemy->GetAcceptanceRange(),
				true,
				true,
				true,
				nullptr,
				true
			);
			
			if (MoveResult == EPathFollowingRequestResult::RequestSuccessful)
			{
				UPathFollowingComponent* PathFollowingComponent = EnemyAIController->GetPathFollowingComponent();
				
				if (PathFollowingComponent)
				{
					PathFollowingComponent->OnRequestFinished.AddUObject(
						this,
						&UAttackStrategy::OnMoveCompleted,
						Enemy,
						RPGCharacter
					);
				}
			}
		}
	}
}

void UAttackStrategy::OnMoveCompleted(FAIRequestID, const FPathFollowingResult& Result, TObjectPtr<AEnemy> Enemy,
	ARPGCharacter* RPGCharacter)
{
	if (Result.IsSuccess())
	{
		// Making sure in range to attack the player
		if (PlayerEnemyDistance(Enemy, RPGCharacter) <= Enemy->GetAttackRange())
		{
			Enemy->Attack();
		}
	}
}

float UAttackStrategy::PlayerEnemyDistance(TObjectPtr<AEnemy> Enemy, TObjectPtr<ARPGCharacter> RPGCharacter)
{
	FVector RPGPos = RPGCharacter->GetActorLocation();
	FVector EnemyPos = Enemy->GetActorLocation();
		
	float Distance = FVector::Dist(EnemyPos, RPGPos);
	
	return Distance;
}