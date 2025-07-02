#include "SmallLightsPass.h"
#include "ISceneGraph.h"

namespace MyGL {
    SmallLightsPass::SmallLightsPass(IScene &s, const Adapter &a3) : AbstractPass(s) {}

    void SmallLightsPass::exec() {
        this->scene().render()->begin();
        ISceneGraph::Visibles obj(this->scene().graph());
        for (int i = 0;; ++i) {
            if (obj.size() <= i)
                break;
            this->drawObject(obj[i]);
        }
        this->scene().render()->end();
    }

    IRenderPass::Pass::Type SmallLightsPass::type() {
        return IRenderPass::Pass::SmallLights;
    }
}