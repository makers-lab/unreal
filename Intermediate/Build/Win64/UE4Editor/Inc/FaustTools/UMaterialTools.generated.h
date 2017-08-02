// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UMaterialInterface;
class UTexture;
#ifdef FAUSTTOOLS_UMaterialTools_generated_h
#error "UMaterialTools.generated.h already included, missing '#pragma once' in UMaterialTools.h"
#endif
#define FAUSTTOOLS_UMaterialTools_generated_h

#define TestSequancer_Plugins_FaustTools_Source_FaustTools_Public_MaterialTools_UMaterialTools_h_25_GENERATED_BODY \
	friend FAUSTTOOLS_API class UScriptStruct* Z_Construct_UScriptStruct_FActorInstance(); \
	FAUSTTOOLS_API static class UScriptStruct* StaticStruct();


#define TestSequancer_Plugins_FaustTools_Source_FaustTools_Public_MaterialTools_UMaterialTools_h_37_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execGetTextureFromBaseMaterialNode) \
	{ \
		P_GET_OBJECT(UMaterialInterface,Z_Param_material); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UTexture**)Z_Param__Result=UMaterialTools::GetTextureFromBaseMaterialNode(Z_Param_material); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execCreateInstance) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->CreateInstance(); \
		P_NATIVE_END; \
	}


#define TestSequancer_Plugins_FaustTools_Source_FaustTools_Public_MaterialTools_UMaterialTools_h_37_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetTextureFromBaseMaterialNode) \
	{ \
		P_GET_OBJECT(UMaterialInterface,Z_Param_material); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UTexture**)Z_Param__Result=UMaterialTools::GetTextureFromBaseMaterialNode(Z_Param_material); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execCreateInstance) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->CreateInstance(); \
		P_NATIVE_END; \
	}


#define TestSequancer_Plugins_FaustTools_Source_FaustTools_Public_MaterialTools_UMaterialTools_h_37_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUMaterialTools(); \
	friend FAUSTTOOLS_API class UClass* Z_Construct_UClass_UMaterialTools(); \
public: \
	DECLARE_CLASS(UMaterialTools, UFaustToolsBaseClass, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/FaustTools"), NO_API) \
	DECLARE_SERIALIZER(UMaterialTools) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define TestSequancer_Plugins_FaustTools_Source_FaustTools_Public_MaterialTools_UMaterialTools_h_37_INCLASS \
private: \
	static void StaticRegisterNativesUMaterialTools(); \
	friend FAUSTTOOLS_API class UClass* Z_Construct_UClass_UMaterialTools(); \
public: \
	DECLARE_CLASS(UMaterialTools, UFaustToolsBaseClass, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/FaustTools"), NO_API) \
	DECLARE_SERIALIZER(UMaterialTools) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define TestSequancer_Plugins_FaustTools_Source_FaustTools_Public_MaterialTools_UMaterialTools_h_37_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UMaterialTools(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UMaterialTools) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UMaterialTools); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UMaterialTools); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UMaterialTools(UMaterialTools&&); \
	NO_API UMaterialTools(const UMaterialTools&); \
public:


#define TestSequancer_Plugins_FaustTools_Source_FaustTools_Public_MaterialTools_UMaterialTools_h_37_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UMaterialTools(UMaterialTools&&); \
	NO_API UMaterialTools(const UMaterialTools&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UMaterialTools); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UMaterialTools); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UMaterialTools)


#define TestSequancer_Plugins_FaustTools_Source_FaustTools_Public_MaterialTools_UMaterialTools_h_37_PRIVATE_PROPERTY_OFFSET
#define TestSequancer_Plugins_FaustTools_Source_FaustTools_Public_MaterialTools_UMaterialTools_h_34_PROLOG
#define TestSequancer_Plugins_FaustTools_Source_FaustTools_Public_MaterialTools_UMaterialTools_h_37_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TestSequancer_Plugins_FaustTools_Source_FaustTools_Public_MaterialTools_UMaterialTools_h_37_PRIVATE_PROPERTY_OFFSET \
	TestSequancer_Plugins_FaustTools_Source_FaustTools_Public_MaterialTools_UMaterialTools_h_37_RPC_WRAPPERS \
	TestSequancer_Plugins_FaustTools_Source_FaustTools_Public_MaterialTools_UMaterialTools_h_37_INCLASS \
	TestSequancer_Plugins_FaustTools_Source_FaustTools_Public_MaterialTools_UMaterialTools_h_37_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define TestSequancer_Plugins_FaustTools_Source_FaustTools_Public_MaterialTools_UMaterialTools_h_37_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TestSequancer_Plugins_FaustTools_Source_FaustTools_Public_MaterialTools_UMaterialTools_h_37_PRIVATE_PROPERTY_OFFSET \
	TestSequancer_Plugins_FaustTools_Source_FaustTools_Public_MaterialTools_UMaterialTools_h_37_RPC_WRAPPERS_NO_PURE_DECLS \
	TestSequancer_Plugins_FaustTools_Source_FaustTools_Public_MaterialTools_UMaterialTools_h_37_INCLASS_NO_PURE_DECLS \
	TestSequancer_Plugins_FaustTools_Source_FaustTools_Public_MaterialTools_UMaterialTools_h_37_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID TestSequancer_Plugins_FaustTools_Source_FaustTools_Public_MaterialTools_UMaterialTools_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
