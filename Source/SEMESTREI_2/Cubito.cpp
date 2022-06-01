// Fill out your copyright notice in the Description page of Project Settings.


#include "Cubito.h"

// Sets default values
ACubito::ACubito()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACubito::BeginPlay()
{
	Super::BeginPlay();

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, TEXT("HOLA DESDE C++"));
	StaticMesh = Cast<UStaticMeshComponent>(GetComponentByClass(UStaticMeshComponent::StaticClass()));

	UE_LOG(LogTemp, Display, TEXT("el nombre del static mesh: %s"), *StaticMesh->GetName());

	StaticMesh->AddImpulse(FVector(0, 1000, 0));
}

// Called every frame
void ACubito::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

