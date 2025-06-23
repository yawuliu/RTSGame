#pragma once

#include "AbstractPass.h"

namespace MyGL {
	class IScene;

	class IGraphicsObject;

	class DepthPass : public AbstractPass {
	public:
		DepthPass(IScene& s);

		virtual ~DepthPass();

		void exec();

		bool isDrawable(IGraphicsObject& obj);

		IRenderPass::Pass::Type type();
	};
}