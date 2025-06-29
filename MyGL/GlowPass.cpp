#include "GlowPass.h"

namespace MyGL {
    GlowPass::GlowPass(IScene &s, const Adapter &adapter, ITextureRectangle *depth) : AbstractPass(s) {
        this->frame = new TextureRectangle(this->scene()->render());
        this->depthBuf = depth;
        this->frame->setFiltration(1LL,1LL);
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
        return obj->visible() == 1;
    }

    void GlowPass::resizeFrame() {
        v2 = this->scene()->render();
        (*(void (__fastcall **)(__int64, int *, int *, int *, int *)) (*(_QWORD *) v2 + 96LL))(v2, v, &v[1], &v[2],
                                                                                               &v[3]);

        this->frame->setFiltration(0LL,
                1LL,
                (unsigned int) (v[2] / this->fakeLv),
                (unsigned int) (v[3] / this->fakeLv),
                4LL);
        if (this->frameBuffer)
            delete this->frameBuffer;
        this->frameBuffer = new FBO(this->scene()->render(), this->frame->width(),  this->frame->height(), 4);
    }

    void GlowPass::initShaders(const Adapter &adapter) {
        ;
    }

    void GlowPass::exec() {
        v2 = this->scene()->render();
        (*(void (__fastcall **)(__int64, int *, int *, int *, int *)) (*(_QWORD *) v2 + 96LL))(v2, v, &v[1], &v[2],
                                                                                               &v[3]);
        v3 = v[2] / this->fakeLv;
        if (v3 !=  this->frame->setClamping())
            || (v4 = v[3] / this->fakeLv,
                v4 !=  this->frame->setClamping())) {
            this->resizeFrame();
        }
        v7 = this->scene()->render();
        (*(void (__fastcall **)(__int64, _QWORD, _QWORD, _QWORD, _QWORD)) (*(_QWORD *) v7 + 88LL))(
                v7,
                (unsigned int) v[0],
                (unsigned int) v[1],
                (unsigned int) (v[2] / this->fakeLv),
                (unsigned int) (v[3] / this->fakeLv));
        this->frameBuffer->bind();
        this->frameBuffer->attachColorTexture(
                this->frame,
                0LL);
        this->frameBuffer->attachDepthTexture(
                this->depthBuf);
        v9 = this->scene()->render();
        cl_0 = (*(double (__fastcall **)(__int64)) (*(_QWORD *) v9 + 24LL))(v9);
        v11 = this->scene()->render();
        v12 = *(void (__fastcall **)(__int64, double, double)) (*(_QWORD *) v11 + 16LL);
        Color v21(0.0, 0.0, 0.0, 0.0);
        v12(v11, *(double *) v21.cdata, *(double *) &v21.cdata[2]);
        v14 = this->scene()->render();
        (*(void (__fastcall **)(__int64, __int64)) (*(_QWORD *) v14 + 32LL))(v14, 1LL);
        v16 = this->scene()->render();
        (*(void (__fastcall **)(__int64, double)) (*(_QWORD *) v16 + 16LL))(v16, cl_0);
        this->draw();
        this->data->lights->exec();
        this->frameBuffer->unbind();
        if (this->used)
            this->postProcess(v[0], v[1], v[2], v[3]);
        v18 = this->scene()->render();
        (*(void (__fastcall **)(__int64, _QWORD, _QWORD, _QWORD, _QWORD)) (*(_QWORD *) v18 + 88LL))(
                v18,
                (unsigned int) v[0],
                (unsigned int) v[1],
                (unsigned int) v[2],
                (unsigned int) v[3]);
    }

    void GlowPass::draw() {
        this->used = 0;
        s = this->scene()->graph();
        ISceneGraph::Visibles obj(s);
        v4 = this->scene()->render();
        (*(void (__fastcall **)(__int64)) (*(_QWORD *) v4 + 296LL))(v4);
        for (int i = 0;; ++i) {
            if (obj.size() <= i)
                break;
            if (this->isDrawable(obj[i])) {
                this->drawObject(obj[i]);
                this->used = 1;
            }
        }
        v9 = this->scene()->render();
        (*(void (__fastcall **)(__int64)) (*(_QWORD *) v9 + 312LL))(v9);
    }

    void GlowPass::postProcess(int a2, int a3, int a4, int a5) {
        this->data->blur->exec();
    }

    ITextureRectangle *GlowPass::output() {
        return this->data->blur->output();
    }

    IRenderPass::Pass::Type GlowPass::type() {
        return 5;
    }
}