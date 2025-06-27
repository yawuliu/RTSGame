#pragma once

#include <vector>
#include "IShader.h"
#include "Uniform1f.h"
#include "UniformArray.h"
#include "IUniformMatrix4x4.h"

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
        Uniform1f *uniform(int location) {
            if (location < 0)
                return 0LL;
            auto& u = new Uniform1f(this, location);
            return this->registerUniform(u);
        }

        template<class T, class N>
        UniformArray<IUniformMatrix4x4> *uniformArray(int location,int s) {
            if (location < 0)
                return 0LL;
            auto& u = new UniformArray(this, location, s)
            return this->registerUniform(u);
        }

        std::vector<IUniform *> *uniforms();

        void updateUniform(IUniform *uniform);

    protected:
        IRender *mrender;
        std::vector<IUniform *> unif;
    };
}

