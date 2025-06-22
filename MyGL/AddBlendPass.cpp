#include "AddBlendPass.h"
#include <MyGL/ISceneGraph.h>

MyGL::AddBlendPass::AddBlendPass(MyGL::IScene& s) : AbstractPass(s) {

}

MyGL::AddBlendPass::~AddBlendPass()
{

}


void MyGL::AddBlendPass::exec()
{
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

	v1 = MyGL::AbstractPass::scene(this);
	s = (void*)(*((__int64(__fastcall**)(MyGL::IScene*))v1->_vptr_IScene + 8))(v1);
	MyGL::ISceneGraph::Visibles::Visibles(&obj, s);
	v3 = MyGL::AbstractPass::scene(this);
	v4 = (*((__int64(__fastcall**)(MyGL::IScene*))v3->_vptr_IScene + 3))(v3);
	(*(void(__fastcall**)(__int64))(*(_QWORD*)v4 + 296LL))(v4);
	for (i = 0; ; ++i)
	{
		i_1 = MyGL::ISceneGraph::Visibles::size(&obj);
		if (i_1 <= i)
			break;
		obj_2 = MyGL::ISceneGraph::Visibles::operator[](&obj, i);
		if (MyGL::AddBlendPass::isDrawable(this, obj_2))
		{
			obj_1 = MyGL::ISceneGraph::Visibles::operator[](&obj, i);
			MyGL::AbstractPass::drawObject<MyGL::AddBlendPass>(this, obj_1);
		}
	}
	v8 = MyGL::AbstractPass::scene(this);
	v9 = (*((__int64(__fastcall**)(MyGL::IScene*))v8->_vptr_IScene + 3))(v8);
	(*(void(__fastcall**)(__int64))(*(_QWORD*)v9 + 312LL))(v9);
}
bool MyGL::AddBlendPass::isDrawable(MyGL::IGraphicsObject& obj)
{
	__int64 v3;
	__int64 v4;
	__int64 v5;
	__int64 v6;
	__int64 v7;
	__int64 v8;

	if ((*((unsigned __int8(__fastcall**)(MyGL::IGraphicsObject* const))obj->_vptr_IGraphicsObject + 9))(obj) != 1)
		return 0;
	v3 = (*((__int64(__fastcall**)(MyGL::IGraphicsObject* const))obj->_vptr_IGraphicsObject + 3))(obj);
	v4 = (*(__int64(__fastcall**)(__int64))(*(_QWORD*)v3 + 88LL))(v3);
	if ((*(unsigned __int8(__fastcall**)(__int64))(*(_QWORD*)v4 + 136LL))(v4) != 1)
		return 0;
	v5 = (*((__int64(__fastcall**)(MyGL::IGraphicsObject* const))obj->_vptr_IGraphicsObject + 3))(obj);
	v6 = (*(__int64(__fastcall**)(__int64))(*(_QWORD*)v5 + 88LL))(v5);
	if ((*(unsigned int(__fastcall**)(__int64))(*(_QWORD*)v6 + 168LL))(v6) != 1)
		return 0;
	v7 = (*((__int64(__fastcall**)(MyGL::IGraphicsObject* const))obj->_vptr_IGraphicsObject + 3))(obj);
	v8 = (*(__int64(__fastcall**)(__int64))(*(_QWORD*)v7 + 88LL))(v7);
	return (*(unsigned int(__fastcall**)(__int64))(*(_QWORD*)v8 + 176LL))(v8) == 1;
}
MyGL::IRenderPass::Pass::Type type()
{
	return MyGL::IRenderPass::Pass::AddBlend;
}

