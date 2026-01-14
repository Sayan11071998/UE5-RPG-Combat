#pragma once

#include "Enemy/AIBehavior/ICombatStrategy.h"
#include "AttackStrategy.generated.h"

struct FPathFollowingResult;
struct FAIRequestID;
class AEnemy;
class ARPGCharacter;

UCLASS()
class UAttackStrategy : public UObject, public ICombatStrategy
{
	GENERATED_BODY()
	
public:
	UAttackStrategy();
	
	// ~ Begin ICombatStrategy interface
	virtual void Execute(AEnemy* Enemy) override;
	// ~ End ICombatStrategy interface
	
	virtual void OnMoveCompleted(FAIRequestID, const FPathFollowingResult& Result, AEnemy* Enemy, ARPGCharacter* RPGCharacter);

private:
	float PlayerEnemyDistance(AEnemy* Enemy, ARPGCharacter* RPGCharacter) const;
};