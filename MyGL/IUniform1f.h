#pragma once

#include "IUniform.h"


namespace MyGL {
    class IUniform1f : public IUniform {
    public:
        IUniform1f() = default;

        ~IUniform1f() override = default; // 0
        // virtual ~IUniform1f(); // 1
        void sendDataToGPU() override = 0; //2
        CGL::ShaderHandle *handlePtr() override = 0; //3
        bool isEqual(IUniform *) override = 0; // 4
        IShader *owner() override = 0;// 5
        void set(double) override = 0;// 6
    };
}