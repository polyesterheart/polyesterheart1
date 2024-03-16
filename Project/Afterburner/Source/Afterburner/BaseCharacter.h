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

	UFUNCTION(BlueprintCallable,BlueprintImplementableEvent)
	void CatchUpCameraSpeed();

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
	
	//Input blocking
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "InputBlock")
	bool bIsLeftMovementBlocked = false;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "InputBlock")
	bool bIsRightMovementBlocked = false;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "InputBlock")
	bool bIsUpMovementBlocked = false;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "InputBlock")
	bool bIsDownMovementBlocked = false;

	//Camera Movement
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera")
	float CameraSpeed = 1.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera")
	bool bIsCameraMoving = false;
};
