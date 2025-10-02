
#include "GameModeSinglePlayer.h"

#include "GameManager.h"


void AGameModeSinglePlayer::StartPlay()
{
	Super::StartPlay();
	mManager = GetGameInstance()->GetSubsystem<UGameManager>();

	if (mManager!=nullptr)
	{
		FShipLoadout mloadout = *mManager -> GetShipLoadout(FName("MINOTAUR_DEFAULT"));
		mManager->SpawnShip(mloadout, FVector(0, 0, 0), FRotator());
	}

	
}
