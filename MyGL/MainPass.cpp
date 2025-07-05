#include "MainPass.h"
namespace MyGL {
	MainPass::MainPass(IScene& s, const Adapter& adapter, IModel* q, bool autoMake) : AbstractPass(s) {
		this->frame = new TextureRectangle(this->scene().render());
		this->depth =  new TextureRectangle(this->scene().render());
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
			auto& v1 = this->passes[i];
			if (v1)
				delete v1;
		}
	}

	void MainPass::buildQuad(int w, int h) {
		IOModel m;
        m.allock(4uLL);
		IOModel::point(&retstr_, &m, 0);
		p = IIOModel::Point::data(&retstr_);
		MainPass::setPoint(p, -1.0, -1.0);
		IOModel::point(&retstr__1, &m, 1);
		p_1 = IIOModel::Point::data(&retstr__1);
		MainPass::setPoint(p_1, 1.0, -1.0);
		IOModel::point(&retstr__2, &m, 2);
		p_2 = IIOModel::Point::data(&retstr__2);
		MainPass::setPoint(p_2, 1.0, 1.0);
		IOModel::point(&retstr__3, &m, 3);
		p_3 = IIOModel::Point::data(&retstr__3);
		MainPass::setPoint(p_3, -1.0, 1.0);
		IOModel::texCoord(&retstr__4, &m, 0);
		p_4 = IIOModel::TexCoord::data(&retstr__4);
		MainPass::setPoint(p_4, 0.0, 0.0);
		IOModel::texCoord(&retstr__5, &m, 1);
		p_5 = IIOModel::TexCoord::data(&retstr__5);
		MainPass::setPoint(p_5, (float)w, 0.0);
		IOModel::texCoord(&retstr__6, &m, 2);
		p_6 = IIOModel::TexCoord::data(&retstr__6);
		MainPass::setPoint(p_6, (float)w, (float)h);
		IOModel::texCoord(&retstr__7, &m, 3);
		p_7 = IIOModel::TexCoord::data(&retstr__7);
		MainPass::setPoint(p_7, 0.0, (float)h);
		this->quad->load(&m);
		this->quad->setPrimitivesType(2LL);
		IOModel::~IOModel(&m);
	}

	ITextureRectangle* MainPass::depthBuffer() {
		return this->depth;
	}

	void MainPass::draw() {
		v2 = this->scene().render();
		(*(void(__fastcall**)(__int64)) (*(_QWORD*)v2 + 248LL))(v2);
		v4 = this->scene().graph();
		(*(void(__fastcall**)(__int64, MainPass* const)) (*(_QWORD*)v4 + 40LL))(v4, this);
		for (i = 0; i < std::vector<IRenderPass*>::size(&this->passes); ++i) {
			v5 = std::vector<IRenderPass*>::operator[](&this->passes, i);
			v5->exec();
		}
		v7 = this->scene().graph();
		(*(void(__fastcall**)(__int64)) (*(_QWORD*)v7 + 48LL))(v7);
	}

	void MainPass::exec() {
		v2 = this->scene().render();
		(*(void(__fastcall**)(__int64, int*, int*, int*, int*)) (*(_QWORD*)v2 + 96LL))(v2, v, &v[1], &v[2],
			&v[3]);
		v3 = v[2];
		if (v3 != this->frame->width()
			|| (v4 = v[3],
				v4 != this->frame->height())) {
            this->resizeFrame();
		}
		v6 = this->frameBuffer();
		v6->bind();
		v7 = this->frameBuffer();
		v7->attachColorTexture(
			this->frame,
			0LL);
		v8 = this->frameBuffer();
		v8->attachDepthTexture( this->depth);
		v10 = this->scene().render();
		(*(void(__fastcall**)(__int64, __int64)) (*(_QWORD*)v10 + 32LL))(v10, 3LL);
        this->draw();
		v11 = this->frameBuffer();
		v11->unbind();
	}

	FBO* MainPass::frameBuffer() {
		return this->m_frameBuffer;
	}

	void MainPass::makeAlgo(const Adapter& adapter) {
		this->makeAlgo(&this->passes,adapter);
	}

	void MainPass::makeAlgo(MainPass& mp, std::vector<IRenderPass*>& passes, const Adapter& adapter) {
		__x = new DepthPass(mp.scene());
		std::vector<IRenderPass*>::push_back(passes, &__x);
		s_1 = Amp.scene();
		__x__4 = (ColorPass*) operator new(0x10uLL);
		ColorPass::ColorPass(__x__4, s_1);
		__x_ = __x__4;
		std::vector<IRenderPass*>::push_back(passes, &__x_);
		s_2 = AbstractPass::scene(mp);
		__x__5 = (AddBlendPass*) operator new(0x10uLL);
		AddBlendPass::AddBlendPass(__x__5, s_2);
		__x__1 = __x__5;
		std::vector<IRenderPass*>::push_back(passes, &__x__1);
		s_3 = AbstractPass::scene(mp);
		__x__6 = (TransparentPass*) operator new(0x18uLL);
		TransparentPass::TransparentPass(__x__6, s_3);
		__x__2 = __x__6;
		std::vector<IRenderPass*>::push_back(passes, &__x__2);
		s_4 = AbstractPass::scene(mp);
		__x__7 = (SSAOpass*) operator new(0x50uLL);
		SSAOpass::SSAOpass(__x__7, s_4, adapter, mp);
		__x__3 = __x__7;
		std::vector<IRenderPass*>::push_back(passes, &__x__3);
	}

	ITextureRectangle* MainPass::output() {
		return this->frame;
	}

	IModel* MainPass::quadModel() {
		return this->quad;
	}

	void MainPass::resizeFrame() {
		int v[12];
		v2 = this->scene().render();
		(*(void(__fastcall**)(__int64, int*, int*, int*, int*)) (*(_QWORD*)v2 + 96LL))(v2, v, &v[1], &v[2],
			&v[3]);

		this->frame->setFiltration(
				0LL,
				1LL,
				(unsigned int)v[2],
				(unsigned int)v[3],
				4LL);
		this->depth->setFiltration(
				0LL,
				3LL,
				(unsigned int)v[2],
				(unsigned int)v[3],
				21LL);
		if (this->m_frameBuffer)
            delete this->m_frameBuffer;
		this->m_frameBuffer = new FBO(this->scene().render(), this->frame->width(), this->frame->height(), 4);;
        this->buildQuad(v[2], v[3]);
	}

	void MainPass::setPoint(float* p, float x, float y) {
		p[0] = x;
		p[1] = y;
	}

	IRenderPass::Pass::Type MainPass::type() {
		return IRenderPass::Pass::None;
	}
}