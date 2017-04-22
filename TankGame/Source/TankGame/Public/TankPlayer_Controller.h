// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayer_Controller.generated.h" // Must be the last include

/**
 * 
 */
UCLASS()
class TANKGAME_API ATankPlayer_Controller : public APlayerController
{
	GENERATED_BODY()
	
public:
	ATank* GetControlledTank() const;

	void BeginPlay() override;
	
	
};
