#include "Adapter.h"
#include <string>

MyGL::Adapter::Adapter(MyGL::IScene &s) : _scene(s) {

}

MyGL::IShader *MyGL::Adapter::getBloomDownSampleShader() {
    MyGL::IShader *v1; 
    std::string d; 
    _BYTE v4[17]; 

    std::allocator<char>::allocator(v4);
    std::string::string(&d, "MyGL::BloomDownSample", v4);
    v1 = MyGL::Adapter::returnShader(this, &d);
    std::string::~string(&d);
    std::allocator<char>::~allocator(v4);
    return v1;
}

MyGL::IShader *MyGL::Adapter::getBlurShadowShader() {
    MyGL::IShader *v1; 
    std::string d; 
    _BYTE v4[17]; 

    std::allocator<char>::allocator(v4);
    std::string::string(&d, "MyGL::BlurShadowShader", v4);
    v1 = MyGL::Adapter::returnShader(this, &d);
    std::string::~string(&d);
    std::allocator<char>::~allocator(v4);
    return v1;
}

MyGL::IShader *MyGL::Adapter::getGausHorizontalShader() {
    MyGL::IShader *v1; 
    std::string d; 
    _BYTE v4[17]; 

    std::allocator<char>::allocator(v4);
    std::string::string(&d, "MyGL::HorizontalShader", v4);
    v1 = MyGL::Adapter::returnShader(this, &d);
    std::string::~string(&d);
    std::allocator<char>::~allocator(v4);
    return v1;
}

MyGL::IShader *MyGL::Adapter::getGausVerticalShader() {
    MyGL::IShader *v1; 
    std::string d; 
    _BYTE v4[17]; 

    std::allocator<char>::allocator(v4);
    std::string::string(&d, "MyGL::GausVerticalShader", v4);
    v1 = MyGL::Adapter::returnShader(this, &d);
    std::string::~string(&d);
    std::allocator<char>::~allocator(v4);
    return v1;
}

MyGL::IShader *MyGL::Adapter::getGlowDownSampleShader() {
    MyGL::IShader *v1; 
    std::string d; 
    _BYTE v4[17]; 

    std::allocator<char>::allocator(v4);
    std::string::string(&d, "MyGL::GlowDownSample", v4);
    v1 = MyGL::Adapter::returnShader(this, &d);
    std::string::~string(&d);
    std::allocator<char>::~allocator(v4);
    return v1;
}

MyGL::IShader *MyGL::Adapter::getLincShader() {
    MyGL::IShader *v1; 
    std::string d; 
    _BYTE v4[17]; 

    std::allocator<char>::allocator(v4);
    std::string::string(&d, "MyGL::LincShader", v4);
    v1 = MyGL::Adapter::returnShader(this, &d);
    std::string::~string(&d);
    std::allocator<char>::~allocator(v4);
    return v1;
}

MyGL::ITexture2d *MyGL::Adapter::getRandTexture() {
    MyGL::IScene *v1; 
    __int64 v2; 
    MyGL::IScene *v3; 
    __int64 v4; 
    MyGL::CGL *v5; 
    MyGL::IErrorControl *v6; 
    MyGL::ITexture2d *re; 

    v1 = MyGL::Adapter::scene(this);
    v2 = (*((__int64 (__fastcall **)(MyGL::IScene *)) v1->_vptr_IScene + 2))(v1);
    re = (MyGL::ITexture2d *) (*(__int64 (__fastcall **)(__int64, const char *)) (*(_QWORD *) v2 + 48LL))(
            v2,
            "MyGL::rand4x4");
    v3 = MyGL::Adapter::scene(this);
    v4 = (*((__int64 (__fastcall **)(MyGL::IScene *)) v3->_vptr_IScene + 3))(v3);
    v5 = (MyGL::CGL *) (*(__int64 (__fastcall **)(__int64)) (*(_QWORD *) v4 + 72LL))(v4);
    v6 = MyGL::CGL::errorCtrl(v5);
    (*((void (__fastcall **)(MyGL::IErrorControl *, bool, const char *)) v6->_vptr_IErrorControl + 4))(
            v6,
            re != 0LL,
            "MyGL::rand4x4 not found");
    return re;
}

