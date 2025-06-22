#include "MainPass.h"

MyGL::MainPass::MainPass(MyGL::IScene &s, const MyGL::Adapter &adapter, MyGL::IModel *q, bool autoMake) : AbstractPass(
        s) {
    MyGL::IScene *v5;
    MyGL::IRender *r;
    MyGL::TextureRectangle *frame;
    MyGL::IScene *v8;
    MyGL::IRender *r_1;
    MyGL::TextureRectangle *depth;
    v5 = MyGL::AbstractPass::scene(this);
    r = (MyGL::IRender *) (*((__int64 (__fastcall **)(MyGL::IScene *)) v5->_vptr_IScene + 3))(v5);
    frame = (MyGL::TextureRectangle *) operator new(0x28uLL);
    MyGL::TextureRectangle::TextureRectangle(frame, r);
    this->frame = frame;
    v8 = MyGL::AbstractPass::scene(this);
    r_1 = (MyGL::IRender *) (*((__int64 (__fastcall **)(MyGL::IScene *)) v8->_vptr_IScene + 3))(v8);
    depth = (MyGL::TextureRectangle *) operator new(0x28uLL);
    MyGL::TextureRectangle::TextureRectangle(depth, r_1);
    this->depth = depth;
    this->m_frameBuffer = 0LL;
    this->quad = q;
    this->resizeFrame();
    if (autoMake)
        this->makeAlgo(adapter);
}

MyGL::MainPass::~MainPass() {
    MyGL::IRenderPass *v1;
    unsigned int i;
    if (this->frame)
        (*((void (__fastcall **)(MyGL::ITextureRectangle *)) this->frame->_vptr_ITexture + 1))(this->frame);
    if (this->depth)
        (*((void (__fastcall **)(MyGL::ITextureRectangle *)) this->depth->_vptr_ITexture + 1))(this->depth);
    if (this->m_frameBuffer)
        (*((void (__fastcall **)(MyGL::FBO *)) this->m_frameBuffer->_vptr_IFBO + 1))(this->m_frameBuffer);
    for (i = 0; i < std::vector<MyGL::IRenderPass *>::size(&this->passes); ++i) {
        v1 = *std::vector<MyGL::IRenderPass *>::operator[](&this->passes, i);
        if (v1)
            (*((void (__fastcall **)(MyGL::IRenderPass *)) v1->_vptr_IRenderPass + 1))(v1);
    }
}

void MyGL::MainPass::buildQuad(int w, int h) {
    float *p;
    float *p_1;
    float *p_2;
    float *p_3;
    float *p_4;
    float *p_5;
    float *p_6;
    float *p_7;
    MyGL::IOModel m;
    MyGL::IIOModel::Point retstr_;
    MyGL::IIOModel::Point retstr__1;
    MyGL::IIOModel::Point retstr__2;
    MyGL::IIOModel::Point retstr__3;
    MyGL::IIOModel::TexCoord retstr__4;
    MyGL::IIOModel::TexCoord retstr__5;
    MyGL::IIOModel::TexCoord retstr__6;
    MyGL::IIOModel::TexCoord retstr__7;

    MyGL::IOModel::IOModel(&m);
    MyGL::IOModel::allock(&m, 4uLL);
    MyGL::IOModel::point(&retstr_, &m, 0);
    p = MyGL::IIOModel::Point::data(&retstr_);
    MyGL::MainPass::setPoint(p, -1.0, -1.0);
    MyGL::IOModel::point(&retstr__1, &m, 1);
    p_1 = MyGL::IIOModel::Point::data(&retstr__1);
    MyGL::MainPass::setPoint(p_1, 1.0, -1.0);
    MyGL::IOModel::point(&retstr__2, &m, 2);
    p_2 = MyGL::IIOModel::Point::data(&retstr__2);
    MyGL::MainPass::setPoint(p_2, 1.0, 1.0);
    MyGL::IOModel::point(&retstr__3, &m, 3);
    p_3 = MyGL::IIOModel::Point::data(&retstr__3);
    MyGL::MainPass::setPoint(p_3, -1.0, 1.0);
    MyGL::IOModel::texCoord(&retstr__4, &m, 0);
    p_4 = MyGL::IIOModel::TexCoord::data(&retstr__4);
    MyGL::MainPass::setPoint(p_4, 0.0, 0.0);
    MyGL::IOModel::texCoord(&retstr__5, &m, 1);
    p_5 = MyGL::IIOModel::TexCoord::data(&retstr__5);
    MyGL::MainPass::setPoint(p_5, (float) w, 0.0);
    MyGL::IOModel::texCoord(&retstr__6, &m, 2);
    p_6 = MyGL::IIOModel::TexCoord::data(&retstr__6);
    MyGL::MainPass::setPoint(p_6, (float) w, (float) h);
    MyGL::IOModel::texCoord(&retstr__7, &m, 3);
    p_7 = MyGL::IIOModel::TexCoord::data(&retstr__7);
    MyGL::MainPass::setPoint(p_7, 0.0, (float) h);
    (*((void (__fastcall **)(MyGL::IModel *, MyGL::IOModel *)) this->quad->_vptr_IModel + 8))(this->quad, &m);
    (*((void (__fastcall **)(MyGL::IModel *, __int64)) this->quad->_vptr_IModel + 4))(this->quad, 2LL);
    MyGL::IOModel::~IOModel(&m);
}

