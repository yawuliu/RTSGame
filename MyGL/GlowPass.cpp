#include "GlowPass.h"

MyGL::GlowPass::GlowPass(MyGL::IScene &s, const MyGL::Adapter &adapter, MyGL::ITextureRectangle *depth) : AbstractPass(
        s) {
    MyGL::IScene *v4;
    MyGL::IRender *r;
    MyGL::TextureRectangle *frame;
    MyGL::IScene *v7;
    MyGL::GlowPass::Data *data;
    MyGL::IScene *s_1;
    MyGL::BloomPass *bloomPass;
    MyGL::IShader *s_2;
    MyGL::IScene *s_3;
    MyGL::SmallLightsPass *lights;
    v4 = this->scene();
    r = (MyGL::IRender *) (*((__int64 (__fastcall **)(MyGL::IScene *)) v4->_vptr_IScene + 3))(v4);
    frame = (MyGL::TextureRectangle *) operator new(0x28uLL);
    MyGL::TextureRectangle::TextureRectangle(frame, r);
    this->frame = frame;
    this->depthBuf = depth;
    (*((void (__fastcall **)(MyGL::ITextureRectangle *, __int64, __int64)) glowPass->frame->_vptr_ITexture + 6))(
            this->frame,
            1LL,
            1LL);
    this->frameBuffer = 0LL;
    this->fakeLv = 1;
    this->resizeFrame();
    v7 = this->scene();
    data = (MyGL::GlowPass::Data *) operator new(0x10uLL);
    MyGL::GlowPass::Data::Data(data, v7);
    this->data = data;
    s_1 = this->scene();
    bloomPass = (MyGL::BloomPass *) operator new(0x78uLL);
    MyGL::BloomPass::BloomPass(bloomPass, s_1, adapter, this->frame);
    this->data->blur = bloomPass;
    s_2 = (MyGL::IShader *) (*((__int64 (__fastcall **)(const MyGL::Adapter &)) adapter->_vptr_Adapter + 4))(adapter);
    MyGL::BloomPass::setShader(this->data->blur, s_2);
    MyGL::BloomPass::setDownSamplesCount(this->data->blur, 2);
    s_3 = this->scene();
    lights = (MyGL::SmallLightsPass *) operator new(0x10uLL);
    MyGL::SmallLightsPass::SmallLightsPass(lights, s_3, adapter);
    this->data->lights = lights;
    this->initShaders(adapter);
}

MyGL::GlowPass::~GlowPass() {
    if (this->data->lights)
        (*((void (__fastcall **)(MyGL::SmallLightsPass *)) this->data->lights->_vptr_IRenderPass + 1))(
                this->data->lights);
    if (this->data->blur)
        (*((void (__fastcall **)(MyGL::BloomPass *)) this->data->blur->_vptr_IRenderPass + 1))(this->data->blur);
    operator delete(this->data);
    if (this->frame)
        (*((void (__fastcall **)(MyGL::ITextureRectangle *)) this->frame->_vptr_ITexture + 1))(this->frame);
    if (this->frameBuffer)
        (*((void (__fastcall **)(MyGL::FBO *)) this->frameBuffer->_vptr_IFBO + 1))(this->frameBuffer);

}

bool MyGL::GlowPass::validate() {
    return MyGL::BloomPass::validate(this->data->blur);
}

bool MyGL::GlowPass::isDrawable(MyGL::IGraphicsObject &obj) {
    return (*((unsigned __int8 (__fastcall **)(MyGL::IGraphicsObject &)) obj->_vptr_IGraphicsObject + 9))(obj) == 1;
}

