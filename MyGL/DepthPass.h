#pragma once

#include "AbstractPass.h"
#include "IScene.h"
#include "IGraphicsObject.h"

namespace MyGL {
	class DepthPass : public AbstractPass {
	public:
		DepthPass(IScene& s);

		virtual ~DepthPass() = default;

		virtual void exec() override;

		virtual IRenderPass::Pass::Type type() override;

		bool isDrawable(IGraphicsObject& obj);
	};
}