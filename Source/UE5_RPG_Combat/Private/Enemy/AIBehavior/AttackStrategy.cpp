#include "Enemy/AIBehavior/AttackStrategy.h"
#include "Navigation/PathFollowingComponent.h"
#include "Character/RPGCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "Enemy/EnemyAIController.h"
#include "AIController.h"
#include "Enemy/Enemy.h"

#include "RPGDebugHelper.h"

AttackStrategy::AttackStrategy()
{
}

void AttackStrategy::Execute(TObjectPtr<AEnemy> Enemy)
{
	Debug::Print(TEXT("Attack Player"));
	
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
				150.f,
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
						&AttackStrategy::OnMoveCompleted,
						Enemy	
					);
				}
			}
		}
	}
}

void AttackStrategy::OnMoveCompleted(FAIRequestID, const FPathFollowingResult& Result, TObjectPtr<AEnemy> Enemy)
{
	if (Result.IsSuccess())
	{
		APawn* Pawn = UGameplayStatics::GetPlayerPawn(Enemy->GetWorld(), 0);
		ARPGCharacter* RPGCharacter = Cast<ARPGCharacter>(Pawn);
		
		FVector RPGPos = RPGCharacter->GetActorLocation();
		FVector EnemyPos = Enemy->GetActorLocation();
		
		float Distance = FVector::Dist(EnemyPos, RPGPos);
		
		// Making sure in range to attack the player
		if (Distance <= 300.f)
		{
			Enemy->MeleeAttack();
		}
	}
}