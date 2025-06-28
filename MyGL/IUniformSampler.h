#pragma once

#include "IUniform.h"

namespace MyGL {
    class ITexture2d;

    class IUniformSampler : public IUniform {
    public:
        IUniformSampler() = default;

        virtual ~IUniformSampler() = default;// 0

        //virtual ~IUniformSampler() = default;// 1
        virtual void sendDataToGPU() = 0; // 2

        virtual CGL::ShaderHandle *handlePtr() = 0; // 3

        virtual bool isEqual(IUniform *) = 0; // 4

        virtual IShader *owner() = 0; // 5

        virtual void set(int) = 0; // 6

        virtual void get() = 0; // 7
    };
}
