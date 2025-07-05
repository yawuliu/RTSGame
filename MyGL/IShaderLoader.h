#pragma once

#include "DisableCopy.h"
#include "DataLoader.h"
#include "IShader.h"


namespace MyGL {
    class IShaderEnvironment;

    class IShaderLoader : public DisableCopy {
    public:
        IShaderLoader() = default;

        virtual ~IShaderLoader() = default; // 0
        // 1
        virtual void load(MyGL::IShader &, char const *, char const *, bool *) = 0; // 2

        virtual void setEnvironment(IShaderEnvironment *) = 0; // 3

        virtual IShaderEnvironment *enviroment(void) = 0; // 4
    };
}