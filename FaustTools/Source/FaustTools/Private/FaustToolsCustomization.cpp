#include "FaustTools/Private/FaustToolsPrivatePCH.h"
#include "FaustToolsCustomization.h"
#include "PropertyEditing.h"

#define LOCTEXT_NAMESPACE "EditorTool"

void FFaustToolsCustomization::CustomizeDetails(IDetailLayoutBuilder& DetailBuilder)
{
	TSet<UClass*> Classes;

	TArray<TWeakObjectPtr<UObject>> ObjectsBeingCustomized;
	DetailBuilder.GetObjectsBeingCustomized(ObjectsBeingCustomized);

	for (auto WeakObject : ObjectsBeingCustomized)
	{
		if (UObject* Instance = WeakObject.Get())
		{
			Classes.Add(Instance->GetClass());
		}
	}

	IDetailCategoryBuilder& Actions = DetailBuilder.EditCategory("Actions");
	IDetailCategoryBuilder& Butterworth = DetailBuilder.EditCategory("Butterworth Filter");
	IDetailCategoryBuilder& FilterKeys = DetailBuilder.EditCategory("Filter Keys");

	for (UClass* Class : Classes)
	{
		for (TFieldIterator<UFunction> FuncIt(Class); FuncIt; ++FuncIt)
		{
			UFunction* Function = *FuncIt;
			if (Function->HasAnyFunctionFlags(FUNC_Exec) && (Function->NumParms == 0))
			{
				const FString FunctionName = Function->GetName();
				const FText ButtonCaption = FText::FromString(FunctionName);
				const FText FilteringString = FText::FromString(FunctionName);
				const TAttribute <FText> ToolTip = FText::Format(LOCTEXT("ToolTipText", "{0}"), Function->GetToolTipText());

				if (FunctionName == "Butterworth")
				{
					Butterworth.AddCustomRow(FilteringString)
						.ValueContent()
						[
							SNew(SButton)
							.Text(ButtonCaption)
						.ToolTipText(ToolTip)
						.OnClicked(FOnClicked::CreateStatic(&FFaustToolsCustomization::ExecuteToolCommand, &DetailBuilder, Function))
						];
				}
				else if (FunctionName == "FilterKeys")
				{
					FilterKeys.AddCustomRow(FilteringString)
						.ValueContent()
						[
							SNew(SButton)
							.Text(ButtonCaption)
						.ToolTipText(ToolTip)
						.OnClicked(FOnClicked::CreateStatic(&FFaustToolsCustomization::ExecuteToolCommand, &DetailBuilder, Function))
						];
				}
				else
				{
					Actions.AddCustomRow(FilteringString)
						.ValueContent()
						[
							SNew(SButton)
							.Text(ButtonCaption)
						.ToolTipText(ToolTip)
						.OnClicked(FOnClicked::CreateStatic(&FFaustToolsCustomization::ExecuteToolCommand, &DetailBuilder, Function))
						];
				}
			}
		}
	}
}

TSharedRef<IDetailCustomization> FFaustToolsCustomization::MakeInstance()
{
	return MakeShareable(new FFaustToolsCustomization);
}

FReply FFaustToolsCustomization::ExecuteToolCommand(IDetailLayoutBuilder* DetailBuilder, UFunction* MethodToExecute)
{
	TArray<TWeakObjectPtr<UObject>> ObjectsBeingCustomized;
	DetailBuilder->GetObjectsBeingCustomized(ObjectsBeingCustomized);

	for (auto WeakObject : ObjectsBeingCustomized)
	{
		if (UObject* Instance = WeakObject.Get())
		{
			Instance->CallFunctionByNameWithArguments(*MethodToExecute->GetName(), *GLog, nullptr, true);
		}
	}

	return FReply::Handled();
}

#undef LOCTEXT_NAMESPACE