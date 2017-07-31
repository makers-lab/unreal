// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Private/FaustToolsPrivatePCH.h"
#include "FaustTools.generated.dep.h"
PRAGMA_DISABLE_OPTIMIZATION
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCode1FaustTools() {}
#if USE_COMPILED_IN_NATIVES
// Cross Module References
	COREUOBJECT_API class UClass* Z_Construct_UClass_UObject();

	FAUSTTOOLS_API class UClass* Z_Construct_UClass_UFaustToolsBaseClass_NoRegister();
	FAUSTTOOLS_API class UClass* Z_Construct_UClass_UFaustToolsBaseClass();
	FAUSTTOOLS_API class UClass* Z_Construct_UClass_UMayaToUE_NoRegister();
	FAUSTTOOLS_API class UClass* Z_Construct_UClass_UMayaToUE();
	FAUSTTOOLS_API class UClass* Z_Construct_UClass_UMotionVector_NoRegister();
	FAUSTTOOLS_API class UClass* Z_Construct_UClass_UMotionVector();
	FAUSTTOOLS_API class UFunction* Z_Construct_UFunction_USequencerTools_Apply();
	FAUSTTOOLS_API class UFunction* Z_Construct_UFunction_USequencerTools_CaptureRange();
	FAUSTTOOLS_API class UFunction* Z_Construct_UFunction_USequencerTools_ResetCapture();
	FAUSTTOOLS_API class UClass* Z_Construct_UClass_USequencerTools_NoRegister();
	FAUSTTOOLS_API class UClass* Z_Construct_UClass_USequencerTools();
	FAUSTTOOLS_API class UClass* Z_Construct_UClass_USupport_NoRegister();
	FAUSTTOOLS_API class UClass* Z_Construct_UClass_USupport();
	FAUSTTOOLS_API class UPackage* Z_Construct_UPackage__Script_FaustTools();
	void UFaustToolsBaseClass::StaticRegisterNativesUFaustToolsBaseClass()
	{
	}
	UClass* Z_Construct_UClass_UFaustToolsBaseClass_NoRegister()
	{
		return UFaustToolsBaseClass::StaticClass();
	}
	UClass* Z_Construct_UClass_UFaustToolsBaseClass()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_UObject();
			Z_Construct_UPackage__Script_FaustTools();
			OuterClass = UFaustToolsBaseClass::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= 0x20000081;


				static TCppClassTypeInfo<TCppClassTypeTraits<UFaustToolsBaseClass> > StaticCppClassTypeInfo;
				OuterClass->SetCppTypeInfo(&StaticCppClassTypeInfo);
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("BlueprintType"), TEXT("true"));
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("FaustToolsBaseClass.h"));
				MetaData->SetValue(OuterClass, TEXT("IsBlueprintBase"), TEXT("true"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("Public/FaustToolsBaseClass.h"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	IMPLEMENT_CLASS(UFaustToolsBaseClass, 10645070);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UFaustToolsBaseClass(Z_Construct_UClass_UFaustToolsBaseClass, &UFaustToolsBaseClass::StaticClass, TEXT("/Script/FaustTools"), TEXT("UFaustToolsBaseClass"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UFaustToolsBaseClass);
	void UMayaToUE::StaticRegisterNativesUMayaToUE()
	{
	}
	UClass* Z_Construct_UClass_UMayaToUE_NoRegister()
	{
		return UMayaToUE::StaticClass();
	}
	UClass* Z_Construct_UClass_UMayaToUE()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_UFaustToolsBaseClass();
			Z_Construct_UPackage__Script_FaustTools();
			OuterClass = UMayaToUE::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= 0x20000080;


PRAGMA_DISABLE_DEPRECATION_WARNINGS
				CPP_BOOL_PROPERTY_BITMASK_STRUCT(Connect, UMayaToUE, bool);
				UProperty* NewProp_Connect = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("Connect"), RF_Public|RF_Transient|RF_MarkAsNative) UBoolProperty(FObjectInitializer(), EC_CppProperty, CPP_BOOL_PROPERTY_OFFSET(Connect, UMayaToUE), 0x0010000000000001, CPP_BOOL_PROPERTY_BITMASK(Connect, UMayaToUE), sizeof(bool), true);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
				static TCppClassTypeInfo<TCppClassTypeTraits<UMayaToUE> > StaticCppClassTypeInfo;
				OuterClass->SetCppTypeInfo(&StaticCppClassTypeInfo);
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("BlueprintType"), TEXT("true"));
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("MayaToUE/MayaToUE.h"));
				MetaData->SetValue(OuterClass, TEXT("IsBlueprintBase"), TEXT("true"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("Public/MayaToUE/MayaToUE.h"));
				MetaData->SetValue(NewProp_Connect, TEXT("Category"), TEXT("Commnands"));
				MetaData->SetValue(NewProp_Connect, TEXT("ModuleRelativePath"), TEXT("Public/MayaToUE/MayaToUE.h"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	IMPLEMENT_CLASS(UMayaToUE, 1379936806);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UMayaToUE(Z_Construct_UClass_UMayaToUE, &UMayaToUE::StaticClass, TEXT("/Script/FaustTools"), TEXT("UMayaToUE"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UMayaToUE);
	void UMotionVector::StaticRegisterNativesUMotionVector()
	{
	}
	UClass* Z_Construct_UClass_UMotionVector_NoRegister()
	{
		return UMotionVector::StaticClass();
	}
	UClass* Z_Construct_UClass_UMotionVector()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_UFaustToolsBaseClass();
			Z_Construct_UPackage__Script_FaustTools();
			OuterClass = UMotionVector::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= 0x20000080;


PRAGMA_DISABLE_DEPRECATION_WARNINGS
				UProperty* NewProp_MaxSpeed = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("MaxSpeed"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(MaxSpeed, UMotionVector), 0x0010000000000001);
				UProperty* NewProp_MinSpeed = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("MinSpeed"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(MinSpeed, UMotionVector), 0x0010000000000001);
				UProperty* NewProp_ColorMultiply = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("ColorMultiply"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(ColorMultiply, UMotionVector), 0x0010000000000001);
				CPP_BOOL_PROPERTY_BITMASK_STRUCT(IncludeCamera, UMotionVector, bool);
				UProperty* NewProp_IncludeCamera = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("IncludeCamera"), RF_Public|RF_Transient|RF_MarkAsNative) UBoolProperty(FObjectInitializer(), EC_CppProperty, CPP_BOOL_PROPERTY_OFFSET(IncludeCamera, UMotionVector), 0x0010000000000001, CPP_BOOL_PROPERTY_BITMASK(IncludeCamera, UMotionVector), sizeof(bool), true);
				CPP_BOOL_PROPERTY_BITMASK_STRUCT(GenerateMotionVectors, UMotionVector, bool);
				UProperty* NewProp_GenerateMotionVectors = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("GenerateMotionVectors"), RF_Public|RF_Transient|RF_MarkAsNative) UBoolProperty(FObjectInitializer(), EC_CppProperty, CPP_BOOL_PROPERTY_OFFSET(GenerateMotionVectors, UMotionVector), 0x0010000000000001, CPP_BOOL_PROPERTY_BITMASK(GenerateMotionVectors, UMotionVector), sizeof(bool), true);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
				static TCppClassTypeInfo<TCppClassTypeTraits<UMotionVector> > StaticCppClassTypeInfo;
				OuterClass->SetCppTypeInfo(&StaticCppClassTypeInfo);
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("BlueprintType"), TEXT("true"));
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("MotionVector/UMotionVector.h"));
				MetaData->SetValue(OuterClass, TEXT("IsBlueprintBase"), TEXT("true"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("Public/MotionVector/UMotionVector.h"));
				MetaData->SetValue(NewProp_MaxSpeed, TEXT("Category"), TEXT("Parameters"));
				MetaData->SetValue(NewProp_MaxSpeed, TEXT("ModuleRelativePath"), TEXT("Public/MotionVector/UMotionVector.h"));
				MetaData->SetValue(NewProp_MinSpeed, TEXT("Category"), TEXT("Parameters"));
				MetaData->SetValue(NewProp_MinSpeed, TEXT("ModuleRelativePath"), TEXT("Public/MotionVector/UMotionVector.h"));
				MetaData->SetValue(NewProp_ColorMultiply, TEXT("Category"), TEXT("Parameters"));
				MetaData->SetValue(NewProp_ColorMultiply, TEXT("ModuleRelativePath"), TEXT("Public/MotionVector/UMotionVector.h"));
				MetaData->SetValue(NewProp_IncludeCamera, TEXT("Category"), TEXT("Commands"));
				MetaData->SetValue(NewProp_IncludeCamera, TEXT("ModuleRelativePath"), TEXT("Public/MotionVector/UMotionVector.h"));
				MetaData->SetValue(NewProp_GenerateMotionVectors, TEXT("Category"), TEXT("Commands"));
				MetaData->SetValue(NewProp_GenerateMotionVectors, TEXT("ModuleRelativePath"), TEXT("Public/MotionVector/UMotionVector.h"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	IMPLEMENT_CLASS(UMotionVector, 1249199639);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UMotionVector(Z_Construct_UClass_UMotionVector, &UMotionVector::StaticClass, TEXT("/Script/FaustTools"), TEXT("UMotionVector"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UMotionVector);
	void USequencerTools::StaticRegisterNativesUSequencerTools()
	{
		UClass* Class = USequencerTools::StaticClass();
		static const TNameNativePtrPair<ANSICHAR> AnsiFuncs[] = {
			{ "Apply", (Native)&USequencerTools::execApply },
			{ "CaptureRange", (Native)&USequencerTools::execCaptureRange },
			{ "ResetCapture", (Native)&USequencerTools::execResetCapture },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, AnsiFuncs, 3);
	}
	UFunction* Z_Construct_UFunction_USequencerTools_Apply()
	{
		UObject* Outer=Z_Construct_UClass_USequencerTools();
		static UFunction* ReturnFunction = NULL;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("Apply"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), NULL, 0x00020601, 65535);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/SequencerTools/USequencerTools.h"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_USequencerTools_CaptureRange()
	{
		UObject* Outer=Z_Construct_UClass_USequencerTools();
		static UFunction* ReturnFunction = NULL;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("CaptureRange"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), NULL, 0x00020601, 65535);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/SequencerTools/USequencerTools.h"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_USequencerTools_ResetCapture()
	{
		UObject* Outer=Z_Construct_UClass_USequencerTools();
		static UFunction* ReturnFunction = NULL;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("ResetCapture"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), NULL, 0x00020601, 65535);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/SequencerTools/USequencerTools.h"));
#endif
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_USequencerTools_NoRegister()
	{
		return USequencerTools::StaticClass();
	}
	UClass* Z_Construct_UClass_USequencerTools()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_UFaustToolsBaseClass();
			Z_Construct_UPackage__Script_FaustTools();
			OuterClass = USequencerTools::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= 0x20000080;

				OuterClass->LinkChild(Z_Construct_UFunction_USequencerTools_Apply());
				OuterClass->LinkChild(Z_Construct_UFunction_USequencerTools_CaptureRange());
				OuterClass->LinkChild(Z_Construct_UFunction_USequencerTools_ResetCapture());

PRAGMA_DISABLE_DEPRECATION_WARNINGS
				UProperty* NewProp_ScaleRightValue = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("ScaleRightValue"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(ScaleRightValue, USequencerTools), 0x0010000000000001);
				UProperty* NewProp_ScaleLeftValue = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("ScaleLeftValue"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(ScaleLeftValue, USequencerTools), 0x0010000000000001);
				UProperty* NewProp_ScaleBotValue = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("ScaleBotValue"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(ScaleBotValue, USequencerTools), 0x0010000000000001);
				UProperty* NewProp_ScaleTopValue = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("ScaleTopValue"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(ScaleTopValue, USequencerTools), 0x0010000000000001);
				CPP_BOOL_PROPERTY_BITMASK_STRUCT(bScaleCapturedRange, USequencerTools, bool);
				UProperty* NewProp_bScaleCapturedRange = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("bScaleCapturedRange"), RF_Public|RF_Transient|RF_MarkAsNative) UBoolProperty(FObjectInitializer(), EC_CppProperty, CPP_BOOL_PROPERTY_OFFSET(bScaleCapturedRange, USequencerTools), 0x0010000000000001, CPP_BOOL_PROPERTY_BITMASK(bScaleCapturedRange, USequencerTools), sizeof(bool), true);
				UProperty* NewProp_ToFrame = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("ToFrame"), RF_Public|RF_Transient|RF_MarkAsNative) UIntProperty(CPP_PROPERTY_BASE(ToFrame, USequencerTools), 0x0010000000000001);
				UProperty* NewProp_FromFrame = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("FromFrame"), RF_Public|RF_Transient|RF_MarkAsNative) UIntProperty(CPP_PROPERTY_BASE(FromFrame, USequencerTools), 0x0010000000000001);
				CPP_BOOL_PROPERTY_BITMASK_STRUCT(Z, USequencerTools, bool);
				UProperty* NewProp_Z = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("Z"), RF_Public|RF_Transient|RF_MarkAsNative) UBoolProperty(FObjectInitializer(), EC_CppProperty, CPP_BOOL_PROPERTY_OFFSET(Z, USequencerTools), 0x0010000000000001, CPP_BOOL_PROPERTY_BITMASK(Z, USequencerTools), sizeof(bool), true);
				CPP_BOOL_PROPERTY_BITMASK_STRUCT(Y, USequencerTools, bool);
				UProperty* NewProp_Y = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("Y"), RF_Public|RF_Transient|RF_MarkAsNative) UBoolProperty(FObjectInitializer(), EC_CppProperty, CPP_BOOL_PROPERTY_OFFSET(Y, USequencerTools), 0x0010000000000001, CPP_BOOL_PROPERTY_BITMASK(Y, USequencerTools), sizeof(bool), true);
				CPP_BOOL_PROPERTY_BITMASK_STRUCT(X, USequencerTools, bool);
				UProperty* NewProp_X = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("X"), RF_Public|RF_Transient|RF_MarkAsNative) UBoolProperty(FObjectInitializer(), EC_CppProperty, CPP_BOOL_PROPERTY_OFFSET(X, USequencerTools), 0x0010000000000001, CPP_BOOL_PROPERTY_BITMASK(X, USequencerTools), sizeof(bool), true);
				CPP_BOOL_PROPERTY_BITMASK_STRUCT(Scaling, USequencerTools, bool);
				UProperty* NewProp_Scaling = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("Scaling"), RF_Public|RF_Transient|RF_MarkAsNative) UBoolProperty(FObjectInitializer(), EC_CppProperty, CPP_BOOL_PROPERTY_OFFSET(Scaling, USequencerTools), 0x0010000000000001, CPP_BOOL_PROPERTY_BITMASK(Scaling, USequencerTools), sizeof(bool), true);
				CPP_BOOL_PROPERTY_BITMASK_STRUCT(Rotation, USequencerTools, bool);
				UProperty* NewProp_Rotation = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("Rotation"), RF_Public|RF_Transient|RF_MarkAsNative) UBoolProperty(FObjectInitializer(), EC_CppProperty, CPP_BOOL_PROPERTY_OFFSET(Rotation, USequencerTools), 0x0010000000000001, CPP_BOOL_PROPERTY_BITMASK(Rotation, USequencerTools), sizeof(bool), true);
				CPP_BOOL_PROPERTY_BITMASK_STRUCT(Location, USequencerTools, bool);
				UProperty* NewProp_Location = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("Location"), RF_Public|RF_Transient|RF_MarkAsNative) UBoolProperty(FObjectInitializer(), EC_CppProperty, CPP_BOOL_PROPERTY_OFFSET(Location, USequencerTools), 0x0010000000000001, CPP_BOOL_PROPERTY_BITMASK(Location, USequencerTools), sizeof(bool), true);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_USequencerTools_Apply(), "Apply"); // 3255983230
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_USequencerTools_CaptureRange(), "CaptureRange"); // 256450413
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_USequencerTools_ResetCapture(), "ResetCapture"); // 410184122
				static TCppClassTypeInfo<TCppClassTypeTraits<USequencerTools> > StaticCppClassTypeInfo;
				OuterClass->SetCppTypeInfo(&StaticCppClassTypeInfo);
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("BlueprintType"), TEXT("true"));
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("SequencerTools/USequencerTools.h"));
				MetaData->SetValue(OuterClass, TEXT("IsBlueprintBase"), TEXT("true"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("Public/SequencerTools/USequencerTools.h"));
				MetaData->SetValue(NewProp_ScaleRightValue, TEXT("Category"), TEXT("Scaling"));
				MetaData->SetValue(NewProp_ScaleRightValue, TEXT("DisplayName"), TEXT("Scale Right"));
				MetaData->SetValue(NewProp_ScaleRightValue, TEXT("Keywords"), TEXT("Scale Right"));
				MetaData->SetValue(NewProp_ScaleRightValue, TEXT("ModuleRelativePath"), TEXT("Public/SequencerTools/USequencerTools.h"));
				MetaData->SetValue(NewProp_ScaleLeftValue, TEXT("Category"), TEXT("Scaling"));
				MetaData->SetValue(NewProp_ScaleLeftValue, TEXT("DisplayName"), TEXT("Scale Left"));
				MetaData->SetValue(NewProp_ScaleLeftValue, TEXT("Keywords"), TEXT("Scale Left"));
				MetaData->SetValue(NewProp_ScaleLeftValue, TEXT("ModuleRelativePath"), TEXT("Public/SequencerTools/USequencerTools.h"));
				MetaData->SetValue(NewProp_ScaleBotValue, TEXT("Category"), TEXT("Scaling"));
				MetaData->SetValue(NewProp_ScaleBotValue, TEXT("DisplayName"), TEXT("Scale Bottom"));
				MetaData->SetValue(NewProp_ScaleBotValue, TEXT("Keywords"), TEXT("Scale Bottom"));
				MetaData->SetValue(NewProp_ScaleBotValue, TEXT("ModuleRelativePath"), TEXT("Public/SequencerTools/USequencerTools.h"));
				MetaData->SetValue(NewProp_ScaleTopValue, TEXT("Category"), TEXT("Scaling"));
				MetaData->SetValue(NewProp_ScaleTopValue, TEXT("DisplayName"), TEXT("Scale Top"));
				MetaData->SetValue(NewProp_ScaleTopValue, TEXT("Keywords"), TEXT("Scale Top"));
				MetaData->SetValue(NewProp_ScaleTopValue, TEXT("ModuleRelativePath"), TEXT("Public/SequencerTools/USequencerTools.h"));
				MetaData->SetValue(NewProp_ScaleTopValue, TEXT("ToolTip"), TEXT("Scaling"));
				MetaData->SetValue(NewProp_bScaleCapturedRange, TEXT("Category"), TEXT("Scaling"));
				MetaData->SetValue(NewProp_bScaleCapturedRange, TEXT("DisplayName"), TEXT("Scale Captured Range Only"));
				MetaData->SetValue(NewProp_bScaleCapturedRange, TEXT("Keywords"), TEXT("Scale Capture Range Only"));
				MetaData->SetValue(NewProp_bScaleCapturedRange, TEXT("ModuleRelativePath"), TEXT("Public/SequencerTools/USequencerTools.h"));
				MetaData->SetValue(NewProp_bScaleCapturedRange, TEXT("ToolTip"), TEXT("Scale selected keys"));
				MetaData->SetValue(NewProp_ToFrame, TEXT("Category"), TEXT("Parameters"));
				MetaData->SetValue(NewProp_ToFrame, TEXT("DisplayName"), TEXT("To Frame"));
				MetaData->SetValue(NewProp_ToFrame, TEXT("Keywords"), TEXT("To Frame"));
				MetaData->SetValue(NewProp_ToFrame, TEXT("ModuleRelativePath"), TEXT("Public/SequencerTools/USequencerTools.h"));
				MetaData->SetValue(NewProp_FromFrame, TEXT("Category"), TEXT("Parameters"));
				MetaData->SetValue(NewProp_FromFrame, TEXT("DisplayName"), TEXT("From Frame"));
				MetaData->SetValue(NewProp_FromFrame, TEXT("Keywords"), TEXT("From Frame"));
				MetaData->SetValue(NewProp_FromFrame, TEXT("ModuleRelativePath"), TEXT("Public/SequencerTools/USequencerTools.h"));
				MetaData->SetValue(NewProp_Z, TEXT("Category"), TEXT("Curve Parameters"));
				MetaData->SetValue(NewProp_Z, TEXT("ModuleRelativePath"), TEXT("Public/SequencerTools/USequencerTools.h"));
				MetaData->SetValue(NewProp_Y, TEXT("Category"), TEXT("Curve Parameters"));
				MetaData->SetValue(NewProp_Y, TEXT("ModuleRelativePath"), TEXT("Public/SequencerTools/USequencerTools.h"));
				MetaData->SetValue(NewProp_X, TEXT("Category"), TEXT("Curve Parameters"));
				MetaData->SetValue(NewProp_X, TEXT("ModuleRelativePath"), TEXT("Public/SequencerTools/USequencerTools.h"));
				MetaData->SetValue(NewProp_Scaling, TEXT("Category"), TEXT("Transform Parameters"));
				MetaData->SetValue(NewProp_Scaling, TEXT("ModuleRelativePath"), TEXT("Public/SequencerTools/USequencerTools.h"));
				MetaData->SetValue(NewProp_Rotation, TEXT("Category"), TEXT("Transform Parameters"));
				MetaData->SetValue(NewProp_Rotation, TEXT("ModuleRelativePath"), TEXT("Public/SequencerTools/USequencerTools.h"));
				MetaData->SetValue(NewProp_Location, TEXT("Category"), TEXT("Transform Parameters"));
				MetaData->SetValue(NewProp_Location, TEXT("ModuleRelativePath"), TEXT("Public/SequencerTools/USequencerTools.h"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	IMPLEMENT_CLASS(USequencerTools, 2827045183);
	static FCompiledInDefer Z_CompiledInDefer_UClass_USequencerTools(Z_Construct_UClass_USequencerTools, &USequencerTools::StaticClass, TEXT("/Script/FaustTools"), TEXT("USequencerTools"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(USequencerTools);
	void USupport::StaticRegisterNativesUSupport()
	{
	}
	UClass* Z_Construct_UClass_USupport_NoRegister()
	{
		return USupport::StaticClass();
	}
	UClass* Z_Construct_UClass_USupport()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_UObject();
			Z_Construct_UPackage__Script_FaustTools();
			OuterClass = USupport::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= 0x20000080;


				static TCppClassTypeInfo<TCppClassTypeTraits<USupport> > StaticCppClassTypeInfo;
				OuterClass->SetCppTypeInfo(&StaticCppClassTypeInfo);
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("SequencerTools/SupportClass.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("Public/SequencerTools/SupportClass.h"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	IMPLEMENT_CLASS(USupport, 386340387);
	static FCompiledInDefer Z_CompiledInDefer_UClass_USupport(Z_Construct_UClass_USupport, &USupport::StaticClass, TEXT("/Script/FaustTools"), TEXT("USupport"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(USupport);
	UPackage* Z_Construct_UPackage__Script_FaustTools()
	{
		static UPackage* ReturnPackage = nullptr;
		if (!ReturnPackage)
		{
			ReturnPackage = CastChecked<UPackage>(StaticFindObjectFast(UPackage::StaticClass(), nullptr, FName(TEXT("/Script/FaustTools")), false, false));
			ReturnPackage->SetPackageFlags(PKG_CompiledIn | 0x00000040);
			FGuid Guid;
			Guid.A = 0x554B22A3;
			Guid.B = 0xA1B0A86A;
			Guid.C = 0x00000000;
			Guid.D = 0x00000000;
			ReturnPackage->SetGuid(Guid);

		}
		return ReturnPackage;
	}
#endif
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
PRAGMA_ENABLE_OPTIMIZATION
