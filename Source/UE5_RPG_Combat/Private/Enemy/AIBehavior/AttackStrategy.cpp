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
		FVector RPGPos = RPGCharacter->GetActorLocation();
		FVector EnemyPos = Enemy->GetActorLocation();
		
		float Distance = FVector::Dist(EnemyPos, RPGPos);
		
		// Making sure in range to attack the player
		if (Distance <= Enemy->GetAttackRange())
		{
			Enemy->MeleeAttack();
		}
	}
}