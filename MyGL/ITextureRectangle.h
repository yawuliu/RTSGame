#pragma once

#include "MyGL/ITexture2d.h"

namespace MyGL {
	class ITextureRectangle : public ITexture2d {
	public:
		virtual void load(unsigned char*, MyGL::ITexture::InputFormat, int, int, MyGL::ITexture::Format) = 0;
		virtual float width() const = 0;
		virtual float height() const = 0;
		virtual void loadMipMaps(unsigned char*, MyGL::ITexture::InputFormat, int, int, MyGL::ITexture::Format) = 0;
		virtual void bind(unsigned int unit) = 0;
		virtual void unbind() = 0;
		virtual int getWidth() const = 0;
		virtual int getHeight() const = 0;
	};
}