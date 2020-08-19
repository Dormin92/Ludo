// Fill out your copyright notice in the Description page of Project Settings.


#include "GitiSpriteComponent.h"

UGitiSpriteComponent::UGitiSpriteComponent()
{
	OnClicked.AddDynamic(this, &UGitiSpriteComponent::RollDice);
}

void UGitiSpriteComponent::RollDice(UPrimitiveComponent* ClickedComponent, FKey ButtonPressed)
{

}