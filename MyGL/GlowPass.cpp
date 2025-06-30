#include "GlowPass.h"
#include "ISceneGraph.h"
#include "TextureRectangle.h"
#include "BloomPass.h"
#include "SmallLightsPass.h"
#include "Data.h"

namespace MyGL {
    GlowPass::GlowPass(IScene &s, const Adapter &adapter, ITextureRectangle *depth) : AbstractPass(s) {
        this->frame = new TextureRectangle(this->scene()->render());
        this->depthBuf = depth;
        this->frame->setFiltration(1LL, 1LL);
        this->frameBuffer = 0LL;
        this->fakeLv = 1;
        this->resizeFrame();
        this->data = new Data(this->scene());
        this->data->blur = new BloomPass(this->scene(), adapter, this->frame);
        this->data->blur->setShader(adapter->getGlowDownSampleShader());
        this->data->blur->setDownSamplesCount(2);
        this->data->lights = new SmallLightsPass(this->scene(), adapter);
        this->initShaders(adapter);
    }

    GlowPass::~GlowPass() {
        if (this->data->lights)
            delete this->data->lights;
        if (this->data->blur)
            delete this->data->blur;
        operator delete(this->data);
        if (this->frame)
            delete this->frame;
        if (this->frameBuffer)
            delete this->frameBuffer;

    }

    bool GlowPass::validate() {
        return this->data->blur->validate();
    }

    bool GlowPass::isDrawable(IGraphicsObject &obj) {
        return obj.visible() == 1;
    }

    void GlowPass::resizeFrame() {
        int v[12];
        this->scene()->render()->getViewport(&v[0], &v[1], &v[2], &v[3]);
        this->frame->setFiltration(0LL,
                                   1LL,
                                   (unsigned int) (v[2] / this->fakeLv),
                                   (unsigned int) (v[3] / this->fakeLv),
                                   4LL);
        if (this->frameBuffer)
            delete this->frameBuffer;
        this->frameBuffer = new FBO(this->scene()->render(), this->frame->width(), this->frame->height(), 4);
    }

    void GlowPass::initShaders(const Adapter &adapter) {
        ;
    }

    void GlowPass::exec() {
        int v[4];
        this->scene()->render()->getViewport(&v[0], &v[1], &v[2], &v[3]);
        if (v[2] / this->fakeLv != this->frame->width() || v[3] / this->fakeLv != this->frame->height()) {
            this->resizeFrame();
        }
        this->scene()->render()->setViewport(v[0], v[1], (v[2] / this->fakeLv), (v[3] / this->fakeLv));
        this->frameBuffer->bind();
        this->frameBuffer->attachColorTexture(this->frame, 0LL);
        this->frameBuffer->attachDepthTexture(this->depthBuf);
        Color cl_0 = this->scene()->render()->clearColor();
        Color v21(0.0, 0.0, 0.0, 0.0);
        this->scene()->render()->clearColor(*(double *) v21.cdata, *(double *) &v21.cdata[2]);
        this->scene()->render()->clear(1LL);
        this->scene()->render()->clearColor(cl_0);
        this->draw();
        this->data->lights->exec();
        this->frameBuffer->unbind();
        if (this->used)
            this->postProcess(v[0], v[1], v[2], v[3]);
        this->scene()->render()->setViewport(v[0], v[1], v[2], v[3]);
    }

    void GlowPass::draw() {
        this->used = 0;
        ISceneGraph::Visibles obj(this->scene()->graph());
        this->scene()->render()->begin();
        for (int i = 0;; ++i) {
            if (obj.size() <= i)
                break;
            if (this->isDrawable(obj[i])) {
                this->drawObject(obj[i]);
                this->used = 1;
            }
        }
        this->scene()->render()->end();
    }

    void GlowPass::postProcess(int a2, int a3, int a4, int a5) {
        this->data->blur->exec();
    }

    ITextureRectangle *GlowPass::output() {
        return this->data->blur->output();
    }

    IRenderPass::Pass::Type GlowPass::type() {
        return IRenderPass::Pass::Glow;
    }
}