#pragma once

#include "ITexture.h"

namespace MyGL {
	class ITexture2d : public ITexture {
	public:
		ITexture2d() = default;

		virtual ~ITexture2d() = default;

		virtual void loadMipMaps(unsigned char*, ITexture::InputFormat, int, int, ITexture::Format) = 0;

		virtual void bind(unsigned int unit) = 0;

		virtual void unbind() = 0;

		virtual int getWidth() const = 0;

		virtual int getHeight() const = 0;
	};
}

