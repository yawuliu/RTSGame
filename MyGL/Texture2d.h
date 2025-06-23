#pragma once

#include "ITexture2d.h"
#include "ITexture.h"
#include "Color.h"
#include "privateGLSupportClass.h"

namespace MyGL {
	class IRender;

	class Texture2d : public ITexture2d {
	public:
		Texture2d(IRender& r);
		virtual ~Texture2d();
		void bind();
		void create();
		void free();
		const void* getHandle();
		unsigned int height();
		void load(const void* pixels, ITexture::InputFormat::Type imgColorSystem,
			unsigned int pw, unsigned int ph, ITexture::Format::Type colorSystem);
		void loadMipMaps(const void* pixels, ITexture::InputFormat::Type imgColorSystem,
			unsigned int pw, unsigned int ph, ITexture::Format::Type colorSystem);
		void setAnisotropy(Texture2d* const re, Float val);
		void setBorderColor(const Color* const c);
		void setClamping(Texture2d* const re, ITexture::ClampMode::Type s);
		void setClamping(ITexture::ClampMode::Type s, ITexture::ClampMode::Type t, ITexture::ClampMode::Type r);
		void setFiltration(ITexture::FilterType::Type mag, ITexture::FilterType::Type min);
		void setFiltration(ITexture::FilterType::Type fmag,
			ITexture::FilterType::Type fmin,
			ITexture::FilterType::Type fmip);
		const void* toGlColorSystem(ITexture::Format::Type colorSystem);
		const void* toGlInputFormat(ITexture::InputFormat::Type imgColorSystem);
		void updateSampler();
		unsigned int width();
	private:
		IRender& render;
		int w;
		int h;
		int handle;
		bool isForwardFormat;
		ITexture::FilterType::Type  filterMin;
		ITexture::FilterType::Type  filterMip;
		ITexture::FilterType::Type filterMag;
		Color border_cl;
		ITexture::ClampMode::Type clamp[3];
	};
}