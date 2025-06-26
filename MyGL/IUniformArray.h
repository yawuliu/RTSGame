#pragma once

#include "IUniform.h"

namespace MyGL {
    template<typename T>
    class IUniformArray : public IUniform {
    public:
        IUniformArray() = default;

        virtual ~IUniformArray() = default; // 0
        //virtual ~IUniformArray() = 0; // 1
        virtual void sendDataToGPU() = 0; // 2
        virtual void handlePtr() = 0; // 3
        virtual void isEqual(MyGL::IUniform *) = 0; // 4
        virtual void owner() = 0; // 5
        virtual void at(int) = 0; // 6
        virtual void operator[](int) = 0; // 7
        virtual void size() = 0; // 8
    };

}
