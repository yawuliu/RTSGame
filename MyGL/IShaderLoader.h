#pragma once

#include <MyGL/DisableCopy.h>
#include "MyGL/DataLoader.h"
#include "MyGL/IShader.h"
#include "MyGL/ShaderEnvironment.h"
namespace MyGL {
    class IShaderLoader : public DisableCopy {
    public:
        IShaderLoader() = default;

        virtual ~IShaderLoader() = default;

        virtual void setShaderAllocator(DataLoader::IAllocator<IShader> *) = 0;

        virtual ShaderEnvironment& enviroment() = 0;

        virtual void setEnvironment(ShaderEnvironment&) = 0;
    };
}