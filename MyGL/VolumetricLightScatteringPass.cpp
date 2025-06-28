#include "VolumetricLightScatteringPass.h"
#include "TextureRectangle.h"
#include "Filter.h"
#include "FBO.h"
#include "Adapter.h"

namespace MyGL {
    VolumetricLightScatteringPass::VolumetricLightScatteringPass(IScene &s, IModel *quad, const Adapter &adapter,
                                                                 ITextureRectangle &d, ITextureRectangle &c)
            : AbstractPass(s) {
        this->depth = d;
        this->filter = new Filter(this->scene());
        this->frame = new TextureRectangle(this->scene()->render());
        this->filter->setShader(adapter->getVolumetricLightScatteringShader());
        this->filter->setInput("colorBuffer", c);
        this->filter->setInput("depthBuffer", this->depth);
        this->filter->setInput("shadowMap", adapter->getShadowMapTexture());
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


        v2 = this->scene()->render();
        (*(void (__fastcall **)(__int64, int *, int *, int *, int *)) (*(_QWORD *) v2 + 96LL))(v2, v, &v[1], &v[2],
                                                                                               &v[3]);

        this->frame->load(0LL, 1LL, (unsigned int) v[2], (unsigned int) v[3], 4LL);
        if (this->frameBuffer)
            delete this->frameBuffer;
        this->frameBuffer = new FBO(this->scene()->render(), this->frame->width(), this->frame->height(), 8);
    }

    void VolumetricLightScatteringPass::exec() {
        IScene *v1;
        __int64 v2;
        IScene *v3;
        __int64 v4;
        int v5;
        int v6;
        int v[8];

        v2 = this->scene()->render();
        (*(void (__fastcall **)(__int64, int *, int *, int *, int *)) (*(_QWORD *) v2 + 96LL))(v2, v, &v[1], &v[2],
                                                                                               &v[3]);
        v4 = this->scene()->render();
        (*(void (__fastcall **)(__int64)) (*(_QWORD *) v4 + 24LL))(v4);
        v5 = v[2];
        if (v5 != this->frame->width()
            || (v6 = v[3],
                v6 != this->frame->height())) {
            this->resizeFrame();
        }
        this->frameBuffer->bind();
        this->frameBuffer->attachColorTexture(this->frame, 0LL);
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