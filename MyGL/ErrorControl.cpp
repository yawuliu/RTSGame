#include "ErrorControl.h"
#include <iostream>

namespace MyGL {
    ErrorControl::ErrorControl() {
        setOutputStream(std::cerr);
    }

    ErrorControl::~ErrorControl() {

    }

    void ErrorControl::setOutputStream(std::ostream &s) {
        this->out = &s;
    }

    std::ostream *ErrorControl::output() {
        return this->out;
    }

    void ErrorControl::warning(bool t, const char *text) {
        if (!t) {
            if (text) {
                *this->output() << text << std::endl;
            }
        }
    }

    void ErrorControl::fail(const char *text) {
        if (text) {
            *this->output() << "ErrorControl::fail :" << std::endl;
            *this->output() << text << std::endl << std::endl;
        }

        std::string error_msg(text);
        throw std::runtime_error(error_msg);
    }

    void ErrorControl::fail(bool t, const char *text) {
        if (!t)
            this->fail(text);
    }

    void ErrorControl::loadError(IShader *a2, const char *msg) {
        *this->output() << msg << std::endl;
    }

    void ErrorControl::loadError(ITexture2d *a2, const char *msg) {
        *this->output() << msg << std::endl;
    }

    void ErrorControl::loadError(IModel *a2, IIOModel *a3, const char *msg) {
        *this->output() << msg << std::endl;
    }

    void ErrorControl::compileError(IShader *a2, const char *msg) {
        *this->output() << msg << std::endl;
    }


}