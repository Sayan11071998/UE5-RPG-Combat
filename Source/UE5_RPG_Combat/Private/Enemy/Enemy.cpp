#include "Enemy/Enemy.h"

#include "RPGDebugHelper.h"

AEnemy::AEnemy() :
	BaseDamage(5.f), Health(100.f), MaxHealth(100.f)
{
	PrimaryActorTick.bCanEverTick = true;
}

void AEnemy::BeginPlay()
{
	Super::BeginPlay();
}

void AEnemy::MeleeAttack()
{
	UAnimInstance* AnimInstance = GetMesh()->GetAnimInstance();
	
	if (AnimInstance && AttackMontage)
	{
		// Get number of montage sections
		const int32 SectionCount = AttackMontage->CompositeSections.Num();
		
		// Get random animation to play
		// Get section index and playtime to use for timer
		const FName SectionName = GetAttackSectionName(SectionCount);
		const int32 SectionIndex = AttackMontage->GetSectionIndex(SectionName);
		const float SectionLength = AttackMontage->GetSectionLength(SectionIndex);
		
		// Play montage section
		AnimInstance->Montage_Play(AttackMontage);
		AnimInstance->Montage_JumpToSection(SectionName, AttackMontage);
		GetWorldTimerManager().SetTimer(TimerAttack, this, &AEnemy::ResetAttack, SectionLength, false);
	}
}

void AEnemy::ResetAttack()
{
	// Reset enemy state
}

FName AEnemy::GetAttackSectionName(int32 SectionCount)
{
	FName SectionName;
	
	// Get random section in montage
	const int32 Section { FMath::RandRange(1, SectionCount) };

	switch (Section)
	{
	case 1:
		SectionName = FName("Attack1");
		break;
	case 2:
		SectionName = FName("Attack2");
		break;
	default:
		SectionName = FName("Attack2");
		break;
	}
	
	return SectionName;
}

void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AEnemy::HitInterface_Implementation(FHitResult HitResult)
{
	// Impact Sound
	// Impact Niagara
	// Hit Montage
}

float AEnemy::TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator,
	AActor* DamageCauser)
{
	if (Health - DamageAmount <= 0.f)
	{
		Health = 0.f;
		
		//Call blueprint function to play death montage and clean things up
		Debug::Print(TEXT("Enemy Died!!"));
	}
	else
	{
		Health -= DamageAmount;
	}
	
	return DamageAmount;
}