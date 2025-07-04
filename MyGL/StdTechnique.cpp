#include "StdTechnique.h"
#include "IShader.h"
#include "IUniformSampler.h"
#include "IUniform4f.h"
#include "ILightsCollection.h"
#include "TransparentPass.h"

namespace MyGL {
    StdTechnique::StdTechnique(IScene &s) : AbstractTechnique(s) {
        this->setColorShader(0LL);
        this->setShadowShader(0LL);
        this->setDepthShader(0LL);
        this->setGlowShader(0LL);
        this->opacitySampler = 0LL;
        this->rstate = new RenderState();
        this->pstate = new RenderState();
        this->rstate->setAlphaTestRef(0.5);
        this->rstate->setAlphaTestMode(IRenderState::AlphaTestMode::Greater); //  1LL
        this->rstate->setAlphaCoverage(1LL);
        this->useDepthPass(1);
        this->useGlow(1);
        this->useCullFace(1);
        this->updateMat = 0;
    }

    StdTechnique::~StdTechnique() {
        if (this->rstate)
            delete this->rstate;
        if (this->pstate)
            delete this->pstate;
    }

    void StdTechnique::bind() {
        if (this->sh) {
            this->render()->useShader(this->sh);
        }
    }

    const IShader *StdTechnique::cmpShader() {
        return this->mshader;
    }

    IShader *StdTechnique::colorShader() {
        return this->mshader;
    }

    void StdTechnique::completeDraw(AddBlendPass const *a2) {
        this->restoreRenderState();
    }

    void StdTechnique::completeDraw(ColorPass const *a2) {
        this->restoreRenderState();
    }

    void StdTechnique::completeDraw(DepthPass const *a2) {
        this->restoreRenderState();
    }

    void StdTechnique::completeDraw(GlowPass const *a2) {
        this->restoreRenderState();
    }

    void StdTechnique::completeDraw(ShadowPass const *a2) {
        this->restoreRenderState();
    }

    void StdTechnique::completeDraw(TransparentPass const *a2) {
        this->restoreRenderState();
    }

    const IShader *StdTechnique::currentShader() {
        return this->sh;
    }

    IShader *StdTechnique::depthShader() {
        return this->depth;
    }

    IUniformSampler *StdTechnique::diffSampler() {
        return this->mdiffSampler;
    }

    bool StdTechnique::drawEvent(const IGraphicsObject &obj, const IMaterial &a3) {
        if (!this->updateMat)
            return 1;
        this->updateMat = 0;
        this->lMatrix.identity();
        ObjectMatrix m;
        this->render()->getProjectionMatrix(m);
        this->lMatrix.mul(m);
        this->render()->getModeViewlMatrix(m);
        this->lMatrix.mul(m);
        this->lMatrix.mul(obj.objectMatrix());
        return this->sh != 0LL;
    }

    IUniformSampler *StdTechnique::glowSampler() {
        return this->gglowSampler;
    }

    IShader *StdTechnique::glowShader() {
        return this->glow;
    }

    IUniformSampler *StdTechnique::normalMapSampler() {
        return this->normalSampler;
    }

    IUniformSampler *StdTechnique::opacitySampler_toSM() {
        return this->opacitySampler;
    }

    bool StdTechnique::passEvent(const AddBlendPass *a2) {
        this->sh = this->mshader;
        if (this->sh) {
            this->storeRenderState();
            this->rstate->setZTest(1LL);
            this->rstate->setZWriting(0LL);
            this->rstate->setZTestMode(IRenderState::ZTestMode::Less);//2LL
        }
        return this->sh != 0LL;
    }

    bool StdTechnique::passEvent(const ColorPass *a2) {
        this->storeRenderState();
        this->setCurrentShader(this->colorShader());
        this->renderState()->setZTest(1LL);
        if (this->useDepthPass()) {
            this->renderState()->setZTestMode(IRenderState::ZTestMode::Equal);// 6LL
        } else {
            this->renderState()->setZTestMode(IRenderState::ZTestMode::Less);//2LL
        }
        return this->currentShader() != 0;
    }

    bool StdTechnique::passEvent(const DepthPass *a2) {
        if (!this->useDepth)
            return 0;
        this->storeRenderState();
        this->sh = this->depth;
        this->rstate->setZTest(1LL);
        this->rstate->setZTestMode(IRenderState::ZTestMode::Less);//2LL
        this->rstate->setColorMask(0LL, 0LL, 0LL, 0LL);
        return this->sh != 0LL;
    }

    bool StdTechnique::passEvent(const GlowPass *a2) {
        if (!this->useGlowM)
            return 0;
        this->storeRenderState();
        this->sh = this->glow;
        if (this->sh) {
            this->rstate->setBlend(0LL);
            this->rstate->setZTest(1LL);
            this->rstate->setZTestMode(IRenderState::ZTestMode::LEqual);//3LL
            this->rstate->setZWriting(0LL);
        }
        return this->sh != 0LL;
    }

