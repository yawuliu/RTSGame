#include <QOpenGLContext>
#include "TextureRectangle.h"


namespace MyGL {
    TextureRectangle::TextureRectangle(IRender &r) : render(&r) {
        this->handle = 0;
        this->isForwardFormat = 0;
        this->w = 0;
        this->h = 0;
        this->setFiltration(ITexture::FilterType::Type::Nearest, ITexture::FilterType::Type::Nearest);
    }

    TextureRectangle::~TextureRectangle() {
        this->free();
    }

    void TextureRectangle::bind() {
        glBindTexture(34037LL, this->handle);
        this->updateSampler();
    }

    void TextureRectangle::create() {
        if (!glIsTexture(this->handle))
            glGenTextures(1LL, &this->handle);
    }

    void TextureRectangle::free() {
        if (this->handle && !glIsTexture(this->handle))
            glDeleteTextures(1LL, &this->handle);
        this->handle = 0;
    }

    const CGL::TextureHandle *TextureRectangle::getHandle() {
        return &this->handle;
    }

    uint32_t TextureRectangle::width() {
        return this->w;
    }

    uint32_t TextureRectangle::height() {
        return this->h;
    }

    void TextureRectangle::load(const void *pixels, ITexture::InputFormat::Type imgColorSystem, unsigned int pw,
                                unsigned int ph, ITexture::Format::Type colorSystem) {
        unsigned int *v9;
        this->w = pw;
        this->h = ph;
        this->free();
        this->create();
        glBindTexture(34037LL, this->handle);
        this->isForwardFormat = 1;
        v9 = (unsigned int *) this->toGlColorSystem(colorSystem);
        glTexImage2D(34037LL, 0LL, *v9, this->w, this->h, 0LL, this->toGlInputFormat(imgColorSystem), 5121, pixels);
    }

    void TextureRectangle::setFiltration(ITexture::FilterType::Type fmag, ITexture::FilterType::Type fmin) {
        this->filterMin = fmin;
        this->filterMag = fmag;
        this->isForwardFormat = 1;
    }

    uint32_t TextureRectangle::toGlColorSystem(ITexture::Format::Type colorSystem) {
        return privateGLSupportClass::toGlColorSystem(this->render, colorSystem);
    }

    uint32_t TextureRectangle::toGlInputFormat(ITexture::InputFormat::Type imgColorSystem) {
        return privateGLSupportClass::toGlInputFormat(this->render, imgColorSystem);
    }

    uint32_t TextureRectangle::filter[2] = {0x2600, 0x2601};

    void TextureRectangle::updateSampler() {
        if (this->isForwardFormat) {
            glTexParameteri(34037LL, 10240LL, TextureRectangle::filter[this->filterMag]);
            glTexParameteri(34037LL, 10241LL, TextureRectangle::filter[this->filterMin]);
            this->isForwardFormat = 0;
        }
    }

}