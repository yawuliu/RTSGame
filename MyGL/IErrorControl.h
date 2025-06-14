#pragma once

#include <fstream>


namespace MyGL {
    class AbstractShader;

    class IErrorControl {
    public:
        void setOutputStream(std::fstream *);

        void compileError(AbstractShader *, char *);

    protected:
        std::fstream *mOutStream;
    };
}



