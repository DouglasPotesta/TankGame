// Fill out your copyright notice in the Description page of Project Settings.

#include "TankGame.h"
#include "TankTrack.h"


void UTankTrack::SetThrottle(float Throttle)
{
	//auto Time = GetWorld()->GetTimeSeconds();

	auto Name = GetName();
	// TODO Clamp actual throttle value so player can't over-drive

	UE_LOG(LogTemp, Warning, TEXT("%s: Projetile fires at %f"), *Name, Throttle);

	auto ForceApplied = GetForwardVector() * Throttle * TrackMaxDrivingForce;
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());

	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);

}

