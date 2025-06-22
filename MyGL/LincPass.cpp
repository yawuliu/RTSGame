#include "LincPass.h"
#include <MyGL/IModel.h>

MyGL::LincPass::LincPass(MyGL::IScene &s, const MyGL::Adapter &adapter, MyGL::IModel *quad,
                         MyGL::ITextureRectangle &f, MyGL::ITextureRectangle &g,
                         MyGL::ITextureRectangle &b, MyGL::ITextureRectangle &d) : AbstractPass(s) {
    MyGL::IScene *s_1;
    MyGL::Filter *filter;
    MyGL::IShader *shader;

    this->frame = f;
    this->glow = g;
    this->bloom = b;
    this->depth = d;
    s_1 = this->scene();
    filter = (MyGL::Filter *) operator new(0x18uLL);
    MyGL::Filter::Filter(filter, s_1);
    this->filter = filter;
    MyGL::Filter::setQuadModel(this->filter, quad);
    shader = (MyGL::IShader *) (*adapter->_vptr_Adapter)(adapter);
    this->setShader(shader);
}

MyGL::LincPass::~LincPass() {
    if (this->filter)
        (*((void (__fastcall **)(MyGL::Filter *)) this->filter->_vptr_IRenderPass + 1))(this->filter);
}

void MyGL::LincPass::exec() {
    MyGL::IScene *v1;
    __int64 v2;
    MyGL::CGL *v3;
    MyGL::IErrorControl *v4;

    if (!this->validate()) {
        v1 = this->scene();
        v2 = (*((__int64 (__fastcall **)(MyGL::IScene *)) v1->_vptr_IScene + 3))(v1);
        v3 = (MyGL::CGL *) (*(__int64 (__fastcall **)(__int64)) (*(_QWORD *) v2 + 72LL))(v2);
        v4 = MyGL::CGL::errorCtrl(v3);
        (*((void (__fastcall **)(MyGL::IErrorControl *, const char *)) v4->_vptr_IErrorControl + 5))(
                v4,
                "Linc frame shader is not loaded");
    } else {
        (*((void (__fastcall **)(MyGL::Filter *)) this->filter->_vptr_IRenderPass + 2))(this->filter);
    }
}

void MyGL::LincPass::setShader(MyGL::IShader *shader) {
    MyGL::ITextureRectangle *frame;
    MyGL::ITextureRectangle *depth;
    MyGL::ITextureRectangle *glow;
    MyGL::ITextureRectangle *bloom;
    MyGL::IScene *v6;
    __int64 v7;
    MyGL::CGL *v8;
    MyGL::IErrorControl *v9;
    std::string name;
    char v11;
    std::string name_;
    char v13;
    std::string name__1;
    char v15;
    std::string name__2;
    _BYTE v17[17];

    MyGL::Filter::setShader(this->filter, shader);
    if (MyGL::Filter::shader(this->filter)) {
        frame = this->frame;
        std::allocator<char>::allocator(&v11);
        std::string::string(&name, "mainPass", &v11);
        MyGL::Filter::setInput(this->filter, &name, frame);
        std::string::~string(&name);
        std::allocator<char>::~allocator(&v11);
        depth = this->depth;
        std::allocator<char>::allocator(&v13);
        std::string::string(&name_, "depthBuffer", &v13);
        MyGL::Filter::setInput(this->filter, &name_, depth);
        std::string::~string(&name_);
        std::allocator<char>::~allocator(&v13);
        glow = this->glow;
        std::allocator<char>::allocator(&v15);
        std::string::string(&name__1, "glowPass", &v15);
        MyGL::Filter::setInput(this->filter, &name__1, glow);
        std::string::~string(&name__1);
        std::allocator<char>::~allocator(&v15);
        bloom = this->bloom;
        std::allocator<char>::allocator(v17);
        std::string::string(&name__2, "bloomPass", v17);
        MyGL::Filter::setInput(this->filter, &name__2, bloom);
        std::string::~string(&name__2);
        std::allocator<char>::~allocator(v17);
    } else {
        v6 = this->scene();
        v7 = (*((__int64 (__fastcall **)(MyGL::IScene *)) v6->_vptr_IScene + 3))(v6);
        v8 = (MyGL::CGL *) (*(__int64 (__fastcall **)(__int64)) (*(_QWORD *) v7 + 72LL))(v7);
        v9 = MyGL::CGL::errorCtrl(v8);
        (*((void (__fastcall **)(MyGL::IErrorControl *, _QWORD, const char *)) v9->_vptr_IErrorControl + 4))(
                v9,
                0LL,
                "Linc frame shader is not loaded");
    }
}

MyGL::IRenderPass::Pass::Type MyGL::LincPass::type() {
    return 6;
}

bool MyGL::LincPass::validate() {
    return this->filter->shader() != 0LL;
}
