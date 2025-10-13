

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


//SHIPS
	UPROPERTY(Config, EditAnywhere)
	TMap < ESHIP_MODEL , TSubclassOf<AActor> > ShipBlueprints;
	


	UPROPERTY(Config, EditAnywhere)
	TSoftObjectPtr <UDataTable>  ShipDataTable;

	UPROPERTY(Config, EditAnywhere)
	TSoftObjectPtr <UDataTable>  ShipLoadoutDataTable;

	UPROPERTY(Config, EditAnywhere)
	TSoftObjectPtr <UDataTable>  WeaponDataTable;

	UPROPERTY(Config, EditAnywhere)
	TSoftObjectPtr <UDataTable>  GeneratorDataTable;



//INPUT
	UPROPERTY(Config, EditAnywhere)
	TSoftObjectPtr< UInputMappingContext> MappingContext;

	UPROPERTY(Config, EditAnywhere)
	TSoftObjectPtr< UCurveFloat> CameraDampingCurve;

	UPROPERTY(Config, EditAnywhere)
	const TSoftObjectPtr< UInputAction> IA_FORWARD;

	UPROPERTY(Config, EditAnywhere)
	const TSoftObjectPtr< UInputAction> IA_BACKWARDS;

	UPROPERTY(Config, EditAnywhere)
	const TSoftObjectPtr< UInputAction> IA_LEFT;

	UPROPERTY(Config, EditAnywhere)
	const TSoftObjectPtr< UInputAction> IA_RIGHT;

};
