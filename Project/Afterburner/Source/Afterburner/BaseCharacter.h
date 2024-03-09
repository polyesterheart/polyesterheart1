#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BaseCharacter.generated.h"


UCLASS()
class AFTERBURNER_API ABaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:

	ABaseCharacter();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	// Input
	UFUNCTION(BlueprintCallable)
	void MoveForwardInput(float Value);
	UFUNCTION(BlueprintCallable)
	void MoveRightInput(float Value);

protected:
	// Input
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	bool bIsMoveForward = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	bool bIsMoveRight = false;

};
