// Fill out your copyright notice in the Description page of Project Settings.


#include "GitiController.h"
#include "Giti.h"

void AGitiController::BeginPlay()
{
	Super::BeginPlay();
}

void AGitiController::SetupInputComponent()
{
	Super::SetupInputComponent();
	//InputComponent->BindAxis("GrabMouse", this, &AGitiController::MouseGrabGiti);
	InputComponent->BindAxis("GrabTouch", this, &AGitiController::TouchGrabGiti);
}

void AGitiController::MouseGrabGiti(float value)
{
	if (value > 0.0f)
	{
		if (GitiGrabbed == nullptr)
		{
			TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypes;
			FHitResult OutHit;
			ObjectTypes.Add(UEngineTypes::ConvertToObjectType(ECC_Pawn));
			GetHitResultUnderCursorForObjects(ObjectTypes, true, OutHit);
			if (OutHit.Actor->IsOwnedBy(this))
			{
				GitiGrabbed = (AGiti*)OutHit.GetActor();
			}
		}
		else
		{
			FVector OutWorldLocation, OutWorldDirection;
			DeprojectMousePositionToWorld(OutWorldLocation, OutWorldDirection);
			GitiGrabbed->MoveGiti(OutWorldLocation);
		}
	}
	else if (GitiGrabbed != nullptr)
	{
		GitiGrabbed = nullptr;
	}
}

void AGitiController::TouchGrabGiti(float value)
{
	bool OutIsPressed;
	float OutTouchX, OutTouchY;
	GetInputTouchState(ETouchIndex::Touch1, OutTouchX, OutTouchY, OutIsPressed);

	if (OutIsPressed)
	{
		if (GitiGrabbed == nullptr)
		{
			TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypes;
			FHitResult OutHit;
			ObjectTypes.Add(UEngineTypes::ConvertToObjectType(ECC_Pawn));
			GetHitResultUnderFingerForObjects(ETouchIndex::Touch1, ObjectTypes, true, OutHit);
			if (OutHit.Actor->IsOwnedBy(this))
			{
				GitiGrabbed = (AGiti*)OutHit.GetActor();
			}
		}
		else
		{
			FVector OutWorldLocation, OutWorldDirection;
			DeprojectScreenPositionToWorld(OutTouchX, OutTouchY, OutWorldLocation, OutWorldDirection);
			GitiGrabbed->MoveGiti(OutWorldLocation);
		}
	}
	else
	{
		GitiGrabbed = nullptr;
	}
}

bool AGitiController::InputTouch(uint32 Handle, ETouchType::Type Type, const FVector2D& TouchLocation, float Force, FDateTime DeviceTimestamp, uint32 TouchpadIndex)
{
	return Super::InputTouch(Handle, Type, TouchLocation, Force, DeviceTimestamp, TouchpadIndex);
}
