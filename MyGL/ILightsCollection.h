#pragma once

#include "ILight.h"

namespace MyGL {
    class IScene;

    class ILightsCollection {
    public:
        ILightsCollection() = default;

        virtual  ~ILightsCollection() = default;// 0
        //virtual  ~ILightsCollection() = 0;// 1
        virtual void add(ILight &) = 0;// 2
        virtual void del(ILight &) = 0;// 3
        virtual void remove(ILight &) = 0;// 4
        virtual int size() = 0;// 5
        virtual ILight *at(uint) = 0;//  6
        virtual IScene *scene() = 0;// 7
    };
}