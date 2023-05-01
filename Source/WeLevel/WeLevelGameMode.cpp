// Copyright Epic Games, Inc. All Rights Reserved.

#include "WeLevelGameMode.h"
#include "WeLevelCharacter.h"
#include "UObject/ConstructorHelpers.h"

AWeLevelGameMode::AWeLevelGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
