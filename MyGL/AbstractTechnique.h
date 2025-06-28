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
        virtual void bind() override; // 2

        virtual void setUniforms() override; // 3

        virtual void uBind() override; // 4

        virtual const IShader *currentShader() override; // 5

        virtual const IShader *cmpShader() const override; // 6

        virtual const IRenderState *renderState() override; // 7

        // virtual void renderState(); // 8

        virtual bool drawEvent(IGraphicsObject const &, IMaterial const &) override; // 9

        virtual bool passEvent(IRenderPass const *) override; // 10

        virtual void completeDraw(IRenderPass const *) override;// 11

        virtual bool passEvent(AddBlendPass const *) override;// 12

        virtual void completeDraw(AddBlendPass const *) override;// 13

        virtual bool passEvent(ColorPass const *) override;// 14

        virtual void completeDraw(ColorPass const *) override;// 15

        virtual bool passEvent(ShadowPass const *) override;// 16

        virtual void completeDraw(ShadowPass const *) override;// 17

        virtual bool passEvent(TransparentPass const *) override;// 18

        virtual void completeDraw(TransparentPass const *) override;// 19

        virtual bool passEvent(DepthPass const *) override;// 20

        virtual void completeDraw(DepthPass const *) override;// 21

        virtual bool passEvent(GlowPass const *) override;// 22

        virtual void completeDraw(GlowPass const *) override;// 23

        IRender *render();

        IScene &scene();

    protected:
        IScene &mscene;
    };

}
