#pragma once

#include "DisableCopy.h"

namespace MyGL {
    class ICamera : public DisableCopy {
    public:
        ICamera() = default;

        virtual ~ICamera() = 0;//0
        //1
        virtual void setPos(double, double, double, double) = 0;//2
        virtual void setAngles(double, double, double) = 0;//3
        virtual void setZoom(double) = 0;//4
        virtual void setDistance(double, double) = 0;//5
        virtual void move(double, double) = 0;//6
        virtual void x() = 0;//7
        virtual void y() = 0;//8
        virtual void z() = 0;//9
        virtual void distance() = 0;//10
        virtual void zoom() = 0;//11
        virtual void rotXY() = 0;//12
        virtual void rotXZ() = 0;//13
        virtual void isPrespective() = 0;//14
        virtual void setPrespective(bool) = 0;//15
    };
}



