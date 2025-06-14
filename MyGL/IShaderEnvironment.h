#pragma once

#include <string>

namespace MyGL {
    class IShaderEnvironment {
    public:
        virtual void pop(const std::string &) = 0;

        virtual void push(const std::string &, const std::string &) = 0;
    };
}



