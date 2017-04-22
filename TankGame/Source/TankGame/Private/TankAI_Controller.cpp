// Fill out your copyright notice in the Description page of Project Settings.

#include "TankGame.h"
#include "TankAI_Controller.h"


void ATankAI_Controller::BeginPlay()
{
	Super::BeginPlay();
	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController NOT POSSESSING A TANK"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController possessing: %s"), *(ControlledTank->GetName()));
	}
}


ATank* ATankAI_Controller::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}







