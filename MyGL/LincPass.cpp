#include "LincPass.h"
#include "IModel.h"

namespace MyGL {
    LincPass::LincPass(IScene &s, const Adapter &adapter, IModel *quad,
                       ITextureRectangle &f, ITextureRectangle &g,
                       ITextureRectangle &b, ITextureRectangle &d) : AbstractPass(s) {
        IScene *s_1;
        Filter *filter;
        IShader *shader;

        this->frame = f;
        this->glow = g;
        this->bloom = b;
        this->depth = d;
        s_1 = this->scene();
        filter = (Filter *) operator new(0x18uLL);
        Filter::Filter(filter, s_1);
        this->filter = filter;
        Filter::setQuadModel(this->filter, quad);
        shader = (IShader *) (*adapter->_vptr_Adapter)(adapter);
        this->setShader(shader);
    }

    LincPass::~LincPass() {
        if (this->filter)
            delete this->filter;
    }

    void LincPass::exec() {
        IScene *v1;
        __int64 v2;
        CGL *v3;
        IErrorControl *v4;

        if (!this->validate()) {
            v1 = this->scene();
            v2 = v1->render();
            v3 = (CGL *) (*(__int64 (__fastcall **)(__int64)) (*(_QWORD *) v2 + 72LL))(v2);
            v4 = v3->errorCtrl();
            v4->fail(
                    "Linc frame shader is not loaded");
        } else {
            this->filter->exec();
        }
    }

    void LincPass::setShader(IShader *shader) {
        ITextureRectangle *frame;
        ITextureRectangle *depth;
        ITextureRectangle *glow;
        ITextureRectangle *bloom;
        IScene *v6;
        __int64 v7;
        CGL *v8;
        IErrorControl *v9;
        std::string name;
        char v11;
        std::string name_;
        char v13;
        std::string name__1;
        char v15;
        std::string name__2;
        _BYTE v17[17];

        Filter::setShader(this->filter, shader);
        if (Filter::shader(this->filter)) {
            frame = this->frame;
            std::allocator<char>::allocator(&v11);
            std::string::string(&name, "mainPass", &v11);
            Filter::setInput(this->filter, &name, frame);
            std::string::~string(&name);
            std::allocator<char>::~allocator(&v11);
            depth = this->depth;
            std::allocator<char>::allocator(&v13);
            std::string::string(&name_, "depthBuffer", &v13);
            Filter::setInput(this->filter, &name_, depth);
            std::string::~string(&name_);
            std::allocator<char>::~allocator(&v13);
            glow = this->glow;
            std::allocator<char>::allocator(&v15);
            std::string::string(&name__1, "glowPass", &v15);
            Filter::setInput(this->filter, &name__1, glow);
            std::string::~string(&name__1);
            std::allocator<char>::~allocator(&v15);
            bloom = this->bloom;
            std::allocator<char>::allocator(v17);
            std::string::string(&name__2, "bloomPass", v17);
            Filter::setInput(this->filter, &name__2, bloom);
            std::string::~string(&name__2);
            std::allocator<char>::~allocator(v17);
        } else {
            v6 = this->scene();
            v7 = v6->render();
            v8 = (CGL *) (*(__int64 (__fastcall **)(__int64)) (*(_QWORD *) v7 + 72LL))(v7);
            v9 = v8->errorCtrl();
            v9->warning(
                    0LL,
                    "Linc frame shader is not loaded");
        }
    }

    IRenderPass::Pass::Type LincPass::type() {
        return 6;
    }

    bool LincPass::validate() {
        return this->filter->shader() != 0LL;
    }
}