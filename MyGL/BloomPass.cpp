#include "BloomPass.h"
#include "Model.h"
#include "IShader.h"
#include "IErrorControl.h"
#include "ITextureRectangle.h"

namespace MyGL {
    BloomPass::Data::Data(IScene &s, IModel *quad) : gausV(s), gausH(s), grab(s) {
        this->gausV.setQuadModel(quad);
        this->gausH.setQuadModel(quad);
        this->grab.setQuadModel(quad);
    }

    BloomPass::BloomPass(IScene &s, const Adapter &adapter, ITextureRectangle *in) : AbstractPass(s) {
        this->m_isValid = 1;
        this->input = in;
        this->m_downSamplesCount = -1;
        this->frame = new TextureRectangle(this->scene().render());
        this->subFrame = new TextureRectangle(this->scene().render());
        this->frame->setFiltration(1LL, 1LL);
        this->subFrame->setFiltration(1LL, 1LL);
        for (int i_0 = 0; i_0 <= 1; ++i_0) {
            (&this->input)[i_0 + 1] = new TextureRectangle(this->scene().render());
        }
        this->frameBuffer[0] = 0LL;
        this->frameBuffer[1] = 0LL;
        this->frameBuffer[2] = 0LL;
        for (int i = 0; i <= 2; ++i) {
            this->quad[i] = new Model(this->scene().render());
        }
        this->data = new Data(this->scene(), this->quad[2]);
        this->data->w = -1;
        this->data->h = -1;
        this->data->gausH.renderState().setBlend(1LL);
        this->data->gausH.renderState().setBlendMode(1LL, 1LL);
        this->data->gausH.renderState().setAlphaTestMode(1LL);
        this->data->gausH.renderState().setAlphaTestRef(0.0);
        this->setDownSamplesCount(3);
        this->initShaders(adapter);
    }

    BloomPass::~BloomPass() {
        if (this->data) {

            delete this->data;
        }
        if (this->frame)
            delete this->frame;
        for (int i = 0; i <= 1; ++i) {
            if ((&this->input)[i + 1])
                delete (&this->input)[i + 1];
        }
        if (this->subFrame)
            delete this->subFrame;
        for (int i_0 = 0; i_0 <= 2; ++i_0) {
            if (this->quad[i_0])
                delete this->quad[i_0];
            if ((&this->subFrame)[i_0 + 1])
                delete (&this->subFrame)[i_0 + 1];
        }
    }

    bool BloomPass::validate() {
        return this->m_isValid;
    }

    int BloomPass::downSamplesCount() {
        return this->m_downSamplesCount;
    }

    void BloomPass::setDownSamplesCount(int c) {
        c = std::max<int>(std::min<int>(c, 3), 1);
        if (this->m_downSamplesCount != c) {
            this->m_downSamplesCount = c;
            this->data->gausV.setQuadModel((IModel *) this->frameBuffer[c + 2]);
            this->data->gausH.setQuadModel((IModel *) this->frameBuffer[c + 2]);
            this->data->grab.setQuadModel((IModel *) this->frameBuffer[c + 2]);
            this->resizeFrame();
        }
    }

