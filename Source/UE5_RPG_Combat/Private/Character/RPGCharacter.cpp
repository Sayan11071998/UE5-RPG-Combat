#include "Character/RPGCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Character/RPGAnimInstance.h"
#include "Components/BoxComponent.h"
#include "Interfaces/HitInterface.h"
#include "Kismet/GameplayStatics.h"
#include "Perception/AIPerceptionStimuliSourceComponent.h"
#include "Perception/AISense_Sight.h"
#include "Sound/SoundCue.h"
#include "MotionWarpingClasses.h"
#include "MotionWarpingComponent.h"

#include "RPGDebugHelper.h"

ARPGCharacter::ARPGCharacter() :
	WalkSpeed(300.f), RunSpeed(600.f), BaseDamage(20.f), Health(100.f), MaxHealth(100.f)
{
	PrimaryActorTick.bCanEverTick = true;
	
	// Create camera boom
	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	SpringArmComponent->SetupAttachment(RootComponent);
	SpringArmComponent->TargetArmLength = 400.f;
	SpringArmComponent->bUsePawnControlRotation = true;
	
	// Create follow camera
	FollowCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCameraComponent->SetupAttachment(SpringArmComponent, USpringArmComponent::SocketName);
	FollowCameraComponent->bUsePawnControlRotation = false;
	
	// Motion warping component
	MotionWarpingComponent = CreateDefaultSubobject<UMotionWarpingComponent>(TEXT("MotionWarpComponent"));
	
	// Jump settings
	GetCharacterMovement()->JumpZVelocity = 300.f;
	GetCharacterMovement()->AirControl = 0.1f;
	
	// Right weapon collision box
	RightWeaponCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("RightWeaponBox"));
	RightWeaponCollision->SetupAttachment(GetMesh(), FName(TEXT("SwordSocket")));
	
	// Stimulus
	SetupStimuliSource();
}

void ARPGCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	// Add input mapping context
	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		// Get local player subsystem
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem =
			ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			// Add input context
			Subsystem->AddMappingContext(InputMapping, 0);
		}
	}
	
	// Bind function to overlap for weapon box
	RightWeaponCollision->OnComponentBeginOverlap.AddDynamic(this, &ARPGCharacter::OnRightWeaponOverlap);
	
	// Setup right weapon collision
	RightWeaponCollision->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	RightWeaponCollision->SetCollisionObjectType(ECollisionChannel::ECC_WorldDynamic);
	RightWeaponCollision->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	RightWeaponCollision->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Overlap);
}

void ARPGCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ARPGCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	if (UEnhancedInputComponent* Input = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		// Movement actions
		Input->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ARPGCharacter::Move);
		Input->BindAction(LookAction, ETriggerEvent::Triggered, this, &ARPGCharacter::Look);
		Input->BindAction(JumpAction, ETriggerEvent::Triggered, this, &ARPGCharacter::Jump);
		Input->BindAction(RunAction, ETriggerEvent::Triggered, this, &ARPGCharacter::Running);
		Input->BindAction(RunAction, ETriggerEvent::Completed, this, &ARPGCharacter::StopRunning);
		
		// Attack actions
		Input->BindAction(BasicAttackAction, ETriggerEvent::Completed, this, &ARPGCharacter::BasicAttack);
		Input->BindAction(HeavyAttackAction, ETriggerEvent::Triggered, this, &ARPGCharacter::HeavyAttack);
		Input->BindAction(SpinAttackAction, ETriggerEvent::Completed, this, &ARPGCharacter::SpinAttack);
		Input->BindAction(JumpAttackAction, ETriggerEvent::Completed, this, &ARPGCharacter::JumpAttack);
		
		// Block actions
		Input->BindAction(BlockAction, ETriggerEvent::Started, this, &ARPGCharacter::StartBlocking);
		Input->BindAction(BlockAction, ETriggerEvent::Completed, this, &ARPGCharacter::StopBlocking);
	}
}

void ARPGCharacter::ActivateRightWeapon()
{
	RightWeaponCollision->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
}

void ARPGCharacter::DeactivateRightWeapon()
{
	RightWeaponCollision->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

float ARPGCharacter::TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent,
	class AController* EventInstigator, AActor* DamageCauser)
{
	URPGAnimInstance* AnimInstance = Cast<URPGAnimInstance>(GetMesh()->GetAnimInstance());
	
	if (AnimInstance && AnimInstance->GetIsBlocking() == false)
	{
		if (Health - DamageAmount <= 0)
		{
			Health = 0.f;
			// Player death event
			DeathOfPlayer();
		}
		else
		{
			Health -= DamageAmount;
			
			if (BodyImpactSound)
			{
				UGameplayStatics::PlaySoundAtLocation(this, BodyImpactSound, GetActorLocation());
			}
		}
	}
	else // isBlocking = true
	{
		// Check if player is facing enemy - run dot product logic
		if (PlayerFacingActor(DamageCauser))
		{
			// Play hit sound for shield
			if (ShieldImpactSound)
			{
				UGameplayStatics::PlaySoundAtLocation(this, ShieldImpactSound, GetActorLocation());
			}
		}
		else
		{
			Health -= DamageAmount;
			
			// Play hit flesh sound
			if (BodyImpactSound)
			{
				UGameplayStatics::PlaySoundAtLocation(this, BodyImpactSound, GetActorLocation());
			}
		}
	}
	
