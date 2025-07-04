#include "ForwardRenderAlgo.h"
#include "IRenderAlgoSettings.h"
#include "IModel.h"
#include "MainPass.h"
#include "GlowPass.h"
#include "BloomPass.h"
#include "LincPass.h"
#include "ShadowPass.h"

namespace MyGL {
    ForwardRenderAlgo::ForwardRenderAlgo(IScene &s, const Adapter &adapter, bool autoMake) {
        this->mscene = s;
        this->quad = new Model(this->scene()->render());
        this->buildQuad(0, 0);
        this->setBloom(1);
        this->setShadowPass(1);
        if (autoMake)
            this->makeAlgo(adapter);
        this->m_settings = new RenderAlgoSettings(this);
    }

    ForwardRenderAlgo::~ForwardRenderAlgo() {
        this->freeAlgo();
        if (this->quad)
            delete this->quad;
        if (this->m_settings)
            delete this->m_settings;
    }

    MainPass *ForwardRenderAlgo::allockMainPass(const Adapter &adapter) {
        return new MainPass(this->scene(), adapter, this->quad, 1);
    }

    void ForwardRenderAlgo::buildQuad(int w, int h) {
        IOModel m;
        m.allock(4uLL);
        IOModel::point(&retstr_, &m, 0);
        p = IIOModel::Point::data(&retstr_);
        ForwardRenderAlgo::setPoint(p, -1.0, -1.0);
        IOModel::point(&retstr__1, &m, 1);
        p_1 = IIOModel::Point::data(&retstr__1);
        ForwardRenderAlgo::setPoint(p_1, 1.0, -1.0);
        IOModel::point(&retstr__2, &m, 2);
        p_2 = IIOModel::Point::data(&retstr__2);
        ForwardRenderAlgo::setPoint(p_2, 1.0, 1.0);
        IOModel::point(&retstr__3, &m, 3);
        p_3 = IIOModel::Point::data(&retstr__3);
        ForwardRenderAlgo::setPoint(p_3, -1.0, 1.0);
        IOModel::texCoord(&retstr__4, &m, 0);
        p_4 = IIOModel::TexCoord::data(&retstr__4);
        ForwardRenderAlgo::setPoint(p_4, 0.0, 0.0);
        IOModel::texCoord(&retstr__5, &m, 1);
        p_5 = IIOModel::TexCoord::data(&retstr__5);
        ForwardRenderAlgo::setPoint(p_5, (float) w, 0.0);
        IOModel::texCoord(&retstr__6, &m, 2);
        p_6 = IIOModel::TexCoord::data(&retstr__6);
        ForwardRenderAlgo::setPoint(p_6, (float) w, (float) h);
        IOModel::texCoord(&retstr__7, &m, 3);
        p_7 = IIOModel::TexCoord::data(&retstr__7);
        ForwardRenderAlgo::setPoint(p_7, 0.0, (float) h);
        this->quad->load(&m);
        this->quad->setPrimitivesType(2LL);
    }

    void ForwardRenderAlgo::exec() {
        if (this->isShadowPass())
            this->shadowPass->exec();
        if (this->lincPass->validate())
            this->mainPass->exec();
        if (this->vlsPass)
            this->vlsPass->exec();
        if (this->bloomPass->validate() && this->isBloom())
            this->bloomPass->exec();
        if (this->glowPass->validate())
            this->glowPass->exec();
        if (this->lincPass->validate())
            this->lincPass->exec();
    }

    void ForwardRenderAlgo::freeAlgo() {
        for (size_t i = 0; i < this->passes.size(); ++i) {
            auto &v1 = this->passes[i];
            if (v1)
                delete v1;
        }
        this->passes.clear();
    }

    bool ForwardRenderAlgo::isBloom() {
        return this->m_isBloom;
    }

    bool ForwardRenderAlgo::isShadowPass() {
        return this->m_shadow;
    }

    void ForwardRenderAlgo::makeAlgo(const Adapter &adapter) {
        this->shadowPass = new ShadowPass(this->scene(), adapter);;
        this->mainPass = this->allockMainPass(adapter);
        this->vlsPass = 0LL;
        this->glowPass = new GlowPass(this->scene(), adapter, this->mainPass->depthBuffer());
        this->bloomPass = new BloomPass(this->scene(), adapter, this->mainPass->output());
        if (this->vlsPass) {
            lincPass_1 = new LincPass(this->scene(), adapter, this->quad, this->vlsPass->output(),
                                      this->glowPass->output(), this->bloomPass->output(),
                                      this->mainPass->depthBuffer());
        } else {
            lincPass_1 = new LincPass(this->scene(), adapter, this->quad, this->mainPass->output(),
                                      this->glowPass->output(), this->bloomPass->output(),
                                      this->mainPass->depthBuffer());

        }
        this->lincPass = lincPass_1;
        this->passes.push_back(this->shadowPass);
        this->passes.push_back(this->mainPass);
        if (this->vlsPass) {
            this->passes.push_back(this->vlsPass);
        }
        this->passes.push_back(this->bloomPass);
        this->passes.push_back(this->glowPass);
        this->passes.push_back(this->lincPass);
    }

    void ForwardRenderAlgo::recreateAlgo(const Adapter &adapter) {
        this->freeAlgo();
        this->makeAlgo(adapter);
    }

    IScene *ForwardRenderAlgo::scene() {
        return this->mscene;
    }

    void ForwardRenderAlgo::setBloom(bool use) {
        this->m_isBloom = use;
    }

    void ForwardRenderAlgo::setPoint(float *p, float x, float y) {
        p[0] = x;
        p[1] = y;
    }

    void ForwardRenderAlgo::setShadowPass(bool use) {
        this->m_shadow = use;
    }

    IRenderAlgoSettings *ForwardRenderAlgo::settings() {
        return this->m_settings;
    }

    IRenderPass::Pass::Type ForwardRenderAlgo::type() {
        return 0;
    }
}