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

        virtual ~IErrorControl() = default;

        virtual void setOutputStream(std::ostream *const s) = 0;

        virtual std::ostream *output() = 0;

        virtual void warning(bool t, const char *text) = 0;


        virtual void fail(const char *text) = 0;

        virtual void fail(bool t, const char *text) = 0;

        virtual void loadError(MyGL::IShader *a2, const char *msg) = 0;

        virtual void loadError(MyGL::ITexture2d *a2, const char *msg) = 0;

        virtual void loadError(MyGL::IModel *a2, MyGL::IIOModel *a3, const char *msg) = 0;

        virtual void compileError(MyGL::IShader *a2, const char *msg) = 0;
    };
}



