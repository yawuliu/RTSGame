#pragma once

#include <string>
#include "DisableCopy.h"
#include "IUniformMatrix4x4.h"
#include "UniformArray.h"

namespace MyGL {
    class CGL;

    class IRender;

    class IUniform4f;

    class IUniformSampler;

    class IUniform1f;

    class IShader : public DisableCopy {
    public:
        IShader() = default;

        virtual ~IShader() = default; // 0
        // virtual ~IShader() = default; // 1
        virtual void loadVertexSource(char const *) = 0;// 2
        virtual void loadFragmentSource(char const *) = 0;// 3
        virtual void printInfoLog() = 0;// 4
        virtual void compile(bool) = 0;// 5
        virtual void link() = 0;// 6
        virtual bool isLinked() = 0;// 7
        virtual const char *getVSLog() = 0;// 8
        virtual const char *getFSLog() = 0;// 9
        virtual void use() = 0;// 10
        virtual void unUse() = 0;// 11
        virtual CGL *gl() = 0;// 12
        virtual IRender *render() = 0;// 13
        virtual IUniform1f *uniform1f(char const *) = 0;// 14
        virtual IUniform4f *uniform4f(char const *) = 0;// 15
        virtual IUniformMatrix4x4 *uniformMatrix4x4(char const *) = 0;// 16
        virtual IUniformSampler *uniformSampler(char const *) = 0;// 17
        virtual UniformArray<IUniformMatrix4x4> *uniformMat4x4Array(char const *, int) = 0;// 18
        virtual void updateUniform(IUniform *) = 0;// 19

    protected:

    };
}

