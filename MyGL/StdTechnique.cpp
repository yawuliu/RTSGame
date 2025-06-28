#include "StdTechnique.h"

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
        this->rstate->setAlphaTestMode(1LL);
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

    IUniformSampler *StdTechnique::diffSampler(StdTechnique &mtechnique) {
        return mtechnique->mdiffSampler;
    }

    bool StdTechnique::drawEvent(const IGraphicsObject &obj, const IMaterial &a3) {
        bool v3;
        IRender *v4;
        IRender *v5;
        const void *other;
        ObjectMatrix m;

        if (!this->updateMat)
            return 1;
        this->updateMat = 0;
        ObjectMatrix::ObjectMatrix(&m);
        this->lMatrix.identity();
        v4 = this->render();
        v4->getProjectionMatrix(&m);
        this->lMatrix.mul(&m);
        v5 = this->render();
        v5->getModeViewlMatrix(&m);
        this->lMatrix.mul(&m);
        other = obj->objectMatrix();
        this->lMatrix.mul(other);
        v3 = this->sh != 0LL;

        return v3;
    }

    IUniformSampler *StdTechnique::glowSampler(StdTechnique &mtechnique) {
        return mtechnique->gglowSampler;
    }

    IShader *StdTechnique::glowShader() {
        return this->glow;
    }

    IUniformSampler *StdTechnique::normalMapSampler(StdTechnique &mtechnique) {
        return mtechnique->normalSampler;
    }

    IUniformSampler *StdTechnique::opacitySampler_toSM(StdTechnique &mtechnique) {
        return mtechnique->opacitySampler;
    }

    bool StdTechnique::passEvent(const AddBlendPass *a2) {
        this->sh = this->mshader;
        if (this->sh) {
            this->storeRenderState();
            this->rstate->setZTest(1LL);
            this->rstate->setZWriting(0LL);
            this->rstate->setZTestMode(2LL);
        }
        return this->sh != 0LL;
    }

    bool StdTechnique::passEvent(const ColorPass *a2) {
        IShader *s;
        __int64 v3;
        __int64 v4;
        __int64 v5;

        this->storeRenderState();
        s = this->colorShader();
        this->setCurrentShader(s);
        v3 = this->renderState();
        (*(void (__fastcall **)(__int64, __int64)) (*(_QWORD *) v3 + 96LL))(v3, 1LL);
        if (this->useDepthPass()) {
            v4 = this->renderState();
            (*(void (__fastcall **)(__int64, __int64)) (*(_QWORD *) v4 + 128LL))(v4, 6LL);
        } else {
            v5 = this->renderState();
            (*(void (__fastcall **)(__int64, __int64)) (*(_QWORD *) v5 + 128LL))(v5, 2LL);
        }
        return this->currentShader() != 0;
    }

    bool StdTechnique::passEvent(const DepthPass *a2) {
        if (!this->useDepth)
            return 0;
        this->storeRenderState();
        this->sh = this->depth;
        this->rstate->setZTest(1LL);
        this->rstate->setZTestMode(2LL);
        this->rstate->setColorMask(
                0LL,
                0LL,
                0LL,
                0LL);
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
            this->rstate->setZTestMode(3LL);
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
            this->rstate->setZTestMode(2LL);
            this->rstate->setColorMask(
                    1LL,
                    1LL,
                    1LL,
                    1LL);
            this->rstate->setBlend(0LL);
            if (this->rstate->cullFaceMode() == 2) {
                this->rstate->setCullFaceMode(1LL);
            } else if (this->rstate->cullFaceMode() == 1) {
                this->rstate->setCullFaceMode(2LL);
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
            this->rstate->setZTestMode(2LL);

            this->rstate->setColorMask(0LL, 0LL, 0LL, 0LL);
            this->rstate->setBlend(0LL);
        }
        if (pass->isColorPass()) {
            this->sh = this->mshader;
            this->rstate->setZTest(1LL);
            this->rstate->setZTestMode(6LL);
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

    void StdTechnique::setColorShader(StdTechnique &mtechnique, IShader *sh) {
        mtechnique->mshader = sh;
        if (mtechnique->mshader) {
            mtechnique->mdiffSampler = mtechnique->mshader->uniformSampler("diffuse_texture");
            mtechnique->mshadowSampler = mtechnique->mshader->uniformSampler("shadow_map_texture");
            mtechnique->mspecSampler = mtechnique->mshader->uniformSampler("specular_texture");
            mtechnique->normalSampler = mtechnique->mshader->uniformSampler("normal_map_texture");
            if (mtechnique->mdiffSampler)
                mtechnique->mdiffSampler->set(0LL);
            if (mtechnique->mshadowSampler)
                mtechnique->mshadowSampler->set(1LL);
            if (mtechnique->mspecSampler)
                mtechnique->mspecSampler->set(2LL);
            if (mtechnique->normalSampler)
                mtechnique->normalSampler->set(3LL);
            mtechnique->lMat = mtechnique->mshader->uniformMatrix4x4("lMatrix");
            mtechnique->lDir = mtechnique->mshader->uniform4f("lDirection");
        } else {
            mtechnique->mdiffSampler = 0LL;
            mtechnique->mshadowSampler = 0LL;
            mtechnique->mspecSampler = 0LL;
            mtechnique->normalSampler = 0LL;
            mtechnique->lMat = 0LL;
            mtechnique->lDir = 0LL;
        }
    }

    void StdTechnique::setCurrentShader(IShader *s) {
        this->sh = s;
    }

    void StdTechnique::setDepthShader(StdTechnique &mtechnique, IShader *sh) {
        mtechnique->depth = sh;
    }

    void StdTechnique::setGlowShader(StdTechnique &mtechnique, IShader *sh) {
        mtechnique->glow = sh;
        if (mtechnique->glow) {
            mtechnique->gglowSampler = mtechnique->glow->uniformSampler("glow_texture");
            if (mtechnique->gglowSampler)
                mtechnique->gglowSampler->set(0LL);
        } else {
            mtechnique->gglowSampler = 0LL;
        }
    }

    void StdTechnique::setShadowShader(StdTechnique &mtechnique, IShader *sh) {
        mtechnique->shadow = sh;
        if (mtechnique->shadow)
            mtechnique->opacitySampler = mtechnique->shadow->uniformSampler("opacity");
        else
            mtechnique->opacitySampler = 0LL;
    }

    void StdTechnique::setUniforms() {
        void (__fastcall *v1)(IUniformMatrix4x4 *, const Float *);
        const Float *v2;
        IScene *v3;
        __int64 v4;
        IScene *v6;
        __int64 v7;
        __int64 v8;
        Float *l;

        if (this->mshader == this->sh) {
            if (this->lMat) {
                v2 = this->lMatrix->data();
                this->lMat->set(v2);
            }
            if (this->lDir) {
                v3 = this->scene();
                v4 = v3->lights();
                if ((*(unsigned int (__fastcall **)(__int64)) (*(_QWORD *) v4 + 40LL))(v4)) {
                    v6 = this->scene();
                    v7 = v6->lights();
                    v8 = (*(__int64 (__fastcall **)(__int64, _QWORD)) (*(_QWORD *) v7 + 48LL))(v7, 0LL);
                    l = (Float *) (*(__int64 (__fastcall **)(__int64)) (*(_QWORD *) v8 + 104LL))(v8);
                    this->lDir->set(*l, l[1], l[2], 1.0);
                }
            }
        }
    }

    IUniformSampler *StdTechnique::shadowSampler(StdTechnique &mtechnique) {
        return mtechnique->mshadowSampler;
    }

    IShader *StdTechnique::shadowShader() {
        return this->shadow;
    }

    IUniformSampler *StdTechnique::specularSampler(StdTechnique &mtechnique) {
        return mtechnique->mspecSampler;
    }

    void StdTechnique::storeRenderState() {
        this->pstate->copy(this->rstate);
    }

    void StdTechnique::uBind() {
        ;
    }

    void StdTechnique::useCullFace(StdTechnique &mtechnique, bool use) {
        StdTechnique::useCullFace(mtechnique, use, IRenderState::CullMode::Type::back);
    }

    void StdTechnique::useCullFace(StdTechnique &mtechnique, bool use, IRenderState::CullMode::Type t) {
        mtechnique->useCull = use;
        if (!mtechnique->useCull)
            mtechnique->rstate->setCullFaceMode(0LL);
        else
            mtechnique->rstate->setCullFaceMode((unsigned int) t);
    }

    void StdTechnique::useDepthPass(StdTechnique &mtechnique, bool use) {
        mtechnique->useDepth = use;
    }

    bool StdTechnique::useDepthPass() {
        return this->useDepth && this->depth;
    }

    void StdTechnique::useGlow(StdTechnique &mtechnique, bool use) {
        mtechnique->useGlowM = use;
    }
}