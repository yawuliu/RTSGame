#pragma once

#include "IUniformSampler.h"
#include "CGL.h"

namespace MyGL {
    class IUniform;

    class IShader;

    class UniformSampler : public IUniformSampler {
    public:
        UniformSampler(IShader *sh, CGL::ShaderHandle h);

        ~UniformSampler() override = default;// 0

        //virtual ~UniformSampler() = default;// 1
        void sendDataToGPU() override; // 2

        CGL::ShaderHandle *handlePtr() override; // 3

        bool isEqual(IUniform *) override; // 4

        IShader *owner() override; // 5

        void set(int) override; // 6

        int get() override; // 7
    protected:
        CGL::ShaderHandle handle;
        IShader *shader;
        int dat;
    };
}



