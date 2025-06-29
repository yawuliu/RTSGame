#pragma once

#include "DisableCopy.h"

namespace MyGL {
    class IModelLoader : public DisableCopy {
    public:
        IModelLoader() = default;

        virtual ~IModelLoader() = default;

        //1
        IModel *load(const char *fileName, bool *ok); // 2

        IModel *loadBin_v0(const char *fileName, bool *ok); // 3
    };
}
