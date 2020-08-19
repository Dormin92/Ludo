// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperSpriteComponent.h"
#include "GitiSpriteComponent.generated.h"
#include <Paper2D\Classes\PaperSpriteActor.h>

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class LUDOGAME_API UGitiSpriteComponent : public UPaperSpriteComponent
{
	GENERATED_BODY()
public:
	APaperSpriteActor* DiceSprites[6];


	UGitiSpriteComponent();

	UFUNCTION()
	void RollDice(UPrimitiveComponent* ClickedComponent, FKey ButtonPressed);
};
