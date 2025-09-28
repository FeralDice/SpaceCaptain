// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameEnums.h"
#include "GameStructs.h"


#include "GeneratorSlot.generated.h"




UCLASS(Blueprintable, ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class SPACECAPTAIN_API UGeneratorSlot: public USceneComponent
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere,Category = "SLOT")
	int SlotNumber;
	
	
	UPROPERTY(EditAnywhere,Category = "SLOT")
	int Size;

	UPROPERTY(EditAnywhere,Category = "SLOT")
	int STRUCTURE;

	TSoftObjectPtr<FGeneratorData> SlotData;
	
	UFUNCTION()
	void InitializeSlot(const FGeneratorData& mData);



};
