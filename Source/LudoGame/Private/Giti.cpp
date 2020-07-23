// Fill out your copyright notice in the Description page of Project Settings.


#include "Giti.h"
#include "Kismet/GameplayStatics.h"
#include "Components/InputComponent.h"

// Sets default values
AGiti::AGiti()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AGiti::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGiti::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}

void AGiti::MoveGiti_Implementation(FVector NewLocation)
{
	UE_LOG(LogTemp, Warning, TEXT("MoveGiti called"));
	SetActorLocation(NewLocation);
}

