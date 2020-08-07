// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "GitiController.generated.h"

class AGiti;

UCLASS()
class LUDOGAME_API AGitiController : public APlayerController
{
	GENERATED_BODY()

public:
	virtual void SetupInputComponent() override;

private:
	virtual void BeginPlay() override;
	AGiti* GitiGrabbed = nullptr;
	void MouseGrabGiti(float value);
	void TouchGrabGiti(float value);
	virtual bool InputTouch(uint32 Handle, ETouchType::Type Type, const FVector2D& TouchLocation, float Force, FDateTime DeviceTimestamp, uint32 TouchpadIndex) override;
};
