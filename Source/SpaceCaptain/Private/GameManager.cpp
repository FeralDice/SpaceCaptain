
#include "GameManager.h"

#include "GamePlayerController.h"
#include "ShipComponent.h"
#include "UObject/Class.h"
#include "GameTools.h"

void UGameManager::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize (Collection);
	
	Settings = GetDefault<UGameSettings>();
	Settings->ShipLoadoutDataTable.LoadSynchronous();
	Settings->ShipDataTable.LoadSynchronous();
	Settings->WeaponDataTable.LoadSynchronous();
	Settings->GeneratorDataTable.LoadSynchronous();

	UE_LOG(LogTemp, Warning, TEXT("Loaded database"));
}


const FShipData* UGameManager::GetShipData(ESHIP_MODEL Model)
{
	FName ShipModelName = GetShipModelAsFName(Model);
	return Settings->ShipDataTable->FindRow<FShipData>(ShipModelName,"",false);
}

const FShipLoadout* UGameManager::GetShipLoadout(FName LoadoutName)
{
	
	return Settings->ShipLoadoutDataTable->FindRow<FShipLoadout>(LoadoutName, "", false);
}

const FWeaponData* UGameManager::GetWeaponData(EWEAPON_MODEL Model)
{
	FName WeaponModelName = GetWeaponModelAsFName(Model);
	return Settings->WeaponDataTable->FindRow<FWeaponData>(WeaponModelName,"",false);
}


void UGameManager::SpawnShip(FShipLoadout loadout,FVector Pos,FRotator mRot)
{
	UClass * mActorClass = Settings->ShipBlueprints.Find(loadout.ShipModel)->Get();

	if (mActorClass != nullptr)
	{
		AActor* mShip = GetWorld()->SpawnActor(mActorClass);

		if (mShip != nullptr)
		{
		
			UShipComponent* mShipComponent = mShip->GetComponentByClass<UShipComponent>();
			mShipComponent->InitializeShip(loadout);
		
		}
	}

	
}

