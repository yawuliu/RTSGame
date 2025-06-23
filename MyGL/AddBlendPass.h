#pragma once

#include "IScene.h"
#include "IRenderPass.h"
#include "IGraphicsObject.h"
#include "AbstractPass.h"

namespace MyGL {
	class AddBlendPass : public AbstractPass {
	public:
		AddBlendPass(IScene& s);

		virtual ~AddBlendPass();

		void exec();

		bool isDrawable(IGraphicsObject& obj);

		IRenderPass::Pass::Type type();
	};
}