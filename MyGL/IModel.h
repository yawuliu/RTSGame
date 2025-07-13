#pragma once

#include "IVBO.h"
#include "IModelInfo.h"
#include "IOModel.h"
#include "IIOModel.h"

namespace MyGL {
    class IModel : public IOModel {
    public:
        IModel() = default;

        virtual  ~IModel() = default;// 0
        //virtual  ~IModel() = default;// 1
        virtual void bind() = 0;// 2
        virtual void uBind() = 0;// 3
        virtual void setPrimitivesType(IVBO::PrimitiveType::Type) = 0;// 4
        virtual IVBO::PrimitiveType::Type primitiveType() = 0;// 5
        virtual void draw(bool) = 0;// 6
        virtual void drawInstance(int, int *, int *, bool) = 0;// 7
        virtual void load(IIOModel &) = 0;// 8
        virtual void free() = 0;// 9
        virtual IModelInfo *cullInfo() = 0;// 10
    };
}


