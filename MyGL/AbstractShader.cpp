#include "AbstractShader.h"

namespace MyGL {
    AbstractShader::AbstractShader(IRender *r) : mrender(r) {

    }


    AbstractShader::~AbstractShader() {
        IUniform *v1;
        std::vector<IUniform *>::size_type i;
        for (i = 0LL; std::vector<IUniform *>::size(&this->unif) > i; ++i) {
            v1 = *std::vector<IUniform *>::operator[](&this->unif, i);
            if (v1)
                delete v1;
        }
    }

    CGL *AbstractShader::gl() {
        return this->mrender->gl();
    }

    IUniform *AbstractShader::registerUniform(IUniform *u) {
        std::vector<IUniform *> *v2;
        std::vector<IUniform *>::reference v3;
        std::vector<IUniform *> *v4;
        std::vector<IUniform *> *v5;
        IUniform *ua;
        AbstractShader *thisa;
        size_t i;
        IUniform *rep;

        thisa = this;
        ua = u;
        rep = 0LL;
        for (i = 0LL;; ++i) {
            v5 = this->uniforms();
            if (std::vector<IUniform *>::size(v5) <= i)
                break;
            v2 = this->uniforms();
            v3 = std::vector<IUniform *>::operator[](v2, i);
            if (v3->isEqual(ua)) {
                v4 = this->uniforms();
                rep = *std::vector<IUniform *>::operator[](v4, i);
            }
        }
        if (rep) {
            if (ua)
                delete ua;
            return rep;
        } else {
            std::vector<IUniform *>::push_back(&thisa->unif, &ua);
        }
        return ua;
    }

    IRender *AbstractShader::render() {
        return this->mrender;
    }

    void AbstractShader::sendUniformsToGPU() {
        std::vector<IUniform *> *v1;
        std::vector<IUniform *>::reference v2;
        std::vector<IUniform *> *v3;
        std::vector<IUniform *>::size_type i;

        for (i = 0LL;; ++i) {
            v3 = this->uniforms();
            if (std::vector<IUniform *>::size(v3) <= i)
                break;
            v1 = this->uniforms();
            v2 = std::vector<IUniform *>::operator[](v1, i);
            v2->sendDataToGPU();
        }
    }


    std::vector<IUniform *> *AbstractShader::uniforms() {
        return &this->unif;
    }

    void AbstractShader::updateUniform(IUniform *uniform) {
        __int64 v2;

        v2 = this->render();
        if ((*(unsigned __int8 (__fastcall **)(__int64, AbstractShader *const)) (*(_QWORD *) v2 + 112LL))(v2, this))
            uniform->sendDataToGPU();
    }

}