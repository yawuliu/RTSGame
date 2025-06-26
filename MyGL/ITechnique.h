#pragma once

#include "IGraphicsObject.h"
#include "IMaterial.h"

namespace MyGL {
    class AddBlendPass;

    class IRenderPass;

    class ColorPass;

    class ShadowPass;

    class TransparentPass;

    class DepthPass;

    class GlowPass;

    class ITechnique {
    public:
        ITechnique() = default;

        virtual ~ITechnique() = default; // 0

        //virtual ~ITechnique()= default; // 1
        virtual void bind() = 0; // 2

        virtual void setUniforms() = 0; // 3

        virtual void uBind() = 0; // 4

        virtual void currentShader() = 0; // 5

        virtual void cmpShader() = 0; // 6

        virtual void renderState() = 0; // 7

        // virtual void renderState() = 0; // 8

        virtual void drawEvent(IGraphicsObject const &, IMaterial const &) = 0; // 9

        virtual void passEvent(IRenderPass const *) = 0; // 10

        virtual void completeDraw(IRenderPass const *) = 0;// 11

        virtual void passEvent(AddBlendPass const *) = 0;// 12

        virtual void completeDraw(AddBlendPass const *) = 0;// 13

        virtual void passEvent(ColorPass const *) = 0;// 14

        virtual void completeDraw(ColorPass const *) = 0;// 15

        virtual void passEvent(ShadowPass const *) = 0;// 16

        virtual void completeDraw(ShadowPass const *) = 0;// 17

        virtual void passEvent(TransparentPass const *) = 0;// 18

        virtual void completeDraw(TransparentPass const *) = 0;// 19

        virtual void passEvent(DepthPass const *) = 0;// 20

        virtual void completeDraw(DepthPass const *) = 0;// 21

        virtual void passEvent(GlowPass const *) = 0;// 22

        virtual void completeDraw(GlowPass const *) = 0;// 23
    };
}