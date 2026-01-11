#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SavePlayerDataActor.generated.h"

class USphereComponent;

UCLASS()
class UE5_RPG_COMBAT_API ASavePlayerDataActor : public AActor
{
	GENERATED_BODY()
	
public:	
	ASavePlayerDataActor();
	virtual void Tick(float DeltaTime) override;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<USphereComponent> SphereComponent;
	
	UFUNCTION()
	void OnOverlapBegin(
		UPrimitiveComponent* OverlappedComp,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult
	);

protected:
	virtual void BeginPlay() override;
};