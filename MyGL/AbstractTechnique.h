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
        explicit AbstractTechnique(IScene &s);

        ~AbstractTechnique() override = default; // 0

        //virtual ~AbstractTechnique()= default; // 1
        virtual void bind() override = 0; // 2

        virtual void setUniforms() override = 0; // 3

        virtual void uBind() override = 0; // 4

        virtual const IShader *currentShader() override = 0; // 5

        virtual const IShader *cmpShader() const override = 0; // 6

        virtual const IRenderState *renderState() override = 0; // 7

        // virtual void renderState(); // 8

        virtual bool drawEvent(IGraphicsObject &, IMaterial &) override; // 9

        virtual bool passEvent(IRenderPass const *) override; // 10

        virtual void completeDraw(IRenderPass const *) override;// 11

        bool passEvent(AddBlendPass const *) override;// 12

        void completeDraw(AddBlendPass const *) override;// 13

        bool passEvent(ColorPass const *) override;// 14

        void completeDraw(ColorPass const *) override;// 15

        bool passEvent(ShadowPass const *) override;// 16

        void completeDraw(ShadowPass const *) override;// 17

        bool passEvent(TransparentPass const *) override;// 18

        void completeDraw(TransparentPass const *) override;// 19

        bool passEvent(DepthPass const *) override;// 20

        void completeDraw(DepthPass const *) override;// 21

        bool passEvent(GlowPass const *) override;// 22

        void completeDraw(GlowPass const *) override;// 23

        IRender *render();

        IScene &scene();

    protected:
        IScene &mscene;
    };

}
