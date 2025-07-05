#pragma once

#include <cstdint>

#include "DisableCopy.h"
#include "Data.h"

namespace MyGL {
    class IErrorControl;

    class privateGLSupportClass;

    class CGL : public DisableCopy {
    public:
        typedef double GLdouble;
        typedef void *GLextFuncPtr;
        typedef float GLfloat;
        typedef int GLint;
        typedef int GLsizei;
        typedef unsigned int GLuint;
        typedef int ShaderHandle;
        typedef unsigned int TextureHandle;
        typedef unsigned int TextureUnitHandle;
        typedef unsigned int VertexBufferHandle;

    public:
        CGL();

        virtual ~CGL();

        void createExtObject(CGL &glD);

        IErrorControl *errorCtrl();

        privateGLSupportClass *ext();

        CGL::GLextFuncPtr getProcAddress(const char *f);

        void initAnisotropy();

        Bool initFBO_API();

        template<class T>
        bool initGlExtensionFuncPtr(T func, const char *name) {
            *func = (T) this->getProcAddress(name);
            return *func != 0LL;
        }

        Bool initShaderAPI();

        Bool initTextureAPI();

        Bool initVBO_API();

        Bool isAnisotropySupported();

        Bool isDXTFormatSupported();

        bool isExtensionSupported(const char *name);

        Float maxAnisotropyLevel();

        void setErrorCtrl(IErrorControl *e);

    protected:
        Bool isDXT_supr;
        Bool isVBOInit;
        Bool isShadingInit;
        Bool isTexturesInit;
        Bool isFBO_Init;
        // padding byte
        // padding byte
        // padding byte
        Float maxAnisotropyLevel_val;
        privateGLSupportClass *gLSupport;
        IErrorControl *eCtrl;
        bool autoECtrl;
        // padding byte
        // padding byte
        // padding byte
        // padding byte
        // padding byte
        // padding byte
        // padding byte
    };
}


