// Fill out your copyright notice in the Description page of Project Settings.


#include "ToolComponent.h"
#include "Components/StaticMeshComponent.h"
// Sets default values
AToolComponent::AToolComponent()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));

}

// Called when the game starts or when spawned
void AToolComponent::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AToolComponent::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

UStaticMesh* AToolComponent::GetMesh() const
{
	return Mesh->GetStaticMesh();
}


