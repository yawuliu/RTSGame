#pragma once
#include "AbstractPass.h"


namespace MyGL {
	class ITextureRectangle;
	class Filter;
	class FBO;
	class VolumetricLightScatteringPass : public AbstractPass {
	public:
		VolumetricLightScatteringPass(
			IScene& s,
			IModel* quad,
			const Adapter& adapter,
			ITextureRectangle& d,
			ITextureRectangle& c);
		virtual ~VolumetricLightScatteringPass();
		void resizeFrame();
		void exec();
		ITextureRectangle* output(VolumetricLightScatteringPass& vlsPass);
		IRenderPass::Pass::Type type();
	protected:
		ITextureRectangle* depth;
		ITextureRectangle* frame;
		Filter* filter;
		FBO* frameBuffer;
	};

}