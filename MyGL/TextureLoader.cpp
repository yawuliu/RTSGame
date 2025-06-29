#include "TextureLoader.h"

namespace MyGL {
    TextureLoader::TextureLoader(IRender & r)
    {
        this->render = r;
        this->flCall = 0LL;
        this->setLoadFileCallBack(0LL);
    }
    TextureLoader::~TextureLoader()
    {
        this->setLoadFileCallBack( 0LL);

    }

    ITexture2d * TextureLoader::load(ITexture2d & taget,const std::string &  fileName,bool *ok)
    {
        CGL *v4;
        IErrorControl *v5;

        if ( this->flCall)
        {
            (*((void (__fastcall **)(ITextureLoader::ILoader *, ITexture2d *const, const std::string *const, bool *))this->flCall->_vptr_ILoader
               + 2))(
                    this->flCall,
                    taget,
                    fileName,
                    ok);
        }
        else
        {
            v4 = (CGL *)(*((__int64 (__fastcall **)(IRender *const))this->render->_vptr_IRender + 9))(this->render);
            v5 = CGL::errorCtrl(v4);
            (*((void (__fastcall **)(IErrorControl *, ITexture2d *const, const char *))v5->_vptr_IErrorControl + 8))(
                    v5,
                    taget,
                    "[Error]:No texture load call back");
        }
        return taget;
    }

    void  TextureLoader::setLoadFileCallBack(TextureLoader::setLoadFileCallBack::loadFileCallBack c)
    {
        void (__fastcall *v2)(TextureLoader *, TextureLoader::Loader<void (*)(ITexture2d&,const std::string&,bool*)> *);
        TextureLoader::Loader<void (*)(ITexture2d&,const std::string&,bool*)> *v3;
        TextureLoader::setLoadFileCallBack::loadFileCallBack ca;
        TextureLoader *thisa;

        thisa = thisa_1;
        ca = c;
        v2 = (void (__fastcall *)(TextureLoader *, TextureLoader::Loader<void (*)(ITexture2d&,const std::string&,bool*)> *))*((_QWORD *)thisa_1->_vptr_ITextureLoader + 4);
        v3 = (TextureLoader::Loader<void (*)(ITexture2d&,const std::string&,bool*)> *)operator new(0x10uLL);
        TextureLoader::Loader<void (*)(ITexture2d &,std::string const&,bool *)>::Loader(v3, &ca);
        v2(thisa, v3);
    }

    void  TextureLoader::setLoadAlgo( ITextureLoader::ILoader *c)
    {
        if ( this->flCall )
            (*((void (__fastcall **)(ITextureLoader::ILoader *))this->flCall->_vptr_ILoader + 1))(this->flCall);
        this->flCall = c;
    }

    void  TextureLoader::Loader<void (*)(ITexture2d &,std::string const&,bool *)>::Loader(
            TextureLoader::Loader<void (*)(ITexture2d&,const std::string&,bool*)> *const this,
    void (*const *const t)(ITexture2d *, const std::string *, bool *))
{
    ITextureLoader::ILoader::ILoader(this);
    this->_vptr_ILoader = (int (**)(...))(&`vtable for'TextureLoader::Loader<void (*)(ITexture2d &,std::string const&,bool *)>
    + 2);
    this->load = *t;
}
}