// Fill out your copyright notice in the Description page of Project Settings.

#include "TankGame.h"
#include "Tank.h"
#include "TankPlayer_Controller.h"


void ATankPlayer_Controller::BeginPlay()
{
	Super::BeginPlay();
	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController NOT POSSESSING A TANK"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController possessing: %s"), *(ControlledTank->GetName()));
	}
}

void ATankPlayer_Controller::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
	// UE_LOG(LogTemp, Warning, TEXT("Tick"));
}


ATank* ATankPlayer_Controller::GetControlledTank() const 
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayer_Controller::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }

	FVector HitLocation; // Out parameter

	

	if (GetSightRayHitLocation(HitLocation)) { // Has "side-effect", is going to line trace
		
		// TODO Tell controlled tank to aim at this point
		GetControlledTank()->AimAt(HitLocation);
	}
	else {

	}
	
	// Get world location linetrace through crosshair
	// If it hits the landscape
	// tell controlled tank to aim at this point true if it hits landscape
}

bool ATankPlayer_Controller::GetSightRayHitLocation(FVector& OutHitLocation) const
{
	OutHitLocation = FVector(1);
	// Fine the crosshair position
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX*CrossHairXLocation, ViewportSizeY*CrossHairYLocation);
	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection)) {

		// Line-trace along that LookDirection, and see what we hit

		GetLookVectorHitLocation(LookDirection, OutHitLocation);
		//UE_LOG(LogTemp, Warning, TEXT("HitLocation: %s"), *OutHitLocation.ToString());
	}

	
	// "De-project" the screen position of the crosshair to a world direction 
	// Line-trace alon that look direction, and see what we hit (up to max range)
	return true;
}

bool ATankPlayer_Controller::GetLookVectorHitLocation(FVector LookDirection, FVector & HitLocation) const
{
	FHitResult HitResult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (LookDirection*LineTraceRange);
	if (GetWorld()->LineTraceSingleByChannel(HitResult,
		StartLocation, 
		EndLocation, 
		ECollisionChannel::ECC_Visibility
		))
	{
		HitLocation = HitResult.Location;
		return true;
	}
		return false;
}

bool ATankPlayer_Controller::GetLookDirection(FVector2D ScreenLocation, FVector & LookDirection) const
{

	FVector worldLocation;
	return DeprojectScreenPositionToWorld(
		ScreenLocation.X, 
		ScreenLocation.Y, 
		worldLocation, 
		LookDirection
	);
}




