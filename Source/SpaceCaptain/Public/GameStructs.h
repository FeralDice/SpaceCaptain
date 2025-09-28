// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameEnums.h"
#include "GameStructs.generated.h"


USTRUCT(BlueprintType)
struct SPACECAPTAIN_API FEquipmentData : public FTableRowBase
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, Category = "EQUIPMENT DATA")
	FString Name;
	UPROPERTY(EditAnywhere, Category = "EQUIPMENT DATA")
	int Size;
	UPROPERTY(EditAnywhere, Category = "EQUIPMENT DATA")
	EQUIPMENT_TYPE EquipmentType;
	UPROPERTY(EditAnywhere, Category = "EQUIPMENT DATA")
	int STRUCTURE;

	TSoftObjectPtr<AActor> Blueprint;


};

USTRUCT(BlueprintType)
struct SPACECAPTAIN_API FWeaponData : public FEquipmentData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category = "WEAPON DATA")
	WEAPON_MODEL Model;
	
	UPROPERTY(EditAnywhere, Category = "WEAPON DATA")
	int DAMAGE;
	UPROPERTY(EditAnywhere, Category = "WEAPON DATA")
	int VELOCITY;
	UPROPERTY(EditAnywhere, Category = "WEAPON DATA")
	int AOD;

	


};
USTRUCT(BlueprintType)
struct SPACECAPTAIN_API FGeneratorData : public FEquipmentData
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, Category = "GENERATOR DATA")
	GENERATOR_MODEL Model;
	
	UPROPERTY(EditAnywhere, Category = "GENERATOR DATA")
	int OUTPUT;
};





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
	TMap<int,FEquipmentData> ShipLoadout;

};

