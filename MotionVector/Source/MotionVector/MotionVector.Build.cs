// Some copyright should be here...

using UnrealBuildTool;

public class MotionVector : ModuleRules
{
	public MotionVector(TargetInfo Target)
	{
		
		PublicIncludePaths.AddRange(
			new string[] {
				"MotionVector/Public",
            }
			);
				
		
		PrivateIncludePaths.AddRange(
			new string[] {
				"MotionVector/Private",
            }
			);
			
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
            }
			);
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
                "Core",
                "CoreUObject",
                "Engine",
                "UnrealEd",
                "SlateCore",
                "Slate",
                "Renderer",
                "RHI",
                "RenderCore"
            }
			);
		
		
		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
			}
			);
	}
}
