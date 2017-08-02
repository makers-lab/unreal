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
	ENGINE_API class UClass* Z_Construct_UClass_UTexture_NoRegister();
	ENGINE_API class UClass* Z_Construct_UClass_UMaterialInterface_NoRegister();
	ENGINE_API class UClass* Z_Construct_UClass_UMaterial_NoRegister();

	FAUSTTOOLS_API class UClass* Z_Construct_UClass_UFaustToolsBaseClass_NoRegister();
	FAUSTTOOLS_API class UClass* Z_Construct_UClass_UFaustToolsBaseClass();
	FAUSTTOOLS_API class UScriptStruct* Z_Construct_UScriptStruct_FActorInstance();
	FAUSTTOOLS_API class UFunction* Z_Construct_UFunction_UMaterialTools_CreateInstance();
	FAUSTTOOLS_API class UFunction* Z_Construct_UFunction_UMaterialTools_GetTextureFromBaseMaterialNode();
	FAUSTTOOLS_API class UClass* Z_Construct_UClass_UMaterialTools_NoRegister();
	FAUSTTOOLS_API class UClass* Z_Construct_UClass_UMaterialTools();
	FAUSTTOOLS_API class UClass* Z_Construct_UClass_UMayaToUE_NoRegister();
	FAUSTTOOLS_API class UClass* Z_Construct_UClass_UMayaToUE();
	FAUSTTOOLS_API class UClass* Z_Construct_UClass_UMotionVector_NoRegister();
	FAUSTTOOLS_API class UClass* Z_Construct_UClass_UMotionVector();
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
class UScriptStruct* FActorInstance::StaticStruct()
{
	extern FAUSTTOOLS_API class UPackage* Z_Construct_UPackage__Script_FaustTools();
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern FAUSTTOOLS_API class UScriptStruct* Z_Construct_UScriptStruct_FActorInstance();
		extern FAUSTTOOLS_API uint32 Get_Z_Construct_UScriptStruct_FActorInstance_CRC();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FActorInstance, Z_Construct_UPackage__Script_FaustTools(), TEXT("ActorInstance"), sizeof(FActorInstance), Get_Z_Construct_UScriptStruct_FActorInstance_CRC());
	}
	return Singleton;
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FActorInstance(FActorInstance::StaticStruct, TEXT("/Script/FaustTools"), TEXT("ActorInstance"), false, nullptr, nullptr);
static struct FScriptStruct_FaustTools_StaticRegisterNativesFActorInstance
{
	FScriptStruct_FaustTools_StaticRegisterNativesFActorInstance()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("ActorInstance")),new UScriptStruct::TCppStructOps<FActorInstance>);
	}
} ScriptStruct_FaustTools_StaticRegisterNativesFActorInstance;
	UScriptStruct* Z_Construct_UScriptStruct_FActorInstance()
	{
		UPackage* Outer = Z_Construct_UPackage__Script_FaustTools();
		extern uint32 Get_Z_Construct_UScriptStruct_FActorInstance_CRC();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("ActorInstance"), sizeof(FActorInstance), Get_Z_Construct_UScriptStruct_FActorInstance_CRC(), false);
		if (!ReturnStruct)
		{
			ReturnStruct = new(EC_InternalUseOnlyConstructor, Outer, TEXT("ActorInstance"), RF_Public|RF_Transient|RF_MarkAsNative) UScriptStruct(FObjectInitializer(), NULL, new UScriptStruct::TCppStructOps<FActorInstance>, EStructFlags(0x00000001));
			ReturnStruct->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnStruct->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnStruct, TEXT("BlueprintType"), TEXT("true"));
			MetaData->SetValue(ReturnStruct, TEXT("IsBlueprintBase"), TEXT("true"));
			MetaData->SetValue(ReturnStruct, TEXT("ModuleRelativePath"), TEXT("Public/MaterialTools/UMaterialTools.h"));
