#include "AbstractShader.h"

namespace MyGL {
    AbstractShader::AbstractShader(IRender *r) : mrender(r) {

    }


    AbstractShader::~AbstractShader() {
        for (size_t i = 0LL; this->unif.size() > i; ++i) {
            auto &v1 = this->unif[i];
            if (v1)
                delete v1;
        }
    }

    CGL *AbstractShader::gl() {
        return this->mrender->gl();
    }

    IUniform *AbstractShader::registerUniform(IUniform *u) {
        IUniform *ua = u;
        IUniform *rep = 0LL;
        for (size_t i = 0LL;; ++i) {
            auto &v5 = this->uniforms();
            if (v5.size() <= i)
                break;
            auto &v2 = this->uniforms();
            auto &v3 = v2[i];
            if (v3->isEqual(ua)) {
                auto &v4 = this->uniforms();
                rep = v4[i];
            }
        }
        if (rep) {
            if (ua)
                delete ua;
            return rep;
        } else {
            this->unif.push_back(&ua);
        }
        return ua;
    }

    IRender *AbstractShader::render() {
        return this->mrender;
    }

    void AbstractShader::sendUniformsToGPU() {
        for (size_t i = 0LL;; ++i) {
            auto &v3 = this->uniforms();
            if (v3.size() <= i)
                break;
            auto &v1 = this->uniforms();
            auto &v2 = v1[i];
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