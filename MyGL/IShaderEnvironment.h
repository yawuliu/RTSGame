#pragma once

#include <string>
#include "DisableCopy"

namespace MyGL {
    class IShaderEnvironment : public DisableCopy {
    public:
        IShaderEnvironment() = default;

        virtual ~IShaderEnvironment() = default;

        virtual void pop(const std::string &) = 0;

        virtual void push(const std::string &, const std::string &) = 0;
    };
}



