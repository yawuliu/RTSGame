#pragma once

#include <ostream>

namespace MyGL {
    class IShader;

    class IModel;

    class IIOModel;

    class ITexture2d;

    class IErrorControl {
    public:
        IErrorControl() = default;

        virtual ~IErrorControl() = default; // 0
        // virtual ~IErrorControl() = default; // 1
        virtual void setOutputStream(std::ostream &) = 0; // 2
        virtual std::ostream *output() = 0; // 3
        virtual void warning(bool, const char *) = 0; // 4
        virtual void fail(const char *) = 0; // 5
        virtual void fail(bool, const char *) = 0; // 6
        virtual void loadError(IShader *, const char *) = 0; // 7
        virtual void loadError(ITexture2d *, const char *) = 0; // 8
        virtual void loadError(IModel *, IIOModel *, const char *) = 0; // 9
        virtual void compileError(IShader *, char const *) = 0; // 10
    };
}



