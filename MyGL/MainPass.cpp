#include "MainPass.h"
namespace MyGL {
	MainPass::MainPass(IScene& s, const Adapter& adapter, IModel* q, bool autoMake) : AbstractPass(
		s) {
		IScene* v5;
		IRender* r;
		TextureRectangle* frame;
		IScene* v8;
		IRender* r_1;
		TextureRectangle* depth;
		v5 = AbstractPass::scene(this);
		r = v5->render();
		frame = (TextureRectangle*) operator new(0x28uLL);
		TextureRectangle::TextureRectangle(frame, r);
		this->frame = frame;
		v8 = AbstractPass::scene(this);
		r_1 = v8->render();
		depth = (TextureRectangle*) operator new(0x28uLL);
		TextureRectangle::TextureRectangle(depth, r_1);
		this->depth = depth;
		this->m_frameBuffer = 0LL;
		this->quad = q;
		this->resizeFrame();
		if (autoMake)
			this->makeAlgo(adapter);
	}

	MainPass::~MainPass() {
		IRenderPass* v1;
		unsigned int i;
		if (this->frame)
            delete this->frame;
		if (this->depth)
            delete this->depth;
		if (this->m_frameBuffer)
			(*((void(__fastcall**)(FBO*)) this->m_frameBuffer->_vptr_IFBO + 1))(this->m_frameBuffer);
		for (i = 0; i < std::vector<IRenderPass*>::size(&this->passes); ++i) {
			v1 = *std::vector<IRenderPass*>::operator[](&this->passes, i);
			if (v1)
				delete v1;
		}
	}

	void MainPass::buildQuad(int w, int h) {
		float* p;
		float* p_1;
		float* p_2;
		float* p_3;
		float* p_4;
		float* p_5;
		float* p_6;
		float* p_7;
		IOModel m;
		IIOModel::Point retstr_;
		IIOModel::Point retstr__1;
		IIOModel::Point retstr__2;
		IIOModel::Point retstr__3;
		IIOModel::TexCoord retstr__4;
		IIOModel::TexCoord retstr__5;
		IIOModel::TexCoord retstr__6;
		IIOModel::TexCoord retstr__7;

		IOModel::IOModel(&m);
		IOModel::allock(&m, 4uLL);
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
		(*((void(__fastcall**)(IModel*, IOModel*)) this->quad->_vptr_IModel + 8))(this->quad, &m);
		(*((void(__fastcall**)(IModel*, __int64)) this->quad->_vptr_IModel + 4))(this->quad, 2LL);
		IOModel::~IOModel(&m);
	}

	ITextureRectangle* MainPass::depthBuffer() {
		return this->depth;
	}

	void MainPass::draw() {
		IScene* v1;
		__int64 v2;
		IScene* v3;
		__int64 v4;
		std::vector<IRenderPass*>::reference v5;
		IScene* v6;
		__int64 v7;
		unsigned int i;

		v1 = AbstractPass::scene(this);
		v2 = v1->render();
		(*(void(__fastcall**)(__int64)) (*(_QWORD*)v2 + 248LL))(v2);
		v3 = AbstractPass::scene(this);
		v4 = v3->graph();
		(*(void(__fastcall**)(__int64, MainPass* const)) (*(_QWORD*)v4 + 40LL))(v4, this);
		for (i = 0; i < std::vector<IRenderPass*>::size(&this->passes); ++i) {
			v5 = std::vector<IRenderPass*>::operator[](&this->passes, i);
			v5->exec();
		}
		v6 = AbstractPass::scene(this);
		v7 = v6->graph();
		(*(void(__fastcall**)(__int64)) (*(_QWORD*)v7 + 48LL))(v7);
	}

	void MainPass::exec() {
		IScene* v1;
		__int64 v2;
		int v3;
		int v4;
		FBO* v6;
		FBO* v7;
		FBO* v8;
		IScene* v9;
		__int64 v10;
		FBO* v11;
		int v[8];

		v1 = this->scene();
		v2 = v1->render();
		(*(void(__fastcall**)(__int64, int*, int*, int*, int*)) (*(_QWORD*)v2 + 96LL))(v2, v, &v[1], &v[2],
			&v[3]);
		v3 = v[2];
		if (v3 != this->frame->width()
			|| (v4 = v[3],
				v4 != this->frame->height())) {
            this-》resizeFrame();
		}
		v6 = this->frameBuffer();
		(*((void(__fastcall**)(FBO*)) v6->_vptr_IFBO + 8))(v6);
		v7 = this->frameBuffer();
		(*((void(__fastcall**)(FBO*, ITextureRectangle*, _QWORD)) v7->_vptr_IFBO + 12))(v7,
			this->frame,
			0LL);
		v8 = this->rameBuffer();
		(*((void(__fastcall**)(FBO*, ITextureRectangle*)) v8->_vptr_IFBO + 13))(v8, this->depth);
		v9 = AbstractPass::scene(this);
		v10 = v9->render();
		(*(void(__fastcall**)(__int64, __int64)) (*(_QWORD*)v10 + 32LL))(v10, 3LL);
		MainPass::draw(this);
		v11 = this->frameBuffer();
		(*((void(__fastcall**)(FBO*)) v11->_vptr_IFBO + 9))(v11);
	}

	FBO* MainPass::frameBuffer() {
		return this->m_frameBuffer;
	}

	void MainPass::makeAlgo(const Adapter& adapter) {
		this->makeAlgo(
				&this->passes,
				adapter);
	}

	void MainPass::makeAlgo(MainPass& mp, std::vector<IRenderPass*>& passes,
		const Adapter& adapter) {
		IScene* s;
		DepthPass* __x_1;
		IScene* s_1;
		ColorPass* __x__4;
		IScene* s_2;
		AddBlendPass* __x__5;
		IScene* s_3;
		TransparentPass* __x__6;
		IScene* s_4;
		SSAOpass* __x__7;
		std::vector<IRenderPass*>::value_type __x;
		std::vector<IRenderPass*>::value_type __x_;
		std::vector<IRenderPass*>::value_type __x__1;
		std::vector<IRenderPass*>::value_type __x__2;
		std::vector<IRenderPass*>::value_type __x__3;

		s = AbstractPass::scene(mp);
		__x_1 = (DepthPass*) operator new(0x10uLL);
		DepthPass::DepthPass(__x_1, s);
		__x = __x_1;
		std::vector<IRenderPass*>::push_back(passes, &__x);
		s_1 = AbstractPass::scene(mp);
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
		IScene* v1;
		__int64 v2;
		IScene* v3;
		IRender* r;
		unsigned int theWidth;
		unsigned int theHeight;
		FBO* m_frameBuffer;
		int v[12];

		v1 = this->scene();
		v2 = v1->render();
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
			(*((void(__fastcall**)(FBO*)) this->m_frameBuffer->_vptr_IFBO + 1))(this->m_frameBuffer);
		v3 = AbstractPass::scene(this);
		r = v3->render();
		theWidth = this->frame->setClamping();
		theHeight = this->frame->setClamping();
		m_frameBuffer = (FBO*) operator new(0x28uLL);
		FBO::FBO(m_frameBuffer, r, theWidth, theHeight, 4);
		this->m_frameBuffer = m_frameBuffer;
		MainPass::buildQuad(this, v[2], v[3]);
	}

	void MainPass::setPoint(float* p, float x, float y) {
		p[0] = x;
		p[1] = y;
	}

	IRenderPass::Pass::Type MainPass::type() {
		return 0;
	}
}