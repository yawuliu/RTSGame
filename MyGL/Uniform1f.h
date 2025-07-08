#pragma once

#include "CGL.h"
#include "IShader.h"
#include "IUniform1f.h"
#include "privateGLSupportClass.h"
#include "Data.h"


namespace MyGL {
    class IUniform;

    class Uniform1f : public IUniform1f {
    public:
        Uniform1f(IShader *sh, CGL::ShaderHandle h);

        virtual ~Uniform1f() = default; // 0
        // virtual ~Uniform1f(); // 1
        virtual void sendDataToGPU(); //2
        virtual CGL::ShaderHandle *handlePtr(); //3
        virtual bool isEqual(IUniform *); // 4
        virtual IShader *owner();// 5
        virtual void set(double);// 6
    private:
        CGL::ShaderHandle handle;
        IShader *shader;
        double dat;
    };
}


