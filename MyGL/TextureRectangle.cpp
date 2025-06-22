#include "MyGL/TextureRectangle.h"

 MyGL::TextureRectangle::TextureRectangle(MyGL::IRender& r) :render(r) {
    this->handle = 0;
    this->isForwardFormat = 0;
    this->w = 0;
    this->h = 0;
    this->setFiltration(MyGL::ITexture::FilterType::Type::Nearest,
        MyGL::ITexture::FilterType::Type::Nearest);
}

 MyGL::TextureRectangle::~TextureRectangle()
{
    this->free();
}

 void MyGL::TextureRectangle::bind()
{
    glBindTexture(34037LL, this->handle);
    this->updateSampler();
}

 void MyGL::TextureRectangle::create()
{
    if (!(unsigned __int8)glIsTexture(this->handle))
        glGenTextures(1LL, &this->handle);
}

 void MyGL::TextureRectangle::free()
{
    if (this->handle && !(unsigned __int8)glIsTexture(this->handle))
        glDeleteTextures(1LL, &this->handle);
    this->handle = 0;
}

 const void* MyGL::TextureRectangle::getHandle()
{
    return &this->handle;
}

 unsigned int MyGL::TextureRectangle::height()
{
    return this->h;
}

 void MyGL::TextureRectangle::load(const void* pixels, MyGL::ITexture::InputFormat::Type imgColorSystem, unsigned int pw, unsigned int ph, MyGL::ITexture::Format::Type colorSystem)
{
    int v6;
    unsigned int h;
    unsigned int w;
    unsigned int* v9;

    this->w = pw;
    this->h = ph;
    (*((void(__fastcall**)(MyGL::TextureRectangle* const))this->_vptr_ITexture + 4))(this);
    (*((void(__fastcall**)(MyGL::TextureRectangle* const))this->_vptr_ITexture + 2))(this);
    glBindTexture(34037LL, this->handle);
    this->isForwardFormat = 1;
    v6 = *(_DWORD*)this->toGlInputFormat(imgColorSystem);
    h = this->h;
    w = this->w;
    v9 = (unsigned int*)this->toGlColorSystem(colorSystem);
    glTexImage2D(34037LL, 0LL, *v9, w, h, 0LL, v6, 5121, pixels);
}

 void MyGL::TextureRectangle::setFiltration(MyGL::ITexture::FilterType::Type fmag, MyGL::ITexture::FilterType::Type fmin)
{
    this->filterMin = fmin;
    this->filterMag = fmag;
    this->isForwardFormat = 1;
}

 const void* MyGL::TextureRectangle::toGlColorSystem(MyGL::ITexture::Format::Type colorSystem)
{
    return MyGL::privateGLSupportClass::toGlColorSystem(this->render, colorSystem);
}

 const void* MyGL::TextureRectangle::toGlInputFormat(MyGL::ITexture::InputFormat::Type imgColorSystem)
{
    return MyGL::privateGLSupportClass::toGlInputFormat(this->render, imgColorSystem);
}

 void MyGL::TextureRectangle::updateSampler()
{
    if (this->isForwardFormat)
    {
        glTexParameteri(34037LL, 10240LL, MyGL::TextureRectangle::updateSampler(void)::filter[this->filterMag]);
        glTexParameteri(34037LL, 10241LL, MyGL::TextureRectangle::updateSampler(void)::filter[this->filterMin]);
        this->isForwardFormat = 0;
    }
}

 unsigned int MyGL::TextureRectangle::width()
{
    return this->w;
}
