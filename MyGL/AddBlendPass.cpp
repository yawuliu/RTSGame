#include "AddBlendPass.h"
#include "ISceneGraph.h"

namespace MyGL {
    AddBlendPass::AddBlendPass(IScene &s) : AbstractPass(s) {

    }

    AddBlendPass::~AddBlendPass() {

    }


    void AddBlendPass::exec() {
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

        s = this->scene()->graph();
        ISceneGraph::Visibles obj(s);
        v4 = this->scene()->render();
        (*(void (__fastcall **)(__int64)) (*(_QWORD *) v4 + 296LL))(v4);
        for (i = 0;; ++i) {
            i_1 = obj.size();
            if (i_1 <= i)
                break;
            obj_2 = obj[i];
            if (this->isDrawable(obj_2)) {
                obj_1 = obj[i];
                this->drawObject<AddBlendPass>(obj_1);
            }
        }
        v9 = this->scene()->render();
        (*(void (__fastcall **)(__int64)) (*(_QWORD *) v9 + 312LL))(v9);
    }

    bool AddBlendPass::isDrawable(IGraphicsObject &obj) {
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
        if ((*(unsigned int (__fastcall **)(__int64)) (*(_QWORD *) v6 + 168LL))(v6) != 1)
            return 0;
        v7 = obj->material();
        v8 = (*(__int64 (__fastcall **)(__int64)) (*(_QWORD *) v7 + 88LL))(v7);
        return (*(unsigned int (__fastcall **)(__int64)) (*(_QWORD *) v8 + 176LL))(v8) == 1;
    }

    IRenderPass::Pass::Type type() {
        return IRenderPass::Pass::AddBlend;
    }

}