	return DamageAmount;
}

void ARPGCharacter::Move(const FInputActionValue& InputValue)
{
	FVector2D InputVector = InputValue.Get<FVector2D>();
	
	if (IsValid(Controller))
	{
		// Get forward direction
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0.f, Rotation.Yaw, 0.f);
		
		// Rotation aatrix
		const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		
		// Add movement input
		AddMovementInput(ForwardDirection, InputVector.Y);
		AddMovementInput(RightDirection, InputVector.X);
	}
}

void ARPGCharacter::Look(const FInputActionValue& InputValue)
{
	FVector2D InputVector = InputValue.Get<FVector2D>();
	
	if (IsValid(Controller))
	{
		AddControllerYawInput(InputVector.X);
		AddControllerPitchInput(InputVector.Y);
	}
}

void ARPGCharacter::Jump()
{
	// Call parent class jump function
	Super::Jump();
	
	if (GetCharacterMovement()->IsMovingOnGround())
	{
		// Get current forward velocity
		FVector ForwardVelocity = GetVelocity();
		ForwardVelocity.Z = 0.f;
		
		// Define jump vertical velocity
		float JumpVerticalVelocity = GetCharacterMovement()->JumpZVelocity;
		
		// Combine current forward velocity with jump vertical velocity
		FVector JumpVelocity = ForwardVelocity + FVector(0.f, 0.f, JumpVerticalVelocity);
		
		// Launch character with the combined velocity
		LaunchCharacter(JumpVelocity, true, true);
	}
}

void ARPGCharacter::Running()
{
	GetCharacterMovement()->MaxWalkSpeed = RunSpeed;
}

void ARPGCharacter::StopRunning()
{
	GetCharacterMovement()->MaxWalkSpeed = WalkSpeed;
}

void ARPGCharacter::BasicAttack()
{
	AnimMontagePlay(AttackMontage, FName(TEXT("Attack1")));
}

void ARPGCharacter::HeavyAttack()
{
	AnimMontagePlay(AttackMontage, FName(TEXT("Attack2")));
}

void ARPGCharacter::SpinAttack()
{
	AnimMontagePlay(AttackMontage, FName(TEXT("Attack3")));
}

void ARPGCharacter::JumpAttack()
{
	MotionWarpAttack(1000.f, FName(TEXT("Attack4")));
	AnimMontagePlay(AttackMontage, FName(TEXT("Attack4")), 2.f);
}

void ARPGCharacter::MotionWarpAttack(float AttackDistance, FName MotionWarpName)
{
	Debug::Print(TEXT("Motion Warp Attack"));
}

void ARPGCharacter::StartBlocking()
{
	URPGAnimInstance* AnimInstance = Cast<URPGAnimInstance>(GetMesh()->GetAnimInstance());
	
	if (AnimInstance)
	{
		GetCharacterMovement()->DisableMovement();
		AnimInstance->SetIsBlocking(true);
	}
}

void ARPGCharacter::StopBlocking()
{
	URPGAnimInstance* AnimInstance = Cast<URPGAnimInstance>(GetMesh()->GetAnimInstance());
	
	if (AnimInstance)
	{
		GetCharacterMovement()->SetMovementMode(MOVE_Walking);
		AnimInstance->SetIsBlocking(false);
	}
}

void ARPGCharacter::AnimMontagePlay(TObjectPtr<UAnimMontage> MontageToPlay, FName SectionName, float PlayRate)
{
	URPGAnimInstance* AnimInstance = Cast<URPGAnimInstance>(GetMesh()->GetAnimInstance());
	
	if (AnimInstance && MontageToPlay)
	{
		// Check to see if montage is playing
		if (!AnimInstance->Montage_IsPlaying(MontageToPlay))
		{
			PlayAnimMontage(MontageToPlay, PlayRate, SectionName);
		}
	}
}

void ARPGCharacter::OnRightWeaponOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (IsValid(SweepResult.GetActor()) && SweepResult.GetActor() != this)
	{
		IHitInterface* HitInterface = Cast<IHitInterface>(SweepResult.GetActor());
		
		if (HitInterface)
		{
			HitInterface->HitInterface_Implementation(SweepResult);
		}
		
		// Apply damage to enemy
		UGameplayStatics::ApplyDamage(
			SweepResult.GetActor(),
			BaseDamage,
			GetController(),
			this,
			UDamageType::StaticClass()
		);
	}
}

bool ARPGCharacter::PlayerFacingActor(TObjectPtr<AActor> FacingActor)
{
	FVector PlayerDirection = GetActorForwardVector();
	FVector ActorDirection = (FacingActor->GetActorLocation() - GetActorLocation()).GetSafeNormal();
	
	float DotProduct = FVector::DotProduct(PlayerDirection, ActorDirection);
	
	if (DotProduct > 0.f)
	{
		return true;
	}
		
	return false;
}

void ARPGCharacter::SetupStimuliSource()
{
	StimuliSource = CreateDefaultSubobject<UAIPerceptionStimuliSourceComponent>(TEXT("Stimulus Source"));
	
	if (StimuliSource)
	{
		StimuliSource->RegisterForSense(TSubclassOf<UAISense_Sight>());
		StimuliSource->RegisterWithPerceptionSystem();
	}
}