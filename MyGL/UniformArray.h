#pragma once

#include <algorithm>
#include <stdexcept>
#include <QOpenGLContext>
#include "CGL.h"
#include "IShader.h"
#include "UniformMatrix4x4.h"
#include "AbstractShader.h"
#include "IUniformArray.h"


namespace MyGL {
    template<typename T>
    class UniformArray : public IUniformArray<T> {
    public:
        class Data {
        public:
            Data(IShader *sh, CGL::ShaderHandle _handle, int s);

            virtual ~Data();

        protected:
            CGL::GLfloat *data;
            std::vector<UniformMatrix4x4 *> uniform;
            CGL::ShaderHandle handle;
            int size;
        };

    public:
        UniformArray(IShader *sh, CGL::ShaderHandle handle, int s) {
            this->shader = sh;
            this->data = new Data::Data(sh, handle, s);
            this->data->handle = handle;
        }

        virtual ~UniformArray() {
            if (this->data) {
                delete this->data;
            }
        }

        IUniformMatrix4x4 *at(int id) {
            return this->data->uniform[id];
        }

        const void *handlePtr() {
            return &this->data->handle;
        }

        bool isEqual(IUniform *u) {
            if (u->owner() == this->owner()) {
                if (this->data->handle == *u->handlePtr())
                    return 1;
            }
            return 0;
        }

        IUniformMatrix4x4 *operator[](int id) {
            return this->set((unsigned int) id);
        }

        IShader *owner() {
            return this->shader;
        }

        void sendDataToGPU() {
            CGL *v1;
            PFNGLUNIFORMMATRIX4FVARBPROC glUniformMatrix4fv;
            CGL::GLfloat *data;
            GLsizei v4;

            v1 = this->shader->gl();
            glUniformMatrix4fv = v1->ext()->glUniformMatrix4fv;
            data = this->data->data;
            v4 = this->size();
            glUniformMatrix4fv(this->data->handle, v4, 0LL, data);
        }

        int size() {
            return this->data->size;
        }

    private:
        UniformArray<T>::Data *data;
        IShader *shader;
    };

    template<class T>
    UniformArray<T> *uniformArray(AbstractShader *const sh, int location, int s) {
        UniformArray<T> *u;

        if (location < 0)
            return 0LL;
        u = (UniformArray<T> *) operator new(0x18uLL);
        UniformArray<T>::UniformArray(u, sh, location, s);
        return (UniformArray<T> *) AbstractShader::registerUniform(sh, u);
    }

    template<typename T>
    UniformArray<T>::Data::Data(IShader *sh, CGL::ShaderHandle _handle, int s) {
        this->size = s;
        this->data = new CGL::GLfloat[64LL * s];
        this->handle = _handle;
        for (int i = 0; i < s; ++i) {
            auto x = new UniformMatrix4x4(sh, this->handle, &this->data[16 * (int64_t) i]);
            this->uniform.push_back(x);
        }
    }

    template<typename T>
    UniformArray<T>::Data::~Data() {
        for (int i = 0; this->size > i; ++i) {
            auto v1 = this->uniform[i];
            if (v1)
                delete v1;
        }
        delete this->data;
    }
}
