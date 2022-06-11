// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ActorSingleton.generated.h"

UCLASS()
class SEMESTREI_2_API AActorSingleton : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AActorSingleton();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	static AActorSingleton* Instance;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	static AActorSingleton* GetInstance();

	UPROPERTY(EditAnywhere)
	int score = 0;

	UFUNCTION(BlueprintCallable)
	static int GetScore();

};
