// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once
#define WIN32_LEAN_AND_MEAN
#include <SDKDDKVer.h>
#include <windows.h>
#include <Pathcch.h>
#include <Psapi.h>
#include <functional>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>
#include <tuple>
#include <map>

typedef std::wstring wstr;
typedef unsigned long long QWORD;
#define SDKGenMaker(EngineMajorVersion, GenMethod) (new EngineMajorVersion##GenMethod##Gen())
#define GetPtr(type, base, offset) (*(type*)(base + offset))

template <typename T> wstr to_wstring(T&& t, std::ios_base& (*f)(std::ios_base&))
{
    wstringstream oss;
    oss << f << std::uppercase << t;
    return oss.str();
}

#include "format\format.h"
#include "Signature.h"
#include "CVars.h"

#include "UEGenBase.h"

#include "UObject.h"
#include "UField.h"
#include "UStruct.h"
#include "UProperty.h"
#include "UFunction.h"
#include "UClass.h"

#include "UArrayProperty.h"
#include "UBoolProperty.h"
#include "UByteProperty.h"
#include "UClassProperty.h"
#include "UDelegateProperty.h"
#include "UDoubleProperty.h"
#include "UFloatProperty.h"
#include "UInterfaceProperty.h"
#include "UIntProperty.h"
#include "UMapProperty.h"
#include "UNameProperty.h"
#include "UObjectProperty.h"
#include "UPointerProperty.h"
#include "UStrProperty.h"
#include "UStructProperty.h"