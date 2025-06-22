#include "DepthPass.h"
#include "ISceneGraph.h"
#include "AbstractPass.h"
#include "IScene.h"
#include "IGraphicsObject.h"

MyGL::DepthPass::DepthPass(MyGL::IScene& s) : AbstractPass(s) {

}

MyGL::DepthPass::~DepthPass() {

}


void MyGL::DepthPass::exec() {
	MyGL::IScene* v1;
	void* s;
	MyGL::IScene* v3;
	__int64 v4;
	MyGL::IGraphicsObject* obj_2;
	MyGL::IGraphicsObject* obj_1;
	int i_1;
	MyGL::IScene* v8;
	__int64 v9;
	MyGL::ISceneGraph::Visibles obj;
	int i;

	v1 = this->scene();
	s = (void*)(*((__int64(__fastcall**)(MyGL::IScene*)) v1->_vptr_IScene + 8))(v1);
	MyGL::ISceneGraph::Visibles::Visibles(&obj, s);
	v3 = this->scene();
	v4 = (*((__int64(__fastcall**)(MyGL::IScene*)) v3->_vptr_IScene + 3))(v3);
	(*(void(__fastcall**)(__int64)) (*(_QWORD*)v4 + 296LL))(v4);
	for (i = 0;; ++i) {
		i_1 = MyGL::ISceneGraph::Visibles::size(&obj);
		if (i_1 <= i)
			break;
		obj_2 = MyGL::ISceneGraph::Visibles::operator[](&obj, i);
		if (MyGL::DepthPass::isDrawable(this, obj_2)) {
			obj_1 = MyGL::ISceneGraph::Visibles::operator[](&obj, i);
			MyGL::AbstractPass::drawObject<MyGL::DepthPass>(this, obj_1);
		}
	}
	v8 = this->scene();
	v9 = (*((__int64(__fastcall**)(MyGL::IScene*)) v8->_vptr_IScene + 3))(v8);
	(*(void(__fastcall**)(__int64)) (*(_QWORD*)v9 + 312LL))(v9);
}

const MyGL::IRenderPass::Pass::Type& MyGL::DepthPass::type() const {
	return IRenderPass::Pass::Depth;
}

bool MyGL::DepthPass::isDrawable(MyGL::IGraphicsObject& obj) {
	__int64 v3;
	__int64 v4;

	if ((*((unsigned __int8(__fastcall**)(MyGL::IGraphicsObject* const))obj->_vptr_IGraphicsObject + 9))(obj) != 1)
		return false;
	v3 = (*((__int64(__fastcall**)(MyGL::IGraphicsObject* const))obj->_vptr_IGraphicsObject + 3))(obj);
	v4 = (*(__int64(__fastcall**)(__int64))(*(_QWORD*)v3 + 88LL))(v3);
	return (*(unsigned __int8(__fastcall**)(__int64))(*(_QWORD*)v4 + 136LL))(v4) == 0;
}

