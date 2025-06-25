#pragma once

#include "ITexture.h"

namespace MyGL {
    class ITextureRectangle : public ITexture {
    public:
        ITextureRectangle() = default;


        virtual  ~ITextureRectangle() = default;// 0
        //virtual  ~ITextureRectangle() = default;// 1
        virtual void create(void) = 0;// 2
        virtual void bind(void) = 0;// 3
        virtual void free(void) = 0;// 4
        virtual void getHandle(void) = 0;// 5
        virtual void setFiltration(ITexture::FilterType::Type, ITexture::FilterType::Type) = 0;// 6
        virtual void load(void const *, ITexture::InputFormat::Type, uint, uint, ITexture::Format::Type) = 0;// 7
        virtual void width() = 0;// 8
        virtual void height() = 0;// 9
    };
}