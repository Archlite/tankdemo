// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "TankAimingComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TANKS_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	//currently just outputs where the tank is aiming
	void AimAt(FVector HitLocation);
	//sets the barrel to the controlled tanks barrel
	void SetBarrelReference(UStaticMeshComponent* BarrelToSet);
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:	
	UStaticMeshComponent* Barrel = nullptr;
		
	
};
