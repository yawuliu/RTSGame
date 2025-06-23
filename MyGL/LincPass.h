#pragma once

#include "IScene.h"
#include "Adapter.h"
#include "ITextureRectangle.h"
#include "AbstractPass.h"

namespace MyGL {
	class IModel;

	class Filter;

	class LincPass : public AbstractPass {
	public:
		LincPass(IScene& s, const Adapter& adapter, IModel* quad, ITextureRectangle& f, ITextureRectangle& g,
			ITextureRectangle& b, ITextureRectangle& d);

		virtual ~LincPass();

		void exec();

		void setShader(IShader* shader);

		IRenderPass::Pass::Type type();

		bool validate();

	protected:
		ITextureRectangle& frame;
		ITextureRectangle& glow;
		ITextureRectangle& bloom;
		ITextureRectangle& depth;
		Filter* filter;
	};

}