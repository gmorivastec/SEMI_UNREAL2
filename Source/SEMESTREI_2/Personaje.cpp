// Fill out your copyright notice in the Description page of Project Settings.


#include "Personaje.h"

// este archivo es de implementación
// es el "CÓMO"

// Sets default values
APersonaje::APersonaje()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Entero = 5;
	UE_LOG(LogTemp, Error, TEXT("ENTERO: %i"), Entero);

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

	Entero = 10;
	UE_LOG(LogTemp, Error, TEXT("ENTERO: %i"), Entero);
	
	// ejemplo: imprimiendo un fstring 
    FString ejemplito = GetName();

	// por qué tiene un asterisco eso?!                            v vvv v v
	UE_LOG(LogTemp, Display, TEXT("el nombre de este cuate: %s"), *ejemplito);
    
	// variables con asterisco son apuntadores (pointer)
	// apuntador es un tipo de variable que NO contiene el dato, APUNTA a un espacio
	// en memoria que lo contiene
	// se crea al utilizar la keyword "new"
	// es INDISPENSABLE destruirlos cuando los creamos

	// en C++ nosotros limpiamos la memoria
	// si no destruimos un objeto nunca se crea un "memory leak"

	// Mensaje en pantalla
	// operador -> 
	// SE USA CUANDO ESTAMOS ACCEDIENDO A UN MIEMBRO DE UN APUNTADOR

	// Clase::Miembro - acceso a un miembro estático
	// miembro - enumeración, atributo, método, etc que pertenece a una clase
	(*GEngine).AddOnScreenDebugMessage(-1, 5.12f, FColor::White, TEXT("HOLA AMIGOTES"));
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, TEXT("HOLA AMIGOTOTES (2)"));

}

// Called every frame
// se ejecuta mientras el juego esté corriendo 
// una vez por frame 
// la frecuencia depende del framerate 
void APersonaje::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

    //UE_LOG(LogTemp, Log, TEXT("delta: %i"), DeltaTime);
}

void APersonaje::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) {

    Super::SetupPlayerInputComponent(PlayerInputComponent);
}
