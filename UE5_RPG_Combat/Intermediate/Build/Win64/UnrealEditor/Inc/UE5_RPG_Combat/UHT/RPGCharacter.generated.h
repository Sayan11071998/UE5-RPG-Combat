// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Character/RPGCharacter.h"

#ifdef UE5_RPG_COMBAT_RPGCharacter_generated_h
#error "RPGCharacter.generated.h already included, missing '#pragma once' in RPGCharacter.h"
#endif
#define UE5_RPG_COMBAT_RPGCharacter_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class ARPGCharacter ************************************************************
UE5_RPG_COMBAT_API UClass* Z_Construct_UClass_ARPGCharacter_NoRegister();

#define FID_Users_sayan_Projects_UE5_RPG_Combat_UE5_RPG_Combat_Source_UE5_RPG_Combat_Public_Character_RPGCharacter_h_16_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesARPGCharacter(); \
	friend struct Z_Construct_UClass_ARPGCharacter_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend UE5_RPG_COMBAT_API UClass* Z_Construct_UClass_ARPGCharacter_NoRegister(); \
public: \
	DECLARE_CLASS2(ARPGCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/UE5_RPG_Combat"), Z_Construct_UClass_ARPGCharacter_NoRegister) \
	DECLARE_SERIALIZER(ARPGCharacter)


#define FID_Users_sayan_Projects_UE5_RPG_Combat_UE5_RPG_Combat_Source_UE5_RPG_Combat_Public_Character_RPGCharacter_h_16_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	ARPGCharacter(ARPGCharacter&&) = delete; \
	ARPGCharacter(const ARPGCharacter&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ARPGCharacter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ARPGCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ARPGCharacter) \
	NO_API virtual ~ARPGCharacter();


#define FID_Users_sayan_Projects_UE5_RPG_Combat_UE5_RPG_Combat_Source_UE5_RPG_Combat_Public_Character_RPGCharacter_h_13_PROLOG
#define FID_Users_sayan_Projects_UE5_RPG_Combat_UE5_RPG_Combat_Source_UE5_RPG_Combat_Public_Character_RPGCharacter_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_sayan_Projects_UE5_RPG_Combat_UE5_RPG_Combat_Source_UE5_RPG_Combat_Public_Character_RPGCharacter_h_16_INCLASS_NO_PURE_DECLS \
	FID_Users_sayan_Projects_UE5_RPG_Combat_UE5_RPG_Combat_Source_UE5_RPG_Combat_Public_Character_RPGCharacter_h_16_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class ARPGCharacter;

// ********** End Class ARPGCharacter **************************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_sayan_Projects_UE5_RPG_Combat_UE5_RPG_Combat_Source_UE5_RPG_Combat_Public_Character_RPGCharacter_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
