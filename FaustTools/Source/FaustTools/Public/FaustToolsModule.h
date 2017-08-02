#pragma once

class FFaustToolsEditorModule : public IModuleInterface
{
public:
	// IMoudleInterface interface
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
	// End of IModuleInterface interface

	static void TriggerTool(UClass* ToolClass);
	static void CreateToolListMenu(class FMenuBuilder& MenuBuilder);
	static void OnToolWindowClosed(const TSharedRef<SWindow>& Window, UFaustToolsBaseClass* Instance);

	TSharedPtr<FUICommandList> CommandList;
};
