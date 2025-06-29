#include "UniformMatrix4x4.h"
#include <cstring>
#include "IShader.h"

namespace MyGL {
    UniformMatrix4x4::UniformMatrix4x4(IShader *sh, CGL::ShaderHandle h) {
        int i;
        this->handle = h;
        this->shader = sh;
        this->dat = this->data;
        for (i = 0; i <= 15; ++i)
            this->dat[i] = 0.0;
    }

    UniformMatrix4x4::UniformMatrix4x4(IShader *sh, CGL::ShaderHandle h, CGL::GLfloat *dataPtr) {
        this->handle = h;
        this->shader = sh;
        this->dat = dataPtr;
        for (int i = 0; i <= 15; ++i)
            this->dat[i] = 0.0;
    }

    CGL::ShaderHandle *UniformMatrix4x4::handlePtr() {
        return &this->handle;
    }

    bool UniformMatrix4x4::isEqual(IUniform *u) {
        if (u->owner() == this->owner()) {
            if (this->handle == *u->handlePtr())
                return 1;
        }
        return 0;
    }

    IShader *UniformMatrix4x4::owner() {
        return this->shader;
    }

    void UniformMatrix4x4::sendDataToGPU() {
        this->shader->gl()->ext()->glUniformMatrix4fv(this->handle, 1LL, 0LL, this->dat);
    }

    void UniformMatrix4x4::set(const Float *data) {
        int i;

        for (i = 0; i <= 15; ++i)
            this->dat[i] = _mm_unpacklo_pd((__m128d) *(unsigned __int64 *) &data[i],
                                           (__m128d) *(unsigned __int64 *) &data[i]).m128d_f64[0];

        this->shader->updateUniform(
                this);
    }
}
