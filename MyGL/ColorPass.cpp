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
        s = this->scene()->graph();
        ISceneGraph::Visibles::Visibles(&obj, s);
        v4 = this->scene()->render();
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

        v9 = this->scene()->render();
        (*(void (__fastcall **)(__int64)) (*(_QWORD *) v9 + 312LL))(v9);
    }

    bool ColorPass::isDrawable(IGraphicsObject &obj) {
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