    void BloomPass::setShader(IShader *s) {
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

    void BloomPass::buildQuad(int w, int h) {
        IOModel m;
        m.allock(4uLL);
        IOModel::point(&retstr_, &m, 0);
        p = IIOModel::Point::data(&retstr_);
        p->setPoint(-1.0, -1.0);
        IOModel::point(&retstr__1, &m, 1);
        p_1 = IIOModel::Point::data(&retstr__1);
        p_1->setPoint(1.0, -1.0);
        IOModel::point(&retstr__2, &m, 2);
        p_2 = IIOModel::Point::data(&retstr__2);
        p_2->setPoint(1.0, 1.0);
        IOModel::point(&retstr__3, &m, 3);
        p_3 = IIOModel::Point::data(&retstr__3);
        p_3->setPoint(-1.0, 1.0);
        IOModel::normal(&retstr__4, &m, 0);
        p_4 = IIOModel::Point::data(&retstr__4);
        p_4->setPoint(1.0, 0.0);
        IOModel::normal(&retstr__5, &m, 1);
        p_5 = IIOModel::Point::data(&retstr__5);
        p_5->setPoint(1.0, 0.0);
        IOModel::normal(&retstr__6, &m, 2);
        p_6 = IIOModel::Point::data(&retstr__6);
        p_6->setPoint(1.0, 0.0);
        IOModel::normal(&retstr__7, &m, 3);
        p_7 = IIOModel::Point::data(&retstr__7);
        p_7->setPoint(1.0, 0.0);
        for (int i = 0; i <= 2; ++i) {
            IOModel::texCoord(&retstr__8, &m, 0);
            p_8 = IIOModel::TexCoord::data(&retstr__8);
            p_8->setPoint(0.0, 0.0);
            IOModel::texCoord(&retstr__9, &m, 1);
            p_9 = IIOModel::TexCoord::data(&retstr__9);
            p_9->setPoint((float) w, 0.0);
            IOModel::texCoord(&retstr__10, &m, 2);
            p_10 = IIOModel::TexCoord::data(&retstr__10);
            p_10->setPoint((float) w, (float) h);
            IOModel::texCoord(&retstr__11, &m, 3);
            p_11 = IIOModel::TexCoord::data(&retstr__11);
            p_11->setPoint(0.0, (float) h);
            w /= 2;
            h /= 2;
            this->quad[i]->load(&m);
            this->quad[i]->setPrimitivesType(2LL);
        }
    }

    void BloomPass::setPoint(float *p, float x, float y) {
        p[0] = x;
        p[1] = y;
    }

    void BloomPass::resizeFrame() {
        int v[6];
        this->scene().render().getViewport(v[0], v[1], v[2], v[3]);
        this->data->w = v[2];
        this->data->h = v[3];
        this->scale[0]->setFiltration(0LL, 1LL, (unsigned int) (v[2] / 2), (unsigned int) (v[3] / 2), 4LL);
        this->scale[1]->setFiltration(0LL, 1LL, (unsigned int) (v[2] / 4), (unsigned int) (v[3] / 4), 4LL);
        int dw = 1 << this->downSamplesCount();
        this->frame->setFiltration(0LL, 1LL, (unsigned int) (v[2] / dw), (unsigned int) (v[3] / dw), 4LL);
        this->subFrame->setFiltration(0LL, 1LL, (unsigned int) (v[2] / dw), (unsigned int) (v[3] / dw), 4LL);
        this->buildQuad(v[2] / 2, v[3] / 2);
        for (int i = 0; i <= 2; ++i) {
            if ((&this->subFrame)[i + 1])
                delete (&this->subFrame)[i + 1];
            (&this->subFrame)[i + 1] = (ITextureRectangle *) new FBO(this->scene().render(), v[2] / 2, v[3] / 2, 8);
            v[2] /= 2;
            v[3] /= 2;
        }
    }

    void BloomPass::incompleteEvent(const std::string &msg) {
        this->scene().render().gl()->errorCtrl()->warning(0LL, msg.c_str());
        this->m_isValid = 0;
    }

    void BloomPass::initShaders(Adapter &adapter) {
        this->data->gausV.setShader(adapter.getGausVerticalShader());
        this->data->gausH.setShader(adapter.getGausHorizontalShader());
        this->data->grab.setShader(adapter.getBloomDownSampleShader());
        this->data->gausV.setInput("input_texture", this->frame);
        this->data->gausH.setInput("input_texture", this->subFrame);
        if (this->data->grab.shader()) {
            this->data->textureIn = this->data->grab.shader()->uniformSampler("mainPass");
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

    void BloomPass::exec() {
        int v[8];
        this->scene().render().getViewport(v[0], v[1], v[2], v[3]);
        Color cl_0 = this->scene().render().clearColor();
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
        this->postProcess((FBO *) (&this->subFrame)[this->downSamplesCount()]);
        this->scene().render().setViewport(v[0], v[1], v[2], v[3]);
        this->scene().render().clearColor(cl_0);
    }

    void BloomPass::downSample(FBO *frameBuffer, ITexture *input, ITextureRectangle *output, IModel *quad) {
        frameBuffer->bind();
        this->scene().render().setViewport(0LL, 0LL, output->width(), output->height());
        frameBuffer->attachColorTexture(output, 0LL);
        this->scene().render().bindTexture(this->data->textureIn, input);
        this->data->grab.setQuadModel(quad);
        this->data->grab.exec();
        frameBuffer->unbind();
    }

    void BloomPass::postProcess(FBO *frameBuffer) {
        frameBuffer->bind();
        frameBuffer->attachColorTexture(this->subFrame, 0LL);
        this->data->gausV.exec();
        frameBuffer->attachColorTexture(this->frame, 0LL);
        this->data->gausH.exec();
        frameBuffer->unbind();
    }

    ITextureRectangle *BloomPass::output() {
        return this->frame;
    }

    IRenderPass::Pass::Type BloomPass::type() {
        return IRenderPass::Pass::Bloom;
    }
}