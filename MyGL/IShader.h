#pragma once

#include <string>
#include <MyGL/DisableCopy.h>
#include <MyGL/ITexture2d.h>
#include <MyGL/IUniform4f.h>
#include <MyGL/IUniformSampler.h>

namespace MyGL {
    class IUniformSampler;

    class IShader : public DisableCopy {
    public:
        IShader() = default;

        virtual ~IShader() = default;

        IUniform4f *uniform4f(const char *);

        virtual IUniformSampler *getUniformSamplerByName(const char *) const = 0;

    protected:

    };
}

