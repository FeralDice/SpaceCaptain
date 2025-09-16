
#include "GameManager.h"
#include "ShipComponent.h"


void UGameManager::Initialize(FSubsystemCollectionBase& Collection)
{
	
	Super::Initialize (Collection);
	Settings = GetDefault<UGameSettings>();


	SpawnShip(SHIP_MODEL::MINOTAUR, FVector(0, 0, 0), FRotator());
}

void UGameManager::SpawnShip(SHIP_MODEL ShipName,FVector Pos,FRotator mRot)
{


	UClass* mBP = Settings->ShipBlueprints.Find(ShipName)->Get();

	AActor * mShip = GetWorld()->SpawnActor(mBP->GetClass());
	if (mShip!=nullptr)
	{
		UShipComponent* mShipComponent = mShip->GetComponentByClass<UShipComponent>();

		FShipData* mShipData = Settings->MainShipDatabase->FindRow<FShipData>(FName(*UEnum::GetValueAsString(ShipName)), "");
		mShipComponent->InitializeShip(*mShipData);

		//mShip->AddComponentByClass(UShipComponent::StaticClass(),true,mShip->GetOwner()->GetTransform(), false);
		//UShipComponent* mShipComponent = Cast<UShipComponent>( mShip->AddComponentByClass(UShipComponent::StaticClass(), true, mShip->GetOwner()->GetTransform(), false)); 
		//mShipComponent->RegisterComponent();
	}
	
}

