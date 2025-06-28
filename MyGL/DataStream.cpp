#include "DataStream.h"

namespace MyGL {
    DataStream::DataStream(IData &d, IShaderEnvironment *e) {
        this->data = d;
        this->env = e;
    }

    DataStream::DataStream(IData *d, IShaderEnvironment *e) {
        this->data = d;
        this->env = e;
    }

    DataStream::DataStream(IScene *s) {
        __int64 v2;

        this->data = s->dataControl();
        v2 = s->shaderLoader();
        this->env = (IShaderEnvironment *) (*(__int64 (__fastcall **)(__int64)) (*(_QWORD *) v2 + 32LL))(v2);
    }

    DataStream::DataStream(IScene &s) {
        __int64 v2;

        this->data = s->dataControl();
        v2 = s->shaderLoader();
        this->env = (IShaderEnvironment *) (*(__int64 (__fastcall **)(__int64)) (*(_QWORD *) v2 + 32LL))(v2);
    }

    void *DataStream::add(IModel *model, const std::string &name) {
        this->data->addModel(name, model);
        return this;
    }

    void *DataStream::add(IShader *sh, const std::string &name) {
        this->data->addShader(name, sh);
        return this;
    }

    void *DataStream::add(ITexture2d *texture, const std::string &name) {
        this->data->addTexture(name, texture);
        return this;
    }

    void *DataStream::addModel(const std::string &name, const std::string &file) {
        this->data->addModel(file, name);
        return this;
    }

    void *DataStream::addModelBin_v0(const std::string &name, const std::string &file) {
        this->data->addModelBin_v0(name, file);
        return this;
    }

    void *DataStream::addShader(const std::string &name, const std::string &vs, const std::string &fs_0) {
        this->data->addShader(name, vs, fs_0, 1LL);
        return this;
    }

    void *DataStream::addTexture(const std::string &name, const std::string &file) {
        this->data->addTexture(name, file);
        return this;
    }

    void DataStream::popShaderDef(const std::string &name) {
        this->env->pop(name);
    }

    void DataStream::pushShaderDef(const std::string &name) {
        this->pushShaderDef(name, unk_4D39E1);
    }

    void DataStream::pushShaderDef(const std::string &name, const std::string &val) {
        this->env->push(name, val);
    }
}