#include "BaseCharacter.h"
#include "EnhancedPlayerInput.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"
#include "Math/UnrealMathUtility.h"

ABaseCharacter::ABaseCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void ABaseCharacter::MoveForwardInput(float Value)
{
	if (bIsUpMovementBlocked && Value > 0)
	{
		Value = 0;
	}
	if (bIsDownMovementBlocked && Value < 0)
	{
		Value = 0;
	}
	AddMovementInput(this->GetActorForwardVector(), Value);
}

void ABaseCharacter::MoveRightInput(float Value)
{
	if (bIsLeftMovementBlocked && Value < 0)
	{
		Value = 0;
	}
	if (bIsRightMovementBlocked && Value > 0)
	{
		Value = 0;
	}
	AddMovementInput(this->GetActorRightVector(), Value);
}


void ABaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

