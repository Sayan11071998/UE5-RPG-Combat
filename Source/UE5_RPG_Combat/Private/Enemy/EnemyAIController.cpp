#include "Enemy/EnemyAIController.h"
#include "Enemy/Enemy.h"
#include "Perception/AIPerceptionTypes.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"
#include "Character/RPGCharacter.h"

AEnemyAIController::AEnemyAIController()
{
	SetupPerceptionSystem();
}

void AEnemyAIController::BeginPlay()
{
	Super::BeginPlay();
}

void AEnemyAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	
	ControlledEnemy = Cast<AEnemy>(InPawn);
    
	if (!ControlledEnemy)
	{
		UE_LOG(LogTemp, Warning, TEXT("AEnemyAIController::OnPossess - Failed to cast pawn to AEnemy"));
	}
}

void AEnemyAIController::SetupPerceptionSystem()
{
	SightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("Sight Config"));
	
	if (SightConfig)
	{
		PerceptionComponent = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("Perception Component"));
		SetPerceptionComponent(*PerceptionComponent);
		
		SightConfig->SightRadius = 1500.f;
		SightConfig->LoseSightRadius = SightConfig->SightRadius + 25.f;
		SightConfig->PeripheralVisionAngleDegrees = 120.f;
		SightConfig->SetMaxAge(5.f);
		SightConfig->AutoSuccessRangeFromLastSeenLocation = 1550.f;
		SightConfig->DetectionByAffiliation.bDetectEnemies = true;
		SightConfig->DetectionByAffiliation.bDetectFriendlies = true;
		SightConfig->DetectionByAffiliation.bDetectNeutrals = true;
		
		GetPerceptionComponent()->SetDominantSense(*SightConfig->GetSenseImplementation());
		GetPerceptionComponent()->OnTargetPerceptionUpdated.AddDynamic(this, &AEnemyAIController::OnTargetDetected);
		GetPerceptionComponent()->ConfigureSense(*SightConfig);
	}
}

void AEnemyAIController::OnTargetDetected(AActor* Actor, FAIStimulus const Stimulus)
{
	if (auto* const RPGCharacter = Cast<ARPGCharacter>(Actor))
	{
		if (Stimulus.IsActive())
		{
			if (ControlledEnemy != nullptr)
			{
				ControlledEnemy->EnterCombat();
			}
		}
		else
		{
			if (ControlledEnemy != nullptr)
			{
				ControlledEnemy->ExitCombat();
			}
		}
	}
}