// Fill out your copyright notice in the Description page of Project Settings.


#include "Personaje.h"

// Sets default values
APersonaje::APersonaje()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
// se ejecuta una sola vez al iniciar gameplay
void APersonaje::BeginPlay()
{
	Super::BeginPlay();

	// imprimir mensajes a log
    // https://unrealcommunity.wiki/logging-lgpidy6i
	UE_LOG(LogTemp, Log, TEXT("Log de Log"));
    UE_LOG(LogTemp, Display, TEXT("Log de display"));
	UE_LOG(LogTemp, Warning, TEXT("Log de warning"));
	UE_LOG(LogTemp, Error, TEXT("Log de error"));
    
    // ESTO HACE QUE EL EDITOR TRUENE
    // UE_LOG(LogTemp, Fatal, TEXT("Log fatal"));

	
}

// Called every frame
// se ejecuta mientras el juego esté corriendo 
// una vez por frame 
// la frecuencia depende del framerate 
void APersonaje::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

    UE_LOG(LogTemp, Log, TEXT("delta: %i"), DeltaTime);
}

void APersonaje::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) {

    Super::SetupPlayerInputComponent(PlayerInputComponent);
}
