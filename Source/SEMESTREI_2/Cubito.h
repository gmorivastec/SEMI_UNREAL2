// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Cubito.generated.h"

// NOTA PARA EL FUTURO:
// si hacen un blueprint class basado en una C++ class
// puede tener lógica desde el código y desde el blueprint

UCLASS()
class SEMESTREI_2_API ACubito : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACubito();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UStaticMeshComponent* StaticMesh;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	FVector Vectorcito = FVector(1, 2, 3);

};
