#include "Uniform1f.h"

namespace MyGL {
    Uniform1f::Uniform1f(IShader *sh, CGL::ShaderHandle h) {
        this->handle = h;
        this->shader = sh;
        this->dat = 0.0;
    }

    CGL::ShaderHandle *Uniform1f::handlePtr() {
        return &this->handle;
    }

    bool Uniform1f::isEqual(IUniform *u) {
        if (u->owner() == this->owner()) {
            if (this->handle == *u->handlePtr())
                return 1;
        }
        return 0;
    }

    IShader *Uniform1f::owner() {
        return this->shader;
    }

    void Uniform1f::sendDataToGPU() {
        this->shader->gl()->ext()->glUniform1fARB(this->handle, this->dat);
    }

    void Uniform1f::set(Float x) {
        if (this->dat != x) {
            this->dat = x;
            this->shader->updateUniform(
                    this);
        }
    }
}