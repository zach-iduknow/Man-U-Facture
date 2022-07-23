// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemDrop.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "InventoryComponent.h"


// Sets default values
AItemDrop::AItemDrop()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = Mesh;
	
	HitBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Hit Box"));
	HitBox->SetupAttachment(RootComponent);
	

}

// Called when the game starts or when spawned
void AItemDrop::BeginPlay()
{
	Super::BeginPlay();
	HitBox->OnComponentBeginOverlap.AddDynamic(this,&AItemDrop::OnOverlapBegin);
	
}

//overlap delegate to see if character that walked over can pickup
void AItemDrop::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//checks to see if actor has a controller
	if(AController* Controller = OtherActor->GetInstigatorController())
	{
		//checks to see if actor has inventory
		if(UInventoryComponent* Inventory = Controller->FindComponentByClass<UInventoryComponent>())
		{
			Inventory->AddItem(Type,Name,Amount);
			Destroy();
		}
	}
}

// Called every frame
void AItemDrop::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

