

#pragma once

#include "CoreMinimal.h"

#include "Engine/DeveloperSettings.h"
#include "ShipData.h"
#include "GameEnums.h"

#include "GameSettings.generated.h"




UCLASS(config = Game, DefaultConfig)
class SPACECAPTAIN_API UGameSettings : public UDeveloperSettings
{
	GENERATED_BODY()

public:
	UGameSettings(const FObjectInitializer& ObjectInitializer);

	UPROPERTY(Config, EditAnywhere)
	TSoftObjectPtr<UDataTable> MainShipDatabase;

	UPROPERTY(Config, EditAnywhere)
	TMap < SHIP_MODEL , TSoftClassPtr<AActor> > ShipBlueprints;
	
};
