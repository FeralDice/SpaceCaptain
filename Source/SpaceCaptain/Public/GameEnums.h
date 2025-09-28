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
enum class SHIP_MODEL : uint8
{
    MINOTAUR = 0 ,
    AEGIR = 1  ,
};

UENUM(BlueprintType)
enum class WEAPON_MODEL : uint8
{
    EMPTY = 0,
    BLASTER_MKI = 1 ,
    BLASTER_MKII = 2  ,
};

UENUM(BlueprintType)
enum class GENERATOR_MODEL : uint8
{
    PULSAR = 0,
    GAMATE = 100 ,
    OREUS = 200  ,
    
};

