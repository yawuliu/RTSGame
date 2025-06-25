#pragma once

#include "ILight.h"

namespace MyGL {
    class ILightsCollection {
    public:
        ILightsCollection() = default;

        virtual  ~ILightsCollection() = default;// 0
        //virtual  ~ILightsCollection() = 0;// 1
        virtual void add(ILight &) = 0;// 2
        virtual void del(ILight &) = 0;// 3
        virtual void remove(ILight &) = 0;// 4
        virtual void size() = 0;// 5
        virtual void at(uint) = 0;//  6
        virtual void scene() = 0;// 7
    };
}