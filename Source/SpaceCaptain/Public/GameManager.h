

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
	
		void SpawnShip(SHIP_MODEL ShipName, FVector Pos, FRotator mRot);




};
