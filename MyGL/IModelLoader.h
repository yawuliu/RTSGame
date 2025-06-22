#pragma once

#include <MyGL/DisableCopy.h>

namespace MyGL {
    class IModelLoader : public DisableCopy {
    public:
        IModelLoader() = default;

        virtual ~IModelLoader() = default;
    };
}
