// Fill out your copyright notice in the Description page of Project Settings.


#include "Resource.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "HealthComponent.h"

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
	HealthComponent = FindComponentByClass<UHealthComponent>();
	if(!HealthComponent)
	{
		UE_LOG(LogTemp, Warning, TEXT("Resource %s doesn't have a health component!"), *GetName());
	}
	
}

// Called every frame
void AResource::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	if(HealthComponent && HealthComponent->GetHasDied())
	{
		Die();
	}

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
	UE_LOG(LogTemp, Warning,TEXT("Ounch!"));
	//for loop for item dropping
	for(int32 i = 0; i < 3; i++)
	{
		FVector Location = GetActorLocation() + FVector(0.f,10.f,0.f);
		FRotator Rotation = FRotator::ZeroRotator;
		//AActor* SpawnedItem = GetWorld()->SpawnActor();
		
	}
	Destroy();
	//spawn item drop in physical space based on the number dropped
	//Add a little force to each object in the y and x or z direction
}

