

#include "PlayerManager.h"

#include "GamePlayerController.h"

APlayerManager::APlayerManager()
{

	CameraGimbal =  CreateDefaultSubobject<USceneComponent>(FName("CameraGimbal"));
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(FName("CameraComponent"));

	CameraGimbalZoom = CreateDefaultSubobject<USceneComponent>(FName("CameraGimbalZoom"));
	CameraGimbalHeight = CreateDefaultSubobject<USceneComponent>(FName("CameraGimbalHeight"));

	CameraGimbal->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	CameraGimbalZoom->AttachToComponent(CameraGimbal, FAttachmentTransformRules::KeepRelativeTransform);
	CameraGimbalHeight->AttachToComponent(CameraGimbalZoom, FAttachmentTransformRules::KeepRelativeTransform);

	CameraComponent->AttachToComponent(CameraGimbalHeight, FAttachmentTransformRules::KeepRelativeTransform);
}

void APlayerManager::BeginPlay()
{
	Super::BeginPlay();
	BindInputs();
	
}

void APlayerManager::Tick(float Deltaseconds)
{
	LastDeltaTime = Deltaseconds;
	UpdateCameraStatus(Deltaseconds);
}

void APlayerManager::BindInputs()
{
	AGamePlayerController * mCtrlr = Cast<AGamePlayerController>( GetWorld()->GetFirstPlayerController());
	if (mCtrlr !=nullptr)
	{
		mCtrlr->mOnActionForward_DELEGATE.AddUObject(this,&APlayerManager::IncreaseCameraTargetZoom);
		mCtrlr->mOnActionBackwards_DELEGATE.AddUObject(this, &APlayerManager::DecreaseCameraTargetZoom);

		mCtrlr->mOnActionRight_DELEGATE.AddUObject(this, &APlayerManager::IncreaseCameraTargetAngle);
		mCtrlr->mOnActionLeft_DELEGATE.AddUObject(this, &APlayerManager::DecreaseCameraTargetAngle);
	}

	const UGameSettings* mSettings = GetDefault<UGameSettings>();
	mSettings->CameraDampingCurve.LoadSynchronous();
	CameraDampingCurve = mSettings->CameraDampingCurve;
}

void APlayerManager::SetCurrentShip(AActor* Ship)
{
	CurrentShip = Ship;
	ResetCameraView();
}
void APlayerManager::ResetCameraView()
{
	CameraGimbal->SetRelativeRotation(FQuat::MakeFromEuler(FVector(0, 0, 0)));
	CameraGimbalHeight->SetRelativeLocation(FVector(0, 0,100));
	CameraGimbalZoom->SetRelativeLocation(FVector(-500, 0, 0));

//	CameraComponent->SetRelativeLocationAndRotation(FVector(-20, 0, 20),FQuat::MakeFromEuler(FVector(0,-20,0)) );
}

void APlayerManager::IncreaseCameraTargetZoom(const FInputActionInstance& mAction)
{
	CameraZoomInput = true;
	CameraTargetZoom +=   LastDeltaTime * KeyResponseSpeed;
	if (CameraTargetZoom > 1)CameraTargetZoom = 1;
	
}

void APlayerManager::DecreaseCameraTargetZoom(const FInputActionInstance& mAction)
{
	CameraZoomInput = true;
	CameraTargetZoom -=   LastDeltaTime * KeyResponseSpeed;
	if (CameraTargetZoom < -1)CameraTargetZoom = -1;
}

void APlayerManager::SetCameraTargetZoom(const FInputActionInstance& mAction)
{
	//CameraTargetZoom +=	mAction.GetValue().GetMagnitude();
}

void APlayerManager::IncreaseCameraTargetAngle(const FInputActionInstance& mAction)
{
	CameraRotateInput = true;
	CameraTargetAngle +=  LastDeltaTime * KeyResponseSpeed;
	if (CameraTargetAngle > 1)CameraTargetAngle = 1;
}

void APlayerManager::DecreaseCameraTargetAngle(const FInputActionInstance& mAction)
{
	CameraRotateInput = true;
	CameraTargetAngle -=  LastDeltaTime * KeyResponseSpeed;
	if (CameraTargetAngle < -1)CameraTargetAngle = -1;
}

void APlayerManager::UpdateCameraStatus(float deltatime)
{
		if (!CameraZoomInput)
		{
			if (CameraTargetZoom > 0)
			{
				CameraTargetZoom -=  LastDeltaTime * KeyResponseSpeed;
			}
			else
			{
				CameraTargetZoom +=  LastDeltaTime * KeyResponseSpeed;
			}
			if (abs(CameraTargetZoom) < KeyDeadZone)
			{
				CameraTargetZoom = 0;
			}
		}

		FVector NewPosition = CameraGimbalZoom->GetRelativeLocation();
		NewPosition.X += CameraTargetZoom*CameraZoomSpeed* deltatime;
		if (NewPosition.X > ZoomBorders.X)//min
		{
			NewPosition.X = ZoomBorders.X;
		}
		if (NewPosition.X < ZoomBorders.Y)//max
		{
			NewPosition.X = ZoomBorders.Y;
		}
		CameraGimbalZoom->SetRelativeLocation(NewPosition);
		CameraZoomInput = false;


		if (!CameraRotateInput)
		{
			if (CameraTargetAngle > 0)
			{
				CameraTargetAngle -= LastDeltaTime * KeyResponseSpeed;
			}
			else
			{
				CameraTargetAngle +=  LastDeltaTime * KeyResponseSpeed;
			}

			if (abs(CameraTargetAngle)< KeyDeadZone)
			{
				CameraTargetAngle = 0;
			}
		}
	

		FRotator mRotation = CameraGimbal->GetRelativeRotation();
		mRotation.Yaw += CameraTargetAngle * deltatime * CameraRotateSpeed;
		CameraGimbal->SetRelativeRotation(mRotation);
		
	
	//CameraDampingCurve->GetFloatValue(abs(CameraGimbalZoom->GetRelativeLocation().X))
		CameraGimbalHeight->SetRelativeLocation(FVector(0,0,-0.25* CameraGimbalZoom->GetRelativeLocation().X));

		FVector LookDirection = CurrentShip->GetActorLocation() - CameraComponent->GetRelativeLocation();
		CameraComponent->SetRelativeRotation(LookDirection.Rotation());
		CameraRotateInput = false;
}

void APlayerManager::UpdateShipRudder(const FInputActionInstance& mAction)
{
	UE_LOG(LogTemp, Display, TEXT("Received Action from playerpawn"));
}
