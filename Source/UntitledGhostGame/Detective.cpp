// Fill out your copyright notice in the Description page of Project Settings.


#include "Detective.h"
#include "EnhancedInputComponent.h"
#include "InputMappingContext.h"
#include "EnhancedInputSubsystems.h"


// Sets default values
ADetective::ADetective()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void ADetective::BeginPlay()
{
	Super::BeginPlay();
	if (ULocalPlayer* localPlayer = GetWorld()->GetFirstLocalPlayerFromController()) {
		if (UEnhancedInputLocalPlayerSubsystem* InputSystem = localPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>()) {
			if (IMC_Default) {
				InputSystem->AddMappingContext(IMC_Default.LoadSynchronous(), 0);
			}
		}
	}

}

// Called every frame
void ADetective::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ADetective::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	UEnhancedInputComponent* Input = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	if (Input) {
		Input->BindAction(IA_Move, ETriggerEvent::Triggered, this, &ADetective::Move);
		Input->BindAction(IA_Look, ETriggerEvent::Triggered, this, &ADetective::Look);
	}

}

void ADetective::Move(const struct FInputActionInstance& Instance) {
	FVector2D movementVector = Instance.GetValue().Get<FVector2D>();
	AddMovementInput(GetActorForwardVector(), movementVector.X);
	AddMovementInput(GetActorRightVector(), movementVector.Y);
}

void ADetective::Look(const struct FInputActionInstance& Instance) {
	FVector2D lookVector = Instance.GetValue().Get<FVector2D>();
	AddControllerPitchInput(lookVector.Y);
	AddControllerYawInput(lookVector.X);
}
