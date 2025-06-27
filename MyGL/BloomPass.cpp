#include "BloomPass.h"

namespace MyGL {
    MyGL::BloomPass::Data::Data(IScene &s, IModel *quad) : gausV(s), gausH(s), grab(s) {
        this->gausV.setQuadModel(quad);
        this->gausH.setQuadModel(quad);
        this->grab.setQuadModel(quad);
    }

    MyGL::BloomPass::BloomPass(IScene &s, const Adapter *const adapter, ITextureRectangle *in) : AbstractPass(s) {
        IScene *v4;
        IRender *r;
        TextureRectangle *frame;
        IScene *v7;
        IRender *r_1;
        TextureRectangle *subFrame;
        IScene *v10;
        IRender *r_2;
        TextureRectangle *v12;
        IScene *v13;
        IRender *r_3;
        Model *v15;
        IScene *s_1;
        BloomPass::Data *data;
        IRenderState *v18;
        IRenderState *v19;
        IRenderState *v20;
        IRenderState *v21;
        int i;
        int i_0;
        this->m_isValid = 1;
        this->input = in;
        this->m_downSamplesCount = -1;
        v4 = this->scene();
        r = v4->render();
        frame = (TextureRectangle *) operator new(0x28uLL);
        TextureRectangle::TextureRectangle(frame, r);
        this->frame = frame;
        v7 = this->scene();
        r_1 = v7->render();
        subFrame = (TextureRectangle *) operator new(0x28uLL);
        TextureRectangle::TextureRectangle(subFrame, r_1);
        this->subFrame = subFrame;

        this->frame->setFiltration(
                1LL,
                1LL);

        this->subFrame->setFiltration(
                1LL,
                1LL);
        for (i_0 = 0; i_0 <= 1; ++i_0) {
            v10 = this->scene();
            r_2 = v10->render();
            v12 = (TextureRectangle *) operator new(0x28uLL);
            TextureRectangle::TextureRectangle(v12, r_2);
            (&this->input)[i_0 + 1] = v12;
        }
        this->frameBuffer[0] = 0LL;
        this->frameBuffer[1] = 0LL;
        this->frameBuffer[2] = 0LL;
        for (i = 0; i <= 2; ++i) {
            v13 = this->scene();
            r_3 = v13->render();
            v15 = (Model *) operator new(0xC0uLL);
            Model::Model(v15, r_3);
            this->quad[i] = v15;
        }
        s_1 = this->scene();
        data = (BloomPass::Data *) operator new(0x58uLL);
        BloomPass::Data::Data(data, s_1, this->quad[2]);
        this->data = data;
        this->data->w = -1;
        this->data->h = -1;
        v18 = this->data->gausH->renderState();
        v18->setBlend(1LL);
        v19 = this->data->gausH->renderState();
        v19->setBlendMode(1LL, 1LL);
        v20 = this->data->gausH->renderState();
        v20->setAlphaTestMode(1LL);
        v21 = this->data->gausH->renderState();
        v21->setAlphaTestRef(0.0);
        this->setDownSamplesCount(3);
        this->initShaders(adapter);
    }

    MyGL::BloomPass::~BloomPass() {
        int i_0;
        int i;
        if (this->data) {

            delete this->data;
        }
        if (this->frame)
            delete this->frame;
        for (i = 0; i <= 1; ++i) {
            if ((&this->input)[i + 1])
                delete (&this->input)[i + 1];
        }
        if (this->subFrame)
            delete this->subFrame;
        for (i_0 = 0; i_0 <= 2; ++i_0) {
            if (this->quad[i_0])
                delete this->quad[i_0];
            if ((&this->subFrame)[i_0 + 1])
                delete (&this->subFrame)[i_0 + 1];
        }
    }

    bool MyGL::BloomPass::validate() {
        return this->m_isValid;
    }

    int MyGL::BloomPass::downSamplesCount() {
        return this->m_downSamplesCount;
    }

    void MyGL::BloomPass::setDownSamplesCount(int c) {
        const int *__a;
        int ca;
        int __b_;
        int __b;

        ca = c;
        __b_ = 1;
        __b = 3;
        __a = std::min<int>(&ca, &__b);
        ca = *std::max<int>(__a, &__b_);
        if (this->m_downSamplesCount != ca) {
            this->m_downSamplesCount = ca;
            this->data->gausV.setQuadModel((IModel *) this->frameBuffer[ca + 2]);
            this->data->gausH.setQuadModel((IModel *) this->frameBuffer[ca + 2]);
            this->data->grab.setQuadModel((IModel *) this->frameBuffer[ca + 2]);
            this->resizeFrame();
        }
    }

