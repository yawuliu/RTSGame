#pragma once

#include "ITexture.h"
#include "CGL.h"

namespace MyGL {
    class ITextureRectangle : public ITexture {
    public:
        ITextureRectangle() = default;


        virtual  ~ITextureRectangle() = default;// 0
        //virtual  ~ITextureRectangle() = default;// 1
        virtual void create() = 0;// 2
        virtual void bind() = 0;// 3
        virtual void free() = 0;// 4
        virtual CGL::TextureHandle *getHandle() = 0;// 5
        virtual void setFiltration(ITexture::FilterType::Type, ITexture::FilterType::Type) = 0;// 6
        virtual void
        load(const void *pixels, ITexture::InputFormat::Type, uint32_t pw, uint32_t ph, ITexture::Format::Type) = 0;// 7
        virtual uint32_t width() = 0;// 8
        virtual uint32_t height() = 0;// 9
    };
}