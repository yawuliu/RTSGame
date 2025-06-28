#pragma once

#include <cstdint>
#include "IGraphicsObject.h"

namespace MyGL {
    class ITexture;

    class ITechnique;

    class IRenderState;

    class IMaterial {
    public:
        IMaterial() = default;

        virtual ~IMaterial() = default;// 0
        // virtual  ~IMaterial() = 0;// 1
        virtual void bind() = 0;// 2
        virtual void setUniforms() = 0;// 3
        virtual void uBind() = 0;// 4
        virtual ITechnique *technique() const = 0;// 5
        // virtual ITechnique* technique() = 0;// 6
        virtual bool operator<(IMaterial const &) = 0;// 7
        virtual bool operator>(IMaterial const &) = 0;// 8
        virtual const ITexture *getTexture(uint32_t) const = 0;// 9
        virtual const IRenderState *renderState() = 0;// 10
        //  virtual const IRenderState *  renderState() = 0;// 11
        virtual bool drawEvent(IGraphicsObject const &) = 0;// 12
    };
}