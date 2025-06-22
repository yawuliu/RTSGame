#include "SmallLightsPass.h"

MyGL::SmallLightsPass::SmallLightsPass(const MyGL::IScene &s, const MyGL::Adapter &a3) : AbstractPass(s) {}

void MyGL::SmallLightsPass::exec() {
    MyGL::IScene *v1;
    __int64 v2;
    MyGL::IScene *v3;
    void *s;
    MyGL::IGraphicsObject *obj_1;
    int i_1;
    MyGL::IScene *v7;
    __int64 v8;
    MyGL::ISceneGraph::Visibles obj;
    int i;

    v1 = MyGL::AbstractPass::scene(this);
    v2 = (*((__int64 (__fastcall **)(MyGL::IScene *)) v1->_vptr_IScene + 3))(v1);
    (*(void (__fastcall **)(__int64)) (*(_QWORD *) v2 + 296LL))(v2);
    v3 = MyGL::AbstractPass::scene(this);
    s = (void *) (*((__int64 (__fastcall **)(MyGL::IScene *)) v3->_vptr_IScene + 8))(v3);
    MyGL::ISceneGraph::Visibles::Visibles(&obj, s);
    for (i = 0;; ++i) {
        i_1 = MyGL::ISceneGraph::Visibles::size(&obj);
        if (i_1 <= i)
            break;
        obj_1 = MyGL::ISceneGraph::Visibles::operator[](&obj, i);
        MyGL::AbstractPass::drawObject<MyGL::SmallLightsPass>(this, obj_1);
    }
    v7 = MyGL::AbstractPass::scene(this);
    v8 = (*((__int64 (__fastcall **)(MyGL::IScene *)) v7->_vptr_IScene + 3))(v7);
    (*(void (__fastcall **)(__int64)) (*(_QWORD *) v8 + 312LL))(v8);
}

MyGL::IRenderPass::Pass::Type MyGL::SmallLightsPass::type() {
    return 10;
}
