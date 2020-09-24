// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperSpriteActor.h"
#include "DiceSprite.generated.h"

class UPaperSprite;
UCLASS()
class LUDOGAME_API ADiceSprite : public APaperSpriteActor
{
	GENERATED_BODY()
public:
	ADiceSprite();

	UPROPERTY(EditAnywhere)
	TArray<UPaperSprite*> DiceArray;

	UPaperSpriteComponent* CurrentDiceSprite;

	UFUNCTION(NetMulticast, Reliable)
	void ChangeSprite(int DiceSide);
};
