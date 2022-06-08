// Fill out your copyright notice in the Description page of Project Settings.


#include "PersonajeMovil.h"


// Sets default values
APersonajeMovil::APersonajeMovil()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// definir si queremos que se asocie automáticamente a un jugador
	AutoPossessPlayer = EAutoReceiveInput::Player0;

	
	// vamos haciendo un root component de manera explícita
	// <> - diamantes 
	// los diamantes se usan en clases y métodos que tienen tipos genéricos
	
	//RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

	// creamos objeto camara
	// UCameraComponent* Camara = CreateDefaultSubobject<UCameraComponent>(TEXT("Camarita"));

	// creamos objeto componente visible 
	//ComponenteVisible = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Cuerpito"));

	// asociamos en jerarquía
	// Camara->SetupAttachment(RootComponent);
	// Camara->SetRelativeLocation(FVector(-250, 0, 250));

	// FRotator - como euler angles
	// 1 valor de rotación por eje
	// pueden toparse con quaternions
	// vector tamaño 4 que define una rotación en espacio 3D
	// Camara->SetRelativeRotation(FRotator(-45, 0, 0));

	// ComponenteVisible->SetupAttachment(RootComponent);
	
}

// Called when the game starts or when spawned
void APersonajeMovil::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APersonajeMovil::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if(bDisparando){

		GetWorld()->SpawnActor<AActor>(Proyectil, GetActorLocation(), GetActorRotation());
		bDisparando = false;
	}

	// moverse sólo si la velocidad no es cero
	if(!VelocidadActual.IsZero()){

		FVector NuevaPos = GetActorLocation() + (VelocidadActual * DeltaTime);
		SetActorLocation(NuevaPos);
	}

}

// Called to bind functionality to input
void APersonajeMovil::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// asociando una acción con un método específico
	InputComponent->BindAction("Disparo", IE_Pressed, this, &APersonajeMovil::EmpezarDisparo);
	InputComponent->BindAction("Disparo", IE_Released, this, &APersonajeMovil::TerminarDisparo);

	// asociar los ejes con el movimiento
	InputComponent->BindAxis("MoverX", this, &APersonajeMovil::MoverX);
	InputComponent->BindAxis("MoverY", this, &APersonajeMovil::MoverY);
}

void APersonajeMovil::MoverX(float Axis){
	//UE_LOG(LogTemp, Display, TEXT("Eje x: %f"), Axis);
	VelocidadActual.X = Axis * 100;
}

void APersonajeMovil::MoverY(float Axis){
	//UE_LOG(LogTemp, Display, TEXT("Eje y: %f"), Axis);
	VelocidadActual.Y = Axis * 100;
}

void APersonajeMovil::EmpezarDisparo(){
	UE_LOG(LogTemp, Display, TEXT("Empieza Disparo"));
	bDisparando = true;
}

void APersonajeMovil::TerminarDisparo(){
	UE_LOG(LogTemp, Display, TEXT("Termina Disparo"));
	bDisparando = false;
}
