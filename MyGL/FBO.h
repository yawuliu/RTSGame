#pragma once


#include "IFBO.h"
#include "IRender.h"

namespace MyGL {
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

		std::string status() override;

		bool validate() override;

		bool bind() override;

		bool unbind() override;

		bool attachColorTexture(ITexture2d* target, int no) override;

		bool attachDepthTexture(ITexture2d* target) override;

		bool attachColorTexture(ITextureRectangle* target, int no) override;

		bool attachDepthTexture(ITextureRectangle* target) override;

		int maxColorAttachemnts() override;

		uint32_t width() override;

		uint32_t height() override;

		bool hasStencil() override;

		bool hasDepth() override;

		bool detachColorTexture(int no) override;

		bool detachDepthTexture() override;

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