// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameEnums.h"
#include "GameStructs.h"


#include "WeaponSlot.generated.h"




UCLASS(Blueprintable, ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class SPACECAPTAIN_API UWeaponSlot: public USceneComponent
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere,Category = "SLOT")
	int SlotNumber;

	UPROPERTY(EditAnywhere,Category = "SLOT")
	int Size;

	UPROPERTY(EditAnywhere,Category = "SLOT")
	int STRUCTURE;

	UPROPERTY(EditAnywhere,Category = "SLOT")
	FWeaponData SlotData;

	
	UFUNCTION()
	void InitializeSlot(const FWeaponData& mData);



};
