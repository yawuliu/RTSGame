#pragma once

#include "DisableCopy.h"

namespace MyGL {
    class IUniform : public DisableCopy {
    public:
        IUniform() = default;

        virtual ~IUniform() = default; // 0
        // virtual ~IUniform(); // 1
        virtual void sendDataToGPU() = 0; //2
        virtual void handlePtr() = 0; //3
        virtual void isEqual(IUniform *) = 0; // 4
        virtual void owner() = 0;// 5
        virtual void set(double) = 0;// 6
    };
}


