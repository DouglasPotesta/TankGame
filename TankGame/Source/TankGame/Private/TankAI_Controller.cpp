// Fill out your copyright notice in the Description page of Project Settings.

#include "TankGame.h"
#include "Tank.h"
#include "TankAI_Controller.h"


void ATankAI_Controller::BeginPlay()
{
	Super::BeginPlay();

}

void ATankAI_Controller::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControlledTank = Cast<ATank>(GetPawn());


	if (PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("sUCCESS"));
		// Aim towards the player
		ControlledTank->AimAt(PlayerTank->GetActorLocation());
		// Fire if ready
		ControlledTank->Fire(); // TODO limit firing rate
	}
}








