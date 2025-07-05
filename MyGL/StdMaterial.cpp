#include "StdMaterial.h"
#include "StdTechnique.h"
#include "IRenderState.h"
#include "IUniformSampler.h"

namespace MyGL {
    StdMaterial::StdMaterial(IScene &s, StdTechnique *technique) : AbstractMaterial(s) {
        this->diff = nullptr;
        if (technique) {
            this->mtechnique = technique;
        } else {
            this->mtechnique = new StdTechnique(s);
        }
        this->setShader(nullptr);
        this->setShadowShader(nullptr);
        this->setDiffuseTexture(nullptr);
        this->setShadowTexture(nullptr);
        this->setSpecularTexture(nullptr);
        this->setGlowTexture(nullptr);
        this->setNormalTexture(nullptr);
        this->curShader = nullptr;
    }

    StdMaterial::~StdMaterial() {
        if (this->mtechnique)
            delete this->mtechnique;
    }

    void StdMaterial::bind() {
        this->technique()->bind();
        this->technique()->setUniforms();
        if (this->curShader != const_cast<IShader *>(this->technique()->currentShader()))
            this->bindTextures();
        this->curShader = const_cast<IShader *>(this->technique()->currentShader());
        this->render()->setRenderState(const_cast<IRenderState *>(this->renderState()));
    }

    void StdMaterial::bindTextures() {
        if (!this->useMainTextures()) {
            if (this->technique()->currentShader()
                && this->mtechnique->glowSampler()
                && this->technique()->currentShader() == this->mtechnique->glowSampler()->owner()
                && this->glow) {
                this->render()->bindTexture(this->mtechnique->glowSampler(), this->glow);
            } else {
                if (this->technique()->currentShader()) {
                    if (this->mtechnique->opacitySampler_toSM()) {
                        if (this->technique()->currentShader() == this->mtechnique->opacitySampler_toSM()->owner()) {
                            if (this->diff) {
                                this->render()->bindTexture(this->mtechnique->opacitySampler_toSM(), this->diff);
                            }
                        }
                    }
                }
            }
        }
    }

    bool StdMaterial::checkSampler(IUniformSampler *s) {
        if (this->technique()->currentShader()) {
            if (s) {
                if (this->technique()->currentShader() == s->owner())
                    return true;
            }
        }
        return false;
    }

    bool StdMaterial::drawEvent(const IGraphicsObject &obj) {
        return this->technique()->drawEvent(obj, *this);
    }

    const ITexture *StdMaterial::getTexture(uint32_t id) {
        if (id)
            return nullptr;
        else
            return this->diff;
    }

    const std::string &StdMaterial::name() {
        return "FFPMaterial";
    }
}