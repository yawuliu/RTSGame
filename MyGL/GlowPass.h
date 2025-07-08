#pragma once

#include "AbstractPass.h"
#include "IScene.h"

namespace MyGL {
    class ITextureRectangle;

    class FBO;

    class BloomPass;

    class SmallLightsPass;

    class GlowPass : public AbstractPass {
    public:
        class Data {
        public:
            explicit Data(IScene &a2) = default;

        public:
            BloomPass *blur;
            SmallLightsPass *lights;
        };

    public:
        GlowPass(IScene &s, Adapter &adapter, ITextureRectangle *depth);

        ~GlowPass() override;

        void exec() override;

        IRenderPass::Pass::Type type() override;

        bool validate();

        bool isDrawable(IGraphicsObject &obj);

        void resizeFrame();

        void initShaders(const Adapter &adapter);

        void draw();

        void postProcess(int a2, int a3, int a4, int a5);

        ITextureRectangle *output();


    protected:
        ITextureRectangle *frame;
        ITextureRectangle *depthBuf;
        FBO *frameBuffer;
        GlowPass::Data *data;
        bool used;
        int fakeLv;
    };

}