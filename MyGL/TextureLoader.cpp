#include "TextureLoader.h"
#include "IErrorControl.h"

namespace MyGL {
    TextureLoader::TextureLoader(IRender &r) : render(r) {
        this->flCall = 0LL;
        this->setLoadFileCallBack(0LL);
    }

    TextureLoader::~TextureLoader() {
        this->setLoadFileCallBack(0LL);

    }

    ITexture2d *TextureLoader::load(ITexture2d &taget, const std::string &fileName, bool *ok) {
        if (this->flCall) {
            this->flCall->operator()(taget, fileName, ok);
        } else {
            this->render.gl()->errorCtrl()->loadError(&taget, "[Error]:No texture load call back");
        }
        return &taget;
    }

    void TextureLoader::setLoadFileCallBack(MyGL::setLoadFileCallBack::loadFileCallBack c) {
        this->setLoadAlgo(new Loader(c));
    }

    void TextureLoader::setLoadAlgo(ITextureLoader::ILoader *c) {
        if (this->flCall)
            delete this->flCall;
        this->flCall = c;
    }
    
}