    void MyGL::BloomPass::setShader(IShader *s) {
        BloomPass::Data *data;
        IShader *v3;
        std::string msg;
        _BYTE v5[17];

        this->m_isValid = 1;
        this->data->grab.setShader(s);
        if (s) {
            data = this->data;
            v3 = Filter::shader(&data->grab);
            data->textureIn = v3->uniformSampler("mainPass");
        } else {
            this->data->textureIn = 0LL;
            std::allocator<char>::allocator(v5);
            std::string::string(&msg, "[BloomPass::setShader]null shader", v5);
            BloomPass::incompleteEvent(this, &msg);
            std::string::~string(&msg);
            std::allocator<char>::~allocator(v5);
        }
        if (this->data->textureIn)
            this->data->textureIn->set(0LL);
    }

    void MyGL::BloomPass::buildQuad(int w, int h) {
        float *p;
        float *p_1;
        float *p_2;
        float *p_3;
        float *p_4;
        float *p_5;
        float *p_6;
        float *p_7;
        float *p_8;
        float *p_9;
        float *p_10;
        float *p_11;
        IOModel m;
        IIOModel::Point retstr_;
        IIOModel::Point retstr__1;
        IIOModel::Point retstr__2;
        IIOModel::Point retstr__3;
        IOModel::Normal retstr__4;
        IOModel::Normal retstr__5;
        IOModel::Normal retstr__6;
        IOModel::Normal retstr__7;
        IIOModel::TexCoord retstr__8;
        IIOModel::TexCoord retstr__9;
        IIOModel::TexCoord retstr__10;
        IIOModel::TexCoord retstr__11;
        int i;

        IOModel::IOModel(&m);
        IOModel::allock(&m, 4uLL);
        IOModel::point(&retstr_, &m, 0);
        p = IIOModel::Point::data(&retstr_);
        BloomPass::setPoint(p, -1.0, -1.0);
        IOModel::point(&retstr__1, &m, 1);
        p_1 = IIOModel::Point::data(&retstr__1);
        BloomPass::setPoint(p_1, 1.0, -1.0);
        IOModel::point(&retstr__2, &m, 2);
        p_2 = IIOModel::Point::data(&retstr__2);
        BloomPass::setPoint(p_2, 1.0, 1.0);
        IOModel::point(&retstr__3, &m, 3);
        p_3 = IIOModel::Point::data(&retstr__3);
        BloomPass::setPoint(p_3, -1.0, 1.0);
        IOModel::normal(&retstr__4, &m, 0);
        p_4 = IIOModel::Point::data(&retstr__4);
        BloomPass::setPoint(p_4, 1.0, 0.0);
        IOModel::normal(&retstr__5, &m, 1);
        p_5 = IIOModel::Point::data(&retstr__5);
        BloomPass::setPoint(p_5, 1.0, 0.0);
        IOModel::normal(&retstr__6, &m, 2);
        p_6 = IIOModel::Point::data(&retstr__6);
        BloomPass::setPoint(p_6, 1.0, 0.0);
        IOModel::normal(&retstr__7, &m, 3);
        p_7 = IIOModel::Point::data(&retstr__7);
        BloomPass::setPoint(p_7, 1.0, 0.0);
        for (i = 0; i <= 2; ++i) {
            IOModel::texCoord(&retstr__8, &m, 0);
            p_8 = IIOModel::TexCoord::data(&retstr__8);
            BloomPass::setPoint(p_8, 0.0, 0.0);
            IOModel::texCoord(&retstr__9, &m, 1);
            p_9 = IIOModel::TexCoord::data(&retstr__9);
            BloomPass::setPoint(p_9, (float) w, 0.0);
            IOModel::texCoord(&retstr__10, &m, 2);
            p_10 = IIOModel::TexCoord::data(&retstr__10);
            BloomPass::setPoint(p_10, (float) w, (float) h);
            IOModel::texCoord(&retstr__11, &m, 3);
            p_11 = IIOModel::TexCoord::data(&retstr__11);
            BloomPass::setPoint(p_11, 0.0, (float) h);
            w /= 2;
            h /= 2;
            this->quad[i]->load(&m);
            this->quad[i]->setPrimitivesType(2LL);
        }
        IOModel::~IOModel(&m);
    }

    void MyGL::BloomPass::setPoint(float *p, float x, float y) {
        *p = x;
        p[1] = y;
    }

