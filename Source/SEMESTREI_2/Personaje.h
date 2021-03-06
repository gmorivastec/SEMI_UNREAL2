// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Personaje.generated.h"

// ARCHIVOS .H (EL "QUÉ")
// headers - encabezados 
// archivo que sólo contiene: contratos y firmas
// contrato - estructura de clase
// firmas - nombre completo de método - tipo de retorno, nombre, lista de parámetros

UCLASS()
class SEMESTREI_2_API APersonaje : public ACharacter
{
	GENERATED_BODY()

public:
	//^^^^ así se escriben los modificadores de acceso en C++

	// Sets default values for this character's properties
	APersonaje();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	int32 Entero = 0;

	// propiedades modificables desde editor
	UPROPERTY(EditAnywhere)
	int32 OtroEntero = 5;

	UPROPERTY(EditAnywhere)
	FVector Vectorcito = FVector(1, 2, 3);

	UPROPERTY(EditAnywhere)
	bool Booleano = false;

	UPROPERTY(EditAnywhere, Category="Una Categoría Chida")
	float Flotante = 5;

	UPROPERTY(VisibleAnywhere)
	float Visible = 10;
};
