#pragma once

#include <MyGL/DisableCopy.h>

namespace MyGL {
    class IUniform : public DisableCopy {
    public:
        IUniform() = default;

        virtual ~IUniform() = default;
    };
}


