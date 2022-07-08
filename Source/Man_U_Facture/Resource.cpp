// Fill out your copyright notice in the Description page of Project Settings.


#include "Resource.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AResource::AResource()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = Mesh;
	
	HitBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Hit Box"));
	HitBox->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AResource::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AResource::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

FString AResource::GetType() const
{
	return Type;
}

FString AResource::GetSubType() const
{
	return SubType;
}

int32 AResource::GetItemLevel() const
{
	return ItemLevel;
}

void AResource::Die()
{
	//spawn item drop in physical space based on the number dropped
	//Add a little force to each object in the y and x or z direction
}

