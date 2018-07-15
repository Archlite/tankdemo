// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tank.h"
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
};
