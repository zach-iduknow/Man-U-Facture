// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InventoryComponent.generated.h"

class AResource;
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MAN_U_FACTURE_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInventoryComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	//using TMap to map item names to their respective slot in the map
	UPROPERTY(VisibleAnywhere, Category = "Resources")
	TMap<FString, uint32> WoodInventory;

	UPROPERTY(VisibleAnywhere, Category = "Resources")
	TMap<FString, uint32> MetalInventory;
	
	//this one is for stuff like glue and rubber
	UPROPERTY(VisibleAnywhere, Category = "Resources")
	TMap<FString, uint32> ChemicalInventory;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
	void AddItem(FString ItemType, FString ItemName, int32 Amount);
	
	void TakeWood(const FString ItemName, const int32 Amount);
	
	void TakeMetal(const FString ItemName, const int32 Amount);
	
	void TakeChemical(const FString ItemName, const int32 Amount);
		
};
