#pragma once

namespace MyGL {
    class IRender;

    class AbstractShader {
    public:
        AbstractShader(IRender *);

        virtual void sendUniformsToGPU() = 0;

        IRender *render();

    protected:
        IRender *mRender;
    };
}

