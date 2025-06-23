#pragma once
#include <string>
#include "Adapter.h"
#include "IRender.h"
#include "Model.h"
#include "FBO.h"
#include "Texture2d.h"
#include "ITexture2d.h"
#include "IShader.h"
#include "AbstractPass.h"
#include "IGraphicsObject.h"
#include "IOModel.h"
#include "Filter.h"
#include "ObjectMatrix.h"
#include "Camera.h"
#include "ILight.h"

namespace MyGL {
	class ShadowPass : public AbstractPass {
	public:
		ShadowPass(IScene& s, const Adapter& adapter);
		virtual ~ShadowPass();
		void buildQuad(int w, int h);
		ITexture2d* createFrame(ITexture2d* in);
		int currentLightId();
		void draw();
		void exec();
		void initLight(int id);
		bool isDrawable(IGraphicsObject& obj);
		void setPoint(float* p, float x, float y);
		ITexture2d* shadowMap();
		IRenderPass::Pass::Type type();
	protected:
		Filter* blur;
		IModel* quad;
		ITexture2d* frame;
		ITexture2d* tmpFrame;
		FBO* frameBuffer;
		Camera lview;
		ObjectMatrix lMat;
		bool nUpdate;
		//        000001C9     // padding byte
		//        000001CA     // padding byte
		//        000001CB     // padding byte
		int lightId;
	};
}