#pragma once

namespace MyGL {
    class ITextureRectangle;

    class IFrameBuffer {
    public:
        float width() const;

        float height() const;

        virtual void attachColorTexture(ITextureRectangle *) = 0;

    protected:
        float mWidth;
        float mHeight;
    };
}