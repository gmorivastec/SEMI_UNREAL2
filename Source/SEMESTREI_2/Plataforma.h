// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Plataforma.generated.h"

UCLASS()
class SEMESTREI_2_API APlataforma : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APlataforma();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	int direccion = 1;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, Category="Límites de plataforma")
	float limiteIzq = 0;

	UPROPERTY(EditAnywhere, Category="Límites de plataforma")
	float limiteDer = 0;

	UPROPERTY(EditAnywhere, Category="Límites de plataforma")
	float velocidad = 10;
};
