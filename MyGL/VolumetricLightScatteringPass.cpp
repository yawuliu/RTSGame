#include "VolumetricLightScatteringPass.h"
#include "TextureRectangle.h"
#include "Filter.h"
#include "FBO.h"
#include "Adapter.h"

namespace MyGL {
    VolumetricLightScatteringPass::VolumetricLightScatteringPass(IScene &s, IModel *quad, const Adapter &adapter,
                                                                 ITextureRectangle &d, ITextureRectangle &c)
            : AbstractPass(s), depth(&d) {
        this->filter = new Filter(this->scene());
        this->frame = new TextureRectangle(this->scene().render());
        this->filter->setShader(adapter.getVolumetricLightScatteringShader());
        this->filter->setInput("colorBuffer", c);
        this->filter->setInput("depthBuffer", this->depth);
        this->filter->setInput("shadowMap", adapter.getShadowMapTexture());
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
        int v[12];
        this->scene().render()->getViewport(&v[0], &v[1], &v[2], &v[3]);
        this->frame->load(0LL, 1LL, v[2], v[3], 4LL);
        if (this->frameBuffer)
            delete this->frameBuffer;
        this->frameBuffer = new FBO(this->scene().render(), this->frame->width(), this->frame->height(), 8);
    }

    void VolumetricLightScatteringPass::exec() {
        int v[8];
        this->scene().render()->getViewport(&v[0], &v[1], &v[2], &v[3]);
        this->scene().render()->clearColor();
        if (v[2] != this->frame->width() || v[3] != this->frame->height()) {
            this->resizeFrame();
        }
        this->frameBuffer->bind();
        this->frameBuffer->attachColorTexture(this->frame, 0LL);
        this->filter->exec();
        this->frameBuffer->unbind();
    }

    ITextureRectangle *VolumetricLightScatteringPass::output() {
        return this->frame;
    }

    IRenderPass::Pass::Type VolumetricLightScatteringPass::type() {
        return IRenderPass::Pass::Type::None;
    }
}