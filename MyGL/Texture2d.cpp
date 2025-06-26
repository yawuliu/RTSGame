#include "Texture2d.h"
#include <stdexcept>
#include <QOpenGLContext>

namespace MyGL {
	Texture2d::Texture2d(IRender& r) :render(r)
	{
		Color other;

		Color::Color(&this->border_cl);
		this->handle = 0;
		this->isForwardFormat = 0;
		this->setFiltration(ITexture::FilterType::Type::Linear,
			ITexture::FilterType::Type::Linear,
			ITexture::FilterType::Type::Count);
		this->setClamping(ITexture::ClampMode::Type::Repeat);
		this->setAnisotropy(1.0);
		Color::Color(&other, 0.0);
		Color::operator=(&this->border_cl, &other);
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

	const void* Texture2d::getHandle()
	{
		return &this->handle;
	}

	unsigned int Texture2d::height()
	{
		return this->h;
	}

	void Texture2d::load(const void* pixels, ITexture::InputFormat::Type imgColorSystem, unsigned int pw, unsigned int ph, ITexture::Format::Type colorSystem)
	{
		int v6;
		unsigned int h;
		unsigned int w;
		unsigned int* v9;

		this->w = pw;
		this->h = ph;
		this->free();
		this->create();
		glBindTexture(3553LL, this->handle);
		this->isForwardFormat = 1;
		v6 = *(_DWORD*)this->toGlInputFormat(imgColorSystem);
		h = this->h;
		w = this->w;
		v9 = (unsigned int*)this->toGlColorSystem(colorSystem);
		glTexImage2D(3553LL, 0LL, *v9, w, h, 0LL, v6, 5121, pixels);
		if (this->filterMip == ITexture::FilterType::Type::Linear)
			this->filterMip = ITexture::FilterType::Type::Count;
	}

	void Texture2d::loadMipMaps(const void* pixels, ITexture::InputFormat::Type imgColorSystem, unsigned int pw, unsigned int ph, ITexture::Format::Type colorSystem)
	{
		unsigned int v6;
		unsigned int h;
		unsigned int w;
		unsigned int* v9;

		this->w = pw;
		this->h = ph;
		this->free();
		this->create();
		glBindTexture(3553LL, this->handle);
		this->isForwardFormat = 1;
		v6 = *(_DWORD*)this->toGlInputFormat( imgColorSystem);
		h = this->h;
		w = this->w;
		v9 = (unsigned int*)this->toGlColorSystem(colorSystem);
		gluBuild2DMipmaps(3553LL, *v9, w, h, v6, 5121LL, pixels);
		if (this->filterMip == ITexture::FilterType::Type::Count)
			this->filterMip = ITexture::FilterType::Type::Linear;
	}

	void Texture2d::setAnisotropy(Texture2d& re, Float val)
	{
		CGL* v2;

		v2 = re.render->gl();
		re->anisLevel = v2->maxAnisotropyLevel() * val;
		re->isForwardFormat = 1;
	}

	void Texture2d::setBorderColor(const Color& c)
	{
        this->border_cl =  c;
		this->isForwardFormat = 1;
	}

	void Texture2d::setClamping(Texture2d & re, ITexture::ClampMode::Type s)
	{
		re.setClamping(
			(unsigned int)s,
			(unsigned int)s,
			(unsigned int)s);
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
		this->setFiltration(
			(unsigned int)mag,
			(unsigned int)min,
			2LL);
	}

	void Texture2d::setFiltration(ITexture::FilterType::Type fmag, ITexture::FilterType::Type fmin, ITexture::FilterType::Type fmip)
	{
		this->filterMin = fmin;
		this->filterMag = fmag;
		this->filterMip = fmip;
		this->isForwardFormat = 1;
	}

	const void* Texture2d::toGlColorSystem(ITexture::Format::Type colorSystem)
	{
		return privateGLSupportClass::toGlColorSystem(this->render, colorSystem);
	}

	const void* Texture2d::toGlInputFormat(ITexture::InputFormat::Type imgColorSystem)
	{
		return privateGLSupportClass::toGlInputFormat(this->render, imgColorSystem);
	}

	void Texture2d::updateSampler()
	{
		CGL* v1;
		const Color::ChanelType* v2;

		if (this->isForwardFormat)
		{
			glTexParameteri(3553LL, 10242LL, Texture2d::updateSampler(void)::clampMode[this->clamp[0]]);
			glTexParameteri(3553LL, 10243LL, Texture2d::updateSampler(void)::clampMode[this->clamp[1]]);
			glTexParameteri(3553LL, 32882LL, Texture2d::updateSampler(void)::clampMode[this->clamp[2]]);
			glTexParameteri(3553LL, 10240LL, Texture2d::updateSampler(void)::filter[this->filterMag]);
			if (this->filterMip == ITexture::FilterType::Type::Count)
			{
				glTexParameteri(3553LL, 10241LL, Texture2d::updateSampler(void)::filter[this->filterMin]);
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
			v1 = this->render->gl();
			if (v1->isAnisotropySupported())
				glTexParameterf(
					3553LL,
					34046LL,
					_mm_unpacklo_pd((__m128d) * (unsigned __int64*)&this->anisLevel, (__m128d) * (unsigned __int64*)&this->anisLevel).m128d_f64[0]);
			v2 = this->border_cl->data();
			glTexParameterfv(3553LL, 4100LL, v2);
			this->isForwardFormat = 0;
		}
	}

	unsigned int Texture2d::width()
	{
		return this->w;
	}
}