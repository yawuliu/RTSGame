#pragma once

#include <MyGL/IRenderPass.h>
#include <MyGL/IGraphicsObject.h>

namespace MyGL {
	class IScene;

	class AbstractPass : public IRenderPass {
	public:
		AbstractPass(IScene& s);

		IScene& scene();

		template<class T>
		bool drawObject(IGraphicsObject& obj) {
			__int64 v2;
			__int64 v3;
			IScene* v5;
			__int64 v6;
			__int64 v7;
			__int64 v8;

			if (!(*((__int64(__fastcall**)(IGraphicsObject* const))obj->_vptr_IGraphicsObject + 7))(obj))
				return false;
			v2 = (*((__int64(__fastcall**)(IGraphicsObject* const))obj->_vptr_IGraphicsObject + 3))(obj);
			v3 = (*(__int64(__fastcall**)(__int64))(*(_QWORD*)v2 + 40LL))(v2);
			if (!(*(unsigned __int8(__fastcall**)(__int64, AbstractPass* const))(*(_QWORD*)v3 + 96LL))(v3, this))
				return false;
			v5 = this->scene();
			v6 = (*((__int64(__fastcall**)(IScene*))v5->_vptr_IScene + 3))(v5);
			(*(void(__fastcall**)(__int64, IGraphicsObject* const))(*(_QWORD*)v6 + 208LL))(v6, obj);
			v7 = (*((__int64(__fastcall**)(IGraphicsObject* const))obj->_vptr_IGraphicsObject + 3))(obj);
			v8 = (*(__int64(__fastcall**)(__int64))(*(_QWORD*)v7 + 40LL))(v7);
			(*(void(__fastcall**)(__int64, AbstractPass* const))(*(_QWORD*)v8 + 104LL))(v8, this);
			return true;
		}

	protected:
		IScene& mscene;
	};


	class Pass {
	public:
		enum Type {
			User
		};
	};
}

