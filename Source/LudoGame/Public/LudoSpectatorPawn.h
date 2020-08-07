// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SpectatorPawn.h"
#include "LudoSpectatorPawn.generated.h"

/**
 * 
 */
UCLASS()
class LUDOGAME_API ALudoSpectatorPawn : public ASpectatorPawn
{
	GENERATED_BODY()
public:
	UFUNCTION(Server, Reliable)
	void MoveGiti(FVector NewLocation);
};
