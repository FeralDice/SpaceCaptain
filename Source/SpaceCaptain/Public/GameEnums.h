// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"


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



