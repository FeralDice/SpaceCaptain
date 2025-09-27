

#pragma once

#include "CoreMinimal.h"

#include "Engine/DeveloperSettings.h"
#include "GameStructs.h"
#include "GameEnums.h"

#include "EnhancedInput/Public/EnhancedInputSubsystems.h"
#include "GameSettings.generated.h"




UCLASS(config = Game, DefaultConfig)
class SPACECAPTAIN_API UGameSettings : public UDeveloperSettings
{
	GENERATED_BODY()

public:

	UGameSettings(const FObjectInitializer& ObjectInitializer);



	UPROPERTY(Config, EditAnywhere)
	TMap < SHIP_MODEL , TSubclassOf<AActor> > ShipBlueprints;
	

	UPROPERTY(Config, EditAnywhere)
	TMap < SHIP_MODEL, FShipData > ShipData;

	UPROPERTY(Config, EditAnywhere)
	TMap < WEAPON_MODEL, FWeaponData > WeaponData;

	UPROPERTY(Config, EditAnywhere)
	TSoftObjectPtr< UInputMappingContext> mMappingContext;

	
	UPROPERTY(Config, EditAnywhere)
	const TSoftObjectPtr< UInputAction> IA_FORWARD;




};
