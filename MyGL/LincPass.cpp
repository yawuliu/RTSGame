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
        __int64 v2;
        CGL *v3;
        if (!this->validate()) {
            v2 = this->scene()->render();
            v3 = (CGL *) (*(__int64 (__fastcall **)(__int64)) (*(_QWORD *) v2 + 72LL))(v2);
            v3->errorCtrl()->fail("Linc frame shader is not loaded");
        } else {
            this->filter->exec();
        }
    }

    void LincPass::setShader(IShader *shader) {
        __int64 v7;
        CGL *v8;

        this->filter->setShader(shader);
        if (this->filter->shader()) {
            this->filter->setInput("mainPass", this->frame);
            this->filter->setInput("depthBuffer", this->depth);
            this->filter->setInput("glowPass", this->glow);
            this->filter->setInput("bloomPass", this->bloom);
        } else {
            v7 = this->scene()->render();
            v8 = (CGL *) (*(__int64 (__fastcall **)(__int64)) (*(_QWORD *) v7 + 72LL))(v7);
            v8->errorCtrl()->warning(0LL, "Linc frame shader is not loaded");
        }
    }

    IRenderPass::Pass::Type LincPass::type() {
        return 6;
    }

    bool LincPass::validate() {
        return this->filter->shader() != 0LL;
    }
}