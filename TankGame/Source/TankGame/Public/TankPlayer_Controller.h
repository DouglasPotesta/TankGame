// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "GameFramework/PlayerController.h"
#include "TankPlayer_Controller.generated.h" // Must be the last include

class ATank;
/**
 * 
 */
UCLASS()
class TANKGAME_API ATankPlayer_Controller : public APlayerController
{
	GENERATED_BODY()
	
public:
	ATank* GetControlledTank() const;

	virtual void BeginPlay() override;
	
	virtual void Tick(float DeltaTime) override;
	
private:
	// Start the tank moving the barrel so that a shot would hit where
	// the crosshair intersects the world
	void AimTowardsCrosshair();

	bool GetSightRayHitLocation(FVector& OutHitLocation) const;

	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;

	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;

	UPROPERTY(EditDefaultsOnly)
		float CrossHairXLocation = 0.5f;
	UPROPERTY(EditDefaultsOnly)
		float CrossHairYLocation = 0.333333f;
	UPROPERTY(EditDefaultsOnly)
		float LineTraceRange = 10000;

};
