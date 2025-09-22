

#pragma once

#include "CoreMinimal.h"
#include "ShipData.h"
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

		void Initialize(FSubsystemCollectionBase& Collection) override;

		
		void InitializeInputSystem();
	
		void SpawnShip(SHIP_MODEL ShipName, FVector Pos, FRotator mRot);




};
