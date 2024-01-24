// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Detective.generated.h"

UCLASS()
class UNTITLEDGHOSTGAME_API ADetective : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ADetective();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere, Category = "Input")
	class UInputAction* IA_Move;

	UPROPERTY(EditAnywhere, Category = "Input")
	class UInputAction* IA_Look;

	UPROPERTY(EditAnywhere, Category = "Input")
	TSoftObjectPtr<class UInputMappingContext> IMC_Default;

	UFUNCTION()
	void Move(const struct FInputActionInstance& Instance);

	UFUNCTION()
	void Look(const struct FInputActionInstance& Instance);


	
};
