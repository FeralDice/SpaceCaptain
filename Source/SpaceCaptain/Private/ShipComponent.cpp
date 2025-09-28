

#include "ShipComponent.h"

#include "EquipmentSlotComponent.h"
#include "GameSettings.h"

void UShipComponent::InitializeShip(const FShipData& mData)
{
	mShipData = mData;

	const UGameSettings* mSettings = GetDefault<UGameSettings>();
	
	GetOwner()->GetComponents(EquipmentSlots, true);
	for (int i = 0; i < EquipmentSlots.Num(); i++)
	{
		
		FEquipmentData mdata;
		//EquipmentSlots[i]->InitializeComponent(mdata);
	
	}
	/*
	GetOwner()->GetComponents(mWeaponSlots, true);
	
	for (int i = 0; i < mWeaponSlots.Num(); i++)
	{
		const FWeaponData* mweapondata = mSettings->WeaponData.Find(mWeaponSlots[i]->mWeaponModel);
		if (mweapondata!=nullptr)
		{
			mWeaponSlots[i]->InitializeWeapon(*mweapondata);
		}
	
	}
	*/
	
}
