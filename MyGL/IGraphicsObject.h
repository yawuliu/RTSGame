#pragma once

#include "DisableCopy.h"
#include "IModelInfo.h"

namespace MyGL {
    class IGraphicsObject : public DisableCopy {
    public:
        IGraphicsObject() = default;

        virtual ~IGraphicsObject() = default;

        virtual bool isAlvaysVisible() const = 0;

        virtual IModelInfo& modelInfo() const = 0;

        virtual void delObjectEvent(IGraphicsObject &) = 0;

        virtual void addObjectEvent(IGraphicsObject &) = 0;

        virtual float x() const = 0;

        virtual float y() const = 0;

        virtual float z() const = 0;

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