#pragma once

#include "DisableCopy.h"

namespace MyGL {
    class IModelLoader : public DisableCopy {
    public:
        IModelLoader() = default;

        virtual ~IModelLoader() = default;

        //1
        virtual IModel *load(const char *fileName, bool *ok) = 0; // 2

        virtual IModel *loadBin_v0(const char *fileName, bool *ok) = 0; // 3
    };
}
