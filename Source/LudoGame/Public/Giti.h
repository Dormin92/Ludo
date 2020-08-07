// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Giti.generated.h"

UCLASS()
class LUDOGAME_API AGiti : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AGiti();

	virtual void Tick(float DeltaSeconds);

	UFUNCTION(Server, Reliable)
	void MoveGiti(FVector NewLocation);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:	
};
