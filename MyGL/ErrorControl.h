#pragma once

#include <fstream>
#include "MyGL/IErrorControl.h"

namespace MyGL {
    class IShader;

    class ITexture2d;

    class IModel;

    class IIOModel;

    class ErrorControl : public IErrorControl {
    public:
        ErrorControl();

        virtual ~ErrorControl();

        virtual void setOutputStream(std::ostream *const s) override;

        virtual std::ostream *output() override;

        virtual void warning(bool t, const char *text) override;

        virtual void fail(const char *text) override;

        virtual void fail(bool t, const char *text) override;

        virtual void loadError(MyGL::IShader *a2, const char *msg) override;

        virtual void loadError(MyGL::ITexture2d *a2, const char *msg) override;

        virtual void loadError(MyGL::IModel *a2, MyGL::IIOModel *a3, const char *msg) override;

        virtual void compileError(MyGL::IShader *a2, const char *msg) override;

    protected:
        std::ostream *out;
    };
}