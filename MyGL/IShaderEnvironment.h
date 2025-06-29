#pragma once

#include <string>
#include "DisableCopy.h"

namespace MyGL {
    class IShaderEnvironment : public DisableCopy {
    public:
        IShaderEnvironment() = default;

        virtual ~IShaderEnvironment() = default; // 0
        // virtual ~IShaderEnvironment() = default; // 1
        virtual const std::string &getPrecompileSource() = 0; // 2

        virtual IShaderEnvironment *operator<<(std::string const &) = 0; // 3

        virtual IShaderEnvironment *operator>>(std::string const &) = 0; // 4

        virtual IShaderEnvironment *push(std::string const &, std::string const &) = 0; // 5

        virtual IShaderEnvironment *pop(std::string const &) = 0; // 6
    };
}



