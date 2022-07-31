// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HarvestTool.generated.h"
class AToolComponent;
class USceneComponent;
UCLASS()
class MAN_U_FACTURE_API AHarvestTool : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AHarvestTool();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//total level of every tool component
	int32 ItemLevel; 
	
	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, Category="Object")
	USceneComponent* SceneRoot;

	//Meshes for the tool
	UPROPERTY(BlueprintReadWrite, Category="Visual")
	UStaticMeshComponent* HeadMesh;

	UPROPERTY(BlueprintReadWrite, Category="Visual")
	UStaticMeshComponent* HandleMesh;
	
	UPROPERTY(VisibleAnywhere,Category="Stats")
	int32 ToolLevel;
};
