// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameEnums.h"
#include "GameStructs.h"

inline FName GetShipModelAsFName(ESHIP_MODEL EnumValue)
{
	switch (EnumValue)
	{
	case ESHIP_MODEL::UNKOWN:
		return FName("UNKOWN");
      
	case ESHIP_MODEL::MINOTAUR:
		return FName("MINOTAUR");
      
	case ESHIP_MODEL::AEGIR:
		return FName("AEGIR");
      
	default:
		return FName("UNKNOWN");
   
	}
}


inline FName GetWeaponModelAsFName(EWEAPON_MODEL EnumValue)
{
	switch (EnumValue)
	{
	case EWEAPON_MODEL::EMPTY:
		return FName("EMPTY");
      
	case EWEAPON_MODEL::BLASTER_MKI:
		return FName("BLASTER_MKI");
      
	case EWEAPON_MODEL::BLASTER_MKII:
		return FName("BLASTER_MKII");
      
	default:
		return FName("UNKNOWN");
   
	}
}


inline FName GetGeneratorModelAsFName(EGENERATOR_MODEL EnumValue)
{
	switch (EnumValue)
	{
	case EGENERATOR_MODEL::EMPTY:
		return FName("EMPTY");
      
	case EGENERATOR_MODEL::PULSAR_MKI:
		return FName("PULSAR_MKI");
      
	case EGENERATOR_MODEL::PULSAR_MKII:
		return FName("PULSAR_MKII");
      
	default:
		return FName("UNKNOWN");
   
	}
}



