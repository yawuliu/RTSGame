#pragma once

#include "DisableCopy.h"

namespace MyGL {

    class IFBO : public DisableCopy {
    public:
        IFBO() = default;

        virtual ~IFBO() = default; // 0
        // virtual ~IFBO() = default; // 1
        virtual void width() = 0; // 2

        virtual void height() = 0; // 3

        virtual void hasStencil() = 0; // 4

        virtual void hasDepth() = 0; // 5

        virtual void validate() = 0; // 6

        virtual void status() = 0; // 7

        virtual void bind() = 0; // 8

        virtual void unbind() = 0; // 9

        virtual void attachColorTexture(ITexture2d *, int) = 0; // 10

        virtual void attachDepthTexture(ITexture2d *) = 0; // 11

        virtual void attachColorTexture(ITextureRectangle *, int) = 0; // 12

        virtual void attachDepthTexture(ITextureRectangle *) = 0; // 13

        virtual void detachColorTexture(int) = 0; // 14

        virtual void detachDepthTexture() = 0; // 15

        virtual void maxColorAttachemnts() = 0; // 16
    };

}
