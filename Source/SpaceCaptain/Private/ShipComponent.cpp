

#include "ShipComponent.h"

#include "GameTools.h"

void UShipComponent::InitializeShip(const FShipLoadout& mData)
{
	ShipLoadOut = mData;

	GameManager = GetWorld()->GetGameInstance()->GetSubsystem<UGameManager>();
	const FShipData * ShipData = GameManager->GetShipData(ShipLoadOut.ShipModel);
	CurrentStructure = ShipData->STRUCTURE;
	
	
	GetOwner()->GetComponents(GeneratorSlots, true);
/*
	for ( UGeneratorSlot* slot : GeneratorSlots)
	{
		int index = slot->SlotNumber;
		const FGeneratorData* mdata = mSettings->GeneratorData.Find(mData.Generators[index]);
		if (mdata != nullptr)
		{
			slot->InitializeSlot(*mdata);
		}
	}
*/
	

	GetOwner()->GetComponents(WeaponSlots, true);
	for ( UWeaponSlot* slot : WeaponSlots)
	{
		EWEAPON_MODEL WeaponModel = ShipLoadOut.Weapons[slot->SlotNumber] ;
		const FWeaponData* WeaponData =GameManager->GetWeaponData(WeaponModel);
		if (WeaponData!=nullptr)
		{
			slot->InitializeSlot(*WeaponData);
		}
	}
	
}
