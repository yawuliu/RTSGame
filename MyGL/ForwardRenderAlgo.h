#pragma once

#include <vector>
#include "IScene.h"
#include "IRenderAlgo.h"
#include "Adapter.h"
#include "IRenderPass.h.h"


namespace MyGL {
    class IRenderAlgoSettings;

    class IModel;

    class MainPass;

    class GlowPass;

    class BloomPass;

    class LincPass;

    class ShadowPass;

    class VolumetricLightScatteringPass;

    class ForwardRenderAlgo : public IRenderAlgo {
    public:
        ForwardRenderAlgo(IScene &s, const Adapter &adapter, bool autoMake);

        virtual ~ForwardRenderAlgo();//0
        //1
        virtual void exec();//2
        virtual IRenderPass::Pass::Type type();//3
        virtual IRenderAlgoSettings *settings(); // 4
        //5
        virtual void recreateAlgo(const Adapter &adapter); //6
        virtual MainPass *allockMainPass(const Adapter &adapter);//7

        void buildQuad(int w, int h);


        void freeAlgo();

        bool isBloom();

        bool isShadowPass();

        void makeAlgo(const Adapter &adapter);


        IScene *scene();

        void setBloom(bool use);

        void setPoint(float *p, float x, float y);

        void setShadowPass(bool use);


    protected:
        MainPass *mainPass;
        GlowPass *glowPass;
        BloomPass *bloomPass;
        LincPass *lincPass;
        ShadowPass *shadowPass;
        VolumetricLightScatteringPass *vlsPass;
        IModel *quad;
        IScene &mscene;
        IRenderAlgoSettings *m_settings;
        std::vector<IRenderPass *> passes;
        bool m_isBloom;
        bool m_shadow;
        // padding byte
        //0000006B     // padding byte
        //0000006C     // padding byte
        //0000006D     // padding byte
        //0000006E     // padding byte
        //0000006F     // padding byte
    };
}
