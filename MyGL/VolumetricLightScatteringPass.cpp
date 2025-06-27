#include "VolumetricLightScatteringPass.h"
#include "TextureRectangle.h"
#include "Filter.h"
#include "FBO.h"
#include "Adapter.h"

namespace MyGL {
    VolumetricLightScatteringPass::VolumetricLightScatteringPass(IScene &s, IModel *quad, const Adapter &adapter,
                                                                 ITextureRectangle &d, ITextureRectangle &c)
            : AbstractPass(s) {
        IScene *s_1;
        Filter *filter;
        IScene *v8;
        IRender *r;
        TextureRectangle *frame;
        IShader *s_2;
        ITextureRectangle *depth;
        ITexture *arg;
        std::string name;
        char v19;
        std::string name_;
        char v21;
        std::string name__1;
        _BYTE v23[17];


        this->depth = d;
        this->filter = new Filter(this->scene());
        v8 = this->scene();
        r = v8->render();
        this->frame = new TextureRectangle(r);
        s_2 = adapter->getVolumetricLightScatteringShader();
        this->filter->setShader(s_2);
        std::allocator<char>::allocator(&v19);
        std::string::string(&name, "colorBuffer", &v19);
        this->filter->setInput(&name, c);
        depth = this->depth;
        std::allocator<char>::allocator(&v21);
        std::string::string(&name_, "depthBuffer", &v21);
        this->filter->setInput(&name_, depth);
        arg = adapter->getShadowMapTexture();
        std::allocator<char>::allocator(v23);
        std::string::string(&name__1, "shadowMap", v23);
        this->filter->setInput(&name__1, arg);
        this->filter->setQuadModel(quad);
        this->frameBuffer = 0LL;
        this->resizeFrame();
    }

    VolumetricLightScatteringPass::~VolumetricLightScatteringPass() {
        if (this->frameBuffer)
            delete this->frameBuffer;
        if (this->frame)
            delete this->frame;

    }

    void VolumetricLightScatteringPass::resizeFrame() {
        IScene *v1;
        __int64 v2;
        IScene *v3;
        IRender *r;
        unsigned int theWidth;
        unsigned int theHeight;
        FBO *frameBuffer;
        int v[12];

        v1 = this->scene();
        v2 = v1->render();
        (*(void (__fastcall **)(__int64, int *, int *, int *, int *)) (*(_QWORD *) v2 + 96LL))(v2, v, &v[1], &v[2],
                                                                                               &v[3]);

        this->frame->load(
                0LL,
                1LL,
                (unsigned int) v[2],
                (unsigned int) v[3],
                4LL);
        if (this->frameBuffer)
            delete this->frameBuffer;
        v3 = this->scene();
        r = v3->render();
        theWidth = this->frame->width();
        theHeight = this->frame->height();
        this->frameBuffer = new FBO(r, theWidth, theHeight, 8);
    }

    void VolumetricLightScatteringPass::exec() {
        IScene *v1;
        __int64 v2;
        IScene *v3;
        __int64 v4;
        int v5;
        int v6;
        int v[8];

        v1 = this->scene();
        v2 = v1->render();
        (*(void (__fastcall **)(__int64, int *, int *, int *, int *)) (*(_QWORD *) v2 + 96LL))(v2, v, &v[1], &v[2],
                                                                                               &v[3]);
        v3 = this->scene();
        v4 = v3->render();
        (*(void (__fastcall **)(__int64)) (*(_QWORD *) v4 + 24LL))(v4);
        v5 = v[2];
        if (v5 != this->frame->width()
            || (v6 = v[3],
                v6 != this->frame->height())) {
            VolumetricLightScatteringPass::resizeFrame(this);
        }
        this->frameBuffer->bind();
        this->frameBuffer->attachColorTexture(
                this->frame,
                0LL);
        this->filter->clearColor();
        this->frameBuffer->unbind();
    }

    ITextureRectangle *VolumetricLightScatteringPass::output() {
        return this->frame;
    }

    IRenderPass::Pass::Type VolumetricLightScatteringPass::type() {
        return IRenderPass::Pass::Type::None;
    }
}