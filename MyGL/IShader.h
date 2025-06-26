#pragma once

#include <string>
#include "DisableCopy.h"
#include "ITexture2d.h"
#include "IUniform4f.h"
#include "IUniformSampler.h"

namespace MyGL {
    class IUniformSampler;

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
        virtual void isLinked() = 0;// 7
        virtual void getVSLog() = 0;// 8
        virtual void getFSLog() = 0;// 9
        virtual void use() = 0;// 10
        virtual void unUse() = 0;// 11
        virtual void gl() = 0;// 12
        virtual void render() = 0;// 13
        virtual void uniform1f(char const *) = 0;// 14
        virtual void uniform4f(char const *) = 0;// 15
        virtual void uniformMatrix4x4(char const *) = 0;// 16
        virtual void uniformSampler(char const *) = 0;// 17
        virtual void uniformMat4x4Array(char const *, int) = 0;// 18
        virtual void updateUniform(IUniform *) = 0;// 19

    protected:

    };
}

