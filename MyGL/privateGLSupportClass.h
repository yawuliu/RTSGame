#pragma once

#include "DisableCopy.h"
#include "ITexture.h"
#include "CGL.h"
#include "IRender.h"


namespace MyGL {
    class privateGLSupportClass : public DisableCopy {
    public:
        CGL *gl;
        bool wasFBOInit;
        bool wasInitShaders;
        bool wasInitTextureAPI;
        bool wasInitVBO;
        PFNGLGENBUFFERSARBPROC glGenBuffersARB;
        PFNGLBINDBUFFERARBPROC glBindBufferARB;
        PFNGLBUFFERDATAARBPROC glBufferDataARB;
        PFNGLDELETEBUFFERSARBPROC glDeleteBuffersARB;
        PFNGLMULTIDRAWARRAYSEXTPROC glMultiDrawArraysEXT;
        PFNGLMAPBUFFERARBPROC glMapBufferARB;
        PFNGLUNMAPBUFFERARBPROC glUnmapBufferARB;
        PFNGLBUFFERSUBDATAARBPROC glBufferSubDataARB;
        PFNGLCLAMPCOLORARBPROC glClampColorARB;
        PFNGLACTIVETEXTUREARBPROC glActiveTextureARB;
        PFNGLUNIFORM1FARBPROC glUniform1fARB;
        PFNGLUNIFORM1IARBPROC glUniform1iARB;
        PFNGLUNIFORM4FARBPROC glUniform4fARB;
        PFNGLGENRENDERBUFFERSEXTPROC glGenRenderbuffersEXT;
        PFNGLGENERATEMIPMAPEXTPROC glGenerateMipmapEXT;
        PFNGLUNIFORM4IARBPROC glUniform4iARB;
        PFNGLUNIFORMMATRIX4FVARBPROC glUniformMatrix4fv;
        PFNGLISRENDERBUFFEREXTPROC glIsRenderbufferEXT;
        PFNGLBINDRENDERBUFFEREXTPROC glBindRenderbufferEXT;
        PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVEXTPROC glGetFramebufferAttachmentParameterivEXT;
        PFNGLDELETERENDERBUFFERSEXTPROC glDeleteRenderbuffersEXT;
        PFNGLRENDERBUFFERSTORAGEEXTPROC glRenderbufferStorageEXT;
        PFNGLGETRENDERBUFFERPARAMETERIVEXTPROC glGetRenderbufferParameterivEXT;
        PFNGLISFRAMEBUFFEREXTPROC glIsFramebufferEXT;
        PFNGLBINDFRAMEBUFFEREXTPROC glBindFramebufferEXT;
        PFNGLDELETEFRAMEBUFFERSEXTPROC glDeleteFramebuffersEXT;
        PFNGLGENFRAMEBUFFERSEXTPROC glGenFramebuffersEXT;
        PFNGLCHECKFRAMEBUFFERSTATUSEXTPROC glCheckFramebufferStatusEXT;
        PFNGLFRAMEBUFFERTEXTURE1DEXTPROC glFramebufferTexture1DEXT;
        PFNGLFRAMEBUFFERTEXTURE2DEXTPROC glFramebufferTexture2DEXT;
        PFNGLFRAMEBUFFERTEXTURE3DEXTPROC glFramebufferTexture3DEXT;
        PFNGLFRAMEBUFFERRENDERBUFFEREXTPROC glFramebufferRenderbufferEXT;

    public:
        privateGLSupportClass(CGL &glD);

        static const void *toGlColorSystem(IRender &render, ITexture::Format::Type colorSystem);

        static const void *toGlInputFormat(IRender &a1, ITexture::InputFormat::Type imgColorSystem);

        bool initVBO_API();

        bool initTextureAPI();

        bool initShadersAPI();

        bool initFBO_API();

        bool initColorAPI();

        template<class T>
        bool initGlExtensionFuncPtr(T func, const char *name) {
            return initGlExtensionFuncPtr(this->gl, func, name);
        }
    };
}


