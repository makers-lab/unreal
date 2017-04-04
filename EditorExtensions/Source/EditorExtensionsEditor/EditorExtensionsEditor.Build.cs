using UnrealBuildTool;

public class EditorExtensionsEditor : ModuleRules
{
	public EditorExtensionsEditor(TargetInfo Target)
	{
		PublicDependencyModuleNames.AddRange(
			new string[] {
				"Core",
				"CoreUObject",
				"Engine",
				"Slate",
				"UnrealEd"
			}
		);
		
		PrivateDependencyModuleNames.AddRange(
			new string[] {
				"InputCore",
				"SlateCore",
				"PropertyEditor",
				"LevelEditor"
			}
		);

        PublicIncludePaths.AddRange(
               new string[] {
                    "Editor/UnrealEd/Public/UnrealEd",
                    "Developer/AssetTools/Public",
                    "Editor/UnrealEd/Public",
                    "Editor/UnrealEd/Classes",
                   // ... add public include paths required here ...
               }
               );

        PrivateIncludePaths.AddRange(
                new string[] {
                    "Editor/UnrealEd/Public/UnrealEd",
                    "Developer/MVEditor/Private",
                    "Editor/UnrealEd/Public",
                    "Editor/UnrealEd/Classes",
                        "Editor/UnrealEd/Private"
					// ... add other private include paths required here ...
				}
                );

        PublicDependencyModuleNames.AddRange(new string[] {
            "Core",
            "CoreUObject",
            "InputCore",
            "EditorStyle",
            "Engine",
            "UnrealEd",
            "Slate",
            "RenderCore",
            "ShaderCore",
            "SlateCore"
        });
    }
}