#pragma once
#include <string>
#include <MyGL/Adapter.h>
#include <MyGL/IRender.h>
#include <MyGL/Model.h>
#include <MyGL/FBO.h>
#include <MyGL/Texture2d.h>
#include <MyGL/ITexture2d.h>
#include <MyGL/IShader.h>
#include <MyGL/AbstractPass.h>
#include <MyGL/IGraphicsObject.h>
#include <MyGL/IOModel.h>
#include <MyGL/Filter.h>
#include <MyGL/ObjectMatrix.h>
#include <MyGL/Camera.h>
#include <MyGL/ILight.h>

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