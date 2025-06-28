#pragma once


#include "IFBO.h"
#include "IRender.h"

namespace MyGL {
    class FBO : public IFBO {
    public:
        class Flags {
        public:
            typedef int BitMap;
        };

    public:
        FBO(IRender &r, unsigned int theWidth, unsigned int theHeight, FBO::Flags::BitMap f);

        virtual ~FBO();

        bool create();

        virtual std::string status() override;

        virtual bool validate() override;

        virtual bool bind() override;

        virtual bool unbind() override;

        virtual bool attachColorTexture(ITexture2d *target, int no) override;

        virtual bool attachDepthTexture(ITexture2d *target) override;

        virtual bool attachColorTexture(ITextureRectangle *target, int no) override;

        virtual bool attachDepthTexture(ITextureRectangle *target) override;

        virtual int maxColorAttachemnts() override;

        virtual uint32_t width() override;

        virtual uint32_t height() override;

        virtual bool hasStencil() override;

        virtual bool hasDepth() override;

        virtual bool detachColorTexture(int no) override;

        virtual bool detachDepthTexture() override;

    protected:
        int frameBuffer;
        int depthBuffer;
        int stencilBuffer;
        int ext;
        int w;
        int h;
        int flags;
    };
}