    bool StdTechnique::passEvent(const ShadowPass *a2) {
        this->sh = this->shadow;
        if (this->sh) {
            this->storeRenderState();
            this->updateMat = 1;
            this->rstate->setZTest(1LL);
            this->rstate->setZTestMode(IRenderState::ZTestMode::Less);//  2LL
            this->rstate->setColorMask(1LL, 1LL, 1LL, 1LL);
            this->rstate->setBlend(0LL);
            if (this->rstate->cullFaceMode() == 2) {
                this->rstate->setCullFaceMode(IRenderState::CullMode::front);// 1LL
            } else if (this->rstate->cullFaceMode() == 1) {
                this->rstate->setCullFaceMode(IRenderState::CullMode::back);// 2LL
            }
        }
        return this->sh != 0LL;
    }

    bool StdTechnique::passEvent(const TransparentPass *pass) {
        this->storeRenderState();
        if (pass->isDepthPass()) {
            this->sh = this->mshader;
            if (this->depth)
                this->sh = this->depth;
            this->rstate->setZTest(1LL);
            this->rstate->setZTestMode(IRenderState::ZTestMode::Less);// 2LL

            this->rstate->setColorMask(0LL, 0LL, 0LL, 0LL);
            this->rstate->setBlend(0LL);
        }
        if (pass->isColorPass()) {
            this->sh = this->mshader;
            this->rstate->setZTest(1LL);
            this->rstate->setZTestMode(IRenderState::ZTestMode::Equal);//6LL
            this->rstate->setColorMask(1LL, 1LL, 1LL, 1LL);
            this->rstate->setBlend(1LL);
        }
        return this->sh != 0LL;
    }

    IRenderState *StdTechnique::renderState() {
        return this->rstate;
    }

    void StdTechnique::restoreRenderState() {

        this->rstate->copy(this->pstate);
    }

    void StdTechnique::setColorShader(IShader *sh) {
        this->mshader = sh;
        if (this->mshader) {
            this->mdiffSampler = this->mshader->uniformSampler("diffuse_texture");
            this->mshadowSampler = this->mshader->uniformSampler("shadow_map_texture");
            this->mspecSampler = this->mshader->uniformSampler("specular_texture");
            this->normalSampler = this->mshader->uniformSampler("normal_map_texture");
            if (this->mdiffSampler)
                this->mdiffSampler->set(0LL);
            if (this->mshadowSampler)
                this->mshadowSampler->set(1LL);
            if (this->mspecSampler)
                this->mspecSampler->set(2LL);
            if (this->normalSampler)
                this->normalSampler->set(3LL);
            this->lMat = this->mshader->uniformMatrix4x4("lMatrix");
            this->lDir = this->mshader->uniform4f("lDirection");
        } else {
            this->mdiffSampler = 0LL;
            this->mshadowSampler = 0LL;
            this->mspecSampler = 0LL;
            this->normalSampler = 0LL;
            this->lMat = 0LL;
            this->lDir = 0LL;
        }
    }

    void StdTechnique::setCurrentShader(IShader *s) {
        this->sh = s;
    }

    void StdTechnique::setDepthShader(IShader *sh) {
        this->depth = sh;
    }

    void StdTechnique::setGlowShader(IShader *sh) {
        this->glow = sh;
        if (this->glow) {
            this->gglowSampler = this->glow->uniformSampler("glow_texture");
            if (this->gglowSampler)
                this->gglowSampler->set(0LL);
        } else {
            this->gglowSampler = 0LL;
        }
    }

    void StdTechnique::setShadowShader(IShader *sh) {
        this->shadow = sh;
        if (this->shadow)
            this->opacitySampler = this->shadow->uniformSampler("opacity");
        else
            this->opacitySampler = 0LL;
    }

    void StdTechnique::setUniforms() {
        if (this->mshader == this->sh) {
            if (this->lMat) {
                this->lMat->set(this->lMatrix.data());
            }
            if (this->lDir) {
                if (this->scene().lights()->size() > 0) {
                    Float *l = this->scene().lights()->at(0LL)->dirTransform();
                    this->lDir->set(*l, l[1], l[2], 1.0);
                }
            }
        }
    }

    IUniformSampler *StdTechnique::shadowSampler() {
        return this->mshadowSampler;
    }

    IShader *StdTechnique::shadowShader() {
        return this->shadow;
    }

    IUniformSampler *StdTechnique::specularSampler() {
        return this->mspecSampler;
    }

    void StdTechnique::storeRenderState() {
        this->pstate->copy(this->rstate);
    }

    void StdTechnique::uBind() {
        ;
    }

    void StdTechnique::useCullFace(bool use) {
        this->useCullFace(use, IRenderState::CullMode::Type::back);
    }

    void StdTechnique::useCullFace(bool use, IRenderState::CullMode::Type t) {
        this->useCull = use;
        if (!this->useCull)
            this->rstate->setCullFaceMode(IRenderState::CullMode::noCull);//0LL
        else
            this->rstate->setCullFaceMode(t);
    }

    void StdTechnique::useDepthPass(bool use) {
        this->useDepth = use;
    }

    bool StdTechnique::useDepthPass() {
        return this->useDepth && this->depth;
    }

    void StdTechnique::useGlow(bool use) {
        this->useGlowM = use;
    }
}