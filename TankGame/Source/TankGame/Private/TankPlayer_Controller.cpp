// Fill out your copyright notice in the Description page of Project Settings.

#include "TankGame.h"
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


ATank* ATankPlayer_Controller::GetControlledTank() const 
{
	return Cast<ATank>(GetPawn());
}



