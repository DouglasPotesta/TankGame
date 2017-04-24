// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AIController.h"
#include "TankAI_Controller.generated.h"

class UTank;
/**
 * 
 */
UCLASS()
class TANKGAME_API ATankAI_Controller : public AAIController
{
	GENERATED_BODY()
		private:
	void BeginPlay() override;
	
	virtual void Tick(float DeltaTime) override;


};
