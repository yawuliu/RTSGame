#include "ColorPass.h"
#include "IScene.h"
#include "AbstractPass.h"
#include "ISceneGraph.h"

namespace MyGL {
    ColorPass::ColorPass(IScene &s) : AbstractPass(s) {

    }


    void ColorPass::exec() {
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

    bool ColorPass::isDrawable(IGraphicsObject &obj) {
        if (obj.visible() != 1)
            return 0;
        return obj.material()->renderState()->isBlend() == 0;
    }

    IRenderPass::Pass::Type ColorPass::type() {
        return IRenderPass::Pass::Color;
    }

}