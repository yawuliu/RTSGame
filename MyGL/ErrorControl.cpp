#include "ErrorControl.h"
#include <iostream>

MyGL::ErrorControl::ErrorControl() {
    setOutputStream(&std::cerr);
}

MyGL::ErrorControl::~ErrorControl() {

}

void MyGL::ErrorControl::setOutputStream(std::ostream *const s) {
    this->out = s;
}

std::ostream *MyGL::ErrorControl::output() {
    return this->out;
}

void MyGL::ErrorControl::warning(bool t, const char *text) {
    if (!t) {
        if (text) {
            *this->output() << text << std::endl;
        }
    }
}

void MyGL::ErrorControl::fail(const char *text) {
    if (text) {
        *this->output() << "MyGL::ErrorControl::fail :" << std::endl;
        *this->output() << text << std::endl << std::endl;
    }

    std::string error_msg(text);
    throw std::runtime_error(error_msg);
}

void MyGL::ErrorControl::fail(bool t, const char *text) {
    if (!t)
        this->fail(text);
}

void MyGL::ErrorControl::loadError(MyGL::IShader *a2, const char *msg) {
    *this->output() << msg << std::endl;
}

void MyGL::ErrorControl::loadError(MyGL::ITexture2d *a2, const char *msg) {
    *this->output() << msg << std::endl;
}

void MyGL::ErrorControl::loadError(MyGL::IModel *a2, MyGL::IIOModel *a3, const char *msg) {
    *this->output() << msg << std::endl;
}

void MyGL::ErrorControl::compileError(MyGL::IShader *a2, const char *msg) {
    *this->output() << msg << std::endl;
}


