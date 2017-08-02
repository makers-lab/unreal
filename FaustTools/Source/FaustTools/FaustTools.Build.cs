using UnrealBuildTool;

public class FaustTools : ModuleRules
{
	public FaustTools(ReadOnlyTargetRules Target) : base(Target)
    {
		PublicDependencyModuleNames.AddRange(
			new string[] {
				"Core",
				"CoreUObject",
				"Engine",
				"Slate",
				"UnrealEd",
                "Networking",
                "Sockets",
                "InputCore",
                "EditorStyle",
                "RenderCore",
                "ShaderCore",
                "SlateCore",
                "LevelSequence"
            }
		);
		
		PrivateDependencyModuleNames.AddRange(
			new string[] {
				"PropertyEditor",
				"LevelEditor",
                "MovieScene",
                "MovieSceneTracks",
            }
		);

        PublicIncludePaths.AddRange(
               new string[] {
                    "FaustTools/Public",
                    "Editor/UnrealEd/Public/UnrealEd",
                    "Developer/AssetTools/Public",
                    "Editor/UnrealEd/Public",
                    "Editor/UnrealEd/Classes",
                    "FaustTools/Private",
                    "FaustTools/Public",
                    

                   // ... add public include paths required here ...
               }
               );

        PrivateIncludePaths.AddRange(
                new string[] {
                    "FaustTools/Private",
                    "Editor/UnrealEd/Public/UnrealEd",
                    "Editor/UnrealEd/Public",
                    "Editor/UnrealEd/Classes",
                    "Editor/UnrealEd/Private"
					// ... add other private include paths required here ...
				}
                );
    }
}