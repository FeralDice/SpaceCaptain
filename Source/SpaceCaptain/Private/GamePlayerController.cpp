

#include "GamePlayerController.h"
#include "GameSettings.h"



void AGamePlayerController::InitInputSystem()
{
	Super::InitInputSystem();
	
}

void AGamePlayerController::BeginPlay()
{
	Super::BeginPlay();

	InitializeInputMappings();
	
}

void AGamePlayerController::InitializeInputMappings()
{


	const UGameSettings * mSettings =   GetDefault<UGameSettings>();
	if (UEnhancedInputLocalPlayerSubsystem* InputSystem = GetLocalPlayer()->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
	{
		InputSystem->AddMappingContext(mSettings->mMappingContext.Get(),0);
	}
	UEnhancedInputComponent *mCOmp = Cast<UEnhancedInputComponent>(InputComponent);
	const UInputAction* mAction =mSettings->IA_FORWARD.Get();
	
	mCOmp->BindAction(mAction, ETriggerEvent::Triggered, this, &AGamePlayerController::OnActionRequest);
}


void AGamePlayerController::OnActionRequest(const FInputActionInstance& mAction)
{
	//TODO : one action per action ;)
	UE_LOG(LogTemp, Display, TEXT("OnActionRequest"));

	mOnActionForward_DELEGATE.Broadcast(mAction);
}
