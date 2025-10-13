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
	int Size;

	UPROPERTY(EditAnywhere, Category = "EQUIPMENT DATA")
	int STRUCTURE;

	
};

USTRUCT(BlueprintType)
struct SPACECAPTAIN_API FWeaponData : public FEquipmentData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category = "WEAPON DATA")
	EWEAPON_MODEL Model;
	
	UPROPERTY(EditAnywhere, Category = "WEAPON DATA")
	int DAMAGE;
	UPROPERTY(EditAnywhere, Category = "WEAPON DATA")
	int VELOCITY;
	UPROPERTY(EditAnywhere, Category = "WEAPON DATA")
	int AOD;

	TSoftObjectPtr<TSubclassOf<AActor>> TurretBlueprint;
	


};
USTRUCT(BlueprintType)
struct SPACECAPTAIN_API FGeneratorData : public FEquipmentData
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, Category = "GENERATOR DATA")
	EGENERATOR_MODEL Model;
	
	UPROPERTY(EditAnywhere, Category = "GENERATOR DATA")
	int OUTPUT;
};





USTRUCT(BlueprintType)
struct SPACECAPTAIN_API FShipData : public FTableRowBase
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, Category = "SHIP DATA")
	int STRUCTURE;	

	UPROPERTY(EditAnywhere, Category = "SHIP DATA")
	int ARMOR;

	UPROPERTY(EditAnywhere, Category = "SHIP DATA")
	int SPEED;

	
};



USTRUCT(BlueprintType)
struct SPACECAPTAIN_API FShipLoadout : public FTableRowBase
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, Category = "SHIP Loadout")
	ESHIP_MODEL ShipModel;	
	

	UPROPERTY(EditAnywhere, Category = "SHIP Loadout")
	TMap<int,EGENERATOR_MODEL> Generators;

	UPROPERTY(EditAnywhere, Category = "SHIP Loadout")
	TMap<int,EWEAPON_MODEL> Weapons;
};