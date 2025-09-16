// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "WeaponData.generated.h"




USTRUCT(BlueprintType)
struct SPACECAPTAIN_API FWeaponData : public FTableRowBase
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, Category = "WEAPON DATA")
	int DAMAGE;
	UPROPERTY(EditAnywhere, Category = "WEAPON DATA")
	int VELOCITY;
	UPROPERTY(EditAnywhere, Category = "WEAPON DATA")
	int AOD;



};
