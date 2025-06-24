#include "ColorPass.h"
#include "IScene.h"
#include "AbstractPass.h"
#include "ISceneGraph.h"

namespace MyGL {
    ColorPass::ColorPass(IScene &s) : AbstractPass(s) {

    }

    ColorPass::~ColorPass() {
    }

    void ColorPass::exec() {
        IScene *v1;
        void *s;
        IScene *v3;
        __int64 v4;
        IGraphicsObject *obj_2;
        IGraphicsObject *obj_1;
        int i_1;
        IScene *v8;
        __int64 v9;
        ISceneGraph::Visibles obj;
        int i;

        v1 = this->scene();
        s = v1->graph();
        ISceneGraph::Visibles::Visibles(&obj, s);
        v3 = this->scene();
        v4 = v3->render();
        (*(void (__fastcall **)(__int64)) (*(_QWORD *) v4 + 296LL))(v4);
        for (i = 0;; ++i) {
            i_1 = ISceneGraph::Visibles::size(&obj);
            if (i_1 <= i)
                break;
            obj_2 = ISceneGraph::Visibles::operator[](&obj, i);
            if (ColorPass::isDrawable(this, obj_2)) {
                obj_1 = ISceneGraph::Visibles::operator[](&obj, i);
                AbstractPass::drawObject<ColorPass>(this, obj_1);
            }
        }
        v8 = this->scene();
        v9 = v8->render();
        (*(void (__fastcall **)(__int64)) (*(_QWORD *) v9 + 312LL))(v9);
    }

    bool ColorPass::isDrawable(IGraphicsObject &obj) {
        __int64 v3;
        __int64 v4;

        if (obj->visible() != 1)
            return 0;
        v3 = obj->material();
        v4 = (*(__int64 (__fastcall **)(__int64)) (*(_QWORD *) v3 + 88LL))(v3);
        return (*(unsigned __int8 (__fastcall **)(__int64)) (*(_QWORD *) v4 + 136LL))(v4) == 0;
    }

    IRenderPass::Pass::Type type() {
        return IRenderPass::Pass::Color;
    }

}