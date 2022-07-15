// Fill out your copyright notice in the Description page of Project Settings.


#include "HarvestTool.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
// Sets default values
AHarvestTool::AHarvestTool()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = SceneRoot;

	AxeHandle = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Axe Handle"));
	AxeHandle->SetupAttachment(RootComponent);
	
	AxeHead = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Axe Head"));
	AxeHead->SetupAttachment(AxeHandle);

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

