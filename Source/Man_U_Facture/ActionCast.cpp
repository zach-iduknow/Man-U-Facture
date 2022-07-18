// Fill out your copyright notice in the Description page of Project Settings.


#include "ActionCast.h"

// Sets default values for this component's properties
UActionCast::UActionCast()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UActionCast::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UActionCast::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	// ...
}

FHitResult UActionCast::PerformCast() const
{
	FVector StartPoint = GetComponentLocation();
	FVector ForwardVector = GetForwardVector();
	FVector EndPoint = (ForwardVector * CastRange) + StartPoint;
	FHitResult Hit;
	GetWorld()->LineTraceSingleByChannel(Hit,StartPoint,EndPoint,ECC_GameTraceChannel1);
	return Hit;
}

