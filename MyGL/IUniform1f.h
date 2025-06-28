#pragma once

#include "IUniform.h"


namespace MyGL {
    class IUniform1f : public IUniform {
    public:
        IUniform1f() = default;

        virtual ~IUniform1f() = default; // 0
        // virtual ~IUniform1f(); // 1
        virtual void sendDataToGPU() = 0; //2
        virtual CGL::ShaderHandle *handlePtr() = 0; //3
        virtual bool isEqual(IUniform *) = 0; // 4
        virtual IShader *owner() = 0;// 5
        virtual void set(double) = 0;// 6
    };
}