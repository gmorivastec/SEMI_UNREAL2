// Fill out your copyright notice in the Description page of Project Settings.


#include "ActorSingleton.h"

// Sets default values
AActorSingleton::AActorSingleton()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void AActorSingleton::BeginPlay()
{
	Super::BeginPlay();
	
	// mismo mecanismo que hicimos en Unity
	// verificar si ya existe y si si tronar esta instancia
	if(Instance != NULL)
		Destroy();

	Instance = this;
}

// Called every frame
void AActorSingleton::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

AActorSingleton * AActorSingleton::GetInstance(){
	return AActorSingleton::Instance;
}

int AActorSingleton::GetScore(){
	return AActorSingleton::GetInstance()->score;
}

AActorSingleton * AActorSingleton::Instance = NULL;