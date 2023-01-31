// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseGeometryActor.h"
#include "GeometryHubActor.generated.h"

USTRUCT(BlueprintType)
struct FGeometryPayload
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnyWhere)
		TSubclassOf<ABaseGeometryActor> GeometryClass;

	UPROPERTY(EditAnyWhere)
		FGeometryData Data;

	UPROPERTY(EditAnyWhere)
		FTransform InitialTransform;

};


UCLASS()
class PJ1_SHOOTTHEMUP_API AGeometryHubActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGeometryHubActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnyWhere)
		TSubclassOf<ABaseGeometryActor> GeometryClass;

	UPROPERTY(EditAnyWhere)
		TArray<FGeometryPayload> GeometryPayloads;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	void DoActorSpawn1();
	void DoActorSpawn2();
	void DoActorSpawn3();

};

