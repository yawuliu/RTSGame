#pragma once

#include "DisableCopy.h"
#include "CGL.h"

namespace MyGL {
    class IShader;

    class IUniform : public DisableCopy {
    public:
        IUniform() = default;

        virtual ~IUniform() = default; // 0
        // virtual ~IUniform(); // 1
        virtual void sendDataToGPU() = 0; //2
        virtual CGL::ShaderHandle *handlePtr() = 0; //3
        virtual bool isEqual(IUniform *) = 0; // 4
        virtual IShader *owner() = 0;// 5
        virtual void set(double) = 0;// 6
    };
}


