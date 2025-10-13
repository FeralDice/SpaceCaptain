// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "InputAction.h"
#include "EnhancedInput/Public/InputMappingContext.h"
#include "EnhancedInputComponent.h"
#include "GameManager.h"
#include "PlayerManager.h"



#include "GamePlayerController.generated.h"


DECLARE_MULTICAST_DELEGATE_OneParam(On_Action_Forward,const FInputActionInstance& );
DECLARE_MULTICAST_DELEGATE_OneParam(On_Action_Backwards, const FInputActionInstance&);
DECLARE_MULTICAST_DELEGATE_OneParam(On_Action_Right, const FInputActionInstance&);
DECLARE_MULTICAST_DELEGATE_OneParam(On_Action_Left, const FInputActionInstance&);

UCLASS(BlueprintType)
class SPACECAPTAIN_API AGamePlayerController : public APlayerController
{
	GENERATED_BODY()

public:

	UPROPERTY()
	UGameManager* mManager;

	UPROPERTY()
	APlayerManager* PlayerPawn;

	On_Action_Forward mOnActionForward_DELEGATE;
	On_Action_Backwards mOnActionBackwards_DELEGATE;
	On_Action_Right mOnActionRight_DELEGATE;
	On_Action_Left mOnActionLeft_DELEGATE;


	void InitInputSystem()override;
	void BeginPlay() override;
	void BeginPlayingState() override;


	void InitializeInputMappings();
	void InitializePlayer();

	

	void OnActionForward(const FInputActionInstance& mAction);
	void OnActionBackward(const FInputActionInstance& mAction);
	void OnActionRight(const FInputActionInstance& mAction);
	void OnActionLeft(const FInputActionInstance& mAction);
};
