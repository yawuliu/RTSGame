#pragma once

#include "IShader.h"
#include "CGL.h"
#include "IUniform4f.h"
#include "Color.h"
#include "Data.h"

namespace MyGL {
    class IUniform;

    class Uniform4f : public IUniform4f {
    public:
        Uniform4f(IShader *sh, CGL::ShaderHandle h);

        virtual ~Uniform4f() = default; // 0
        // virtual ~Uniform4f()= default; /;/ 1
        virtual void sendDataToGPU(); // 2

        virtual CGL::ShaderHandle *handlePtr(); // 3

        virtual bool isEqual(IUniform *); // 4

        virtual IShader *owner(); // 5

        virtual void set(Color); // 6

        virtual void set(double const *); // 7

        virtual void set(double, double, double, double); // 8

    private:
        CGL::ShaderHandle handle;
        IShader *shader;
        int dat[4];
    };
}


