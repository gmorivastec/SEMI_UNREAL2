// Fill out your copyright notice in the Description page of Project Settings.


#include "Spawner.h"
#include "Kismet/GameplayStatics.h"

// Sets default values for this component's properties
USpawner::USpawner()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void USpawner::BeginPlay()
{
	Super::BeginPlay();

	player = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	// ...
	
}


// Called every frame
void USpawner::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
	if(player->IsInputKeyDown(EKeys::SpaceBar)){

		// como instanciar un actor
		GetWorld()->SpawnActor<AActor>(Proyectil, GetOwner()->GetActorLocation(), GetOwner()->GetActorRotation());
	}
}

