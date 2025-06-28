#pragma once

#include <string>
#include "DisableCopy.h"

namespace MyGL {
    class IShaderEnvironment : public DisableCopy {
    public:
        IShaderEnvironment() = default;

        virtual ~IShaderEnvironment() = default; // 0
        // virtual ~IShaderEnvironment() = default; // 1
        virtual void getPrecompileSource() = 0; // 2

        virtual void operator<<(std::string const &) = 0; // 3

        virtual void operator>>(std::string const &) = 0; // 4

        virtual void push(std::string const &, std::string const &) = 0; // 5

        virtual void pop(std::string const &) = 0; // 6
    };
}