void MyGL::GlowPass::resizeFrame() {
    MyGL::IScene *v1;
    __int64 v2;
    MyGL::IScene *v3;
    MyGL::IRender *r;
    unsigned int theWidth;
    unsigned int theHeight;
    MyGL::FBO *frameBuffer;
    int v[12];

    v1 = this->scene();
    v2 = (*((__int64 (__fastcall **)(MyGL::IScene *)) v1->_vptr_IScene + 3))(v1);
    (*(void (__fastcall **)(__int64, int *, int *, int *, int *)) (*(_QWORD *) v2 + 96LL))(v2, v, &v[1], &v[2], &v[3]);
    (*((void (__fastcall **)(MyGL::ITextureRectangle *, _QWORD, __int64, _QWORD, _QWORD,
                             __int64)) glowPass->frame->_vptr_ITexture
       + 7))(
            this->frame,
            0LL,
            1LL,
            (unsigned int) (v[2] / this->fakeLv),
            (unsigned int) (v[3] / this->fakeLv),
            4LL);
    if (this->frameBuffer)
        (*((void (__fastcall **)(MyGL::FBO *)) glowPass->frameBuffer->_vptr_IFBO + 1))(this->frameBuffer);
    v3 = this->scene();
    r = (MyGL::IRender *) (*((__int64 (__fastcall **)(MyGL::IScene *)) v3->_vptr_IScene + 3))(v3);
    theWidth = (*((__int64 (__fastcall **)(MyGL::ITextureRectangle *)) this->frame->_vptr_ITexture + 8))(
            this->frame);
    theHeight = (*((__int64 (__fastcall **)(MyGL::ITextureRectangle *)) this->frame->_vptr_ITexture + 9))(
            this->frame);
    frameBuffer = (MyGL::FBO *) operator new(0x28uLL);
    MyGL::FBO::FBO(frameBuffer, r, theWidth, theHeight, 4);
    this->frameBuffer = frameBuffer;
}

void MyGL::GlowPass::initShaders(const MyGL::Adapter &adapter) {
    ;
}

void MyGL::GlowPass::exec() {
    MyGL::IScene *v1;
    __int64 v2;
    int v3;
    int v4;
    MyGL::IScene *v6;
    __int64 v7;
    MyGL::IScene *v8;
    __int64 v9;
    MyGL::IScene *v10;
    __int64 v11;
    void (__fastcall *v12)(__int64, double, double);
    MyGL::IScene *v13;
    __int64 v14;
    MyGL::IScene *v15;
    __int64 v16;
    MyGL::IScene *v17;
    __int64 v18;
    double cl_0;
    int v[4];
    MyGL::Color v21;

    v1 = this->scene();
    v2 = (*((__int64 (__fastcall **)(MyGL::IScene *)) v1->_vptr_IScene + 3))(v1);
    (*(void (__fastcall **)(__int64, int *, int *, int *, int *)) (*(_QWORD *) v2 + 96LL))(v2, v, &v[1], &v[2], &v[3]);
    v3 = v[2] / this->fakeLv;
    if (v3 != (*((unsigned int (__fastcall **)(MyGL::ITextureRectangle *)) this->frame->_vptr_ITexture + 8))(
            this->frame)
        || (v4 = v[3] / this->fakeLv,
            v4 != (*((unsigned int (__fastcall **)(MyGL::ITextureRectangle *)) this->frame->_vptr_ITexture + 9))(
                    this->frame))) {
        MyGL::GlowPass::resizeFrame(this);
    }
    v6 = this->scene();
    v7 = (*((__int64 (__fastcall **)(MyGL::IScene *)) v6->_vptr_IScene + 3))(v6);
    (*(void (__fastcall **)(__int64, _QWORD, _QWORD, _QWORD, _QWORD)) (*(_QWORD *) v7 + 88LL))(
            v7,
            (unsigned int) v[0],
            (unsigned int) v[1],
            (unsigned int) (v[2] / this->fakeLv),
            (unsigned int) (v[3] / this->fakeLv));
    (*((void (__fastcall **)(MyGL::FBO *)) glowPass->frameBuffer->_vptr_IFBO + 8))(this->frameBuffer);
    (*((void (__fastcall **)(MyGL::FBO *, MyGL::ITextureRectangle *, _QWORD)) glowPass->frameBuffer->_vptr_IFBO + 12))(
            this->frameBuffer,
            this->frame,
            0LL);
    (*((void (__fastcall **)(MyGL::FBO *, MyGL::ITextureRectangle *)) glowPass->frameBuffer->_vptr_IFBO + 13))(
            this->frameBuffer,
            this->depthBuf);
    v8 = this->scene();
    v9 = (*((__int64 (__fastcall **)(MyGL::IScene *)) v8->_vptr_IScene + 3))(v8);
    cl_0 = (*(double (__fastcall **)(__int64)) (*(_QWORD *) v9 + 24LL))(v9);
    v10 = this->scene();
    v11 = (*((__int64 (__fastcall **)(MyGL::IScene *)) v10->_vptr_IScene + 3))(v10);
    v12 = *(void (__fastcall **)(__int64, double, double)) (*(_QWORD *) v11 + 16LL);
    MyGL::Color::Color(&v21, 0.0, 0.0, 0.0, 0.0);
    v12(v11, *(double *) v21.cdata, *(double *) &v21.cdata[2]);
    v13 = this->scene();
    v14 = (*((__int64 (__fastcall **)(MyGL::IScene *)) v13->_vptr_IScene + 3))(v13);
    (*(void (__fastcall **)(__int64, __int64)) (*(_QWORD *) v14 + 32LL))(v14, 1LL);
    v15 = this->scene();
    v16 = (*((__int64 (__fastcall **)(MyGL::IScene *)) v15->_vptr_IScene + 3))(v15);
    (*(void (__fastcall **)(__int64, double)) (*(_QWORD *) v16 + 16LL))(v16, cl_0);
    MyGL::GlowPass::draw(this);
    (*((void (__fastcall **)(MyGL::SmallLightsPass *)) this->data->lights->_vptr_IRenderPass + 2))(
            this->data->lights);
    (*((void (__fastcall **)(MyGL::FBO *)) glowPass->frameBuffer->_vptr_IFBO + 9))(this->frameBuffer);
    if (this->used)
        MyGL::GlowPass::postProcess(this, v[0], v[1], v[2], v[3]);
    v17 = this->scene();
    v18 = (*((__int64 (__fastcall **)(MyGL::IScene *)) v17->_vptr_IScene + 3))(v17);
    (*(void (__fastcall **)(__int64, _QWORD, _QWORD, _QWORD, _QWORD)) (*(_QWORD *) v18 + 88LL))(
            v18,
            (unsigned int) v[0],
            (unsigned int) v[1],
            (unsigned int) v[2],
            (unsigned int) v[3]);
}

