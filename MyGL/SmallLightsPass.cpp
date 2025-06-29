#include "SmallLightsPass.h"

namespace MyGL {
    SmallLightsPass::SmallLightsPass(const IScene &s, const Adapter &a3) : AbstractPass(s) {}

    void SmallLightsPass::exec() {
        v2 = this->scene()->render();
        (*(void (__fastcall **)(__int64)) (*(_QWORD *) v2 + 296LL))(v2);
        ISceneGraph::Visibles objVisibles(this->scene()->graph());
        for (int i = 0;; ++i) {
            if (obj.size() <= i)
                break;
            this->drawObject(obj[i]);
        }
        v8 = this->scene()->render();
        (*(void (__fastcall **)(__int64)) (*(_QWORD *) v8 + 312LL))(v8);
    }

    IRenderPass::Pass::Type SmallLightsPass::type() {
        return IRenderPass::Pass::SmallLights;
    }
}