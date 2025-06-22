#pragma once

#include <vector>
#include <MyGL/IShader.h>
#include <MyGL/Uniform1f.h>
#include <MyGL/UniformArray.h>
#include <MyGL/IUniformMatrix4x4.h>

namespace MyGL {
    class IRender;

    class CGL;

    class IUniform;

    class AbstractShader : public IShader {
    public:
        AbstractShader(IRender *);

        virtual ~AbstractShader();

        CGL *gl();

        IUniform *registerUniform(IUniform *u);

        IRender *render();

        void sendUniformsToGPU();

        template<class T, class N>
        Uniform1f *uniform(AbstractShader *const sh, int location) {
            if (location < 0)
                return 0LL;
            u = (Uniform1f *) operator new(0x20uLL);
            Uniform1f *u = new Uniform1f(sh, location);
            return (Uniform1f *) AbstractShader::registerUniform(sh, u);
        }

        template<class T, class N>
        UniformArray<IUniformMatrix4x4> *uniformArray(
                AbstractShader *const sh,
                int location,
                int s) {
            UniformArray<IUniformMatrix4x4> *u; 

            if (location < 0)
                return 0LL;
            u = (UniformArray<IUniformMatrix4x4> *) operator new(0x18uLL);
            UniformArray<IUniformMatrix4x4>::UniformArray(u, sh, location, s);
            return (UniformArray<IUniformMatrix4x4> *) AbstractShader::registerUniform(sh, u);
        }

        std::vector<IUniform *> *uniforms();

        void updateUniform(IUniform *uniform);

    protected:
        IRender *mrender;
        std::vector<IUniform *> unif;
    };
}

