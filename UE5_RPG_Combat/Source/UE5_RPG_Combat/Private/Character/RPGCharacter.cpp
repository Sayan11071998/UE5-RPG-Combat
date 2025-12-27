#include "Character/RPGCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

#include  "RPGDebugHelper.h"

ARPGCharacter::ARPGCharacter() :
	WalkSpeed(300.f), RunSpeed(600.f)
{
	PrimaryActorTick.bCanEverTick = true;
	
	// Create Camera Boom
	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	SpringArmComponent->SetupAttachment(RootComponent);
	SpringArmComponent->TargetArmLength = 400.f;
	SpringArmComponent->bUsePawnControlRotation = true;
	
	// Create Follow Camera
	FollowCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCameraComponent->SetupAttachment(SpringArmComponent, USpringArmComponent::SocketName);
	FollowCameraComponent->bUsePawnControlRotation = false;
	
	// Jump Settings
	GetCharacterMovement()->JumpZVelocity = 300.f;
	GetCharacterMovement()->AirControl = 0.1f;
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
		// Movement Actions
		Input->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ARPGCharacter::Move);
		Input->BindAction(LookAction, ETriggerEvent::Triggered, this, &ARPGCharacter::Look);
		Input->BindAction(JumpAction, ETriggerEvent::Triggered, this, &ARPGCharacter::Jump);
		Input->BindAction(RunAction, ETriggerEvent::Triggered, this, &ARPGCharacter::Running);
		Input->BindAction(RunAction, ETriggerEvent::Completed, this, &ARPGCharacter::StopRunning);
		
		// Attack Actions
		Input->BindAction(BasicAttackAction, ETriggerEvent::Completed, this, &ARPGCharacter::BasicAttack);
		Input->BindAction(HeavyAttackAction, ETriggerEvent::Triggered, this, &ARPGCharacter::HeavyAttack);
		Input->BindAction(SpinAttackAction, ETriggerEvent::Completed, this, &ARPGCharacter::SpinAttack);
		Input->BindAction(JumpAttackAction, ETriggerEvent::Completed, this, &ARPGCharacter::JumpAttack);
	}
}

void ARPGCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	// Add Input Mapping Context
	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		// Get Local Player Subsystem
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem =
			ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			// Add Input Context
			Subsystem->AddMappingContext(InputMapping, 0);
		}
	}
}

void ARPGCharacter::Move(const FInputActionValue& InputValue)
{
	FVector2D InputVector = InputValue.Get<FVector2D>();
	
	if (IsValid(Controller))
	{
		// Get Forward Direction
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0.f, Rotation.Yaw, 0.f);
		
		// Rotation Matrix
		const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		
		// Add Movement Input
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
	// Call Parent Class Jump Function
	Super::Jump();
	
	if (GetCharacterMovement()->IsMovingOnGround())
	{
		// Get Current Forward Velocity
		FVector ForwardVelocity = GetVelocity();
		ForwardVelocity.Z = 0.f;
		
		// Define Jump Vertical Velocity
		float JumpVerticalVelocity = GetCharacterMovement()->JumpZVelocity;
		
		// Combine Current Forward Velocity with Jump Vertical Velocity
		FVector JumpVelocity = ForwardVelocity + FVector(0.f, 0.f, JumpVerticalVelocity);
		
		// Launch Character with the Combined Velocity
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
	Debug::Print(TEXT("Basic Attack"));
}

void ARPGCharacter::HeavyAttack()
{
	Debug::Print(TEXT("Heavy Attack"));
}

void ARPGCharacter::SpinAttack()
{
	Debug::Print(TEXT("Spin Attack"));
}

void ARPGCharacter::JumpAttack()
{
	Debug::Print(TEXT("Jump Attack"));
}