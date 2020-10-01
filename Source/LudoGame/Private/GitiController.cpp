// Fill out your copyright notice in the Description page of Project Settings.


#include "GitiController.h"
#include "DiceSprite.h"
#include "Giti.h"
#include <TimerManager.h>

void AGitiController::BeginPlay()
{
	Super::BeginPlay();
	
}

void AGitiController::SetupInputComponent()
{
	Super::SetupInputComponent();
	//InputComponent->BindAxis("GrabMouse", this, &AGitiController::MouseGrabGiti);
	InputComponent->BindAxis("GrabTouch", this, &AGitiController::TouchGrabGiti);
	InputComponent->BindAction("ClickTouch", IE_Pressed, this, &AGitiController::TouchDice);
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

void AGitiController::TouchDice()
{
	TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypes;
	FHitResult OutHit;
	ETraceTypeQuery MyQuery = UEngineTypes::ConvertToTraceType(ECollisionChannel::ECC_GameTraceChannel1);
	GetHitResultUnderFingerByChannel(ETouchIndex::Touch1, MyQuery, true, OutHit);
	if (OutHit.bBlockingHit)
	{
		//GEngine->AddOnScreenDebugMessage(1, 3.0f, FColor::Blue, OutHit.Actor->GetName());
		ADiceSprite* Dice = (ADiceSprite*)OutHit.GetActor();

		FTimerDelegate DiceRollDelegate;
		DiceRollDelegate.BindUFunction(this, FName("RollDiceOnServer"), Dice);
		GetWorldTimerManager().SetTimer(MemberTimerHandle, DiceRollDelegate, 0.25f, true);
		FTimerHandle StopTimerTimer;
		GetWorldTimerManager().SetTimer(StopTimerTimer, this, &AGitiController::StopLoop, 0.1f, false, 2.0f);
	}
}

void AGitiController::RollDiceOnServer_Implementation(ADiceSprite* DiceToRoll)
{
	int DiceSide = FMath::RandRange(0, 5);
	DiceToRoll->ChangeSprite(DiceSide);
}

void AGitiController::StopLoop_Implementation()
{
	GetWorldTimerManager().ClearTimer(MemberTimerHandle);
}

bool AGitiController::InputTouch(uint32 Handle, ETouchType::Type Type, const FVector2D& TouchLocation, float Force, FDateTime DeviceTimestamp, uint32 TouchpadIndex)
{
	return Super::InputTouch(Handle, Type, TouchLocation, Force, DeviceTimestamp, TouchpadIndex);
}
