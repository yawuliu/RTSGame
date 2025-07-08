#pragma once

#include <string>
#include "DisableCopy.h"

namespace MyGL {
    class ITexture2d;

    class IDataLoader;

    class IModel;

    class IShader;

    class IData : public DisableCopy {
    public:
        IData() = default;

        virtual ~IData() = default; //0
        // virtual void ~Data() = 0; //1
        virtual void clear() = 0;//2
        virtual IDataLoader *loader() = 0;//3
        virtual ITexture2d *addTexture(char const *, ITexture2d *) = 0;//4
        virtual ITexture2d *addTexture(char const *, char const *) = 0;//5
        virtual ITexture2d *texture(char const *) = 0;//6
        virtual ITexture2d *texture(std::string const &) = 0;//7
        virtual IModel *addModel(char const *, IModel *) = 0;//8
        virtual IModel *addModel(char const *, char const *) = 0;//9
        virtual IModel *addModelBin_v0(char const *, char const *) = 0;//10
        virtual IModel *model(char const *) = 0;//11
        virtual IModel *model(std::string const &) = 0;//12
        virtual IShader *addShader(char const *, IShader *) = 0;//13
        virtual IShader *addShader(char const *, char const *, char const *, bool) = 0;//14
        virtual IShader *shader(char const *) = 0;//15
        virtual IShader *shader(std::string const &) = 0;//16
    };
}


