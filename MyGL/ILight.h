#pragma once

#include "Data.h"

namespace MyGL {


    class ILight {
    public:
        ILight() = default;

        virtual  ~ILight() = default;// 0
        //virtual  ~ILight() = 0;// `
        virtual void setPosition(double, double, double) = 0;//  2
        virtual Float x() = 0;// 3
        virtual Float y() = 0;// 4
        virtual Float z() = 0;// 5
        virtual void setShadowCast(bool) = 0;// 6
        virtual bool isShadowCaster() = 0;// 7
        virtual void setDirection(double, double, double) = 0;// 8
        virtual Float dirX() = 0;// 9
        virtual Float dirY() = 0;// 10
        virtual Float dirZ() = 0;//11
        virtual void upset() = 0;// 12
        virtual Float *dirTransform() = 0;// 13
        virtual bool hasOccluder() = 0;// 14
        virtual void occluder() = 0;// 15
        virtual bool isDeferred() = 0;// 16
        virtual void setDeferred(bool) = 0;// 17
    };

}


