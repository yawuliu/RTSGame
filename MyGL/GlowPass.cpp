#include "GlowPass.h"

namespace MyGL {
    GlowPass::GlowPass(IScene &s, const Adapter &adapter, ITextureRectangle *depth) : AbstractPass(s) {
        IScene *v4;
        IRender *r;
        TextureRectangle *frame;
        IScene *v7;
        GlowPass::Data *data;
        IScene *s_1;
        BloomPass *bloomPass;
        IShader *s_2;
        IScene *s_3;
        SmallLightsPass *lights;
        v4 = this->scene();
        r = v4->render();
        this->frame = new TextureRectangle(r);
        this->depthBuf = depth;
        this->frame->setFiltration(1LL,1LL);
        this->frameBuffer = 0LL;
        this->fakeLv = 1;
        this->resizeFrame();
        this->data = new Data(this->scene());
        this->data->blur = new BloomPass(this->scene(), adapter, this->frame);
        s_2 = adapter->getGlowDownSampleShader();
        this->data->blur->setShader(s_2);
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
        IScene *v1;
        __int64 v2;
        IScene *v3;
        IRender *r;
        unsigned int theWidth;
        unsigned int theHeight;
        int v[12];

        v1 = this->scene();
        v2 = v1->render();
        (*(void (__fastcall **)(__int64, int *, int *, int *, int *)) (*(_QWORD *) v2 + 96LL))(v2, v, &v[1], &v[2],
                                                                                               &v[3]);

        this->frame->setFiltration(0LL,
                1LL,
                (unsigned int) (v[2] / this->fakeLv),
                (unsigned int) (v[3] / this->fakeLv),
                4LL);
        if (this->frameBuffer)
            delete this->frameBuffer;
        v3 = this->scene();
        r = v3->render();
        theWidth = this->frame->setClamping();
        theHeight = this->frame->setClamping();
        this->frameBuffer = new FBO(r, theWidth, theHeight, 4);
    }

    void GlowPass::initShaders(const Adapter &adapter) {
        ;
    }

    void GlowPass::exec() {
        IScene *v1;
        __int64 v2;
        int v3;
        int v4;
        IScene *v6;
        __int64 v7;
        IScene *v8;
        __int64 v9;
        IScene *v10;
        __int64 v11;
        void (__fastcall *v12)(__int64, double, double);
        IScene *v13;
        __int64 v14;
        IScene *v15;
        __int64 v16;
        IScene *v17;
        __int64 v18;
        double cl_0;
        int v[4];
        Color v21;

        v1 = this->scene();
        v2 = v1->render();
        (*(void (__fastcall **)(__int64, int *, int *, int *, int *)) (*(_QWORD *) v2 + 96LL))(v2, v, &v[1], &v[2],
                                                                                               &v[3]);
        v3 = v[2] / this->fakeLv;
        if (v3 !=  this->frame->setClamping())
            || (v4 = v[3] / this->fakeLv,
                v4 !=  this->frame->setClamping())) {
            this->resizeFrame();
        }
        v6 = this->scene();
        v7 = v6->render();
        (*(void (__fastcall **)(__int64, _QWORD, _QWORD, _QWORD, _QWORD)) (*(_QWORD *) v7 + 88LL))(
                v7,
                (unsigned int) v[0],
                (unsigned int) v[1],
                (unsigned int) (v[2] / this->fakeLv),
                (unsigned int) (v[3] / this->fakeLv));
        (*((void (__fastcall **)(FBO *)) glowPass->frameBuffer->_vptr_IFBO + 8))(this->frameBuffer);
        (*((void (__fastcall **)(FBO *, ITextureRectangle *, _QWORD)) glowPass->frameBuffer->_vptr_IFBO + 12))(
                this->frameBuffer,
                this->frame,
                0LL);
        (*((void (__fastcall **)(FBO *, ITextureRectangle *)) glowPass->frameBuffer->_vptr_IFBO + 13))(
                this->frameBuffer,
                this->depthBuf);
        v8 = this->scene();
        v9 = v8->render();
        cl_0 = (*(double (__fastcall **)(__int64)) (*(_QWORD *) v9 + 24LL))(v9);
        v10 = this->scene();
        v11 = v10->render();
        v12 = *(void (__fastcall **)(__int64, double, double)) (*(_QWORD *) v11 + 16LL);
        Color v21(0.0, 0.0, 0.0, 0.0);
        v12(v11, *(double *) v21.cdata, *(double *) &v21.cdata[2]);
        v13 = this->scene();
        v14 = v13->render();
        (*(void (__fastcall **)(__int64, __int64)) (*(_QWORD *) v14 + 32LL))(v14, 1LL);
        v15 = this->scene();
        v16 = v15->render();
        (*(void (__fastcall **)(__int64, double)) (*(_QWORD *) v16 + 16LL))(v16, cl_0);
        this->draw();
        this->data->lights->exec();
        (*((void (__fastcall **)(FBO *)) glowPass->frameBuffer->_vptr_IFBO + 9))(this->frameBuffer);
        if (this->used)
            this->postProcess(v[0], v[1], v[2], v[3]);
        v17 = this->scene();
        v18 = v17->render();
        (*(void (__fastcall **)(__int64, _QWORD, _QWORD, _QWORD, _QWORD)) (*(_QWORD *) v18 + 88LL))(
                v18,
                (unsigned int) v[0],
                (unsigned int) v[1],
                (unsigned int) v[2],
                (unsigned int) v[3]);
    }

    void GlowPass::draw() {
        IScene *v1;
        void *s;
        IScene *v3;
        __int64 v4;
        IGraphicsObject *obj_2;
        IGraphicsObject *obj_1;
        int i_1;
        IScene *v8;
        __int64 v9;
        int i;

        this->used = 0;
        v1 = this->scene();
        s = v1->graph();
        ISceneGraph::Visibles obj(s);
        v3 = this->scene();
        v4 = v3->render();
        (*(void (__fastcall **)(__int64)) (*(_QWORD *) v4 + 296LL))(v4);
        for (i = 0;; ++i) {
            i_1 = ISceneGraph::Visibles::size(&obj);
            if (i_1 <= i)
                break;
            obj_2 = ISceneGraph::Visibles::operator[](&obj, i);
            if (GlowPass::isDrawable(this, obj_2)) {
                obj_1 = ISceneGraph::Visibles::operator[](&obj, i);
                this->drawObject<GlowPass>(obj_1);
                this->used = 1;
            }
        }
        v8 = this->scene();
        v9 = v8->render();
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