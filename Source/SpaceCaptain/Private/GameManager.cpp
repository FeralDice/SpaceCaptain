
#include "GameManager.h"

#include "GamePlayerController.h"
#include "ShipComponent.h"
#include "UObject/Class.h"

void UGameManager::Initialize(FSubsystemCollectionBase& Collection)
{
	
	Super::Initialize (Collection);

	//Settings = Collection.InitializeDependency<UGameSettings>();
	Settings = GetDefault<UGameSettings>();

	
	SpawnShip(SHIP_MODEL::MINOTAUR, FVector(0, 0, 0), FRotator());
}



void UGameManager::SpawnShip(SHIP_MODEL ShipName,FVector Pos,FRotator mRot)
{
	

	UClass * mActorClass = Settings->ShipBlueprints.Find(SHIP_MODEL::MINOTAUR)->Get();

	if (mActorClass != nullptr)
	{
		AActor* mShip = GetWorld()->SpawnActor(mActorClass);

		if (mShip != nullptr)
		{
			const FShipData* mShipData = Settings->ShipData.Find(SHIP_MODEL::MINOTAUR);
			UShipComponent* mShipComponent = mShip->GetComponentByClass<UShipComponent>();
			mShipComponent->InitializeShip(*mShipData);
		
		}
	}

	
}

