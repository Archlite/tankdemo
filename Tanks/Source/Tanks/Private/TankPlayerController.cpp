// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "Tanks.h"

void  ATankPlayerController::BeginPlay() {
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank) {
		UE_LOG(LogTemp, Warning, TEXT("Player not a tank"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Player possessing %s"), *(ControlledTank->GetName()));
	}
}

ATank* ATankPlayerController::GetControlledTank() const {
	return Cast<ATank>(GetPawn());
}

// Called every frame
void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}

void ATankPlayerController::AimTowardsCrosshair() {
	if (!GetControlledTank) {
		return;
	}
	FVector HitLocation;
	if (GetSightRayHitLocation(HitLocation)) {
		UE_LOG(LogTemp, Warning, TEXT("Hitlocation= %s", *HitLocation.ToString()));
	}
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const{

}

