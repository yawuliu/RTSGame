#pragma once

#include <string>
#include "IModelLoader.h"
#include "IRender.h"
#include "IModel.h"
#include "IOModel.h"
#include "IErrorControl.h"

namespace MyGL {
    class ModelLoader : public IModelLoader {
    public:
        explicit ModelLoader(IRender &r);

        ~ModelLoader() override = default;//0
        //1
        IModel *load(IModel &taget, const char *fileName, bool *ok); // 2

        IModel *loadBin_v0(IModel &taget, const char *fileName, bool *ok); // 3

    protected:
        IRender &render;
    };
}