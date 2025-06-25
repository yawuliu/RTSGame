#include <QOpenGLContext>
#include "TextureRectangle.h"


namespace MyGL {
	TextureRectangle::TextureRectangle(IRender& r) :render(r) {
		this->handle = 0;
		this->isForwardFormat = 0;
		this->w = 0;
		this->h = 0;
		this->setFiltration(ITexture::FilterType::Type::Nearest,
			ITexture::FilterType::Type::Nearest);
	}

	TextureRectangle::~TextureRectangle()
	{
		this->free();
	}

	void TextureRectangle::bind()
	{
		glBindTexture(34037LL, this->handle);
		this->updateSampler();
	}

	void TextureRectangle::create()
	{
		if (!(unsigned __int8)glIsTexture(this->handle))
			glGenTextures(1LL, &this->handle);
	}

	void TextureRectangle::free()
	{
		if (this->handle && !(unsigned __int8)glIsTexture(this->handle))
			glDeleteTextures(1LL, &this->handle);
		this->handle = 0;
	}

	const void* TextureRectangle::getHandle()
	{
		return &this->handle;
	}

	unsigned int TextureRectangle::height()
	{
		return this->h;
	}

	void TextureRectangle::load(const void* pixels, ITexture::InputFormat::Type imgColorSystem, unsigned int pw, unsigned int ph, ITexture::Format::Type colorSystem)
	{
		int v6;
		unsigned int h;
		unsigned int w;
		unsigned int* v9;

		this->w = pw;
		this->h = ph;
		this->free();
		this->create();
		glBindTexture(34037LL, this->handle);
		this->isForwardFormat = 1;
		v6 = *(_DWORD*)this->toGlInputFormat(imgColorSystem);
		h = this->h;
		w = this->w;
		v9 = (unsigned int*)this->toGlColorSystem(colorSystem);
		glTexImage2D(34037LL, 0LL, *v9, w, h, 0LL, v6, 5121, pixels);
	}

	void TextureRectangle::setFiltration(ITexture::FilterType::Type fmag, ITexture::FilterType::Type fmin)
	{
		this->filterMin = fmin;
		this->filterMag = fmag;
		this->isForwardFormat = 1;
	}

	const void* TextureRectangle::toGlColorSystem(ITexture::Format::Type colorSystem)
	{
		return privateGLSupportClass::toGlColorSystem(this->render, colorSystem);
	}

	const void* TextureRectangle::toGlInputFormat(ITexture::InputFormat::Type imgColorSystem)
	{
		return privateGLSupportClass::toGlInputFormat(this->render, imgColorSystem);
	}

	void TextureRectangle::updateSampler()
	{
		if (this->isForwardFormat)
		{
			glTexParameteri(34037LL, 10240LL, TextureRectangle::updateSampler(void)::filter[this->filterMag]);
			glTexParameteri(34037LL, 10241LL, TextureRectangle::updateSampler(void)::filter[this->filterMin]);
			this->isForwardFormat = 0;
		}
	}

	unsigned int TextureRectangle::width()
	{
		return this->w;
	}
}