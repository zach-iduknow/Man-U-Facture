// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "AlanController.generated.h"

/**
 * 
 */
class UInventoryComponent;
UCLASS()
class MAN_U_FACTURE_API AAlanController : public APlayerController
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="Inventory")
	UInventoryComponent* PlayerInventory; 

protected:
	virtual void BeginPlay() override;
	
};
