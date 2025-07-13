#include "FBO.h"
#include "IRender.h"
#include <gl/GL.h>

namespace MyGL {
    FBO::FBO(IRender &r, unsigned int theWidth, unsigned int theHeight, FBO::Flags::BitMap f) : ext(r.gl()->ext()) {
        this->w = theWidth;
        this->h = theHeight;
        this->flags = f;
        this->frameBuffer = 0;
        this->depthBuffer = 0;
        this->stencilBuffer = 0;
        this->create();
    }

    FBO::~FBO() {
        if (this->depthBuffer)
            this->ext->glDeleteRenderbuffersEXT(1LL, &this->depthBuffer);
        if (this->stencilBuffer)
            this->ext->glDeleteRenderbuffersEXT(1LL, &this->stencilBuffer);
        if (this->frameBuffer)
            this->ext->glDeleteFramebuffersEXT(1LL, &this->frameBuffer);
    }

    bool FBO::create() {
        bool complete;
        GLenum stencilFormat;
        GLenum depthFormat;

        if (this->w > 0x84E7 || this->h > 0x84E7)
            return 0;
        this->ext->glGenFramebuffersEXT(1LL, &this->frameBuffer);
        this->ext->glBindFramebufferEXT(36160LL, this->frameBuffer);
        depthFormat = 0;
        stencilFormat = 0;
        if ((this->flags & 1) != 0) {
            depthFormat = 33189;
        } else if ((this->flags & 2) != 0) {
            depthFormat = 33190;
        } else if ((this->flags & 4) != 0) {
            depthFormat = 33191;
        } else if ((this->flags & 8) != 0) {
            depthFormat = 6402;
        }
        if ((this->flags & 0x10) != 0) {
            stencilFormat = 36166;
        } else if ((this->flags & 0x20) != 0) {
            stencilFormat = 36167;
        } else if ((this->flags & 0x40) != 0) {
            stencilFormat = 36168;
        } else if ((this->flags & 0x80) != 0) {
            stencilFormat = 36169;
        }
        if (depthFormat) {
            this->ext->glGenRenderbuffersEXT(1LL, &this->depthBuffer);
            this->ext->glBindRenderbufferEXT(36161LL, this->depthBuffer);
            this->ext->glRenderbufferStorageEXT(36161LL, depthFormat, this->w, this->h);
            this->ext->glFramebufferRenderbufferEXT(36160LL, 36096LL, 36161LL, this->depthBuffer);
        }
        if (stencilFormat) {
            this->ext->glGenRenderbuffersEXT(1LL, &this->stencilBuffer);
            this->ext->glBindRenderbufferEXT(36161LL, this->stencilBuffer);
            this->ext->glRenderbufferStorageEXT(36161LL, stencilFormat, this->w, this->h);
            this->ext->glFramebufferRenderbufferEXT(36160LL, 36128LL, 36161LL, this->stencilBuffer);
        }
        complete = this->ext->glCheckFramebufferStatusEXT(36160LL) == 36053;
        this->ext->glBindFramebufferEXT(36160LL, 0LL);
        return complete;
    }

    std::string FBO::status() {
        unsigned int currentFb;
        glGetIntegerv(36006LL, &currentFb);
        if (this->frameBuffer != currentFb)
            this->ext->glBindFramebufferEXT(36160LL, this->frameBuffer);
        GLenum complete = this->ext->glCheckFramebufferStatusEXT(36160LL);
        if (complete == 36053)
            return "GL_FRAMEBUFFER_COMPLETE_EXT";
        if (complete == 36054)
            return "GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT_EXT";
        if (complete == 36055)
            return "GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT_EXT";
        if (complete == 36057)
            return "GL_FRAMEBUFFER_INCOMPLETE_DIMENSIONS_EXT";
        if (complete == 36057)
            return "GL_FRAMEBUFFER_INCOMPLETE_DIMENSIONS_EXT";
        if (complete == 36058)
            return "GL_FRAMEBUFFER_INCOMPLETE_FORMATS_EXT";
        if (complete == 36059)
            return "GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER_EXT";
        if (complete == 36060)
            return "GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER_EXT";
        if (complete == 36061)
            return "GL_FRAMEBUFFER_UNSUPPORTED_EXT";
        if (this->frameBuffer != currentFb)
            this->ext->glBindFramebufferEXT(36160LL, currentFb);
        return "";
    }

