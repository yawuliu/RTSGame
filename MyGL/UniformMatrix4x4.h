#pragma once

#include "IUniformMatrix4x4.h"
#include "CGL.h"

namespace MyGL {
    class IShader;

    class UniformMatrix4x4 : public IUniformMatrix4x4 {
    public:
        UniformMatrix4x4(IShader *sh, CGL::ShaderHandle h);

        UniformMatrix4x4(IShader *sh, CGL::ShaderHandle h, CGL::GLfloat *dataPtr);

        virtual ~UniformMatrix4x4() = default;

        const void *handlePtr();

        bool isEqual(IUniform *u);

        IShader *owner();

        void sendDataToGPU();

        void set(const Float *data);

    protected:
        CGL::ShaderHandle handle;
        IShader *shader;
        int dat;
    };
}

