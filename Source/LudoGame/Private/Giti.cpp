// Fill out your copyright notice in the Description page of Project Settings.


#include "Giti.h"
#include "Kismet/GameplayStatics.h"
#include "Components/InputComponent.h"

// Sets default values
AGiti::AGiti()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned
void AGiti::BeginPlay()
{
	Super::BeginPlay();
	
}

void AGiti::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}

void AGiti::MoveGiti_Implementation(FVector NewLocation)
{
	SetActorLocation(NewLocation);
}

