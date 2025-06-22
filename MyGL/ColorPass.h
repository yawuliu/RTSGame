#pragma once

#include <MyGL/IScene.h>
#include <MyGL/AbstractPass.h>
#include <MyGL/IRenderPass.h>
#include <MyGL/IGraphicsObject.h>

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