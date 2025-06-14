#include "IErrorControl.h"
#include <MyGL/AbstractShader.h>

void MyGL::IErrorControl::setOutputStream(std::fstream *s) {
    mOutStream = s;
}

void MyGL::IErrorControl::compileError(MyGL::AbstractShader *s, char *str) {
    if (mOutStream == nullptr) {
        return;
    }
    *mOutStream << str << std::endl;
}
