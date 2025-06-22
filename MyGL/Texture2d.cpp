#include "Texture2d.h"
#include <stdexcept>

MyGL::Texture2d::Texture2d(MyGL::IRender& r) :render(r)
{
	MyGL::Color other;

	MyGL::Color::Color(&this->border_cl);
	this->handle = 0;
	this->isForwardFormat = 0;
	this->setFiltration(MyGL::ITexture::FilterType::Type::Linear,
		MyGL::ITexture::FilterType::Type::Linear,
		MyGL::ITexture::FilterType::Type::Count);
	this->setClamping(MyGL::ITexture::ClampMode::Type::Repeat);
	this->setAnisotropy(1.0);
	MyGL::Color::Color(&other, 0.0);
	MyGL::Color::operator=(&this->border_cl, &other);
}

MyGL::Texture2d::~Texture2d()
{
	this->free();
}

void MyGL::Texture2d::bind()
{
	glBindTexture(3553LL, this->handle);
	this->updateSampler();
}

void MyGL::Texture2d::create()
{
	if (!(unsigned __int8)glIsTexture(this->handle))
		glGenTextures(1LL, &this->handle);
}

void MyGL::Texture2d::free()
{
	if (this->handle && !(unsigned __int8)glIsTexture(this->handle))
		glDeleteTextures(1LL, &this->handle);
	this->handle = 0;
}

const void* MyGL::Texture2d::getHandle()
{
	return &this->handle;
}

unsigned int MyGL::Texture2d::height()
{
	return this->h;
}

void MyGL::Texture2d::load(const void* pixels, MyGL::ITexture::InputFormat::Type imgColorSystem, unsigned int pw, unsigned int ph, MyGL::ITexture::Format::Type colorSystem)
{
	int v6;
	unsigned int h;
	unsigned int w;
	unsigned int* v9;

	this->w = pw;
	this->h = ph;
	(*((void(__fastcall**)(MyGL::Texture2d* const))this->_vptr_ITexture + 4))(this);
	(*((void(__fastcall**)(MyGL::Texture2d* const))this->_vptr_ITexture + 2))(this);
	glBindTexture(3553LL, this->handle);
	this->isForwardFormat = 1;
	v6 = *(_DWORD*)MyGL::Texture2d::toGlInputFormat(this, imgColorSystem);
	h = this->h;
	w = this->w;
	v9 = (unsigned int*)MyGL::Texture2d::toGlColorSystem(this, colorSystem);
	glTexImage2D(3553LL, 0LL, *v9, w, h, 0LL, v6, 5121, pixels);
	if (this->filterMip == MyGL::ITexture::FilterType::Type::Linear)
		this->filterMip = MyGL::ITexture::FilterType::Type::Count;
}

void MyGL::Texture2d::loadMipMaps(const void* pixels, MyGL::ITexture::InputFormat::Type imgColorSystem, unsigned int pw, unsigned int ph, MyGL::ITexture::Format::Type colorSystem)
{
	unsigned int v6;
	unsigned int h;
	unsigned int w;
	unsigned int* v9;

	this->w = pw;
	this->h = ph;
	(*((void(__fastcall**)(MyGL::Texture2d* const))this->_vptr_ITexture + 4))(this);
	(*((void(__fastcall**)(MyGL::Texture2d* const))this->_vptr_ITexture + 2))(this);
	glBindTexture(3553LL, this->handle);
	this->isForwardFormat = 1;
	v6 = *(_DWORD*)MyGL::Texture2d::toGlInputFormat(this, imgColorSystem);
	h = this->h;
	w = this->w;
	v9 = (unsigned int*)MyGL::Texture2d::toGlColorSystem(this, colorSystem);
	gluBuild2DMipmaps(3553LL, *v9, w, h, v6, 5121LL, pixels);
	if (this->filterMip == MyGL::ITexture::FilterType::Type::Count)
		this->filterMip = MyGL::ITexture::FilterType::Type::Linear;
}

void MyGL::Texture2d::setAnisotropy(MyGL::Texture2d* const re, MyGL::Float val)
{
	MyGL::CGL* v2;

	v2 = (MyGL::CGL*)(*((__int64(__fastcall**)(MyGL::IRender*))re->render->_vptr_IRender + 9))(re->render);
	re->anisLevel = MyGL::CGL::maxAnisotropyLevel(v2) * val;
	re->isForwardFormat = 1;
}

