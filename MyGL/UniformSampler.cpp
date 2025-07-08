#include "UniformSampler.h"
#include "IUniform.h"
#include "IShader.h"

namespace MyGL {
    UniformSampler::UniformSampler(IShader *sh, CGL::ShaderHandle h) {
        this->handle = h;
        this->shader = sh;
        this->dat = 0;
    }

    int UniformSampler::get() {
        return this->dat;
    }

    CGL::ShaderHandle *UniformSampler::handlePtr() {
        return &this->handle;
    }

    bool UniformSampler::isEqual(IUniform *u) {
        if (u->owner() == this->owner()) {
            if (this->handle == *(u->handlePtr()))
                return 1;
        }
        return 0;
    }

    IShader *UniformSampler::owner() {
        return this->shader;
    }

    void UniformSampler::sendDataToGPU() {
        this->shader->gl()->ext()->glUniform1iARB(this->handle, this->dat);
    }

    void UniformSampler::set(int x) {
        if (this->dat != x) {
            this->dat = x;
            this->shader->updateUniform(this);
        }
    }
}