#include "DepthPass.h"
#include "ISceneGraph.h"

namespace MyGL {
	DepthPass::DepthPass(IScene& s) : AbstractPass(s) {

	}

	void DepthPass::exec() {
		void* s;
		__int64 v4;
		__int64 v9;
		int i;;
		ISceneGraph::Visibles obj(this->scene()->graph());
		v4 = this->scene()->render();
		(*(void(__fastcall**)(__int64)) (*(_QWORD*)v4 + 296LL))(v4);
		for (i = 0;; ++i) {
			if (obj.size() <= i)
				break;
			if (this->isDrawable(obj[i])) {
				this->drawObject<DepthPass>(obj[i]);
			}
		}
		v9 = this->scene()->render();
		(*(void(__fastcall**)(__int64)) (*(_QWORD*)v9 + 312LL))(v9);
	}

	IRenderPass::Pass::Type DepthPass::type() {
		return IRenderPass::Pass::Depth;
	}

	bool DepthPass::isDrawable(IGraphicsObject& obj) {
		__int64 v4;

		if (obj->visible() != 1)
			return false;
		v4 = (*(__int64(__fastcall**)(__int64)) (*(_QWORD*)v3 + 88LL))(obj->material());
		return (*(unsigned __int8(__fastcall**)(__int64)) (*(_QWORD*)v4 + 136LL))(v4) == 0;
	}

}