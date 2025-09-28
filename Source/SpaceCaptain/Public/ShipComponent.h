// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "GameStructs.h"


#include "ShipComponent.generated.h"




UCLASS(Blueprintable, ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class SPACECAPTAIN_API UShipComponent: public UActorComponent
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, Category = "SHIP")
	FShipData mShipData;

	UPROPERTY()
	TArray<TSoftObjectPtr< UGeneratorSlot>> GeneratorSlots;

	UPROPERTY()
	TArray<TSoftObjectPtr< UWeaponSlot>> WeaponSlots;

	UPROPERTY()
	USceneComponent* mRoot;

	UFUNCTION()
	void InitializeShip(const FShipData& mData);



};
