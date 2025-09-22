// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "InputAction.h"
#include "EnhancedInput/Public/InputMappingContext.h"
#include "EnhancedInputComponent.h"

#include "GamePlayerController.generated.h"


DECLARE_MULTICAST_DELEGATE_OneParam(On_Action_Forward,const FInputActionInstance& );

UCLASS(BlueprintType)
class SPACECAPTAIN_API AGamePlayerController : public APlayerController
{
	GENERATED_BODY()

public:

	On_Action_Forward mOnActionForward_DELEGATE;



	void InitInputSystem()override;
	void BeginPlay() override;

	void InitializeInputMappings();

	void OnActionRequest(const FInputActionInstance& mAction);
	
};
