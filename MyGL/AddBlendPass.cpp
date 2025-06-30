#include "AddBlendPass.h"
#include "ISceneGraph.h"
#include "IRenderState.h"

namespace MyGL {
    AddBlendPass::AddBlendPass(IScene &s) : AbstractPass(s) {

    }


    void AddBlendPass::exec() {
        ISceneGraph::Visibles obj(this->scene().graph());
        this->scene().render()->begin();
        for (int i = 0;; ++i) {
            if (obj.size() <= i)
                break;
            if (this->isDrawable(obj[i])) {
                this->drawObject(obj[i]);
            }
        }
        this->scene().render()->end();
    }

    bool AddBlendPass::isDrawable(IGraphicsObject &obj) {
        if (obj.visible() != 1)
            return 0;
        if (obj.material()->renderState()->isBlend() != 1)
            return 0;
        if (obj.material()->renderState()->getBlendSFactor() != 1)
            return 0;

        return obj.material()->renderState()->getBlendDFactor() == 1;
    }

    IRenderPass::Pass::Type type() {
        return IRenderPass::Pass::AddBlend;
    }

}