// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HealthComponent.h"
#include "GameFramework/Actor.h"
#include "Resource.generated.h"

class UStaticMeshComponent;
class UBoxComponent;
class UHealthComponent;
UCLASS()
class MAN_U_FACTURE_API AResource : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AResource();

	UPROPERTY(EditAnywhere, Category="World")
	UStaticMeshComponent* Mesh;

	UPROPERTY(EditAnywhere,Category="World")
	UBoxComponent* HitBox;
	
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category="Stats")
	FString Type = TEXT("");

	//Subtype is what kind of resource it is in respect to it's category
	UPROPERTY(EditAnywhere, Category="Stats")
	FString SubType = TEXT("");

	//what level of resource this is
	//this denotes what tool is needed and generally what crafting recipes need it
	UPROPERTY(EditAnywhere, Category="Stats")
	int32 ItemLevel;

	//Destroys object and drops item on death
	void Die();
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	FString GetType() const;
	FString GetSubType() const;
	int32 GetItemLevel() const;

private:
	UPROPERTY(EditAnywhere, Category="Stats")
	UHealthComponent* HealthComponent;

};
