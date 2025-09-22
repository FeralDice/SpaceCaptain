

#pragma once

#include "CoreMinimal.h"

#include "PlayerManager.generated.h"




UCLASS(Blueprintable)
class SPACECAPTAIN_API APlayerManager : public APawn
{
	GENERATED_BODY()

	public:

	virtual void BeginPlay() override;


};
