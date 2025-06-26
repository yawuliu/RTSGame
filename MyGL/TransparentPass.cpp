#include "TransparentPass.h"

namespace MyGL {
    TransparentPass::TransparentPass(IScene &s) : AbstractPass(s) {}

    TransparentPass::~TransparentPass() {}

    void TransparentPass::exec() {
        IScene *v1;
        __int64 v2;
        IScene *v3;
        void *s;
        IGraphicsObject *obj_2;
        IGraphicsObject *obj_1;
        int i_1;
        IGraphicsObject *obj_4;
        IGraphicsObject *obj_3;
        int i_2;
        IScene *v11;
        __int64 v12;
        ISceneGraph::Visibles obj;
        int i_0;
        int i;

        v1 = this->scene();
        v2 = v1->render();
        (*(void (__fastcall **)(__int64)) (*(_QWORD *) v2 + 296LL))(v2);
        this->depthP = 1;
        v3 = this->scene();
        s = v3->graph();
        ISceneGraph::Visibles::Visibles(&obj, s);
        for (i = 0;; ++i) {
            i_1 = ISceneGraph::Visibles::size(&obj);
            if (i_1 <= i)
                break;
            obj_2 = ISceneGraph::Visibles::operator[](&obj, i);
            if (TransparentPass::isDrawable(this, obj_2)) {
                obj_1 = ISceneGraph::Visibles::operator[](&obj, i);
                AbstractPass::drawObject<TransparentPass>(this, obj_1);
            }
        }
        this->depthP = 0;
        for (i_0 = 0;; ++i_0) {
            i_2 = ISceneGraph::Visibles::size(&obj);
            if (i_2 <= i_0)
                break;
            obj_4 = ISceneGraph::Visibles::operator[](&obj, i_0);
            if (TransparentPass::isDrawable(this, obj_4)) {
                obj_3 = ISceneGraph::Visibles::operator[](&obj, i_0);
                AbstractPass::drawObject<TransparentPass>(this, obj_3);
            }
        }
        v11 = AbstractPass::scene(this);
        v12 = v11->render();
        (*(void (__fastcall **)(__int64)) (*(_QWORD *) v12 + 312LL))(v12);
    }

    bool TransparentPass::isColorPass() {
        return !this->depthP;
    }

    bool TransparentPass::isDepthPass() {
        return this->depthP;
    }

    bool TransparentPass::isDrawable(IGraphicsObject *const obj) {
        __int64 v3;
        __int64 v4;
        __int64 v5;
        __int64 v6;
        __int64 v7;
        __int64 v8;

        if (obj->visible() != 1)
            return 0;
        v3 = obj->material();
        v4 = (*(__int64 (__fastcall **)(__int64)) (*(_QWORD *) v3 + 88LL))(v3);
        if ((*(unsigned __int8 (__fastcall **)(__int64)) (*(_QWORD *) v4 + 136LL))(v4) != 1)
            return 0;
        v5 = obj->material();
        v6 = (*(__int64 (__fastcall **)(__int64)) (*(_QWORD *) v5 + 88LL))(v5);
        if ((*(unsigned int (__fastcall **)(__int64)) (*(_QWORD *) v6 + 168LL))(v6) != 4)
            return 0;
        v7 = obj->material();
        v8 = (*(__int64 (__fastcall **)(__int64)) (*(_QWORD *) v7 + 88LL))(v7);
        return (*(unsigned int (__fastcall **)(__int64)) (*(_QWORD *) v8 + 176LL))(v8) == 5;
    }

    IRenderPass::Pass::Type TransparentPass::type() {
        return 8;
    }
}