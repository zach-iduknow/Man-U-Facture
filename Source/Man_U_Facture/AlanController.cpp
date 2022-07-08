// Fill out your copyright notice in the Description page of Project Settings.


#include "AlanController.h"
#include "InventoryComponent.h"

void AAlanController::BeginPlay()
{
	Super::BeginPlay();
	PlayerInventory = FindComponentByClass<UInventoryComponent>();
	if(PlayerInventory)
	{
		UE_LOG(LogTemp, Warning, TEXT("Inventory Attached!"));
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("No Inventory Attached!"));
	}
}
