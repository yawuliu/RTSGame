#pragma once

#include "IUniformSampler.h"
#include "CGL.h"

namespace MyGL {
    class IUniform;

    class IShader;

    class UniformSampler : public IUniformSampler {
    public:
        UniformSampler(IShader *sh, CGL::ShaderHandle h);

        virtual ~UniformSampler() = default;// 0

        //virtual ~UniformSampler() = default;// 1
        virtual void sendDataToGPU(); // 2

        virtual void handlePtr(); // 3

        virtual void isEqual(IUniform *); // 4

        virtual void owner(); // 5

        virtual void set(int); // 6

        virtual void get(); // 7
    protected:
        CGL::ShaderHandle handle;
        IShader *shader;
        int dat;
    };
}



