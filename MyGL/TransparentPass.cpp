#include "TransparentPass.h"
#include "ISceneGraph.h"
#include "IScene.h"
#include "IRender.h"
#include "IRenderState.h"

namespace MyGL {
    TransparentPass::TransparentPass(IScene &s) : AbstractPass(s) {}

    void TransparentPass::exec() {
        this->scene().render()->begin();
        this->depthP = 1;
        ISceneGraph::Visibles obj(this->scene().graph());
        for (int i = 0;; ++i) {
            if (obj.size() <= i)
                break;
            if (this->isDrawable(obj[i])) {
                this->drawObject(obj[i]);
            }
        }
        this->depthP = 0;
        for (int i_0 = 0;; ++i_0) {
            if (obj.size() <= i_0)
                break;
            if (this->isDrawable(obj[i_0])) {
                this->drawObject(obj[i_0]);
            }
        }
        this->scene().render()->end();
    }

    bool TransparentPass::isColorPass() {
        return !this->depthP;
    }

    bool TransparentPass::isDepthPass() {
        return this->depthP;
    }

    bool TransparentPass::isDrawable(IGraphicsObject &obj) {
        if (obj.visible() != 1)
            return 0;
        if (obj.material()->renderState()->isBlend() != 1)
            return 0;
        if (obj.material()->renderState()->getBlendSFactor() != 4)
            return 0;
        return obj.material()->renderState()->getBlendDFactor() == 5;
    }

    IRenderPass::Pass::Type TransparentPass::type() {
        return IRenderPass::Pass::Transparent;
    }
}