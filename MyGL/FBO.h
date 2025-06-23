#pragma once
#include <string>
#include "IFBO.h"


namespace MyGL {
	class ITexture2d;
	class ITextureRectangle;
	class FBO : public IFBO {
	public:
		class Flags {
		public:
			typedef int BitMap;
		};

	public:
		FBO(IRender& r, unsigned int theWidth, unsigned int theHeight, FBO::Flags::BitMap f);
		virtual ~FBO();
		bool create();
		std::string status();
		bool validate();
		bool bind();
		bool unbind();
		bool attachColorTexture(ITexture2d* target, int no);
		bool attachDepthTexture(ITexture2d* target);
		bool attachColorTexture(ITextureRectangle* target, int no);
		bool attachDepthTexture(ITextureRectangle* target);
		int maxColorAttachemnts();
		unsigned int width();
		unsigned int height();
		bool hasStencil();
		bool hasDepth();
		bool detachColorTexture(int no);
		bool detachDepthTexture();
	protected:
		int frameBuffer;
		int depthBuffer;
		int stencilBuffer;
		int ext;
		int w;
		int h;
		int flags;
	};
}