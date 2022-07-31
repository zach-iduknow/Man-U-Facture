// Fill out your copyright notice in the Description page of Project Settings.


#include "HarvestTool.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "ToolComponent.h"
// Sets default values
AHarvestTool::AHarvestTool()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = SceneRoot;

	HandleMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Handle"));
	HandleMesh->SetupAttachment(RootComponent);

	HeadMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Head"));
	HeadMesh->SetupAttachment(HandleMesh);
}

// Called when the game starts or when spawned
void AHarvestTool::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AHarvestTool::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

