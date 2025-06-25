#pragma once

#include <cstdint>
#include "IGraphicsObject.h"

namespace MyGL {
    class IMaterial {
    public:
        IMaterial() = default;

        virtual ~IMaterial() = default;// 0
        // virtual  ~IMaterial() = 0;// 1
        virtual void bind() = 0;// 2
        virtual void setUniforms(void) = 0;// 3
        virtual void uBind(void) = 0;// 4
        virtual void technique() = 0;// 5
        // virtual void technique() = 0;// 6
        virtual void operator<(IMaterial const &) = 0;// 7
        virtual void operator>(IMaterial const &) = 0;// 8
        virtual void getTexture(uint32_t) = 0;// 9
        virtual void renderState() = 0;// 10
        //  virtual void renderState() = 0;// 11
        virtual void drawEvent(IGraphicsObject const &) = 0;// 12
    };
}