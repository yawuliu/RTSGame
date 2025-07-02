#pragma once

#include "ITextureLoader.h"
#include "IRender.h"

namespace MyGL {
    class ILoader;

    class TextureLoader : public ITextureLoader {
    public:
        template<typename T>
        class Loader : public ITextureLoader::ILoader {
        public:
            Loader(T t) {
                this->load = t;
            }

            virtual ~Loader() = default;

            virtual ITexture2d *operator()(ITexture2d &taget, const std::string &fileName, bool *ok) {
                this->load(&taget, fileName, ok);
                return &taget;
            }

        public:
            T load;
        };

    public:
        TextureLoader(IRender &r);

        virtual ~TextureLoader();

        virtual ITexture2d *load(ITexture2d &taget, const std::string &fileName, bool *ok);

        virtual void setLoadFileCallBack(setLoadFileCallBack::loadFileCallBack c);

        virtual void setLoadAlgo(ILoader *c);

    protected:
        IRender &render;
        ITextureLoader::ILoader *flCall;
    };

}


