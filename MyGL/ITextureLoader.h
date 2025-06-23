#pragma once

#include <string>
#include "DisableCopy.h"
#include "ITexture2d.h"
#include "ShaderEnvironment.h"

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