    void MyGL::BloomPass::resizeFrame() {
        IScene *v1;
        __int64 v2;
        IScene *v3;
        IRender *r;
        FBO *v5;
        int v[6];
        int dw;
        int i;

        v1 = this->scene();
        v2 = v1->render();
        (*(void (__fastcall **)(__int64, int *, int *, int *, int *)) (*(_QWORD *) v2 + 96LL))(v2, v, &v[1], &v[2],
                                                                                               &v[3]);
        this->data->w = v[2];
        this->data->h = v[3];

        this->scale[0]->setFiltration(
                0LL,
                1LL,
                (unsigned int) (v[2] / 2),
                (unsigned int) (v[3] / 2),
                4LL);

        this->scale[1]->setFiltration(
                0LL,
                1LL,
                (unsigned int) (v[2] / 4),
                (unsigned int) (v[3] / 4),
                4LL);
        dw = 1 << this->downSamplesCount();

        this->frame->setFiltration(
                0LL,
                1LL,
                (unsigned int) (v[2] / dw),
                (unsigned int) (v[3] / dw),
                4LL);
        this->subFrame->setFiltration(
                0LL,
                1LL,
                (unsigned int) (v[2] / dw),
                (unsigned int) (v[3] / dw),
                4LL);
        BloomPass::buildQuad(this, v[2] / 2, v[3] / 2);
        for (i = 0; i <= 2; ++i) {
            if ((&this->subFrame)[i + 1])
                delete (&this->subFrame)[i + 1];
            v3 = this->scene();
            r = v3->render();
            v5 = (FBO *) operator new(0x28uLL);
            FBO::FBO(v5, r, v[2] / 2, v[3] / 2, 8);
            (&this->subFrame)[i + 1] = (ITextureRectangle *) v5;
            v[2] /= 2;
            v[3] /= 2;
        }
    }

    void MyGL::BloomPass::incompleteEvent(const std::string &msg) {
        IScene *v2;
        __int64 v3;
        CGL *v4;
        IErrorControl *v5;
        void (__fastcall *v6)(IErrorControl *, _QWORD, __int64);
        __int64 v7;

        v2 = this->scene();
        v3 = v2->render();
        v4 = (CGL *) (*(__int64 (__fastcall **)(__int64)) (*(_QWORD *) v3 + 72LL))(v3);
        v5 = CGL::errorCtrl(v4);
        v7 = std::string::data((std::string *) msg);
        v5->warning(0LL, v7);
        this->m_isValid = 0;
    }

    void MyGL::BloomPass::initShaders(const Adapter &adapter) {
        IShader *s;
        IShader *s_1;
        IShader *s_2;
        ITextureRectangle *frame;
        ITextureRectangle *subFrame;
        BloomPass::Data *data;
        IShader *v8;
        std::string name;
        char v11;
        std::string name_;
        char v13;
        std::string msg;
        char v15;
        std::string msg_;
        _BYTE v17[17];

        s = (IShader *) (*((__int64 (__fastcall **)(const Adapter *const)) adapter->_vptr_Adapter + 1))(adapter);
        this->data->gausV->setShader(s);
        s_1 = (IShader *) (*((__int64 (__fastcall **)(const Adapter *const)) adapter->_vptr_Adapter + 2))(adapter);
        this->data->gausH->setShader(s_1);
        s_2 = (IShader *) (*((__int64 (__fastcall **)(const Adapter *const)) adapter->_vptr_Adapter + 3))(adapter);
        this->data->grab->setShader(s_2);
        frame = this->frame;
        std::allocator<char>::allocator(&v11);
        std::string::string(&name, "input_texture", &v11);
        this->data->gausV->setInput(&name, frame);
        std::string::~string(&name);
        std::allocator<char>::~allocator(&v11);
        subFrame = this->subFrame;
        std::allocator<char>::allocator(&v13);
        std::string::string(&name_, "input_texture", &v13);
        this->data->gausH->setInput(&name_, subFrame);
        std::string::~string(&name_);
        std::allocator<char>::~allocator(&v13);
        if (this->data->grab->shader()) {
            data = this->data;
            v8 = Filter::shader(&data->grab);
            data->textureIn = v8->uniformSampler("mainPass");
        } else {
            this->data->textureIn = 0LL;
            std::allocator<char>::allocator(&v15);
            std::string::string(&msg, "[BloomPass::initShaders]null shader", &v15);
            this->incompleteEvent(&msg);
            std::string::~string(&msg);
            std::allocator<char>::~allocator(&v15);
        }
        if (this->data->textureIn) {
            this->data->textureIn->set(0LL);
        } else {
            std::allocator<char>::allocator(v17);
            std::string::string(&msg_, "[BloomPass::initShaders]no texture sampler in shader", v17);
            this->incompleteEvent(&msg_);
            std::string::~string(&msg_);
            std::allocator<char>::~allocator(v17);
        }
    }

