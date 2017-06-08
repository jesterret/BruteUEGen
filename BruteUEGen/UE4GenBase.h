#pragma once
#include "UEGenBase.h"

class UE4GenBase : public UEGenBase
{
    virtual void RegisterTypes() override;
    virtual void CustomInitialization() override;
    virtual void ProcessPackages() override;
    virtual void FinalizeGeneration() override;
};