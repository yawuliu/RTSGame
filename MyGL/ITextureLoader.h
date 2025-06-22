#pragma once

#include <string>
#include "MyGL/DisableCopy.h"
#include "MyGL/ITexture2d.h"
#include "MyGL/ShaderEnvironment.h"

namespace MyGL {
    class ITextureLoader : public DisableCopy {
    public:
        class ILoader {
        public:
            ILoader() = default;

            virtual ~ILoader() = default;
        };

    public:
        ITextureLoader() = default;

        virtual ~ITextureLoader() = default;

        virtual void setLoadFileCallBack(void(&)(ITexture2d &, const std::string &, bool *)) = 0;
    };
}

