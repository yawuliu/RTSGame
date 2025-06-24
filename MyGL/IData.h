#pragma once

#include <string>
#include "DisableCopy.h"
#include "IRenderState.h"

namespace MyGL {
    class IData : public DisableCopy {
    public:
        IData() = default;

        virtual ~IData() = default; //0
        // virtual void ~Data() = 0; //1
        virtual void clear(void) = 0;//2
        virtual void loader(void) = 0;//3
        virtual void addTexture(char const *, ITexture2d *) = 0;//4
        virtual void addTexture(char const *, char const *) = 0;//5
        virtual void texture(char const *) = 0;//6
        virtual void texture(std::string const &) = 0;//7
        virtual void addModel(char const *, IModel *) = 0;//8
        virtual void addModel(char const *, char const *) = 0;//9
        virtual void addModelBin_v0(char const *, char const *) = 0;//10
        virtual void model(char const *) = 0;//11
        virtual void model(std::string const &) = 0;//12
        virtual void addShader(char const *, IShader *) = 0;//13
        virtual void addShader(char const *, char const *, char const *, bool) = 0;//14
        virtual void shader(char const *) = 0;//15
        virtual void shader(std::string const &) = 0;//16
    };
}


