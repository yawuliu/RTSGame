#pragma once

#include "IUniform.h"

namespace MyGL {
    class IUniform4f : public IUniform {
    public:
        IUniform4f() = default;

        virtual ~IUniform4f() = default; // 0
        // virtual ~IUniform4f()= default; /;/ 1
        virtual void sendDataToGPU() = 0; // 2

        virtual CGL::ShaderHandle *handlePtr() = 0; // 3

        virtual bool isEqual(IUniform *) = 0; // 4

        virtual IShader *owner() = 0; // 5

        virtual void set(Color) = 0; // 6

        virtual void set(double const *) = 0; // 7

        virtual void set(double, double, double, double) = 0; // 8
    };
}

