#pragma once

#include <fstream>
#include "IErrorControl.h"

namespace MyGL {
    class IShader;

    class ITexture2d;

    class IModel;

    class IIOModel;

    class ErrorControl : public IErrorControl {
    public:
        ErrorControl();

        virtual ~ErrorControl();

        virtual void setOutputStream(std::ostream &s) override;

        virtual std::ostream *output() override;

        virtual void warning(bool t, const char *text) override;

        virtual void fail(const char *text) override;

        virtual void fail(bool t, const char *text) override;

        virtual void loadError(IShader *a2, const char *msg) override;

        virtual void loadError(ITexture2d *a2, const char *msg) override;

        virtual void loadError(IModel *a2, IIOModel *a3, const char *msg) override;

        virtual void compileError(IShader *a2, const char *msg) override;

    protected:
        std::ostream *out;
    };
}