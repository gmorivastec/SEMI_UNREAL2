// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Camera/CameraComponent.h"
#include "PersonajeMovil.generated.h"


UCLASS()
class SEMESTREI_2_API APersonajeMovil : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APersonajeMovil();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// funciones para entrada
	void MoverX(float Axis);
	void MoverY(float Axis);
	void EmpezarDisparo();
	void TerminarDisparo();

	// variables de entrada
	FVector VelocidadActual;
	bool bDisparando;

	UPROPERTY(EditAnywhere)
	USceneComponent* ComponenteVisible;

	UPROPERTY(EditAnywhere, Category="Spawner")
	TSubclassOf<AActor> Proyectil;
};
