#include "FaustTools/Private/FaustToolsPrivatePCH.h"
#include "FaustToolsBaseClass.h"
#include "PropertyEditorModule.h"
#include "FaustToolsModule.h"
#include "FaustToolsCustomization.h"

#include "Editor/LevelEditor/Public/LevelEditor.h"

#include "TutorialMetaData.h"
#include "SDockTab.h"
#include "ModuleManager.h"

#define LOCTEXT_NAMESPACE "FFaustToolsEditorModule"

void FFaustToolsEditorModule::StartupModule()
{
	// Register the details customizations
	{
		FPropertyEditorModule& PropertyModule = FModuleManager::LoadModuleChecked<FPropertyEditorModule>(TEXT("PropertyEditor"));
		PropertyModule.RegisterCustomClassLayout(TEXT("FaustToolsBaseClass"), FOnGetDetailCustomizationInstance::CreateStatic(&FFaustToolsCustomization::MakeInstance));
		PropertyModule.NotifyCustomizationModuleChanged();
	}

	CommandList = MakeShareable(new FUICommandList);

	{
		FLevelEditorModule& LevelEditorModule = FModuleManager::LoadModuleChecked<FLevelEditorModule>(TEXT("LevelEditor"));

		CommandList->Append(LevelEditorModule.GetGlobalLevelEditorActions());


		struct Local
		{
			static void AddMenuCommands(FMenuBuilder& MenuBuilder)
			{
				MenuBuilder.AddSubMenu(LOCTEXT("FaustTools", "Faust Tools"),
					LOCTEXT("FaustToolsTooltip", "List of tools"),
					FNewMenuDelegate::CreateStatic(&FFaustToolsEditorModule::CreateToolListMenu)
					);
			}
		};

		TSharedRef<FExtender> MenuExtender(new FExtender());
		MenuExtender->AddMenuExtension(
			TEXT("LevelEditor"),
			EExtensionHook::After,
			CommandList.ToSharedRef(),
			FMenuExtensionDelegate::CreateStatic(&Local::AddMenuCommands));
		LevelEditorModule.GetMenuExtensibilityManager()->AddExtender(MenuExtender);

	}
}

void FFaustToolsEditorModule::ShutdownModule()
{
	FPropertyEditorModule& PropertyModule = FModuleManager::LoadModuleChecked<FPropertyEditorModule>("PropertyEditor");
	PropertyModule.UnregisterCustomClassLayout("FaustToolsBaseClass");
}

void FFaustToolsEditorModule::TriggerTool(UClass* ToolClass)
{
	UFaustToolsBaseClass* ToolInstance = NewObject<UFaustToolsBaseClass>(GetTransientPackage(), ToolClass);
	ToolInstance->AddToRoot();

	FPropertyEditorModule& PropertyModule = FModuleManager::LoadModuleChecked<FPropertyEditorModule>("PropertyEditor");

	TArray<UObject*> ObjectsToView;
	ObjectsToView.Add(ToolInstance);
	TSharedRef<SWindow> Window = PropertyModule.CreateFloatingDetailsView(ObjectsToView, /*bIsLockeable=*/ false);
	Window->SetTitle(FText::FromString(ToolClass->GetName()));
	Window->SetOnWindowClosed(FOnWindowClosed::CreateStatic(&FFaustToolsEditorModule::OnToolWindowClosed, ToolInstance));
}

void FFaustToolsEditorModule::CreateToolListMenu(class FMenuBuilder& MenuBuilder)
{
	for (TObjectIterator<UClass> ClassIt; ClassIt; ++ClassIt)
	{
		UClass* Class = *ClassIt;
		if (!Class->HasAnyClassFlags(CLASS_Deprecated | CLASS_NewerVersionExists | CLASS_Abstract))
		{
			if (Class->IsChildOf(UFaustToolsBaseClass::StaticClass()))
			{
				FString FriendlyName = Class->GetName();
				FText MenuDescription = FText::Format(LOCTEXT("ToolMenuDescription", "{0}"), FText::FromString(FriendlyName));
				FText MenuTooltip = FText::Format(LOCTEXT("ToolMenuTooltip", "Execute the {0} tool"), FText::FromString(FriendlyName));

				FUIAction Action(FExecuteAction::CreateStatic(&FFaustToolsEditorModule::TriggerTool, Class));

				MenuBuilder.AddMenuEntry(
					MenuDescription,
					MenuTooltip,
					FSlateIcon(),
					Action);
			}
		}
	}
}

void FFaustToolsEditorModule::OnToolWindowClosed(const TSharedRef<SWindow>& Window, UFaustToolsBaseClass* Instance)
{
	Instance->RemoveFromRoot();
	Instance->OnToolClosed();
}
#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FFaustToolsEditorModule, FaustTools);

