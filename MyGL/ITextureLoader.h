#pragma once

#include <string>
#include "MyGL/ITexture2d.h"
#include "MyGL/ShaderEnvironment.h"

namespace MyGL {
    class ITextureLoader {
    public:
        virtual void setLoadFileCallBack(void(&)(MyGL::ITexture2d &, const std::string &, bool *)) = 0;
    };
}

