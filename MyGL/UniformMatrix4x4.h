#pragma once

#include "IUniformMatrix4x4.h"
#include "CGL.h"

namespace MyGL {
    class IShader;

    class UniformMatrix4x4 : public IUniformMatrix4x4 {
    public:
        UniformMatrix4x4(IShader *sh, CGL::ShaderHandle h);

        UniformMatrix4x4(IShader *sh, CGL::ShaderHandle h, CGL::GLfloat *dataPtr);

        ~UniformMatrix4x4() override = default; // 0
        //virtual ~UniformMatrix4x4() = default; // 1
        void sendDataToGPU() override; // 2
        CGL::ShaderHandle *handlePtr() override; // 3
        bool isEqual(IUniform *) override; // 4
        IShader *owner() override; // 5
        void set(double const *) override; // 6

    protected:
        CGL::ShaderHandle handle;
//        0000000C     // padding byte
//        0000000D     // padding byte
//        0000000E     // padding byte
//        0000000F     // padding byte
        IShader *shader;
        float data[16];
        CGL::GLfloat *dat;
    };
}

