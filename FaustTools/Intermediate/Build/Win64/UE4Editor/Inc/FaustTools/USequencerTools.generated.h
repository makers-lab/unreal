// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef FAUSTTOOLS_USequencerTools_generated_h
#error "USequencerTools.generated.h already included, missing '#pragma once' in USequencerTools.h"
#endif
#define FAUSTTOOLS_USequencerTools_generated_h

#define SequencerPlugin_Plugins_FaustTools_Source_FaustTools_Public_SequencerTools_USequencerTools_h_14_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execResetCapture) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->ResetCapture(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execCaptureRange) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->CaptureRange(); \
		P_NATIVE_END; \
	}


#define SequencerPlugin_Plugins_FaustTools_Source_FaustTools_Public_SequencerTools_USequencerTools_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execResetCapture) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->ResetCapture(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execCaptureRange) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->CaptureRange(); \
		P_NATIVE_END; \
	}


#define SequencerPlugin_Plugins_FaustTools_Source_FaustTools_Public_SequencerTools_USequencerTools_h_14_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUSequencerTools(); \
	friend FAUSTTOOLS_API class UClass* Z_Construct_UClass_USequencerTools(); \
public: \
	DECLARE_CLASS(USequencerTools, UFaustToolsBaseClass, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/FaustTools"), NO_API) \
	DECLARE_SERIALIZER(USequencerTools) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define SequencerPlugin_Plugins_FaustTools_Source_FaustTools_Public_SequencerTools_USequencerTools_h_14_INCLASS \
private: \
	static void StaticRegisterNativesUSequencerTools(); \
	friend FAUSTTOOLS_API class UClass* Z_Construct_UClass_USequencerTools(); \
public: \
	DECLARE_CLASS(USequencerTools, UFaustToolsBaseClass, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/FaustTools"), NO_API) \
	DECLARE_SERIALIZER(USequencerTools) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define SequencerPlugin_Plugins_FaustTools_Source_FaustTools_Public_SequencerTools_USequencerTools_h_14_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API USequencerTools(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(USequencerTools) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, USequencerTools); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(USequencerTools); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API USequencerTools(USequencerTools&&); \
	NO_API USequencerTools(const USequencerTools&); \
public:


#define SequencerPlugin_Plugins_FaustTools_Source_FaustTools_Public_SequencerTools_USequencerTools_h_14_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API USequencerTools(USequencerTools&&); \
	NO_API USequencerTools(const USequencerTools&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, USequencerTools); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(USequencerTools); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(USequencerTools)


#define SequencerPlugin_Plugins_FaustTools_Source_FaustTools_Public_SequencerTools_USequencerTools_h_14_PRIVATE_PROPERTY_OFFSET
#define SequencerPlugin_Plugins_FaustTools_Source_FaustTools_Public_SequencerTools_USequencerTools_h_11_PROLOG
#define SequencerPlugin_Plugins_FaustTools_Source_FaustTools_Public_SequencerTools_USequencerTools_h_14_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	SequencerPlugin_Plugins_FaustTools_Source_FaustTools_Public_SequencerTools_USequencerTools_h_14_PRIVATE_PROPERTY_OFFSET \
	SequencerPlugin_Plugins_FaustTools_Source_FaustTools_Public_SequencerTools_USequencerTools_h_14_RPC_WRAPPERS \
	SequencerPlugin_Plugins_FaustTools_Source_FaustTools_Public_SequencerTools_USequencerTools_h_14_INCLASS \
	SequencerPlugin_Plugins_FaustTools_Source_FaustTools_Public_SequencerTools_USequencerTools_h_14_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define SequencerPlugin_Plugins_FaustTools_Source_FaustTools_Public_SequencerTools_USequencerTools_h_14_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	SequencerPlugin_Plugins_FaustTools_Source_FaustTools_Public_SequencerTools_USequencerTools_h_14_PRIVATE_PROPERTY_OFFSET \
	SequencerPlugin_Plugins_FaustTools_Source_FaustTools_Public_SequencerTools_USequencerTools_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	SequencerPlugin_Plugins_FaustTools_Source_FaustTools_Public_SequencerTools_USequencerTools_h_14_INCLASS_NO_PURE_DECLS \
	SequencerPlugin_Plugins_FaustTools_Source_FaustTools_Public_SequencerTools_USequencerTools_h_14_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID SequencerPlugin_Plugins_FaustTools_Source_FaustTools_Public_SequencerTools_USequencerTools_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