#endif
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FActorInstance_CRC() { return 3993361852U; }
	void UMaterialTools::StaticRegisterNativesUMaterialTools()
	{
		UClass* Class = UMaterialTools::StaticClass();
		static const TNameNativePtrPair<ANSICHAR> AnsiFuncs[] = {
			{ "CreateInstance", (Native)&UMaterialTools::execCreateInstance },
			{ "GetTextureFromBaseMaterialNode", (Native)&UMaterialTools::execGetTextureFromBaseMaterialNode },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, AnsiFuncs, 2);
	}
	UFunction* Z_Construct_UFunction_UMaterialTools_CreateInstance()
	{
		UObject* Outer=Z_Construct_UClass_UMaterialTools();
		static UFunction* ReturnFunction = NULL;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("CreateInstance"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), NULL, 0x00020601, 65535);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/MaterialTools/UMaterialTools.h"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_UMaterialTools_GetTextureFromBaseMaterialNode()
	{
		struct MaterialTools_eventGetTextureFromBaseMaterialNode_Parms
		{
			UMaterialInterface* material;
			UTexture* ReturnValue;
		};
		UObject* Outer=Z_Construct_UClass_UMaterialTools();
		static UFunction* ReturnFunction = NULL;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("GetTextureFromBaseMaterialNode"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), NULL, 0x04022401, 65535, sizeof(MaterialTools_eventGetTextureFromBaseMaterialNode_Parms));
			UProperty* NewProp_ReturnValue = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("ReturnValue"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(ReturnValue, MaterialTools_eventGetTextureFromBaseMaterialNode_Parms), 0x0010000000000580, Z_Construct_UClass_UTexture_NoRegister());
			UProperty* NewProp_material = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("material"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(material, MaterialTools_eventGetTextureFromBaseMaterialNode_Parms), 0x0010000000000080, Z_Construct_UClass_UMaterialInterface_NoRegister());
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("Faust Tools"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/MaterialTools/UMaterialTools.h"));
#endif
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UMaterialTools_NoRegister()
	{
		return UMaterialTools::StaticClass();
	}
	UClass* Z_Construct_UClass_UMaterialTools()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_UFaustToolsBaseClass();
			Z_Construct_UPackage__Script_FaustTools();
			OuterClass = UMaterialTools::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= 0x20000080;

				OuterClass->LinkChild(Z_Construct_UFunction_UMaterialTools_CreateInstance());
				OuterClass->LinkChild(Z_Construct_UFunction_UMaterialTools_GetTextureFromBaseMaterialNode());

PRAGMA_DISABLE_DEPRECATION_WARNINGS
				UProperty* NewProp_BaseMaterialForInstance = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("BaseMaterialForInstance"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(BaseMaterialForInstance, UMaterialTools), 0x0010000000000001, Z_Construct_UClass_UMaterial_NoRegister());
PRAGMA_ENABLE_DEPRECATION_WARNINGS
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_UMaterialTools_CreateInstance(), "CreateInstance"); // 4254733155
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_UMaterialTools_GetTextureFromBaseMaterialNode(), "GetTextureFromBaseMaterialNode"); // 3700137949
				static TCppClassTypeInfo<TCppClassTypeTraits<UMaterialTools> > StaticCppClassTypeInfo;
				OuterClass->SetCppTypeInfo(&StaticCppClassTypeInfo);
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("BlueprintType"), TEXT("true"));
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("MaterialTools/UMaterialTools.h"));
				MetaData->SetValue(OuterClass, TEXT("IsBlueprintBase"), TEXT("true"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("Public/MaterialTools/UMaterialTools.h"));
				MetaData->SetValue(NewProp_BaseMaterialForInstance, TEXT("Category"), TEXT("Material for instance"));
				MetaData->SetValue(NewProp_BaseMaterialForInstance, TEXT("ModuleRelativePath"), TEXT("Public/MaterialTools/UMaterialTools.h"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	IMPLEMENT_CLASS(UMaterialTools, 1527601880);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UMaterialTools(Z_Construct_UClass_UMaterialTools, &UMaterialTools::StaticClass, TEXT("/Script/FaustTools"), TEXT("UMaterialTools"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UMaterialTools);
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
	UPackage* Z_Construct_UPackage__Script_FaustTools()
	{
		static UPackage* ReturnPackage = nullptr;
		if (!ReturnPackage)
		{
			ReturnPackage = CastChecked<UPackage>(StaticFindObjectFast(UPackage::StaticClass(), nullptr, FName(TEXT("/Script/FaustTools")), false, false));
			ReturnPackage->SetPackageFlags(PKG_CompiledIn | 0x00000000);
			FGuid Guid;
			Guid.A = 0x6F0DDB06;
			Guid.B = 0xB6712D91;
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
