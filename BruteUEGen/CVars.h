#pragma once
#include "stdafx.h"

class CVars
{
public:
    DWORD FNameEntry_Flags;
    DWORD FNameEntry_WideString;
    DWORD FNameEntry_NameAddress;
    DWORD FNameEntry_ForceWide;

    DWORD UObject_ObjectFlags;
    DWORD UObject_ObjectInternalInteger;
    DWORD UObject_Outer;
    DWORD UObject_Name;
    DWORD UObject_Class;
    DWORD UField_Next;
    DWORD UStruct_SuperField;
    DWORD UStruct_Children;
    DWORD UStruct_PropertySize;
    DWORD UProperty_ArrayDim;
    DWORD UProperty_ElementSize;
    DWORD UProperty_Offset;
    DWORD UProperty_PropertyFlags;
    DWORD UFunction_FunctionFlags;
    DWORD UFunction_NumParms;
    DWORD UFunction_ParamsSize;
    DWORD UFunction_ReturnValueOffset;
    DWORD UFunction_Func;

    DWORD UEnum_Names;
    DWORD UConst_Value;
    DWORD UByteProperty_Enum;
    DWORD UBoolProperty_BitMask;
    DWORD UDelegateProperty_Delegate;
    DWORD UObjectProperty_PropertyClass;
    DWORD UInterfaceProperty_InterfaceClass;
    DWORD UClassProperty_MetaClass;
    DWORD UStructProperty_Struct;
    DWORD UArrayProperty_Inner;
    DWORD UMapProperty_Key;
    DWORD UMapProperty_Value;

    CVars()
    {
        memset(this, 0, sizeof(CVars));
    }
};

extern CVars* pVars;