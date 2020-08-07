// Fill out your copyright notice in the Description page of Project Settings.


#include "DiceSprite.h"


void ADiceSprite::DiceSprite()
{
	OnClicked.AddDynamic(this, &ADiceSprite::RollDice);
}

void ADiceSprite::RollDice(UPrimitiveComponent* ClickedComponent, FKey ButtonPressed)
{

}