#pragma once
#include <string>
#include "DisableCopy.h"
#include "ITexture2d.h"
#include "ITextureRectangle.h"


namespace MyGL {

	class IFBO : public DisableCopy {
	public:
		IFBO() = default;

		virtual ~IFBO() = default; // 0
		// virtual ~IFBO() = default; // 1
		virtual uint32_t width() = 0; // 2

		virtual uint32_t height() = 0; // 3

		virtual bool hasStencil() = 0; // 4

		virtual bool hasDepth() = 0; // 5

		virtual bool validate() = 0; // 6

		virtual std::string  status() = 0; // 7

		virtual bool bind() = 0; // 8

		virtual bool unbind() = 0; // 9

		virtual bool attachColorTexture(ITexture2d*, int) = 0; // 10

		virtual bool attachDepthTexture(ITexture2d*) = 0; // 11

		virtual bool attachColorTexture(ITextureRectangle*, int) = 0; // 12

		virtual bool attachDepthTexture(ITextureRectangle*) = 0; // 13

		virtual bool detachColorTexture(int) = 0; // 14

		virtual bool detachDepthTexture() = 0; // 15

		virtual int maxColorAttachemnts() = 0; // 16
	};

}
