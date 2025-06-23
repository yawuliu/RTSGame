#pragma once

#include "ITextureRectangle.h"
#include "ITexture2d.h"
#include "privateGLSupportClass.h"


namespace MyGL {
	class IRender;

	class TextureRectangle : public ITextureRectangle {
	public:
		TextureRectangle(IRender& r);
		virtual ~TextureRectangle();
		void bind();
		void create();
		void free();
		const void* getHandle();
		unsigned int height();
		void load(const void* pixels, ITexture::InputFormat::Type imgColorSystem, unsigned int pw, unsigned int ph, ITexture::Format::Type colorSystem);

		void setFiltration(ITexture::FilterType::Type fmag, ITexture::FilterType::Type fmin);
		const void* toGlColorSystem(ITexture::Format::Type colorSystem);
		const void* toGlInputFormat(ITexture::InputFormat::Type imgColorSystem);
		void updateSampler();
		unsigned int width();
	private:
		int handle;
		IRender& render;
		ITexture::FilterType::Type filterMin;
		ITexture::FilterType::Type  filterMag;
		int w;
		int h;
		bool isForwardFormat;
	};
}

