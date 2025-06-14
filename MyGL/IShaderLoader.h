#pragma once

#include "MyGL/DataLoader.h"
#include "MyGL/IShader.h"

namespace MyGL {
    class ShaderEnvironment;

    class IShaderLoader {
    public:
        virtual void setShaderAllocator(DataLoader::IAllocator<IShader> *) = 0;

        virtual ShaderEnvironment *enviroment() = 0;

        virtual void setEnvironment(ShaderEnvironment *) = 0;
    };
}