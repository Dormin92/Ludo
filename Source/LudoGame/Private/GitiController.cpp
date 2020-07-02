// Fill out your copyright notice in the Description page of Project Settings.


#include "GitiController.h"
#include "Giti.h"

void AGitiController::SetupInputComponent()
{
	Super::SetupInputComponent();
	InputComponent->BindAxis("Grab", this, &AGitiController::GrabGiti);
}

void AGitiController::GrabGiti(float Value)
{
	if (Value != 0 && GitiGrabbed != nullptr)
	{
		FVector MouseLocation, aimDirection;
		DeprojectMousePositionToWorld(MouseLocation, aimDirection);
		GitiGrabbed->MoveGiti(MouseLocation);
	}
}
