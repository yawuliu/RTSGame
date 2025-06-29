#pragma once

#include "ITextureLoader.h"
#include "IRender.h"

namespace MyGL {
    class ILoader;

    class TextureLoader : public ITextureLoader {
    public:
        class setLoadFileCallBack {
        public:
            typedef void (*loadFileCallBack)(MyGL::ITexture2d *, const std::string *, bool *);
        };

        class Loader : public ITextureLoader::ILoader {
        public:
            Loader(void (*const *const t)(ITexture2d *, const std::string *, bool *));
        };

    public:
        TextureLoader(IRender &r);

        virtual ~TextureLoader();

        ITexture2d *load(ITexture2d &taget, const std::string &fileName, bool *ok);

        void setLoadFileCallBack(setLoadFileCallBack::loadFileCallBack c);

        void setLoadAlgo(ILoader *c);

    protected:
        IRender &render;
        ITextureLoader::ILoader *flCall;
    };

}


