#include "MainPass.h"
#include "FBO.h"
#include "TextureRectangle.h"
#include "SSAOpass.h"
#include "DepthPass.h"
#include "ColorPass.h"
#include "AddBlendPass.h"
#include "SSAOpass.h"
#include "TransparentPass.h"
#include "IIOModel.h"


namespace MyGL {
    MainPass::MainPass(IScene &s, const Adapter &adapter, IModel *q, bool autoMake) : AbstractPass(s) {
        this->frame = new TextureRectangle(this->scene().render());
        this->depth = new TextureRectangle(this->scene().render());
        this->m_frameBuffer = 0LL;
        this->quad = q;
        this->resizeFrame();
        if (autoMake)
            this->makeAlgo(adapter);
    }

    MainPass::~MainPass() {
        if (this->frame)
            delete this->frame;
        if (this->depth)
            delete this->depth;
        if (this->m_frameBuffer)
            delete this->m_frameBuffer;
        for (int i = 0; i < this->passes.size(); ++i) {
            auto &v1 = this->passes[i];
            if (v1)
                delete v1;
        }
    }

    void MainPass::buildQuad(int w, int h) {
        IOModel m;
        m.allock(4uLL);
        m.point(0)->data()->setPoint(-1.0, -1.0);
        IOModel::point(&retstr__1, &m, 1);
        p_1 = IIOModel::Point::data(&retstr__1);
        p_1.setPoint(1.0, -1.0);
        IOModel::point(&retstr__2, &m, 2);
        p_2 = IIOModel::Point::data(&retstr__2);
        p_2.setPoint(1.0, 1.0);
        IOModel::point(&retstr__3, &m, 3);
        p_3 = IIOModel::Point::data(&retstr__3);
        p_3.setPoint(-1.0, 1.0);
        IOModel::texCoord(&retstr__4, &m, 0);
        p_4 = IIOModel::TexCoord::data(&retstr__4);
        p_4.setPoint(0.0, 0.0);
        IOModel::texCoord(&retstr__5, &m, 1);
        p_5 = IIOModel::TexCoord::data(&retstr__5);
        p_5.setPoint((float) w, 0.0);
        IOModel::texCoord(&retstr__6, &m, 2);
        p_6 = IIOModel::TexCoord::data(&retstr__6);
        p_6.setPoint((float) w, (float) h);
        IOModel::texCoord(&retstr__7, &m, 3);
        p_7 = IIOModel::TexCoord::data(&retstr__7);
        p_7.setPoint(0.0, (float) h);
        this->quad->load(&m);
        this->quad->setPrimitivesType(2LL);
    }

    ITextureRectangle *MainPass::depthBuffer() {
        return this->depth;
    }

    void MainPass::draw() {
        v2 = this->scene().render();
        (*(void (__fastcall **)(__int64)) (*(_QWORD *) v2 + 248LL))(v2);
        v4 = this->scene().graph();
        (*(void (__fastcall **)(__int64, MainPass *const)) (*(_QWORD *) v4 + 40LL))(v4, this);
        for (int i = 0; i < this->passes.size(); ++i) {
            this->passes[i]->exec();
        }
        v7 = this->scene().graph();
        (*(void (__fastcall **)(__int64)) (*(_QWORD *) v7 + 48LL))(v7);
    }

    void MainPass::exec() {
        v2 = this->scene().render();
        (*(void (__fastcall **)(__int64, int *, int *, int *, int *)) (*(_QWORD *) v2 + 96LL))(v2, v, &v[1], &v[2],
                                                                                               &v[3]);
        v3 = v[2];
        if (v3 != this->frame->width()
            || (v4 = v[3],
                v4 != this->frame->height())) {
            this->resizeFrame();
        }
        this->frameBuffer()->bind();
        v7 = this->frameBuffer();this->frame, 0LL);
        this->frameBuffer()->attachDepthTexture(this->depth);
        v10 = this->scene().render();
        (*(void (__fastcall **)(__int64, __int64)) (*(_QWORD *) v10 + 32LL))(v10, 3LL);
        this->draw();
        this->frameBuffer()->unbind();
    }

    FBO *MainPass::frameBuffer() {
        return this->m_frameBuffer;
    }

    void MainPass::makeAlgo(const Adapter &adapter) {
        this->makeAlgo(this->passes, adapter);
    }

    void MainPass::makeAlgo(std::vector<IRenderPass *> &passes, const Adapter &adapter) {
        passes.push_back(new DepthPass(this->scene()));
        passes.push_back(new ColorPass(this->scene()));
        passes.push_back(new AddBlendPass(this->scene()));
        passes.push_back(new TransparentPass(this->scene()));
        passes.push_back(new SSAOpass(this->scene(), adapter, this));
    }

    ITextureRectangle *MainPass::output() {
        return this->frame;
    }

    IModel *MainPass::quadModel() {
        return this->quad;
    }

    void MainPass::resizeFrame() {
        int v[12];
        this->scene().render().getViewport(v[0], v[1], v[2], v[3]);
        this->frame->load(0LL, ITexture::InputFormat::RGB8, v[2], v[3], ITexture::Format::RGB);//1LL 4LL
        this->depth->load(0LL, ITexture::InputFormat::Depth, v[2], v[3], ITexture::Format::Depth32);//3LL 21LL
        if (this->m_frameBuffer)
            delete this->m_frameBuffer;
        this->m_frameBuffer = new FBO(this->scene().render(), this->frame->width(), this->frame->height(), 4);
        this->buildQuad(v[2], v[3]);
    }

    void MainPass::setPoint(float *p, float x, float y) {
        p[0] = x;
        p[1] = y;
    }

    IRenderPass::Pass::Type MainPass::type() {
        return IRenderPass::Pass::None;
    }
}