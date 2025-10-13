

#pragma once

#include "CoreMinimal.h"
#include "GameStructs.h"
#include "GameSettings.h"


#include "Subsystems/SubsystemCollection.h"


#include "GameManager.generated.h"




UCLASS()
class SPACECAPTAIN_API UGameManager : public UGameInstanceSubsystem
{
	GENERATED_BODY()

	public:

	UPROPERTY()
	const UGameSettings* Settings;

	

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;


	const FShipData* GetShipData(ESHIP_MODEL Model);
	const FShipLoadout* GetShipLoadout(FName LoadoutName);
	const FWeaponData* GetWeaponData(EWEAPON_MODEL Model);
	
	AActor* SpawnShip(FShipLoadout ShipLoadout, FVector Pos, FRotator mRot);




};
