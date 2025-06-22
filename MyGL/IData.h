#pragma once

#include "DisableCopy.h"
#include "IRenderState.h"

namespace MyGL {
    class IData : public DisableCopy {
    public:
        IData() = default;

        virtual ~IData() = default;
    };
}


