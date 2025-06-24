#pragma once

#include "DisableCopy.h"
#include "IModelInfo.h"
#include "ObjectMatrix.h"

namespace MyGL {
    class IGraphicsObject : public DisableCopy {
    public:
        IGraphicsObject() = default;

        virtual  ~IGraphicsObject() = default;// 0
        //virtual void ~GraphicsObject() = 0;// 1
        virtual void setMaterial(IMaterial *) = 0;// 2
        virtual void material() = 0;// 3
        virtual void setMatrix(ObjectMatrix &) = 0;// 4
        virtual void objectMatrix() = 0;// 5
        virtual void setModel(IModel *) = 0;// 6
        virtual void model() = 0;// 7
        virtual void setVisible(bool) = 0;// 8
        virtual void visible() = 0;// 9
        virtual void setAlvaysVisible(bool) = 0;// 10
        virtual void isAlvaysVisible() = 0;// 11
        virtual void setPosition(double, double, double) = 0;// 12
        virtual void x() = 0;// 13
        virtual void y() = 0;// 14
        virtual void z() = 0;// 15
        virtual void setSize(double, double, double) = 0;// 16
        virtual void setSize(double) = 0;// 17
        virtual void setRotateZ(double) = 0;// 18
        virtual void zRotation() = 0;// 19
        virtual void modelInfo() = 0;// 20
    };
}