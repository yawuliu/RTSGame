#pragma once

#include "ITexture2d.h"

namespace MyGL {
    class ITextureRectangle : public ITexture {
    public:
        ITextureRectangle() = default;

        virtual ~ITextureRectangle() = default;

        virtual void load(unsigned char *, ITexture::InputFormat, int, int, ITexture::Format) = 0;

        virtual float width() const = 0;

        virtual float height() const = 0;

        virtual void loadMipMaps(unsigned char *, ITexture::InputFormat, int, int, ITexture::Format) = 0;

        virtual void bind(unsigned int unit) = 0;

        virtual void unbind() = 0;

        virtual int getWidth() const = 0;

        virtual int getHeight() const = 0;
    };
}