void MyGL::GlowPass::draw() {
    MyGL::IScene *v1;
    void *s;
    MyGL::IScene *v3;
    __int64 v4;
    MyGL::IGraphicsObject *obj_2;
    MyGL::IGraphicsObject *obj_1;
    int i_1;
    MyGL::IScene *v8;
    __int64 v9;
    MyGL::ISceneGraph::Visibles obj;
    int i;

    this->used = 0;
    v1 = this->scene();
    s = (void *) (*((__int64 (__fastcall **)(MyGL::IScene *)) v1->_vptr_IScene + 8))(v1);
    MyGL::ISceneGraph::Visibles::Visibles(&obj, s);
    v3 = this->scene();
    v4 = (*((__int64 (__fastcall **)(MyGL::IScene *)) v3->_vptr_IScene + 3))(v3);
    (*(void (__fastcall **)(__int64)) (*(_QWORD *) v4 + 296LL))(v4);
    for (i = 0;; ++i) {
        i_1 = MyGL::ISceneGraph::Visibles::size(&obj);
        if (i_1 <= i)
            break;
        obj_2 = MyGL::ISceneGraph::Visibles::operator[](&obj, i);
        if (MyGL::GlowPass::isDrawable(this, obj_2)) {
            obj_1 = MyGL::ISceneGraph::Visibles::operator[](&obj, i);
            MyGL::AbstractPass::drawObject<MyGL::GlowPass>(this, obj_1);
            this->used = 1;
        }
    }
    v8 = this->scene();
    v9 = (*((__int64 (__fastcall **)(MyGL::IScene *)) v8->_vptr_IScene + 3))(v8);
    (*(void (__fastcall **)(__int64)) (*(_QWORD *) v9 + 312LL))(v9);
}

void MyGL::GlowPass::postProcess(int a2, int a3, int a4, int a5) {
    (*((void (__fastcall **)(MyGL::BloomPass *)) this->data->blur->_vptr_IRenderPass + 2))(this->data->blur);
}

MyGL::ITextureRectangle *MyGL::GlowPass::output() {
    return MyGL::BloomPass::output(this->data->blur);
}

MyGL::IRenderPass::Pass::Type MyGL::GlowPass::type() {
    return 5;
}
