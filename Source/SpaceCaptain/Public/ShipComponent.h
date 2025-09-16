// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "ShipData.h"

#include "ShipComponent.generated.h"




UCLASS(Blueprintable, ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class SPACECAPTAIN_API UShipComponent: public UActorComponent
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, Category = "SHIP")
	FShipData mShipData;

	UPROPERTY(EditAnywhere, Category = "SHIP")
	int Guns;

	UFUNCTION()
	void InitializeShip(const FShipData& mData);



};
