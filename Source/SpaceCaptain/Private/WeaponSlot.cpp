

#include "WeaponSlot.h"
#include "GameSettings.h"

void UWeaponSlot::InitializeSlot(const FWeaponData& mData)
{
	SlotData = mData;
	STRUCTURE = mData.STRUCTURE;
	
}
