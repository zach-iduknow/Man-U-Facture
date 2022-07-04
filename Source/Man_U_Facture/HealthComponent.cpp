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
	
	//this whole setup below is crucial for damage systems
	//Getting the owning Actor and checking if it is valid
	AActor* Owner = GetOwner();
	if(Owner)
	{
		//Adding the TakeDamage function(delegate) to the OnTakeAnyDamage listener
		//Adds logic to the OnTakeAnyDamage listner to do a specific action once damage is taken
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
	if(Damage < 0) 
	{
		return;
	}
	if(Health <= 0)
	{
		Die();
	}
	Health = FMath::Clamp(Health - Damage, 0.0f, MaxHealth);

}

void UHealthComponent::Die()
{
	AActor* Owner = GetOwner();
	if(Owner)
	{
		UE_LOG(LogTemp,Warning,TEXT("Player Has Died!"));
		//Have the controller spawn the Game Over Screen(create an event here, handle that in BP)
		APawn* PlayerPawn = Cast<APawn>(Owner);
		//Detach from controller causes crash, maybe I only do that when I have an animation
		if(PlayerPawn)
		PlayerPawn->DetachFromControllerPendingDestroy();
		/*To Do
		*
			Tell game mode player died
				*Pass stats over
		*/
	}
	else
	{
		//log if the owner cast fails
		UE_LOG(LogTemp,Error,TEXT("Owner Pawn Cast Failed!"));
	}
}
