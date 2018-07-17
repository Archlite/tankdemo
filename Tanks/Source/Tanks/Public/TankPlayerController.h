// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tank.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class TANKS_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	ATank * GetControlledTank() const;
	void Tick(float DeltaTime) override;
	void BeginPlay() override;
	//Points barrel at where the crosshair is aiming
	void AimTowardsCrosshair();
private:
	//Returns true if pointing at landscape
	bool GetSightRayHitLocation(FVector& HitLocation) const;
	UPROPERTY(EditAnywhere)
	float CrossHairXLocation = 0.5, CrossHairYLocation = 0.333333;
	UPROPERTY(EditAnywhere)
	//10km range
	float LineTraceRange = 1000000;
	//Gets the direction the player is looking
	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;
	//Gets the exact point in the world the player is looking at
	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;
};
