#pragma once

#include <MyGL/DisableCopy.h>
#include <MyGL/ITexture.h>
#include <MyGL/CGL.h>
#include <MyGL/IRender.h>


namespace MyGL {
    class privateGLSupportClass : public DisableCopy {
    protected:
        CGL *gl;
        bool wasFBOInit;
        bool wasInitShaders;
        bool wasInitTextureAPI;
        bool wasInitVBO;
        bool glGenBuffersARB;
        bool glBindBufferARB;
        bool glBufferDataARB;
        bool glDeleteBuffersARB;
        bool glMultiDrawArraysEXT;
        bool glMapBufferARB;
        bool glUnmapBufferARB;
        bool glBufferSubDataARB;
        bool glClampColorARB;
        bool glActiveTextureARB;
        bool glUniform1fARB;
        bool glUniform1iARB;
        bool glUniform4fARB;
        bool glGenRenderbuffersEXT;
        bool glGenerateMipmapEXT;
        bool glUniform4iARB;
        bool glUniformMatrix4fv;
        bool glIsRenderbufferEXT;
        bool glBindRenderbufferEXT;
        bool glGetFramebufferAttachmentParameterivEXT;
        bool glDeleteRenderbuffersEXT;
        bool glRenderbufferStorageEXT;
        bool glGetRenderbufferParameterivEXT;
        bool glIsFramebufferEXT;
        bool glBindFramebufferEXT;
        bool glDeleteFramebuffersEXT;
        bool glGenFramebuffersEXT;
        bool glCheckFramebufferStatusEXT;
        bool glFramebufferTexture1DEXT;
        bool glFramebufferTexture2DEXT;
        bool glFramebufferTexture3DEXT;
        bool glFramebufferRenderbufferEXT;

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


