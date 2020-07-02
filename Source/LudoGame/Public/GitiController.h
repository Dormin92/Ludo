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
	UFUNCTION(BlueprintCallable)
	void SetGitiGrabbed(AGiti* G) { GitiGrabbed = G; };

	UFUNCTION(BlueprintCallable)
	void SetGitiGrabbedToNull() { GitiGrabbed = nullptr; };

	UFUNCTION(BlueprintCallable)
	AGiti* GetGitiGrabbed() const { return GitiGrabbed; };

private:
	virtual void SetupInputComponent() override;
	void GrabGiti(float Value);

	UPROPERTY(VisibleAnywhere)
	AGiti* GitiGrabbed = nullptr;
};
