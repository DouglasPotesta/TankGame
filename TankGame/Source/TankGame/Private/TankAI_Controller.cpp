// Fill out your copyright notice in the Description page of Project Settings.

#include "TankGame.h"
#include "Tank.h"
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
	auto PlayerControlledTank = GetPlayerTank();
	if (!PlayerControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Player is not POSSESSING A TANK"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Player tank is: %s"), *(PlayerControlledTank->GetName()));
	}
}

void ATankAI_Controller::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GetPlayerTank()) 
	{
		// TODO Move Towards the player

		// Aim towards the player
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
		// Fire if ready

	}
}




ATank* ATankAI_Controller::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank * ATankAI_Controller::GetPlayerTank() const
{

	APlayerController* playerController = GetWorld()->GetFirstPlayerController();

	return Cast<ATank>(playerController->GetPawn());
}






