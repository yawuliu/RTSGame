#pragma once

#include <string>
#include "IData.h"
#include "IScene.h"

namespace MyGL {
    class IShaderEnvironment;

    class DataStream {
    public:
        DataStream(IData &d, IShaderEnvironment *e);

        DataStream(IData *d, IShaderEnvironment *e);

        explicit DataStream(IScene &s);

        explicit DataStream(IScene *s);

        void *add(IModel *model, const std::string &name);

        void *add(IShader *sh, const std::string &name);

        void *add(ITexture2d *texture, const std::string &name);

        void *addModel(const std::string &name, const std::string &file);

        void *addModelBin_v0(const std::string &name, const std::string &file);

        void *addShader(const std::string &name, const std::string &vs, const std::string &fs_0);

        void *addTexture(const std::string &name, const std::string &file);

        void popShaderDef(const std::string &name);

        void pushShaderDef(const std::string &name);

        void pushShaderDef(const std::string &name, const std::string &val);

    protected:
        IData *data;
        IShaderEnvironment *env;
    };
}