    bool FBO::validate() {
        unsigned int currentFb;
        glGetIntegerv(36006LL, &currentFb);
        if (this->frameBuffer != currentFb)
            this->ext->glBindFramebufferEXT(36160LL, this->frameBuffer);
        bool complete = this->ext->glCheckFramebufferStatusEXT(36160LL) == 36053;
        if (this->frameBuffer != currentFb)
            this->ext->glBindFramebufferEXT(36160LL, currentFb);
        return complete;
    }

    bool FBO::bind() {
        if (!this->frameBuffer)
            return 0;
        this->ext->glBindFramebufferEXT(36160LL, this->frameBuffer);
        return 1;
    }

    bool FBO::unbind() {
        if (!this->frameBuffer)
            return 0;
        this->ext->glBindFramebufferEXT(36160LL, 0LL);
        return 1;
    }

    bool FBO::attachColorTexture(ITexture2d *target, int no) {
        PFNGLFRAMEBUFFERTEXTURE2DEXTPROC glFramebufferTexture2DEXT;
        GLuint *v5;

        if (!this->frameBuffer)
            return 0;
        glFramebufferTexture2DEXT = this->ext->glFramebufferTexture2DEXT;
        v5 = target->getHandle();
        glFramebufferTexture2DEXT(36160LL, no + 36064, 3553LL, *v5, 0LL);
        return 1;
    }

    bool FBO::attachDepthTexture(ITexture2d *target) {
        PFNGLFRAMEBUFFERTEXTURE2DEXTPROC glFramebufferTexture2DEXT;
        GLuint *v4;

        if (!this->frameBuffer)
            return 0;
        glFramebufferTexture2DEXT = this->ext->glFramebufferTexture2DEXT;
        v4 = target->getHandle();
        glFramebufferTexture2DEXT(36160LL, 36096LL, 3553LL, *v4, 0LL);
        return 1;
    }

    bool FBO::attachColorTexture(ITextureRectangle *target, int no) {
        PFNGLFRAMEBUFFERTEXTURE2DEXTPROC glFramebufferTexture2DEXT;
        GLuint *v5;

        if (!this->frameBuffer)
            return 0;
        glFramebufferTexture2DEXT = this->ext->glFramebufferTexture2DEXT;
        v5 = target->getHandle();
        glFramebufferTexture2DEXT(36160LL, no + 36064, 34037LL, *v5, 0LL);
        return 1;
    }

    bool FBO::attachDepthTexture(ITextureRectangle *target) {
        PFNGLFRAMEBUFFERTEXTURE2DEXTPROC glFramebufferTexture2DEXT;
        GLuint *v4;

        if (!this->frameBuffer)
            return 0;
        glFramebufferTexture2DEXT = this->ext->glFramebufferTexture2DEXT;
        v4 = target->getHandle();
        glFramebufferTexture2DEXT(36160LL, 36096LL, 34037LL, *v4, 0LL);
        return 1;
    }

    int FBO::maxColorAttachemnts() {
        int n;

        glGetIntegerv(36063LL, &n);
        return n;
    }

    unsigned int FBO::width() {
        return this->w;
    }

    unsigned int FBO::height() {
        return this->h;
    }

    bool FBO::hasStencil() {
        return this->stencilBuffer != 0;
    }

    bool FBO::hasDepth() {
        return this->depthBuffer != 0;
    }

    bool FBO::detachColorTexture(int no) {
        if (!this->frameBuffer)
            return 0;
        this->ext->glFramebufferTexture2DEXT(36160LL, no + 36064, 3553LL, 0LL, 0LL);
        return 1;
    }

    bool FBO::detachDepthTexture() {
        if (!this->frameBuffer)
            return 0;
        this->ext->glFramebufferTexture2DEXT(36160LL, 36096LL, 3553LL, 0LL, 0LL);
        return 1;
    }
}
