#pragma once

#include "IRenderState.h"
#include "RenderState.h"
#include "AbstractTechnique.h"

namespace MyGL {
    class IUniformMatrix4x4;

    class AddBlendPass;

    class ColorPass;

    class DepthPass;

    class GlowPass;

    class ShadowPass;

    class TransparentPass;

    class IScene;

    class IUniformSampler;

    class IShader;

    class IUniform4f;

    class StdTechnique : public AbstractTechnique {
    public:
        StdTechnique(IScene &s);

        virtual ~StdTechnique();

        void bind();

        const IShader *cmpShader();

        IShader *colorShader();

        void completeDraw(AddBlendPass const *a2);

        void completeDraw(ColorPass const *a2) override;

        void completeDraw(DepthPass const *a2);

        void completeDraw(GlowPass const *a2);

        void completeDraw(ShadowPass const *a2);

        void completeDraw(TransparentPass const *a2);

        const IShader *currentShader();

        IShader *depthShader();

        IUniformSampler *diffSampler();

        bool drawEvent(IGraphicsObject &obj, IMaterial &a3);

        IUniformSampler *glowSampler();

        IShader *glowShader();

        IUniformSampler *normalMapSampler();

        IUniformSampler *opacitySampler_toSM();

        bool passEvent(AddBlendPass const *a2);

        bool passEvent(ColorPass const *a2);

        bool passEvent(DepthPass const *a2);

        bool passEvent(GlowPass const *a2);

        bool passEvent(ShadowPass const *a2);

        bool passEvent(TransparentPass const *pass);

        IRenderState *renderState();

        void restoreRenderState();

        void setColorShader(IShader *sh);

        void setCurrentShader(IShader *s);

        void setDepthShader(IShader *sh);

        void setGlowShader(IShader *sh);

        void setShadowShader(IShader *sh);

        void setUniforms();

        IUniformSampler *shadowSampler();

        IShader *shadowShader();

        IUniformSampler *specularSampler();

        void storeRenderState();

        void uBind();

        void useCullFace(bool use);

        void useCullFace(bool use, IRenderState::CullMode::Type t);

        void useDepthPass(bool use);

        bool useDepthPass();

        void useGlow(bool use);

    public:
        IRenderState *rstate;
        IRenderState *pstate;
        bool blendFactor;
        bool useDepth;
        bool useGlowM;
        bool useCull;
        //        00000024     // padding byte
        //        00000025     // padding byte
        //        00000026     // padding byte
        //        00000027     // padding byte
        IShader *sh;
        IShader *mshader;
        IShader *shadow;
        IShader *depth;
        IShader *glow;
        IUniformSampler *mdiffSampler;
        IUniformSampler *mshadowSampler;
        IUniformSampler *mspecSampler;
        IUniformSampler *gglowSampler;
        IUniformSampler *normalSampler;
        IUniformSampler *opacitySampler;
        IUniformMatrix4x4 *lMat;
        bool updateMat;
        //        00000089     // padding byte
        //        0000008A     // padding byte
        //        0000008B     // padding byte
        //        0000008C     // padding byte
        //        0000008D     // padding byte
        //        0000008E     // padding byte
        //        0000008F     // padding byte
        IUniform4f *lDir;
        ObjectMatrix lMatrix;
    };
}


