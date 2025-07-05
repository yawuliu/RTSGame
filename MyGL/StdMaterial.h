#pragma once

#include <string>
#include "AbstractMaterial.h"
#include "IRenderState.h"

namespace MyGL {
    class IShader;

    class StdTechnique;

    class IUniformSampler;

    class ITexture2d;

    class StdMaterial : public AbstractMaterial {
    public:
        StdMaterial(IScene &s, StdTechnique *technique);

        virtual ~StdMaterial();

        virtual void bind() override;

        virtual void setUniforms() override;

        virtual void uBind() override;

        virtual ITechnique *technique() override;

        virtual const ITexture *getTexture(uint32_t id) override;

        virtual const IRenderState *renderState() override;

        virtual bool drawEvent(IGraphicsObject const &obj) override;

        void bindTextures();

        bool checkSampler(IUniformSampler *s);

        static const std::string &name();

        void setDepthShader(IShader *sh);

        void setDiffuseTexture(ITexture2d *t);

        void setGlowShader(IShader *sh);

        void setGlowTexture(ITexture2d *sh);

        void setNormalTexture(ITexture2d *sh);

        void setShader(IShader *sh);

        void setShadowShader(IShader *sh);

        void setShadowTexture(ITexture2d *sh);

        void setSpecularTexture(ITexture2d *sh);

        void useCullFace(bool use, IRenderState::CullMode::Type t);

        void useDepthPass(bool use);

        void useGlow(bool use);

        bool useMainTextures();

    protected:
        ITexture2d *diff;
        ITexture2d *shadowMap;
        ITexture2d *glow;
        ITexture2d *spec;
        ITexture2d *normal;
        StdTechnique *mtechnique;
        IShader *curShader;
    };


}

