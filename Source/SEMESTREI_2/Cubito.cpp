// Fill out your copyright notice in the Description page of Project Settings.


#include "Cubito.h"
#include "ActorSingleton.h"

// Sets default values
ACubito::ACubito()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void ACubito::BeginPlay()
{
	Super::BeginPlay();

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, TEXT("HOLA DESDE C++"));
	StaticMesh = Cast<UStaticMeshComponent>(GetComponentByClass(UStaticMeshComponent::StaticClass()));
	
	// podriamos obtener el box
	// no lo vamos a usar pero lo ponemos para que vean que se puede
	UBoxComponent* Box = Cast<UBoxComponent>(GetComponentByClass(UBoxComponent::StaticClass()));

	UE_LOG(LogTemp, Display, TEXT("el nombre del static mesh: %s"), *StaticMesh->GetName());

	StaticMesh->AddImpulse(Vectorcito);

	StaticMesh->OnComponentBeginOverlap.AddDynamic(this, &ACubito::OverlapBegin);
	StaticMesh->OnComponentEndOverlap.AddDynamic(this, &ACubito::OverlapEnd);
}

// Called every frame
void ACubito::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACubito::OverlapBegin(UPrimitiveComponent* Comp, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult){

	UE_LOG(LogTemp, Warning, TEXT("OVERLAP %s VS. %s"), *GetName(), *OtherActor->GetName());
	AActorSingleton::GetInstance()->score += 100;
	Destroy();
}

void ACubito::OverlapEnd(UPrimitiveComponent* Comp, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex){
	UE_LOG(LogTemp, Warning, TEXT("OVERLAP END %s VS. %s"), *GetName(), *OtherActor->GetName());
}