#include "Texture2d.h"
#include "Color.h"
#include <stdexcept>
#include <QOpenGLContext>
#include <GL/glu.h>
#include "privateGLSupportClass.h"

namespace MyGL {
	Texture2d::Texture2d(IRender& r) :render(&r)
	{
		this->handle = 0;
		this->isForwardFormat = 0;
		this->setFiltration(ITexture::FilterType::Type::Linear,
			ITexture::FilterType::Type::Linear,
			ITexture::FilterType::Type::Count);
		this->setClamping(ITexture::ClampMode::Type::Repeat);
		this->setAnisotropy(1.0);
		Color other(0.0);
        this->border_cl = other;
	}

	Texture2d::~Texture2d()
	{
		this->free();
	}

	void Texture2d::bind()
	{
		glBindTexture(3553LL, this->handle);
		this->updateSampler();
	}

	void Texture2d::create()
	{
		if (!(unsigned __int8)glIsTexture(this->handle))
			glGenTextures(1LL, &this->handle);
	}

	void Texture2d::free()
	{
		if (this->handle && !(unsigned __int8)glIsTexture(this->handle))
			glDeleteTextures(1LL, &this->handle);
		this->handle = 0;
	}

	CGL::TextureHandle* Texture2d::getHandle()
	{
		return &this->handle;
	}

    uint32_t Texture2d::width()
    {
        return this->w;
    }

	 uint32_t Texture2d::height()
	{
		return this->h;
	}

	void Texture2d::load(const void* pixels, ITexture::InputFormat::Type imgColorSystem, unsigned int pw, unsigned int ph, ITexture::Format::Type colorSystem)
	{
		this->w = pw;
		this->h = ph;
		this->free();
		this->create();
		glBindTexture(3553LL, this->handle);
		this->isForwardFormat = 1;
		glTexImage2D(3553LL, 0LL, this->toGlColorSystem(colorSystem), this->w, this->h, 0LL, this->toGlInputFormat(imgColorSystem), 5121, pixels);
		if (this->filterMip == ITexture::FilterType::Type::Linear)
			this->filterMip = ITexture::FilterType::Type::Count;
	}

	void Texture2d::loadMipMaps(const void* pixels, ITexture::InputFormat::Type imgColorSystem, unsigned int pw, unsigned int ph, ITexture::Format::Type colorSystem)
	{
		this->w = pw;
		this->h = ph;
		this->free();
		this->create();
		glBindTexture(3553LL, this->handle);
		this->isForwardFormat = 1;
		h = this->h;
		w = this->w;
		gluBuild2DMipmaps(3553LL, this->toGlColorSystem(colorSystem), w, h, this->toGlInputFormat( imgColorSystem), 5121LL, pixels);
		if (this->filterMip == ITexture::FilterType::Type::Count)
			this->filterMip = ITexture::FilterType::Type::Linear;
	}

	void Texture2d::setAnisotropy(Float val)
	{
		this->anisLevel = this->render->gl()->maxAnisotropyLevel() * val;
        this->isForwardFormat = 1;
	}

	void Texture2d::setBorderColor(const Color& c)
	{
        this->border_cl =  c;
		this->isForwardFormat = 1;
	}

	void Texture2d::setClamping(ITexture::ClampMode::Type s)
	{
		this->setClamping(s,s,s);
	}

	void Texture2d::setClamping(ITexture::ClampMode::Type s, ITexture::ClampMode::Type t, ITexture::ClampMode::Type r)
	{
		this->clamp[0] = s;
		this->clamp[1] = t;
		this->clamp[2] = r;
		this->isForwardFormat = 1;
	}

	void Texture2d::setFiltration(ITexture::FilterType::Type mag, ITexture::FilterType::Type min)
	{
		this->setFiltration(mag, min, (ITexture::FilterType::Type)2LL);
	}

	void Texture2d::setFiltration(ITexture::FilterType::Type fmag, ITexture::FilterType::Type fmin, ITexture::FilterType::Type fmip)
	{
		this->filterMin = fmin;
		this->filterMag = fmag;
		this->filterMip = fmip;
		this->isForwardFormat = 1;
	}

    uint32_t Texture2d::toGlColorSystem(ITexture::Format::Type colorSystem)
	{
		return privateGLSupportClass::toGlColorSystem(this->render, colorSystem);
	}

	 uint32_t Texture2d::toGlInputFormat(ITexture::InputFormat::Type imgColorSystem)
	{
		return privateGLSupportClass::toGlInputFormat(this->render, imgColorSystem);
	}
    static uint32_t clampMode[6] = {0x2900, 0x812D, 0x812F, 0x8370, 0x2901,  0x2901};
    static uint32_t filter[2] = {0x2600, 0x2601};
	void Texture2d::updateSampler()
	{
		if (this->isForwardFormat)
		{
			glTexParameteri(3553LL, 10242LL, clampMode[this->clamp[0]]);
			glTexParameteri(3553LL, 10243LL, clampMode[this->clamp[1]]);
			glTexParameteri(3553LL, 32882LL, clampMode[this->clamp[2]]);
			glTexParameteri(3553LL, 10240LL, filter[this->filterMag]);
			if (this->filterMip == ITexture::FilterType::Type::Count)
			{
				glTexParameteri(3553LL, 10241LL, filter[this->filterMin]);
			}
			else if (this->filterMip)
			{
				if (this->filterMip == ITexture::FilterType::Type::Linear)
					glTexParameteri(3553LL, 10241LL, Texture2d::updateSampler(void)::filter_mipL[this->filterMin]);
			}
			else
			{
				glTexParameteri(3553LL, 10241LL, Texture2d::updateSampler(void)::filter_mipN[this->filterMin]);
			}
			if (this->render->gl()->isAnisotropySupported())
				glTexParameterf(
					3553LL,
					34046LL,
					_mm_unpacklo_pd((__m128d) * (unsigned __int64*)&this->anisLevel, (__m128d) * (unsigned __int64*)&this->anisLevel).m128d_f64[0]);
			glTexParameterfv(3553LL, 4100LL, this->border_cl.data());
			this->isForwardFormat = 0;
		}
	}

}