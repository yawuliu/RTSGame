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

            virtual ~ILoader() = default; // 0
            //1
            virtual void operator()(ITexture2d &, std::string const &, bool *) = 0;// 2
        };

    public:
        ITextureLoader() = default;

        virtual ~ITextureLoader() = default; //0
        //1
        virtual void load(ITexture2d &, std::string const &, bool *) = 0; // 2
        virtual void setLoadFileCallBack(void (*)(ITexture2d &, std::string const &, bool *)) = 0; // 3
        virtual void setLoadAlgo(ITextureLoader::ILoader *) = 0;// 4
    };
}

