#pragma once

#include "DisableCopy.h"
#include "ObjectMatrix.h"

namespace MyGL {
    class IModel;

    class IModelInfo;

    class IMaterial;

    class IGraphicsObject : public DisableCopy {
    public:
        IGraphicsObject() = default;

        virtual  ~IGraphicsObject() = default;// 0
        //virtual void ~GraphicsObject() = 0;// 1
        virtual void setMaterial(IMaterial *) = 0;// 2
        virtual IMaterial *material() = 0;// 3
        virtual void setMatrix(ObjectMatrix &) = 0;// 4
        virtual const ObjectMatrix *objectMatrix() = 0;// 5
        virtual void setModel(IModel *) = 0;// 6
        virtual IModel *model() = 0;// 7
        virtual void setVisible(bool) = 0;// 8
        virtual bool visible() = 0;// 9
        virtual void setAlvaysVisible(bool) = 0;// 10
        virtual bool isAlvaysVisible() = 0;// 11
        virtual void setPosition(Float, Float, Float) = 0;// 12
        virtual Float x() = 0;// 13
        virtual Float y() = 0;// 14
        virtual Float z() = 0;// 15
        virtual void setSize(Float, Float, Float) = 0;// 16
        virtual void setSize(Float) = 0;// 17
        virtual void setRotateZ(Float) = 0;// 18
        virtual Float zRotation() = 0;// 19
        virtual const IModelInfo *modelInfo() = 0;// 20
    };
}