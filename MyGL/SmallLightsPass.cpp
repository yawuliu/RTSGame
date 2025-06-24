#include "SmallLightsPass.h"

namespace MyGL {
    SmallLightsPass::SmallLightsPass(const IScene &s, const Adapter &a3) : AbstractPass(s) {}

    void SmallLightsPass::exec() {
        IScene *v1;
        __int64 v2;
        IScene *v3;
        void *s;
        IGraphicsObject *obj_1;
        int i_1;
        IScene *v7;
        __int64 v8;
        ISceneGraph::Visibles obj;
        int i;

        v1 = AbstractPass::scene(this);
        v2 = v1->render();
        (*(void (__fastcall **)(__int64)) (*(_QWORD *) v2 + 296LL))(v2);
        v3 = AbstractPass::scene(this);
        s = v3->graph();
        ISceneGraph::Visibles::Visibles(&obj, s);
        for (i = 0;; ++i) {
            i_1 = ISceneGraph::Visibles::size(&obj);
            if (i_1 <= i)
                break;
            obj_1 = ISceneGraph::Visibles::operator[](&obj, i);
            AbstractPass::drawObject<SmallLightsPass>(this, obj_1);
        }
        v7 = AbstractPass::scene(this);
        v8 = v7->render();
        (*(void (__fastcall **)(__int64)) (*(_QWORD *) v8 + 312LL))(v8);
    }

    IRenderPass::Pass::Type SmallLightsPass::type() {
        return 10;
    }
}