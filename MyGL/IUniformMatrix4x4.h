#pragma once

#include "IUniform.h"

namespace MyGL {
    class IUniformMatrix4x4 : public IUniform {
    public:
        IUniformMatrix4x4() = default;

        virtual ~IUniformMatrix4x4() = default; // 0
        //virtual ~IUniformMatrix4x4() = default; // 1
        virtual void sendDataToGPU() = 0; // 2
        virtual void handlePtr() = 0; // 3
        virtual void isEqual(IUniform *) = 0; // 4
        virtual void owner() = 0; // 5
        virtual void set(double const *) = 0; // 6
    };
}