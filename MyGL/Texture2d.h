#pragma once

#include "ITexture2d.h"
#include "CGL.h"
#include "Color.h"

namespace MyGL {
    class IRender;

    class Texture2d : public ITexture2d {
    public:
        Texture2d(IRender &r);

        virtual  ~Texture2d();// 0
        //virtual  ~Texture2d() = default;// 1
        virtual void create() = 0;// 2
        virtual void bind() = 0;// 3
        virtual void free() = 0;// 4
        virtual CGL::TextureHandle *getHandle() = 0;// 5
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
        virtual void setAnisotropy(Float) = 0;// 13
        virtual uint32_t width() = 0;// 14
        virtual uint32_t height() = 0;// 15

        uint32_t toGlColorSystem(ITexture::Format::Type colorSystem);

        uint32_t toGlInputFormat(ITexture::InputFormat::Type imgColorSystem);

        void updateSampler();


    private:
        IRender *render;
        ITexture::FilterType::Type filterMin;
        ITexture::FilterType::Type filterMag;
        ITexture::FilterType::Type filterMip;
        ITexture::ClampMode::Type clamp[3];
        Float anisLevel;
        bool isForwardFormat;
        // padding byte
        // padding byte
        // padding byte
        unsigned int w;
        unsigned int h;
        CGL::TextureHandle handle;
        Color border_cl;
    };
}