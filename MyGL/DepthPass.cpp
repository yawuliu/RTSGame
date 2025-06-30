#include "DepthPass.h"
#include "ISceneGraph.h"
#include "IRenderState.h"

namespace MyGL {
    DepthPass::DepthPass(IScene &s) : AbstractPass(s) {

    }

    void DepthPass::exec() {
        ISceneGraph::Visibles obj(this->scene()->graph());
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

    IRenderPass::Pass::Type DepthPass::type() {
        return IRenderPass::Pass::Depth;
    }

    bool DepthPass::isDrawable(IGraphicsObject &obj) {
        if (obj.visible() != 1)
            return false;;
        return obj.material()->renderState()->isBlend() == 0;
    }

}