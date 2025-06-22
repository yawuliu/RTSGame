#pragma once
#include "IRenderPass.h"
#include "AbstractPass.h"
#include "ITextureRectangle.h"
#include "FBO.h"
#include "BloomPass.h"
#include "SmallLightsPass.h"


namespace MyGL {
	class GlowPass : public AbstractPass {
	public:
		class Data {
		public:
			Data(IScene& a2) = default;

		protected:
			BloomPass* blur;
			SmallLightsPass* lights;
		};
	public:
		GlowPass(IScene& s, const Adapter& adapter, ITextureRectangle* depth);
		virtual ~GlowPass();
		bool validate();
		bool isDrawable(IGraphicsObject& obj);
		void resizeFrame();
		void initShaders(const Adapter& adapter);
		void exec();
		void draw();
		void postProcess(int a2, int a3, int a4, int a5);
		ITextureRectangle* output();
		IRenderPass::Pass::Type type();
	protected:
		ITextureRectangle* frame;
		ITextureRectangle* depthBuf;
		FBO* frameBuffer;
		GlowPass::Data* data;
		bool used;
		int fakeLv;
	};

}