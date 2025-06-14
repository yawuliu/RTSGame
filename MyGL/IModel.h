#pragma once

#include <MyGL/IVBO.h>
#include <MyGL/IModelInfo.h>
#include <MyGL/IRender.h>

namespace MyGL {
    class IModel {
    public:
        virtual IVBO::PrimitiveType primitiveType() = 0;

        virtual IModelInfo *cullInfo() = 0;

        virtual void setPrimitivesType(IVBO::PrimitiveType) = 0;

        virtual void allocate(size_t) = 0;

 
    };
}


