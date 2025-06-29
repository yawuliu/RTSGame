#include "LincPass.h"
#include "IModel.h"

namespace MyGL {
    LincPass::LincPass(IScene &s, const Adapter &adapter, IModel *quad,
                       ITextureRectangle &f, ITextureRectangle &g,
                       ITextureRectangle &b, ITextureRectangle &d) : AbstractPass(s) {

        this->frame = f;
        this->glow = g;
        this->bloom = b;
        this->depth = d;
        this->filter = new Filter(this->scene());
        this->filter->setQuadModel(quad);
        this->setShader(adapter->getLincShader());
    }

    LincPass::~LincPass() {
        if (this->filter)
            delete this->filter;
    }

    void LincPass::exec() {
        if (!this->validate()) {
            this->scene()->render()->gl()->errorCtrl()->fail("Linc frame shader is not loaded");
        } else {
            this->filter->exec();
        }
    }

    void LincPass::setShader(IShader *shader) {
        this->filter->setShader(shader);
        if (this->filter->shader()) {
            this->filter->setInput("mainPass", this->frame);
            this->filter->setInput("depthBuffer", this->depth);
            this->filter->setInput("glowPass", this->glow);
            this->filter->setInput("bloomPass", this->bloom);
        } else {
            this->scene()->render()->gl()->errorCtrl()->warning(0LL, "Linc frame shader is not loaded");
        }
    }

    IRenderPass::Pass::Type LincPass::type() {
        return IRenderPass::Pass::Linc;
    }

    bool LincPass::validate() {
        return this->filter->shader() != 0LL;
    }
}