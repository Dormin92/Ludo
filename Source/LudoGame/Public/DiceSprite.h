// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperSpriteActor.h"
#include "DiceSprite.generated.h"

/**
 * 
 */
UCLASS()
class LUDOGAME_API ADiceSprite : public APaperSpriteActor
{
	GENERATED_BODY()
public:
	DiceSprite();

	UFUNCTION()
	void RollDice(UPrimitiveComponent* ClickedComponent, FKey ButtonPressed);
};