    void MyGL::BloomPass::exec() {
        IScene *v1;
        __int64 v2;
        IScene *v3;
        __int64 v4;
        int v5;
        IScene *v6;
        __int64 v7;
        IScene *v8;
        __int64 v9;
        double cl_0;
        unsigned int v[8];

        v1 = this->scene();
        v2 = v1->render();
        (*(void (__fastcall **)(__int64, unsigned int *, unsigned int *, unsigned int *, unsigned int *)) (
                *(_QWORD *) v2 + 96LL))(
                v2,
                v,
                &v[1],
                &v[2],
                &v[3]);
        v3 = this->scene();
        v4 = v3->render();
        cl_0 = (*(double (__fastcall **)(__int64)) (*(_QWORD *) v4 + 24LL))(v4);
        if (v[2] != this->data->w || v[3] != this->data->h)
            BloomPass::resizeFrame(this);
        if (BloomPass::downSamplesCount(this) > 1)
            BloomPass::downSample(this, this->frameBuffer[0], this->input, this->scale[0], this->quad[0]);
        if (BloomPass::downSamplesCount(this) > 2)
            BloomPass::downSample(this, this->frameBuffer[1], this->scale[0], this->scale[1], this->quad[1]);
        if (BloomPass::downSamplesCount(this) == 3)
            BloomPass::downSample(this, this->frameBuffer[2], this->scale[1], this->frame, this->quad[2]);
        if (BloomPass::downSamplesCount(this) == 2)
            BloomPass::downSample(this, this->frameBuffer[1], this->scale[0], this->frame, this->quad[1]);
        v5 = BloomPass::downSamplesCount(this);
        BloomPass::postProcess(this, (FBO *) (&this->subFrame)[v5]);
        v6 = this->scene();
        v7 = v6->render();
        (*(void (__fastcall **)(__int64, _QWORD, _QWORD, _QWORD, _QWORD)) (*(_QWORD *) v7 + 88LL))(v7, v[0], v[1], v[2],
                                                                                                   v[3]);
        v8 = this->scene();
        v9 = v8->render();
        (*(void (__fastcall **)(__int64, double)) (*(_QWORD *) v9 + 16LL))(v9, cl_0);
    }

    void MyGL::BloomPass::downSample(FBO *frameBuffer, ITexture *input, ITextureRectangle *output, IModel *quad) {
        IScene *v5;
        __int64 v6;
        void (__fastcall *v7)(__int64, _QWORD, _QWORD, _QWORD, _QWORD);
        unsigned int v8;
        unsigned int v9;
        IScene *v10;
        __int64 v11;

        (*((void (__fastcall **)(FBO *)) frameBuffer->_vptr_IFBO + 8))(frameBuffer);
        v5 = this->scene();
        v6 = v5->render();
        v7 = *(void (__fastcall **)(__int64, _QWORD, _QWORD, _QWORD, _QWORD)) (*(_QWORD *) v6 + 88LL);
        v8 = output->height();
        v9 = output->width();
        v7(v6, 0LL, 0LL, v9, v8);
        (*((void (__fastcall **)(FBO *, ITextureRectangle *, _QWORD)) frameBuffer->_vptr_IFBO + 12))(
                frameBuffer,
                output,
                0LL);
        v10 = this->scene();
        v11 = v10->render();
        (*(void (__fastcall **)(__int64, IUniformSampler *, ITexture *)) (*(_QWORD *) v11 + 128LL))(
                v11,
                this->data->textureIn,
                input);
        this->data->grab->setQuadModel(quad);
        this->data->grab->exec();
        (*((void (__fastcall **)(FBO *)) frameBuffer->_vptr_IFBO + 9))(frameBuffer);
    }

    void MyGL::BloomPass::postProcess(FBO *frameBuffer) {
        (*((void (__fastcall **)(FBO *)) frameBuffer->_vptr_IFBO + 8))(frameBuffer);
        (*((void (__fastcall **)(FBO *, ITextureRectangle *, _QWORD)) frameBuffer->_vptr_IFBO + 12))(
                frameBuffer,
                this->subFrame,
                0LL);
        this->data->gausV->exec();
        (*((void (__fastcall **)(FBO *, ITextureRectangle *, _QWORD)) frameBuffer->_vptr_IFBO + 12))(
                frameBuffer,
                this->frame,
                0LL);
        this->data->gausH->exec();
        (*((void (__fastcall **)(FBO *)) frameBuffer->_vptr_IFBO + 9))(frameBuffer);
    }

    ITextureRectangle *MyGL::BloomPass::output() {
        return this->frame;
    }

    IRenderPass::Pass::Type MyGL::BloomPass::type() {
        return 2;
    }
}