// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameEnums.h"
#include "GameStructs.h"


#include "WeaponComponent.generated.h"




UCLASS(Blueprintable, ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class SPACECAPTAIN_API UWeaponComponent: public USceneComponent
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere,Category = "SHIP")
	int SlotNumber;
	
	UPROPERTY(EditAnywhere, Category = "SHIP")
	WEAPON_MODEL mWeaponModel;


	UPROPERTY(EditAnywhere, Category = "SHIP")
	FWeaponData mWeaponData;

	UFUNCTION()
	void InitializeWeapon(const FWeaponData& mData);



};