void MyGL::Texture2d::setBorderColor(const MyGL::Color* const c)
{
	MyGL::Color::operator=(&this->border_cl, c);
	this->isForwardFormat = 1;
}

void MyGL::Texture2d::setClamping(MyGL::Texture2d* const re, MyGL::ITexture::ClampMode::Type s)
{
	(*((void(__fastcall**)(MyGL::Texture2d* const, _QWORD, _QWORD, _QWORD))re->_vptr_ITexture + 8))(
		re,
		(unsigned int)s,
		(unsigned int)s,
		(unsigned int)s);
}

void MyGL::Texture2d::setClamping(MyGL::ITexture::ClampMode::Type s, MyGL::ITexture::ClampMode::Type t, MyGL::ITexture::ClampMode::Type r)
{
	this->clamp[0] = s;
	this->clamp[1] = t;
	this->clamp[2] = r;
	this->isForwardFormat = 1;
}

void MyGL::Texture2d::setFiltration(MyGL::ITexture::FilterType::Type mag, MyGL::ITexture::FilterType::Type min)
{
	(*((void(__fastcall**)(MyGL::Texture2d* const, _QWORD, _QWORD, __int64))this->_vptr_ITexture + 6))(
		this,
		(unsigned int)mag,
		(unsigned int)min,
		2LL);
}

void MyGL::Texture2d::setFiltration(MyGL::ITexture::FilterType::Type fmag, MyGL::ITexture::FilterType::Type fmin, MyGL::ITexture::FilterType::Type fmip)
{
	this->filterMin = fmin;
	this->filterMag = fmag;
	this->filterMip = fmip;
	this->isForwardFormat = 1;
}

const void* MyGL::Texture2d::toGlColorSystem(MyGL::ITexture::Format::Type colorSystem)
{
	return MyGL::privateGLSupportClass::toGlColorSystem(this->render, colorSystem);
}

const void* MyGL::Texture2d::toGlInputFormat(MyGL::ITexture::InputFormat::Type imgColorSystem)
{
	return MyGL::privateGLSupportClass::toGlInputFormat(this->render, imgColorSystem);
}

void MyGL::Texture2d::updateSampler()
{
	MyGL::CGL* v1;
	const MyGL::Color::ChanelType* v2;

	if (this->isForwardFormat)
	{
		glTexParameteri(3553LL, 10242LL, MyGL::Texture2d::updateSampler(void)::clampMode[this->clamp[0]]);
		glTexParameteri(3553LL, 10243LL, MyGL::Texture2d::updateSampler(void)::clampMode[this->clamp[1]]);
		glTexParameteri(3553LL, 32882LL, MyGL::Texture2d::updateSampler(void)::clampMode[this->clamp[2]]);
		glTexParameteri(3553LL, 10240LL, MyGL::Texture2d::updateSampler(void)::filter[this->filterMag]);
		if (this->filterMip == MyGL::ITexture::FilterType::Type::Count)
		{
			glTexParameteri(3553LL, 10241LL, MyGL::Texture2d::updateSampler(void)::filter[this->filterMin]);
		}
		else if (this->filterMip)
		{
			if (this->filterMip == MyGL::ITexture::FilterType::Type::Linear)
				glTexParameteri(3553LL, 10241LL, MyGL::Texture2d::updateSampler(void)::filter_mipL[this->filterMin]);
		}
		else
		{
			glTexParameteri(3553LL, 10241LL, MyGL::Texture2d::updateSampler(void)::filter_mipN[this->filterMin]);
		}
		v1 = (MyGL::CGL*)(*((__int64(__fastcall**)(MyGL::IRender*))this->render->_vptr_IRender + 9))(this->render);
		if (MyGL::CGL::isAnisotropySupported(v1))
			glTexParameterf(
				3553LL,
				34046LL,
				_mm_unpacklo_pd((__m128d) * (unsigned __int64*)&this->anisLevel, (__m128d) * (unsigned __int64*)&this->anisLevel).m128d_f64[0]);
		v2 = MyGL::Color::data(&this->border_cl);
		glTexParameterfv(3553LL, 4100LL, v2);
		this->isForwardFormat = 0;
	}
}

unsigned int MyGL::Texture2d::width()
{
	return this->w;
}
