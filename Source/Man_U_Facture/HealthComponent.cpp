// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthComponent.h"
#include "GameFramework/Character.h"
// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;
	Health = MaxHealth;
	// ...
}


// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	//didn't know you could declare variables in the argument for an if statement
	if(AActor* Owner = GetOwner())
	{
		//Adding the TakeDamage function(delegate) to the OnTakeAnyDamage listener
		//Adds logic to the OnTakeAnyDamage listener to do a specific action once damage is taken
		Owner->OnTakeAnyDamage.AddDynamic(this,&UHealthComponent::TakeDamage);
	}
	else 
	{
		UE_LOG(LogTemp,Error,TEXT("Can't Find Owner!"));
	}
}


// Called every frame
void UHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

//this function is a delegate to handle damage taken by the owning actor
//these arguments are what is required to be a delegate for the OnTakeAnyDamage listener
void UHealthComponent::TakeDamage(AActor*DamagedActor, float Damage, const class UDamageType* DamageType, 
class AController* InstigatedBy, AActor* DamageCauser)
{	
	//returns out of the function if no damage was dealt
	if(Damage < 0) return;
	Health = FMath::Clamp(Health - Damage, 0.0f, MaxHealth);
	if(Health <= 0)
	{
		bHasDied = true;
	}
	if(!GetOwner()) return;
	UE_LOG(LogTemp,Display,TEXT("%s has %f health"), *GetOwner()->GetName(),Health);
}

//getter for the protected bHasDied variable
bool UHealthComponent::GetHasDied() const
{
	return bHasDied;
}