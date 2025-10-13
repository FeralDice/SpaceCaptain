

#pragma once

#include "CoreMinimal.h"
#include "InputAction.h"
#include "Camera/CameraComponent.h"

#include "PlayerManager.generated.h"




UCLASS(Blueprintable)
class SPACECAPTAIN_API APlayerManager : public APawn
{
	GENERATED_BODY()

	public:

	UPROPERTY(VisibleAnywhere, Category = "Manager")
	float LastDeltaTime =0;

	UPROPERTY(EditAnywhere, Category = "Manager")
	float KeyResponseSpeed = 3;

	UPROPERTY(VisibleAnywhere, Category = "Manager")
	bool CameraZoomInput = false;

	UPROPERTY(VisibleAnywhere, Category = "Manager")
	bool CameraRotateInput = false;

	UPROPERTY(EditAnywhere, Category = "Manager")
	float KeyDeadZone = 0.1;
	
	UPROPERTY(EditAnywhere, Category = "Manager")
	float CameraTargetZoom;

	UPROPERTY(EditAnywhere, Category = "Manager")
	float CameraZoomSpeed = 6.0;

	UPROPERTY(EditAnywhere, Category = "Manager")
	FVector2f ZoomBorders;

	UPROPERTY(EditAnywhere, Category = "Manager")
	float CameraTargetAngle;

	UPROPERTY(EditAnywhere, Category = "Manager")
	float CameraRotateSpeed = 0.1;


	UPROPERTY(Config, EditAnywhere)
	TSoftObjectPtr< UCurveFloat> CameraDampingCurve;



	UPROPERTY(BlueprintReadWrite, EditAnywhere,  Category = "Manager")
	USceneComponent* CameraGimbal;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Manager")
	USceneComponent* CameraGimbalZoom;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Manager")
	USceneComponent* CameraGimbalHeight;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Manager")
	UCameraComponent* CameraComponent;

	UPROPERTY(VisibleAnywhere, Category = "Manager")
	AActor * CurrentShip;
	
	APlayerManager();

	virtual void BeginPlay() override;


	virtual void Tick(float Deltaseconds)override;

	void BindInputs();

	void SetCurrentShip(AActor* Ship);

	void ResetCameraView();

	void IncreaseCameraTargetZoom(const FInputActionInstance& mAction);
	void DecreaseCameraTargetZoom(const FInputActionInstance& mAction);

	void SetCameraTargetZoom(const FInputActionInstance& mAction);
	void IncreaseCameraTargetAngle(const FInputActionInstance& mAction);
	void DecreaseCameraTargetAngle(const FInputActionInstance& mAction);

	void UpdateCameraStatus(float deltatime);

	void UpdateShipRudder(const FInputActionInstance& mAction);

};
