#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "EnemyAIController.generated.h"

class AEnemy;
class UAISenseConfig_Sight;

UCLASS()
class UE5_RPG_COMBAT_API AEnemyAIController : public AAIController
{
	GENERATED_BODY()

public:
	AEnemyAIController();
	virtual void BeginPlay() override;
	
protected:
	UPROPERTY()
	TObjectPtr<AEnemy> ControlledEnemy;
	
	// Declare sight config in class
	UPROPERTY(VisibleAnywhere, Category = "AI")
	TObjectPtr<UAISenseConfig_Sight> SightConfig;
	
private:
	void SetupControlledPawn();
	void SetupPerceptionSystem();
	
	UFUNCTION()
	void OnTargetDetected(AActor* Actor, FAIStimulus const Stimulus);
};