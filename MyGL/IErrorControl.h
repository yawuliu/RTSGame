#pragma once

#include <fstream>


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
        virtual void output() = 0; // 3
        virtual void warning(bool, char const *) = 0; // 4
        virtual void fail(char const *) = 0; // 5
        virtual void fail(bool, char const *) = 0; // 6
        virtual void loadError(IShader *, char const *) = 0; // 7
        virtual void loadError(ITexture2d *, char const *) = 0; // 8
        virtual void loadError(IModel *, IIOModel *, char const *) = 0; // 9
        virtual void compileError(IShader *, char const *) = 0; // 10
    };
}



