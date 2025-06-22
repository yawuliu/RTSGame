
#pragma once

#include <string>
#include <MyGL/AbstractPass.h>
#include <MyGL/Filter.h>
#include <MyGL/TextureRectangle.h>
#include <MyGL/ITextureRectangle.h>
#include <MyGL/FBO.h>
#include <MyGL/MainPass.h>
#include <MyGL/Adapter.h>
#include <MyGL/ITexture.h>
#include <MyGL/IRender.h>

namespace MyGL {
	class IScene;

	class IAdapter;

	class SSAOpass : public AbstractPass {
	public:
		class Data {
		public:
			Data(IScene& s);
			virtual ~Data() = default;
		protected:
			Filter ssao;
		};
	public:
		SSAOpass(IScene& s, const Adapter& adapter, MainPass* mp);
		virtual ~SSAOpass();
		void exec();
		bool isActive();
		ITextureRectangle* output();
		void resizeFrame();
		void setActive(bool active);
		IRenderPass::Pass::Type type();
	protected:
		ITextureRectangle* frame;
		ITextureRectangle* depthBuf;
		FBO* frameBuffer;
		ITextureRectangle* out;
		ITextureRectangle* depth;
		MainPass* mpass;
		bool active;
		//        00000041     // padding byte
		//        00000042     // padding byte
		//        00000043     // padding byte
		//        00000044     // padding byte
		//        00000045     // padding byte
		//        00000046     // padding byte
		//        00000047     // padding byte
		SSAOpass::Data* data;
	};
}