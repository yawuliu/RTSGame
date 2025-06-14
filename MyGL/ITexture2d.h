#pragma once

#include "ITexture.h"

namespace MyGL {
	class ITexture2d {
	public:
		virtual void loadMipMaps(unsigned char*, MyGL::ITexture::InputFormat, int, int, MyGL::ITexture::Format) = 0;
		virtual void bind(unsigned int unit) = 0;
		virtual void unbind() = 0;
		virtual int getWidth() const = 0;
		virtual int getHeight() const = 0;
	};
}

