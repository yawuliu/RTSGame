#pragma once

#include "ITexture.h"

namespace MyGL {
    class ITexture2d : public ITexture {
    public:
        ITexture2d() = default;

        virtual  ~ITexture2d() = default;// 0
        //virtual  ~ITexture2d() = default;// 1
        virtual void create() = 0;// 2
        virtual void bind() = 0;// 3
        virtual void free() = 0;// 4
        virtual void getHandle() = 0;// 5
        virtual void
        setFiltration(ITexture::FilterType::Type, ITexture::FilterType::Type, ITexture::FilterType::Type) = 0;//  6
        virtual void setFiltration(ITexture::FilterType::Type, ITexture::FilterType::Type) = 0;// 7
        virtual void
        setClamping(ITexture::ClampMode::Type, ITexture::ClampMode::Type, ITexture::ClampMode::Type) = 0;// 8
        virtual void setClamping(ITexture::ClampMode::Type) = 0;// 9
        virtual void setBorderColor(Color const &) = 0;// 10
        virtual void
        load(void const *, ITexture::InputFormat::Type, uint32_t, uint32_t, ITexture::Format::Type) = 0;// 11
        virtual void
        loadMipMaps(void const *, ITexture::InputFormat::Type, uint32_t, uint32_t, ITexture::Format::Type) = 0;// 12
        virtual void setAnisotropy(double) = 0;// 13
        virtual void width() = 0;// 14
        virtual void height() = 0;// 15
    };
}

