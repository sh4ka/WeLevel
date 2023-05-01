// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class WeLevel : ModuleRules
{
	public WeLevel(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {"Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "EnhancedInput", "GameplayAbilities", "GameplayTasks", "GameplayTags" });
	}
}
