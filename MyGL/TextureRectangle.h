#pragma once

#include "ITextureRectangle.h"
#include "ITexture2d.h"
#include "privateGLSupportClass.h"


namespace MyGL {
    class IRender;

    class TextureRectangle : public ITextureRectangle {
    public:
        TextureRectangle(IRender &r);

        virtual ~TextureRectangle();

        virtual void create() override;

        virtual void bind() override;

        virtual void free() override;

        virtual CGL::TextureHandle *getHandle() override;

        virtual void
        load(const void *pixels, ITexture::InputFormat::Type imgColorSystem, unsigned int pw, unsigned int ph,
             ITexture::Format::Type colorSystem) override;

        virtual void setFiltration(ITexture::FilterType::Type fmag, ITexture::FilterType::Type fmin) override;

        virtual uint32_t width() override;

        virtual uint32_t height() override;

        uint32_t toGlColorSystem(ITexture::Format::Type colorSystem);

        uint32_t toGlInputFormat(ITexture::InputFormat::Type imgColorSystem);

        void updateSampler();


    protected:
        static uint32_t filter[2];
        IRender *render;
        ITexture::FilterType::Type filterMin;
        ITexture::FilterType::Type filterMag;
        bool isForwardFormat;
        // padding byte
        // padding byte
        // padding byte
        unsigned int w;
        unsigned int h;
        CGL::TextureHandle handle;
    };
}

