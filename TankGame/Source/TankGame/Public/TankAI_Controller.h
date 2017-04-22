// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Tank.h"
#include "AIController.h"
#include "TankAI_Controller.generated.h"

/**
 * 
 */
UCLASS()
class TANKGAME_API ATankAI_Controller : public AAIController
{
	GENERATED_BODY()
public:
	ATank* GetControlledTank() const;

	void BeginPlay() override;


};
