// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

UENUM(BlueprintType)
enum class EQUIPMENT_TYPE : uint8
{
    GENERATOR = 0 ,
    ENGINE = 1  ,
    WEAPON = 2  ,
    LIFESYSTEM = 3  ,
    RADAR = 4  ,
    JAMMER = 5  ,
    
};
UENUM(BlueprintType)
enum class ESHIP_MODEL : uint8
{
    UNKOWN = 0 ,
    MINOTAUR = 10 ,
    AEGIR = 20  ,
};

UENUM(BlueprintType)
enum class EWEAPON_MODEL : uint8
{
    EMPTY = 0 ,
    BLASTER_MKI = 10 ,
    BLASTER_MKII = 11 ,
};




UENUM(BlueprintType)
enum class EGENERATOR_MODEL : uint8
{
    EMPTY = 0,
    PULSAR_MKI = 10,
    PULSAR_MKII = 11,
    
};

