// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ItemDrop.generated.h"

class UStaicMeshComponent;
class UBoxComponent;
UCLASS()
class MAN_U_FACTURE_API AItemDrop : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItemDrop();

	//name of item
	UPROPERTY(EditDefaultsOnly, Category="Stats")
	FString Name;

	//type of item for sorting
	UPROPERTY(EditAnywhere, Category="Stats")
	FString Type;

	//amount of item
	UPROPERTY(EditAnywhere,Category="Stats")
	int32 Amount;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* Mesh;

	UPROPERTY(EditAnywhere)
	UBoxComponent* HitBox;

	UFUNCTION()
	void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
