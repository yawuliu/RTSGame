#include "Adapter.h"

namespace MyGL {
    Adapter::Adapter(IScene &s) : _scene(s) {

    }

    IShader *Adapter::getBloomDownSampleShader() {
        return this->returnShader("BloomDownSample");
    }

    IShader *Adapter::getBlurShadowShader() {
        return this->returnShader("BlurShadowShader");
    }

    IShader *Adapter::getGausHorizontalShader() {
        return this->returnShader("HorizontalShader");
    }

    IShader *Adapter::getGausVerticalShader() {
        return this->returnShader("GausVerticalShader");
    }

    IShader *Adapter::getGlowDownSampleShader() {
        return this->returnShader("GlowDownSample");
    }

    IShader *Adapter::getLincShader() {
        return this->returnShader("LincShader");
    }

    ITexture2d *Adapter::getRandTexture() {
        IScene *v1;
        __int64 v2;
        IScene *v3;
        __int64 v4;
        CGL *v5;
        IErrorControl *v6;
        ITexture2d *re;

        v1 = this->scene();
        v2 = v1->dataControl();
        re = (ITexture2d *) (*(__int64 (__fastcall **)(__int64, const char *)) (*(_QWORD *) v2 + 48LL))(
                v2,
                "rand4x4");
        v3 = this->scene();
        v4 = v3->render();
        v5 = (CGL *) (*(__int64 (__fastcall **)(__int64)) (*(_QWORD *) v4 + 72LL))(v4);
        v6 = CGL::errorCtrl(v5);
        (*((void (__fastcall **)(IErrorControl *, bool, const char *)) v6->_vptr_IErrorControl + 4))(
                v6,
                re != 0LL,
                "rand4x4 not found");
        return re;
    }

    IShader *Adapter::getSSAOShader() {
        return this->returnShader("SSAOShader");
    }

    ITexture2d *Adapter::getShadowMapTexture() {
        IScene *v1;
        __int64 v2;
        IScene *v3;
        IRender *r;
        Texture2d *re_1;
        IScene *v6;
        __int64 v7;
        ITexture2d *re;

        v1 = this->scene();
        v2 = v1->dataControl();
        re = (ITexture2d *) (*(__int64 (__fastcall **)(__int64, const char *)) (*(_QWORD *) v2 + 48LL))(
                v2,
                "shadow_map_texture");
        if (!re) {
            v3 = this->scene();
            r = v3->render();
            re_1 = (Texture2d *) operator new(0x50uLL);
            Texture2d::Texture2d(re_1, r);
            re = re_1;
            v6 = Adapter::scene(this);
            v7 = v6->dataControl();
            (*(void (__fastcall **)(__int64, const char *, Texture2d *)) (*(_QWORD *) v7 + 32LL))(
                    v7,
                    "shadow_map_texture",
                    re_1);
        }
        return re;
    }

    IShader *Adapter::getVolumetricLightScatteringShader() {
        return this->returnShader("VolumetricLightScatteringShader");
    }

    IShader *Adapter::returnShader(const std::string &d) {
        IScene *v2;
        __int64 v3;
        IScene *v4;
        __int64 v5;
        CGL *v6;
        IErrorControl *v7;
        void (__fastcall *v8)(IErrorControl *, bool, __int64);
        __int64 v9;
        std::string __lhs_;
        std::string __lhs;
        IShader *s;

        v2 = this->scene();
        v3 = v2->dataControl();
        s = (IShader *) (*(__int64 (__fastcall **)(__int64, const std::string *const)) (*(_QWORD *) v3 + 128LL))(v3,
                                                                                                                 d);
        v4 = this->scene();
        v5 = v4->render();
        v6 = (CGL *) (*(__int64 (__fastcall **)(__int64)) (*(_QWORD *) v5 + 72LL))(v5);
        v7 = CGL::errorCtrl(v6);
        v8 = (void (__fastcall *)(IErrorControl *, bool, __int64)) *((_QWORD *) v7->_vptr_IErrorControl + 4);
        std::operator+<char>((const char *) &__lhs, &_rhs_);
        std::operator+<char>(&__lhs_, (const char *) &__lhs);
        v9 = std::string::data(&__lhs_);
        v8(v7, s != 0LL, v9);
        std::string::~string(&__lhs_);
        std::string::~string(&__lhs);
        return s;
    }

    IScene &Adapter::scene() {
        return this->_scene;
    }
}