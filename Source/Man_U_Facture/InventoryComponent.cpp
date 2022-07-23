// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryComponent.h"
#include "Resource.h"

// Sets default values for this component's properties
UInventoryComponent::UInventoryComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UInventoryComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UInventoryComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UInventoryComponent::AddItem(FString ItemType, FString ItemName, int32 Amount)
{
	if(ItemType == "Wood")
	{
		uint32& WoodRef = WoodInventory.FindOrAdd(ItemName);
		WoodRef += Amount;
	}
	else if(ItemType == "Metal")
	{
		uint32&  MetalRef = MetalInventory.FindOrAdd(ItemName);
		MetalRef += Amount;
	}
	else if(ItemType == "Chemical")
	{
		uint32& ChemicalRef = ChemicalInventory.FindOrAdd(ItemName);
		ChemicalRef += Amount;
	}
	else
	{
		UE_LOG(LogTemp,Warning,TEXT("This item is nothing!!!"));
	}
}

void UInventoryComponent::TakeWood(const FString ItemName, const int32 Amount)
{
	if(WoodInventory.Contains(ItemName))
	{
		WoodInventory[ItemName] = WoodInventory[ItemName] - Amount;
	}
	else
	{
		UE_LOG(LogTemp,Warning,TEXT("You don't have enough %s!"), *ItemName);
	}
}

void UInventoryComponent::TakeChemical(const FString ItemName, const int32 Amount)
{
	if(ChemicalInventory.Contains(ItemName))
	{
		ChemicalInventory[ItemName] = ChemicalInventory[ItemName] - Amount;
	}
	else
	{
		UE_LOG(LogTemp,Warning,TEXT("You don't have enough %s!"), *ItemName);
	}
}

void UInventoryComponent::TakeMetal(const FString ItemName, const int32 Amount)
{
	if(MetalInventory.Contains(ItemName))
	{
		MetalInventory[ItemName] = MetalInventory[ItemName] - Amount;
	}
	else
	{
		UE_LOG(LogTemp,Warning,TEXT("You don't have enough %s!"), *ItemName);
	}
}



