#pragma once

#include <string>
#include "DisableCopy.h"
#include "ITexture2d.h"
#include "ShaderEnvironment.h"

namespace MyGL {
    class setLoadFileCallBack {
    public:
        typedef void (*loadFileCallBack)(ITexture2d *, const ::std::string &, bool *);
    };

    class ITextureLoader : public DisableCopy {
    public:
        class ILoader {
        public:
            ILoader() = default;

            virtual ~ILoader() = default; // 0
            //1
            virtual ITexture2d *operator()(ITexture2d &, const ::std::string &, bool *) = 0;// 2
        };

    public:
        ITextureLoader() = default;

        virtual ~ITextureLoader() = default; //0
        //1
        virtual ITexture2d *load(ITexture2d &, const ::std::string &, bool *) = 0; // 2
        virtual void setLoadFileCallBack(setLoadFileCallBack::loadFileCallBack t) = 0; // 3
        virtual void setLoadAlgo(ITextureLoader::ILoader *) = 0;// 4
    };
}

