#pragma once

#include "IScene.h"
#include "AbstractPass.h"
#include "IRenderPass.h"
#include "IGraphicsObject.h"

namespace MyGL {
	class ColorPass : public AbstractPass {
	public:
		ColorPass(IScene& s);

		virtual ~ColorPass();

		void exec();

		bool isDrawable(IGraphicsObject& obj);

		IRenderPass::Pass::Type type();
	};
}