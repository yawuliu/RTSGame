#pragma once

#include "MyGL/IModelInfo.h"

namespace MyGL {
    class IGraphicsObject {
    public:
        virtual bool isAlvaysVisible() const = 0;

        virtual IModelInfo *modelInfo() const = 0;

        virtual void delObjectEvent(IGraphicsObject *) = 0;

        virtual void addObjectEvent(IGraphicsObject *) = 0;

        virtual double x() const = 0;

        virtual double y() const = 0;

        virtual float xSize() const = 0;

        virtual float ySize() const = 0;

        virtual float zSize() const = 0;

        virtual void setRotateX(float) = 0;

        virtual void setRotateY(float) = 0;

        virtual void setRotateZ(float) = 0;

        virtual float xRotation() = 0;

        virtual float yRotation() = 0;

        virtual float zRotation() = 0;
    };
}