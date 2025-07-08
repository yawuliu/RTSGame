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

        virtual CGL *gl() override;

        virtual IRender *render() override;

        virtual void updateUniform(IUniform *uniform) override;


        IUniform *registerUniform(IUniform *u);


        void sendUniformsToGPU();

        template<class T, class N>
        Uniform1f *uniform(int location) {
            if (location < 0)
                return 0LL;
            return this->registerUniform(new Uniform1f(this, location));
        }

        template<class T, class N>
        UniformArray<T> *uniformArray(int location, int s) {
            if (location < 0)
                return 0LL;
            auto &u = new UniformArray<T>(this, location, s);
            return this->registerUniform(u);
        }

        std::vector<IUniform *> *uniforms();

    protected:
        IRender *mrender;
        std::vector<IUniform *> unif;
    };
}

