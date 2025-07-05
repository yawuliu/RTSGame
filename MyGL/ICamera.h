#pragma once

#include "DisableCopy.h"

namespace MyGL {
    class ICamera : public DisableCopy {
    public:
        ICamera() = default;

        virtual ~ICamera() = default;//0
        //1
        virtual void setPos(Float, Float, Float, Float) = 0;//2
        virtual void setAngles(Float, Float, Float) = 0;//3
        virtual void setZoom(Float) = 0;//4
        virtual void setDistance(Float, Float) = 0;//5
        virtual void move(Float, Float) = 0;//6
        virtual Float x() = 0;//7
        virtual Float y() = 0;//8
        virtual Float z() = 0;//9
        virtual Float distance() = 0;//10
        virtual Float zoom() = 0;//11
        virtual Float rotXY() = 0;//12
        virtual Float rotXZ() = 0;//13
        virtual bool isPrespective() = 0;//14
        virtual void setPrespective(bool) = 0;//15
    };
}



