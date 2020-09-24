// Fill out your copyright notice in the Description page of Project Settings.


#include "DiceSprite.h"
#include <PaperSpriteComponent.h>


ADiceSprite::ADiceSprite()
{
	CurrentDiceSprite = FindComponentByClass<UPaperSpriteComponent>();
	//OnClicked.AddDynamic(this, &ADiceSprite::RollDice);
}

void ADiceSprite::ChangeSprite_Implementation(int DiceSide)
{

	CurrentDiceSprite->SetSprite(DiceArray[DiceSide]);
}