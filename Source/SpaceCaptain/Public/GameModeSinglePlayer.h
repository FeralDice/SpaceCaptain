

#pragma once

#include "CoreMinimal.h"
#include "GameManager.h"


#include "GameFramework/GameMode.h"

#include "GameModeSinglePlayer.generated.h"

UCLASS()
class SPACECAPTAIN_API AGameModeSinglePlayer : public AGameMode
{
	GENERATED_BODY()


public :


	UPROPERTY()
	UGameManager * mManager;
	
	virtual void StartPlay() override;

};
