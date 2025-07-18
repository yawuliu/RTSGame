#include "CGL.h"
#include "ErrorControl.h"
#include "IErrorControl.h"
#include "privateGLSupportClass.h"

namespace MyGL {
    CGL::CGL() {
        this->eCtrl = new ErrorControl();
        this->autoECtrl = 1;
        this->isDXT_supr = 0;
        this->isFBO_Init = 0;
        this->isVBOInit = 0;
        this->isShadingInit = 0;
        this->isTexturesInit = 0;
        this->maxAnisotropyLevel_val = -1.0;
        this->gLSupport = 0LL;
    }

    CGL::~CGL() {
        delete this->gLSupport;
        if (this->autoECtrl) {
            if (this->eCtrl)
                delete this->eCtrl;
        }
    }

    void CGL::createExtObject(CGL &glD) {
        if (!glD.gLSupport) {
            glD.gLSupport = new privateGLSupportClass(glD);;
        }
    }

    IErrorControl *CGL::errorCtrl() {
        return this->eCtrl;
    }

    privateGLSupportClass *CGL::ext() {
        return this->gLSupport;
    }

    CGL::GLextFuncPtr CGL::getProcAddress(const char *f) {
        return (CGL::GLextFuncPtr) glXGetProcAddressARB(f);
    }

    void CGL::initAnisotropy() {
        int g_nMaxAnisotropy;

        if (this->maxAnisotropyLevel_val < 0.0) {
            this->maxAnisotropyLevel_val = 0.0;
            if (this->isExtensionSupported("GL_EXT_texture_filter_anisotropic")) {
                glGetIntegerv(34047LL, &g_nMaxAnisotropy);
                this->maxAnisotropyLevel_val = (double) g_nMaxAnisotropy;
            }
        }
    }

    Bool CGL::initFBO_API() {
        if (this->isFBO_Init)
            return 1;
        if (!this->isExtensionSupported("GL_EXT_framebuffer_object"))
            return 0;
        this->isFBO_Init = this->ext()->initFBO_API();
        return this->isFBO_Init;
    }

    Bool CGL::initShaderAPI() {
        privateGLSupportClass *v3;

        if (this->isShadingInit)
            return 1;
        if (!this->isExtensionSupported("GL_ARB_shader_objects")
            || !this->isExtensionSupported("GL_ARB_shading_language_100")
            || !this->isExtensionSupported("GL_ARB_vertex_shader")
            || !this->isExtensionSupported("GL_ARB_fragment_shader")) {
            return 0;
        }
        this->isShadingInit = this->ext()->initShadersAPI();
        return this->isShadingInit;
    }

    Bool CGL::initTextureAPI() {
        privateGLSupportClass *v2;

        if (this->isTexturesInit)
            return 1;
        this->isDXT_supr = this->isExtensionSupported("GL_EXT_texture_compression_s3tc");
        this->isTexturesInit = this->ext()->initTextureAPI();
        return this->isTexturesInit;
    }

    Bool CGL::initVBO_API() {
        privateGLSupportClass *v2;

        if (this->isVBOInit)
            return 1;
        if (!this->isExtensionSupported("GL_ARB_vertex_buffer_object"))
            return 0;
        this->isVBOInit = this->ext()->initVBO_API();
        return this->isVBOInit;
    }

    Bool CGL::isAnisotropySupported() {
        this->initAnisotropy();
        return this->maxAnisotropyLevel_val > 0.0;
    }

    Bool CGL::isDXTFormatSupported() {
        return this->isDXT_supr;
    }

    bool CGL::isExtensionSupported(const char *name) {
        char *ext;
        bool r;
        int id;
        int i;

        ext = (char *) glGetString(7939LL);
        i = 0;
        if (ext) {
            while (ext[i]) {
                r = 1;
                while (ext[i] == 32)
                    ++i;
                id = 0;
                while (ext[i] && ext[i] != 32) {
                    r = (r & (ext[i++] == name[id])) != 0;
                    if (name[id])
                        ++id;
                }
                if (r && name[id] == 0)
                    return 1;
            }
        }
        return 0;
    }

    Float CGL::maxAnisotropyLevel() {
        this->initAnisotropy();
        return this->maxAnisotropyLevel_val;
    }

    void CGL::setErrorCtrl(IErrorControl *e) {
        if (e) {
            if (this->eCtrl)
                delete this->eCtrl;
            this->eCtrl = e;
            this->autoECtrl = 0;
        } else if (!this->autoECtrl) {
            this->eCtrl = new ErrorControl();
            this->autoECtrl = 1;
        }
    }
}