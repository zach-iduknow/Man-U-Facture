// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ToolComponent.generated.h"

class UStaticMeshComponent;
UCLASS()
class MAN_U_FACTURE_API AToolComponent : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AToolComponent();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category="Visual")
	UStaticMeshComponent* Mesh;

	UPROPERTY(EditAnywhere, Category="Stats")
	FString ToolType;

	UPROPERTY(EditAnywhere, Category="Stats")
	int32 Level;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	UStaticMesh* GetMesh() const;
};
