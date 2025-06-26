#pragma once

#include "IUniformMatrix4x4.h"
#include "CGL.h"

namespace MyGL {
    class IShader;

    class UniformMatrix4x4 : public IUniformMatrix4x4 {
    public:
        UniformMatrix4x4(IShader *sh, CGL::ShaderHandle h);

        UniformMatrix4x4(IShader *sh, CGL::ShaderHandle h, CGL::GLfloat *dataPtr);

        virtual ~UniformMatrix4x4() = default; // 0
        //virtual ~UniformMatrix4x4() = default; // 1
        virtual void sendDataToGPU(); // 2
        virtual void handlePtr(); // 3
        virtual void isEqual(IUniform *); // 4
        virtual void owner(); // 5
        virtual void set(double const *); // 6

    protected:
        CGL::ShaderHandle handle;
        IShader *shader;
        int dat;
    };
}

