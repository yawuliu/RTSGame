#pragma once

#include "MyGL/AbstractPass.h"
#include "MyGL/ISceneGraph.h"

namespace MyGL {
	class IScene;

	class TransparentPass : public AbstractPass {
	public:
		TransparentPass(IScene& s);

		virtual ~TransparentPass();

		void exec();

		bool isColorPass();

		bool isDepthPass();

		bool isDrawable(IGraphicsObject* const obj);

		IRenderPass::Pass::Type type();

	protected:
		bool depthP;
	};
}