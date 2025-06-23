#pragma once

#include <vector>
#include "IScene.h"
#include "IModel.h"
#include "IIOModel.h"
#include "IOModel.h"
#include "IRender.h"
#include "TextureRectangle.h"
#include "AbstractPass.h"
#include "FBO.h"

namespace MyGL {
	class Adapter;

	class MainPass : public AbstractPass {
	public:
		MainPass(IScene& s, const Adapter& adapter, IModel* q, bool autoMake);

		virtual ~MainPass();

		void buildQuad(int w, int h);

		ITextureRectangle* depthBuffer();

		void draw();

		void exec();

		FBO* frameBuffer();

		void makeAlgo(const Adapter& adapter);

		void makeAlgo(MainPass& mp, std::vector<IRenderPass*>& passes, const Adapter& adapter);

		ITextureRectangle* output();

		IModel* quadModel();

		void resizeFrame();

		void setPoint(float* p, float x, float y);

		IRenderPass::Pass::Type type();

	protected:
		IModel* quad;
		FBO* m_frameBuffer;
		ITextureRectangle* frame;
		ITextureRectangle* depth;
		std::vector<IRenderPass*> passes;
	};
}
