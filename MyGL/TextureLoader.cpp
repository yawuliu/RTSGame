#include "TextureLoader.h"

namespace MyGL {
    TextureLoader::TextureLoader(IRender &r) {
        this->render = r;
        this->flCall = 0LL;
        this->setLoadFileCallBack(0LL);
    }

    TextureLoader::~TextureLoader() {
        this->setLoadFileCallBack(0LL);

    }

    ITexture2d *TextureLoader::load(const std::string &fileName, bool *ok) {
        if (this->flCall) {
            this->flCall->operator()(this, fileName, ok);
        } else {
            this->render->gl()->errorCtrl()->loadError(this, "[Error]:No texture load call back");
        }
        return this;
    }

    void TextureLoader::setLoadFileCallBack(TextureLoader::setLoadFileCallBack::loadFileCallBack c) {
        this->setLoadAlgo(new TextureLoader::Loader(&c));
    }

    void TextureLoader::setLoadAlgo(ITextureLoader::ILoader *c) {
        if (this->flCall)
            delete this->flCall;
        this->flCall = c;
    }

    TextureLoader::Loader::Loader(void (*const *const t)(ITexture2d *, const std::string *, bool *)) {
        this->load = *t;
    }
}