#pragma once

#include "IScene.h"
#include "ITechnique.h"

namespace MyGL {
    class IMaterial;

    class AddBlendPass;

    class ColorPass;

    class DepthPass;

    class GlowPass;

    class IRenderPass;

    class ShadowPass;

    class TransparentPass;

    class AbstractTechnique : public ITechnique {
    public:
        AbstractTechnique(IScene &s);

        virtual ~AbstractTechnique() = default; // 0

        //virtual ~AbstractTechnique()= default; // 1
        virtual void bind(); // 2

        virtual void setUniforms(); // 3

        virtual void uBind(); // 4

        virtual void currentShader(); // 5

        virtual void cmpShader(); // 6

        virtual void renderState(); // 7

        // virtual void renderState(); // 8

        virtual void drawEvent(IGraphicsObject const &, IMaterial const &); // 9

        virtual void passEvent(IRenderPass const *); // 10

        virtual void completeDraw(IRenderPass const *);// 11

        virtual void passEvent(AddBlendPass const *);// 12

        virtual void completeDraw(AddBlendPass const *);// 13

        virtual void passEvent(ColorPass const *);// 14

        virtual void completeDraw(ColorPass const *);// 15

        virtual void passEvent(ShadowPass const *);// 16

        virtual void completeDraw(ShadowPass const *);// 17

        virtual void passEvent(TransparentPass const *);// 18

        virtual void completeDraw(TransparentPass const *);// 19

        virtual void passEvent(DepthPass const *);// 20

        virtual void completeDraw(DepthPass const *);// 21

        virtual void passEvent(GlowPass const *);// 22

        virtual void completeDraw(GlowPass const *);// 23

    protected:
        IScene &mscene;
    };

}
