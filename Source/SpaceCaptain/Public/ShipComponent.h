// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameManager.h"

#include "GameStructs.h"

#include "GeneratorSlot.h"
#include "WeaponSlot.h"

#include "ShipComponent.generated.h"




UCLASS(Blueprintable, ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class SPACECAPTAIN_API UShipComponent: public UActorComponent
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere)
	UGameManager* GameManager;
	
	UPROPERTY(EditAnywhere, Category = "SHIP")
	FShipLoadout ShipLoadOut;

	UPROPERTY(EditAnywhere)
	TArray<UGeneratorSlot*> GeneratorSlots;

	UPROPERTY(EditAnywhere)
	TArray< UWeaponSlot*> WeaponSlots;

	UPROPERTY(EditAnywhere)
	USceneComponent* mRoot;

	UPROPERTY(EditAnywhere)
	int CurrentStructure;

	UFUNCTION()
	void InitializeShip(const FShipLoadout& mData);

	



};
