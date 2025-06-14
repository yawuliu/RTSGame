#pragma once

#include <string>
#include <MyGL/ITexture2d.h>
#include <MyGL/IUniform4f.h>

namespace MyGL {
    class IShader {
    public:
        MyGL::IUniform4f *uniform4f(const char *);

    protected:
        
    };
}

