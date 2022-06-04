// Fill out your copyright notice in the Description page of Project Settings.


#include "Plataforma.h"

// Sets default values
APlataforma::APlataforma()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APlataforma::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlataforma::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// como obtener ubicación programáticamente
	// programatically 
	FVector currentLocation = GetActorLocation();

	//UE_LOG(LogTemp, Warning, TEXT("UBICACION: %s"), currentLocation);

	// verificamos en qué dirección debe moverse
	if(currentLocation.Y < limiteIzq || currentLocation.Y > limiteDer){

		// cambia de dirección
		direccion *= -1;
	}

	// modificamos la posición en Y
	currentLocation.Y += DeltaTime * velocidad * direccion;
	SetActorLocation(currentLocation);
}

