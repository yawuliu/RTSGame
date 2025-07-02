#include "privateGLSupportClass.h"

namespace MyGL {
    privateGLSupportClass::privateGLSupportClass(CGL &glD) {
        this->gl = &glD;
        this->wasFBOInit = 0;
        this->wasInitShaders = 0;
        this->wasInitTextureAPI = 0;
        this->wasInitVBO = 0;
    }

    uint32_t  MyGL::privateGLSupportClass::dxtFormat[4] = {0x83F0, 0x83F1, 0x83F2, 0x83F3};
    uint32_t  MyGL::privateGLSupportClass::gpuFormat[22] = {
            0x1909, 0x803F, 0x8040, 0x8042, 0x1907, 0x804F, 0x8050, 0x8052,
            0x8053, 0x8054, 0x1908, 0x8058, 0x8059, 0x805A, 0x805B, 0x1907,
            0x1908, 0x1908, 0x1908, 0x81A5, 0x81A6, 0x81A7
    };

    uint32_t privateGLSupportClass::toGlColorSystem(IRender *render, ITexture::Format::Type colorSystem) {
        CGL *v2;

        v2 = render->gl();
        if (v2->isDXTFormatSupported()
            && (colorSystem == ITexture::Format::Type::RGB_DXT1
                || colorSystem == ITexture::Format::Type::RGBA_DXT1
                || colorSystem == ITexture::Format::Type::RGBA_DXT3
                || colorSystem == ITexture::Format::Type::RGBA_DXT5)) {
            return MyGL::privateGLSupportClass::dxtFormat[colorSystem - 15];
        } else {
            return MyGL::privateGLSupportClass::gpuFormat[colorSystem];
        }
    }

    uint32_t  MyGL::privateGLSupportClass::inputFormat[5] = {0x1909, 0x1907, 0x1908, 0x1902, 0x1908};

    uint32_t privateGLSupportClass::toGlInputFormat(IRender *a1, ITexture::InputFormat::Type imgColorSystem) {
        return inputFormat[imgColorSystem];
    }

    bool privateGLSupportClass::initVBO_API() {
        bool wasInitVBO;

        if (this->wasInitVBO)
            return true;
        wasInitVBO = initGlExtensionFuncPtr(&this->glGenBuffersARB, "glGenBuffersARB")
                     && initGlExtensionFuncPtr(&this->glBindBufferARB, "glBindBufferARB")
                     && initGlExtensionFuncPtr(
                &this->glBufferDataARB,
                "glBufferDataARB")
                     && initGlExtensionFuncPtr(

                &this->glDeleteBuffersARB,
                "glDeleteBuffersARB")
                     && initGlExtensionFuncPtr(

                &this->glMultiDrawArraysEXT,
                "glMultiDrawArraysEXT")
                     && initGlExtensionFuncPtr(

                &this->glMapBufferARB,
                "glMapBufferARB")
                     && initGlExtensionFuncPtr(

                &this->glUnmapBufferARB,
                "glUnmapBufferARB")
                     && initGlExtensionFuncPtr(

                &this->glBufferSubDataARB,
                "glBufferSubDataARB");
        this->wasInitVBO = wasInitVBO;
        return this->wasInitVBO;
    }

    bool privateGLSupportClass::initTextureAPI() {
        if (this->wasInitTextureAPI)
            return true;
        this->wasInitTextureAPI = initGlExtensionFuncPtr(
                &this->glActiveTextureARB,
                "glActiveTextureARB");
        return this->wasInitTextureAPI;
    }

    bool privateGLSupportClass::initShadersAPI() {
        bool wasInitShaders;

        if (this->wasInitShaders)
            return true;
        wasInitShaders = initGlExtensionFuncPtr(
                &this->glUniform1fARB,
                "glUniform1fARB")
                         && initGlExtensionFuncPtr(
                &this->glUniform1iARB,
                "glUniform1iARB")
                         && initGlExtensionFuncPtr(
                &this->glUniform4fARB,
                "glUniform4fARB")
                         && initGlExtensionFuncPtr(
                &this->glUniform4iARB,
                "glUniform4iARB")
                         && initGlExtensionFuncPtr(
                &this->glUniformMatrix4fv,
                "glUniformMatrix4fv");
        this->wasInitShaders = wasInitShaders;
        return this->wasInitShaders;
    }

    bool privateGLSupportClass::initFBO_API() {
        bool wasFBOInit;

        if (this->wasFBOInit)
            return true;
        wasFBOInit = initGlExtensionFuncPtr(
                &this->glIsRenderbufferEXT,
                "glIsRenderbufferEXT")
                     && initGlExtensionFuncPtr(
                &this->glBindRenderbufferEXT,
                "glBindRenderbufferEXT")
                     && initGlExtensionFuncPtr(
                &this->glDeleteRenderbuffersEXT,
                "glDeleteRenderbuffersEXT")
                     && initGlExtensionFuncPtr(
                &this->glGenRenderbuffersEXT,
                "glGenRenderbuffersEXT")
                     && initGlExtensionFuncPtr(
                &this->glRenderbufferStorageEXT,
                "glRenderbufferStorageEXT")
                     && initGlExtensionFuncPtr(
                &this->glGetRenderbufferParameterivEXT,
                "glGetRenderbufferParameterivEXT")
                     && initGlExtensionFuncPtr(
                &this->glIsFramebufferEXT,
                "glIsFramebufferEXT")
                     && initGlExtensionFuncPtr(
                &this->glBindFramebufferEXT,
                "glBindFramebufferEXT")
                     && initGlExtensionFuncPtr(
                &this->glDeleteFramebuffersEXT,
                "glDeleteFramebuffersEXT")
                     && initGlExtensionFuncPtr(
                &this->glGenFramebuffersEXT,
                "glGenFramebuffersEXT")
                     && initGlExtensionFuncPtr(
                &this->glCheckFramebufferStatusEXT,
                "glCheckFramebufferStatusEXT")
                     && initGlExtensionFuncPtr(
                &this->glFramebufferTexture1DEXT,
                "glFramebufferTexture1DEXT")
                     && initGlExtensionFuncPtr(
                &this->glFramebufferTexture2DEXT,
                "glFramebufferTexture2DEXT")
                     && initGlExtensionFuncPtr(
                &this->glFramebufferTexture3DEXT,
                "glFramebufferTexture3DEXT")
                     && initGlExtensionFuncPtr(
                &this->glFramebufferRenderbufferEXT,
                "glFramebufferRenderbufferEXT")
                     && initGlExtensionFuncPtr(
                &this->glRenderbufferStorageEXT,
                "glRenderbufferStorageEXT")
                     && initGlExtensionFuncPtr(
                &this->glGetFramebufferAttachmentParameterivEXT,
                "glGetFramebufferAttachmentParameterivEXT")
                     && initGlExtensionFuncPtr(
                &this->glGenRenderbuffersEXT,
                "glGenRenderbuffersEXT")
                     && initGlExtensionFuncPtr(
                &this->glGenerateMipmapEXT,
                "glGenerateMipmapEXT");
        this->wasFBOInit = wasFBOInit;
        return this->wasFBOInit;
    }

    bool privateGLSupportClass::initColorAPI() {
        return initGlExtensionFuncPtr(&this->glClampColorARB, "glClampColorARB");
    }
}