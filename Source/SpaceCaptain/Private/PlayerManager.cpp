

#include "PlayerManager.h"

#include "GamePlayerController.h"

void APlayerManager::BeginPlay()
{
	Super::BeginPlay();
	BindInputs();
	
}

void APlayerManager::BindInputs()
{
	AGamePlayerController * mCtrlr = Cast<AGamePlayerController>( GetWorld()->GetFirstPlayerController());
	if (mCtrlr !=nullptr)
	{
		mCtrlr->mOnActionForward_DELEGATE.AddUObject(this,&APlayerManager::UpdateShipRudder);
	}
}

void APlayerManager::UpdateShipRudder(const FInputActionInstance& mAction)
{
	UE_LOG(LogTemp, Display, TEXT("Received Action from playerpawn"));
}