MyGL::ITextureRectangle *MyGL::MainPass::depthBuffer() {
    return this->depth;
}

void MyGL::MainPass::draw() {
    MyGL::IScene *v1;
    __int64 v2;
    MyGL::IScene *v3;
    __int64 v4;
    std::vector<MyGL::IRenderPass *>::reference v5;
    MyGL::IScene *v6;
    __int64 v7;
    unsigned int i;

    v1 = MyGL::AbstractPass::scene(this);
    v2 = (*((__int64 (__fastcall **)(MyGL::IScene *)) v1->_vptr_IScene + 3))(v1);
    (*(void (__fastcall **)(__int64)) (*(_QWORD *) v2 + 248LL))(v2);
    v3 = MyGL::AbstractPass::scene(this);
    v4 = (*((__int64 (__fastcall **)(MyGL::IScene *)) v3->_vptr_IScene + 8))(v3);
    (*(void (__fastcall **)(__int64, MyGL::MainPass *const)) (*(_QWORD *) v4 + 40LL))(v4, this);
    for (i = 0; i < std::vector<MyGL::IRenderPass *>::size(&this->passes); ++i) {
        v5 = std::vector<MyGL::IRenderPass *>::operator[](&this->passes, i);
        (*((void (__fastcall **)(MyGL::IRenderPass *)) (*v5)->_vptr_IRenderPass + 2))(*v5);
    }
    v6 = MyGL::AbstractPass::scene(this);
    v7 = (*((__int64 (__fastcall **)(MyGL::IScene *)) v6->_vptr_IScene + 8))(v6);
    (*(void (__fastcall **)(__int64)) (*(_QWORD *) v7 + 48LL))(v7);
}

void MyGL::MainPass::exec() {
    MyGL::IScene *v1;
    __int64 v2;
    int v3;
    int v4;
    MyGL::FBO *v6;
    MyGL::FBO *v7;
    MyGL::FBO *v8;
    MyGL::IScene *v9;
    __int64 v10;
    MyGL::FBO *v11;
    int v[8];

    v1 = MyGL::AbstractPass::scene(this);
    v2 = (*((__int64 (__fastcall **)(MyGL::IScene *)) v1->_vptr_IScene + 3))(v1);
    (*(void (__fastcall **)(__int64, int *, int *, int *, int *)) (*(_QWORD *) v2 + 96LL))(v2, v, &v[1], &v[2],
                                                                                           &v[3]);
    v3 = v[2];
    if (v3 != (*((unsigned int (__fastcall **)(MyGL::ITextureRectangle *)) this->frame->_vptr_ITexture + 8))(
            this->frame)
        || (v4 = v[3],
            v4 !=
            (*((unsigned int (__fastcall **)(MyGL::ITextureRectangle *)) this->frame->_vptr_ITexture + 9))(
                    this->frame))) {
        MyGL::MainPass::resizeFrame(this);
    }
    v6 = this->frameBuffer();
    (*((void (__fastcall **)(MyGL::FBO *)) v6->_vptr_IFBO + 8))(v6);
    v7 = this->frameBuffer();
    (*((void (__fastcall **)(MyGL::FBO *, MyGL::ITextureRectangle *, _QWORD)) v7->_vptr_IFBO + 12))(v7,
                                                                                                    this->frame,
                                                                                                    0LL);
    v8 = this->rameBuffer();
    (*((void (__fastcall **)(MyGL::FBO *, MyGL::ITextureRectangle *)) v8->_vptr_IFBO + 13))(v8, this->depth);
    v9 = MyGL::AbstractPass::scene(this);
    v10 = (*((__int64 (__fastcall **)(MyGL::IScene *)) v9->_vptr_IScene + 3))(v9);
    (*(void (__fastcall **)(__int64, __int64)) (*(_QWORD *) v10 + 32LL))(v10, 3LL);
    MyGL::MainPass::draw(this);
    v11 = this->frameBuffer();
    (*((void (__fastcall **)(MyGL::FBO *)) v11->_vptr_IFBO + 9))(v11);
}

MyGL::FBO *MyGL::MainPass::frameBuffer() {
    return this->m_frameBuffer;
}

void MyGL::MainPass::makeAlgo(const MyGL::Adapter &adapter) {
    (*((void (__fastcall **)(MyGL::MainPass *const, std::vector<MyGL::IRenderPass *> *,
                             const MyGL::Adapter *const)) this->_vptr_IRenderPass
       + 5))(
            this,
            &this->passes,
            adapter);
}

