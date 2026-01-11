#include "Core/SavePlayerDataActor.h"
#include "Character/RPGCharacter.h"
#include "Components/SphereComponent.h"

ASavePlayerDataActor::ASavePlayerDataActor()
{
	PrimaryActorTick.bCanEverTick = true;
	
	// Create the sphere component and attach to root
	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
	SphereComponent->SetupAttachment(RootComponent);
	SphereComponent->InitSphereRadius(300.f);
	SphereComponent->SetCollisionProfileName(TEXT("Trigger"));
	
	// Bind overlap event
	SphereComponent->OnComponentBeginOverlap.AddDynamic(this, &ASavePlayerDataActor::OnOverlapBegin);
}

void ASavePlayerDataActor::BeginPlay()
{
	Super::BeginPlay();
}

void ASavePlayerDataActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ASavePlayerDataActor::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	ARPGCharacter* RPGCharacter = Cast<ARPGCharacter>(OtherActor);
	
	if (RPGCharacter)
	{
		RPGCharacter->SavePlayerData();
	}
}