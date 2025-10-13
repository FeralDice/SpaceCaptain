

#include "GamePlayerController.h"
#include "GameModeSinglePlayer.h"
#include "GameSettings.h"



void AGamePlayerController::InitInputSystem()
{
	Super::InitInputSystem();
	
}

void AGamePlayerController::BeginPlay()
{
	Super::BeginPlay();

	InitializeInputMappings();

	//OnPossessedPawnChanged.Add(&AGamePlayerController::InitializePlayer());

	
}

void AGamePlayerController::BeginPlayingState()
{
	Super::BeginPlayingState();

	InitializePlayer();
}

void AGamePlayerController::InitializeInputMappings()
{


	const UGameSettings * mSettings =   GetDefault<UGameSettings>();
	mSettings->MappingContext.LoadSynchronous();
	mSettings->IA_FORWARD.LoadSynchronous();
	mSettings->IA_BACKWARDS.LoadSynchronous();
	mSettings->IA_RIGHT.LoadSynchronous();
	mSettings->IA_LEFT.LoadSynchronous();

	if (UEnhancedInputLocalPlayerSubsystem* InputSystem = GetLocalPlayer()->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
	{
		InputSystem->AddMappingContext(mSettings->MappingContext.Get(),0);
	}
	UEnhancedInputComponent *mCOmp = Cast<UEnhancedInputComponent>(InputComponent);

	if (mCOmp!=nullptr)
	{
		mCOmp->BindAction(mSettings->IA_FORWARD.Get(), ETriggerEvent::Triggered, this, &AGamePlayerController::OnActionForward);
		mCOmp->BindAction(mSettings->IA_BACKWARDS.Get(), ETriggerEvent::Triggered, this, &AGamePlayerController::OnActionBackward);
		mCOmp->BindAction(mSettings->IA_RIGHT.Get(), ETriggerEvent::Triggered, this, &AGamePlayerController::OnActionRight);
		mCOmp->BindAction(mSettings->IA_LEFT.Get(), ETriggerEvent::Triggered, this, &AGamePlayerController::OnActionLeft);
	}

}

void AGamePlayerController::InitializePlayer()
{
	mManager = GetGameInstance()->GetSubsystem<UGameManager>();
	if (mManager != nullptr)
	{
		FShipLoadout mloadout = *mManager->GetShipLoadout(FName("MINOTAUR_DEFAULT"));
		AActor* mShip = mManager->SpawnShip(mloadout, FVector(0, 0, 0), FRotator());

		if (mShip != nullptr)
		{
			PlayerPawn = Cast<APlayerManager>(GetPawn());
			PlayerPawn->SetCurrentShip(mShip);

		}
	}


}



void AGamePlayerController::OnActionForward(const FInputActionInstance& mAction)
{
	mOnActionForward_DELEGATE.Broadcast(mAction);
}

void AGamePlayerController::OnActionBackward(const FInputActionInstance& mAction)
{
	mOnActionBackwards_DELEGATE.Broadcast(mAction);
}

void AGamePlayerController::OnActionRight(const FInputActionInstance& mAction)
{
	mOnActionRight_DELEGATE.Broadcast(mAction);
}

void AGamePlayerController::OnActionLeft(const FInputActionInstance& mAction)
{
	mOnActionLeft_DELEGATE.Broadcast(mAction);
}