void MyGL::MainPass::makeAlgo(MyGL::MainPass &mp, std::vector<MyGL::IRenderPass *> &passes,
                              const MyGL::Adapter &adapter) {
    MyGL::IScene *s;
    MyGL::DepthPass *__x_1;
    MyGL::IScene *s_1;
    MyGL::ColorPass *__x__4;
    MyGL::IScene *s_2;
    MyGL::AddBlendPass *__x__5;
    MyGL::IScene *s_3;
    MyGL::TransparentPass *__x__6;
    MyGL::IScene *s_4;
    MyGL::SSAOpass *__x__7;
    std::vector<MyGL::IRenderPass *>::value_type __x;
    std::vector<MyGL::IRenderPass *>::value_type __x_;
    std::vector<MyGL::IRenderPass *>::value_type __x__1;
    std::vector<MyGL::IRenderPass *>::value_type __x__2;
    std::vector<MyGL::IRenderPass *>::value_type __x__3;

    s = MyGL::AbstractPass::scene(mp);
    __x_1 = (MyGL::DepthPass *) operator new(0x10uLL);
    MyGL::DepthPass::DepthPass(__x_1, s);
    __x = __x_1;
    std::vector<MyGL::IRenderPass *>::push_back(passes, &__x);
    s_1 = MyGL::AbstractPass::scene(mp);
    __x__4 = (MyGL::ColorPass *) operator new(0x10uLL);
    MyGL::ColorPass::ColorPass(__x__4, s_1);
    __x_ = __x__4;
    std::vector<MyGL::IRenderPass *>::push_back(passes, &__x_);
    s_2 = MyGL::AbstractPass::scene(mp);
    __x__5 = (MyGL::AddBlendPass *) operator new(0x10uLL);
    MyGL::AddBlendPass::AddBlendPass(__x__5, s_2);
    __x__1 = __x__5;
    std::vector<MyGL::IRenderPass *>::push_back(passes, &__x__1);
    s_3 = MyGL::AbstractPass::scene(mp);
    __x__6 = (MyGL::TransparentPass *) operator new(0x18uLL);
    MyGL::TransparentPass::TransparentPass(__x__6, s_3);
    __x__2 = __x__6;
    std::vector<MyGL::IRenderPass *>::push_back(passes, &__x__2);
    s_4 = MyGL::AbstractPass::scene(mp);
    __x__7 = (MyGL::SSAOpass *) operator new(0x50uLL);
    MyGL::SSAOpass::SSAOpass(__x__7, s_4, adapter, mp);
    __x__3 = __x__7;
    std::vector<MyGL::IRenderPass *>::push_back(passes, &__x__3);
}

MyGL::ITextureRectangle *MyGL::MainPass::output() {
    return this->frame;
}

MyGL::IModel *MyGL::MainPass::quadModel() {
    return this->quad;
}

void MyGL::MainPass::resizeFrame() {
    MyGL::IScene *v1;
    __int64 v2;
    MyGL::IScene *v3;
    MyGL::IRender *r;
    unsigned int theWidth;
    unsigned int theHeight;
    MyGL::FBO *m_frameBuffer;
    int v[12];

    v1 = this->scene();
    v2 = (*((__int64 (__fastcall **)(MyGL::IScene *)) v1->_vptr_IScene + 3))(v1);
    (*(void (__fastcall **)(__int64, int *, int *, int *, int *)) (*(_QWORD *) v2 + 96LL))(v2, v, &v[1], &v[2],
                                                                                           &v[3]);
    (*((void (__fastcall **)(MyGL::ITextureRectangle *, _QWORD, __int64, _QWORD, _QWORD,
                             __int64)) this->frame->_vptr_ITexture
       + 7))(
            this->frame,
            0LL,
            1LL,
            (unsigned int) v[2],
            (unsigned int) v[3],
            4LL);
    (*((void (__fastcall **)(MyGL::ITextureRectangle *, _QWORD, __int64, _QWORD, _QWORD,
                             __int64)) this->depth->_vptr_ITexture
       + 7))(
            this->depth,
            0LL,
            3LL,
            (unsigned int) v[2],
            (unsigned int) v[3],
            21LL);
    if (this->m_frameBuffer)
        (*((void (__fastcall **)(MyGL::FBO *)) this->m_frameBuffer->_vptr_IFBO + 1))(this->m_frameBuffer);
    v3 = MyGL::AbstractPass::scene(this);
    r = (MyGL::IRender *) (*((__int64 (__fastcall **)(MyGL::IScene *)) v3->_vptr_IScene + 3))(v3);
    theWidth = (*((__int64 (__fastcall **)(MyGL::ITextureRectangle *)) this->frame->_vptr_ITexture + 8))(
            this->frame);
    theHeight = (*((__int64 (__fastcall **)(MyGL::ITextureRectangle *)) this->frame->_vptr_ITexture + 9))(
            this->frame);
    m_frameBuffer = (MyGL::FBO *) operator new(0x28uLL);
    MyGL::FBO::FBO(m_frameBuffer, r, theWidth, theHeight, 4);
    this->m_frameBuffer = m_frameBuffer;
    MyGL::MainPass::buildQuad(this, v[2], v[3]);
}

void MyGL::MainPass::setPoint(float *p, float x, float y) {
    p[0] = x;
    p[1] = y;
}

MyGL::IRenderPass::Pass::Type MyGL::MainPass::type() {
    return 0;
}
