#include "BloomPass.h"

namespace MyGL {
    MyGL::BloomPass::Data::Data(IScene &s, IModel *quad) : gausV(s), gausH(s), grab(s) {
        this->gausV.setQuadModel(quad);
        this->gausH.setQuadModel(quad);
        this->grab.setQuadModel(quad);
    }

    MyGL::BloomPass::BloomPass(IScene &s, const Adapter &adapter, ITextureRectangle *in) : AbstractPass(s) {
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
        this->frame = new TextureRectangle(this->scene()->render());
        this->subFrame = new TextureRectangle(this->scene()->render());
        this->frame->setFiltration(1LL, 1LL);
        this->subFrame->setFiltration(1LL, 1LL);
        for (i_0 = 0; i_0 <= 1; ++i_0) {
            (&this->input)[i_0 + 1] = new TextureRectangle(this->scene()->render());
        }
        this->frameBuffer[0] = 0LL;
        this->frameBuffer[1] = 0LL;
        this->frameBuffer[2] = 0LL;
        for (i = 0; i <= 2; ++i) {
            this->quad[i] = new Model(this->scene()->render());
        }
        this->data = new Data(this->scene(), this->quad[2]);
        this->data->w = -1;
        this->data->h = -1;
        this->data->gausH->renderState()->setBlend(1LL);
        this->data->gausH->renderState()->setBlendMode(1LL, 1LL);
        this->data->gausH->renderState()->setAlphaTestMode(1LL);
        this->data->gausH->renderState()->setAlphaTestRef(0.0);
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
        this->m_isValid = 1;
        this->data->grab.setShader(s);
        if (s) {
            this->data->textureIn = this->data->grab.shader()->uniformSampler("mainPass");
        } else {
            this->data->textureIn = 0LL;
            this->incompleteEvent("[BloomPass::setShader]null shader");
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
        v2 = this->scene()->render();
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
        this->buildQuad(v[2] / 2, v[3] / 2);
        for (i = 0; i <= 2; ++i) {
            if ((&this->subFrame)[i + 1])
                delete (&this->subFrame)[i + 1];
            (&this->subFrame)[i + 1] = (ITextureRectangle *) new FBO(this->scene()->render(), v[2] / 2, v[3] / 2, 8);
            v[2] /= 2;
            v[3] /= 2;
        }
    }

    void MyGL::BloomPass::incompleteEvent(const std::string &msg) {
        v3 = this->scene()->render();
        v4 = (CGL *) (*(__int64 (__fastcall **)(__int64)) (*(_QWORD *) v3 + 72LL))(v3);
        v4->errorCtrl()->warning(0LL, msg);
        this->m_isValid = 0;
    }

    void MyGL::BloomPass::initShaders(const Adapter &adapter) {
        this->data->gausV->setShader(adapter->getGausVerticalShader());
        this->data->gausH->setShader(adapter->getGausHorizontalShader());
        this->data->grab->setShader(adapter->getBloomDownSampleShader());
        this->data->gausV->setInput("input_texture", this->frame);
        this->data->gausH->setInput"input_texture", this->subFrame);
        if (this->data->grab->shader()) {
            this->data->textureIn = this->data->grab->shader()->uniformSampler("mainPass");
        } else {
            this->data->textureIn = 0LL;
            this->incompleteEvent("[BloomPass::initShaders]null shader");
        }
        if (this->data->textureIn) {
            this->data->textureIn->set(0LL);
        } else {
            this->incompleteEvent("[BloomPass::initShaders]no texture sampler in shader");
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


        v2 = this->scene()->render();
        (*(void (__fastcall **)(__int64, unsigned int *, unsigned int *, unsigned int *, unsigned int *)) (
                *(_QWORD *) v2 + 96LL))(
                v2,
                v,
                &v[1],
                &v[2],
                &v[3]);
        v4 = this->scene()->render();
        cl_0 = (*(double (__fastcall **)(__int64)) (*(_QWORD *) v4 + 24LL))(v4);
        if (v[2] != this->data->w || v[3] != this->data->h)
            this->resizeFrame();
        if (this->downSamplesCount() > 1)
            this->downSample(this->frameBuffer[0], this->input, this->scale[0], this->quad[0]);
        if (this->downSamplesCount() > 2)
            this->downSample(this->frameBuffer[1], this->scale[0], this->scale[1], this->quad[1]);
        if (this->downSamplesCount() == 3)
            this->downSample(this->frameBuffer[2], this->scale[1], this->frame, this->quad[2]);
        if (this->downSamplesCount() == 2)
            this->downSample(this->frameBuffer[1], this->scale[0], this->frame, this->quad[1]);
        v5 = this->downSamplesCount();
        this->postProcess((FBO *) (&this->subFrame)[v5]);
        v7 = this->scene()->render();
        (*(void (__fastcall **)(__int64, _QWORD, _QWORD, _QWORD, _QWORD)) (*(_QWORD *) v7 + 88LL))(v7, v[0], v[1], v[2],
                                                                                                   v[3]);
        v9 = this->scene()->render();
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

        frameBuffer->bind();
        v6 = this->scene()->render();
        v7 = *(void (__fastcall **)(__int64, _QWORD, _QWORD, _QWORD, _QWORD)) (*(_QWORD *) v6 + 88LL);
        v7(v6, 0LL, 0LL, output->width(), output->height());
        frameBuffer->attachColorTexture(output,0LL);
        v11 = this->scene()->render();
        (*(void (__fastcall **)(__int64, IUniformSampler *, ITexture *)) (*(_QWORD *) v11 + 128LL))(
                v11,
                this->data->textureIn,
                input);
        this->data->grab->setQuadModel(quad);
        this->data->grab->exec();
        frameBuffer->unbind();
    }

    void MyGL::BloomPass::postProcess(FBO *frameBuffer) {
        frameBuffer->bind();
        frameBuffer->attachColorTexture(this->subFrame,0LL);
        this->data->gausV->exec();
        frameBuffer->attachColorTexture(this->frame,0LL);
        this->data->gausH->exec();
        frameBuffer->unbind();
    }

    ITextureRectangle *MyGL::BloomPass::output() {
        return this->frame;
    }

    IRenderPass::Pass::Type MyGL::BloomPass::type() {
        return 2;
    }
}