MyGL::IShader *MyGL::Adapter::getSSAOShader() {
    MyGL::IShader *v1; 
    std::string d; 
    _BYTE v4[17]; 

    std::allocator<char>::allocator(v4);
    std::string::string(&d, "MyGL::SSAOShader", v4);
    v1 = MyGL::Adapter::returnShader(this, &d);
    std::string::~string(&d);
    std::allocator<char>::~allocator(v4);
    return v1;
}

MyGL::ITexture2d *MyGL::Adapter::getShadowMapTexture() {
    MyGL::IScene *v1; 
    __int64 v2; 
    MyGL::IScene *v3; 
    MyGL::IRender *r; 
    MyGL::Texture2d *re_1; 
    MyGL::IScene *v6; 
    __int64 v7; 
    MyGL::ITexture2d *re; 

    v1 = MyGL::Adapter::scene(this);
    v2 = (*((__int64 (__fastcall **)(MyGL::IScene *)) v1->_vptr_IScene + 2))(v1);
    re = (MyGL::ITexture2d *) (*(__int64 (__fastcall **)(__int64, const char *)) (*(_QWORD *) v2 + 48LL))(
            v2,
            "MyGL::shadow_map_texture");
    if (!re) {
        v3 = MyGL::Adapter::scene(this);
        r = (MyGL::IRender *) (*((__int64 (__fastcall **)(MyGL::IScene *)) v3->_vptr_IScene + 3))(v3);
        re_1 = (MyGL::Texture2d *) operator new(0x50uLL);
        MyGL::Texture2d::Texture2d(re_1, r);
        re = re_1;
        v6 = MyGL::Adapter::scene(this);
        v7 = (*((__int64 (__fastcall **)(MyGL::IScene *)) v6->_vptr_IScene + 2))(v6);
        (*(void (__fastcall **)(__int64, const char *, MyGL::Texture2d *)) (*(_QWORD *) v7 + 32LL))(
                v7,
                "MyGL::shadow_map_texture",
                re_1);
    }
    return re;
}

MyGL::IShader *MyGL::Adapter::getVolumetricLightScatteringShader() {
    MyGL::IShader *v1; 
    std::string d; 
    _BYTE v4[17]; 

    std::allocator<char>::allocator(v4);
    std::string::string(&d, "MyGL::VolumetricLightScatteringShader", v4);
    v1 = MyGL::Adapter::returnShader(this, &d);
    std::string::~string(&d);
    std::allocator<char>::~allocator(v4);
    return v1;
}

MyGL::IShader *MyGL::Adapter::returnShader(const std::string *const d) {
    MyGL::IScene *v2; 
    __int64 v3; 
    MyGL::IScene *v4; 
    __int64 v5; 
    MyGL::CGL *v6; 
    MyGL::IErrorControl *v7; 
    void (__fastcall *v8)(MyGL::IErrorControl *, bool, __int64); 
    __int64 v9; 
    std::string __lhs_; 
    std::string __lhs; 
    MyGL::IShader *s; 

    v2 = MyGL::Adapter::scene(this);
    v3 = (*((__int64 (__fastcall **)(MyGL::IScene *)) v2->_vptr_IScene + 2))(v2);
    s = (MyGL::IShader *) (*(__int64 (__fastcall **)(__int64, const std::string *const)) (*(_QWORD *) v3 + 128LL))(v3,
                                                                                                                   d);
    v4 = MyGL::Adapter::scene(this);
    v5 = (*((__int64 (__fastcall **)(MyGL::IScene *)) v4->_vptr_IScene + 3))(v4);
    v6 = (MyGL::CGL *) (*(__int64 (__fastcall **)(__int64)) (*(_QWORD *) v5 + 72LL))(v5);
    v7 = MyGL::CGL::errorCtrl(v6);
    v8 = (void (__fastcall *)(MyGL::IErrorControl *, bool, __int64)) *((_QWORD *) v7->_vptr_IErrorControl + 4);
    std::operator+<char>((const char *) &__lhs, &_rhs_);
    std::operator+<char>(&__lhs_, (const char *) &__lhs);
    v9 = std::string::data(&__lhs_);
    v8(v7, s != 0LL, v9);
    std::string::~string(&__lhs_);
    std::string::~string(&__lhs);
    return s;
}

MyGL::IScene &MyGL::Adapter::scene() {
    return this->_scene;
}
