// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "WeaponData.h"
#include "ShipData.generated.h"

USTRUCT(BlueprintType)
struct SPACECAPTAIN_API FShipData : public FTableRowBase
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, Category = "SHIP DATA")
	int HIT_POINTS;	
	UPROPERTY(EditAnywhere, Category = "SHIP DATA")
	int ARMOR;
	UPROPERTY(EditAnywhere, Category = "SHIP DATA")
	int SPEED;

	UPROPERTY(EditAnywhere, Category = "SHIP DATA")
	TMap<int, FWeaponData> mWeapons;



};



