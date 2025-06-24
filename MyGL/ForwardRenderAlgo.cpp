#include "ForwardRenderAlgo.h"
#include "IRenderAlgoSettings.h"
#include "IModel.h"
#include "MainPass.h"
#include "GlowPass.h"
#include "BloomPass.h"
#include "LincPass.h"
#include "ShadowPass.h"
namespace MyGL {
	ForwardRenderAlgo::ForwardRenderAlgo(IScene& s, const Adapter& adapter, bool autoMake)
	{
		IScene* v4;
		IRender* r;
		Model* quad;
		RenderAlgoSettings<ForwardRenderAlgo>* m_settings;
		this->mscene = s;
		std::vector<IRenderPass*>::vector(&this->passes);
		v4 = ForwardRenderAlgo::scene(this);
		r = v4->render();
		quad = (Model*)operator new(0xC0uLL);
		Model::Model(quad, r);
		this->quad = quad;
		ForwardRenderAlgo::buildQuad(this, 0, 0);
		ForwardRenderAlgo::setBloom(this, 1);
		ForwardRenderAlgo::setShadowPass(this, 1);
		if (autoMake)
			ForwardRenderAlgo::makeAlgo(this, adapter);
		m_settings = (RenderAlgoSettings<ForwardRenderAlgo> *)operator new(0x10uLL);
		RenderAlgoSettings<ForwardRenderAlgo>::RenderAlgoSettings(m_settings, this);
		this->m_settings = m_settings;
	}

	ForwardRenderAlgo::~ForwardRenderAlgo()
	{
		this->freeAlgo();
		if (this->quad)
			(*((void(__fastcall**)(IModel*))this->quad->_vptr_IModel + 1))(this->quad);
		if (this->m_settings)
			(*((void(__fastcall**)(IRenderAlgoSettings*))this->m_settings->_vptr_IRenderAlgoSettings + 1))(this->m_settings);
	}

	MainPass* ForwardRenderAlgo::allockMainPass(const Adapter& adapter)
	{
		IScene* s;
		MainPass* v3;

		s = ForwardRenderAlgo::scene(this);
		v3 = (MainPass*)operator new(0x48uLL);
		MainPass::MainPass(v3, s, adapter, this->quad, 1);
		return v3;
	}

	void ForwardRenderAlgo::buildQuad(int w, int h)
	{
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
		ForwardRenderAlgo::setPoint(p, -1.0, -1.0);
		IOModel::point(&retstr__1, &m, 1);
		p_1 = IIOModel::Point::data(&retstr__1);
		ForwardRenderAlgo::setPoint(p_1, 1.0, -1.0);
		IOModel::point(&retstr__2, &m, 2);
		p_2 = IIOModel::Point::data(&retstr__2);
		ForwardRenderAlgo::setPoint(p_2, 1.0, 1.0);
		IOModel::point(&retstr__3, &m, 3);
		p_3 = IIOModel::Point::data(&retstr__3);
		ForwardRenderAlgo::setPoint(p_3, -1.0, 1.0);
		IOModel::texCoord(&retstr__4, &m, 0);
		p_4 = IIOModel::TexCoord::data(&retstr__4);
		ForwardRenderAlgo::setPoint(p_4, 0.0, 0.0);
		IOModel::texCoord(&retstr__5, &m, 1);
		p_5 = IIOModel::TexCoord::data(&retstr__5);
		ForwardRenderAlgo::setPoint(p_5, (float)w, 0.0);
		IOModel::texCoord(&retstr__6, &m, 2);
		p_6 = IIOModel::TexCoord::data(&retstr__6);
		ForwardRenderAlgo::setPoint(p_6, (float)w, (float)h);
		IOModel::texCoord(&retstr__7, &m, 3);
		p_7 = IIOModel::TexCoord::data(&retstr__7);
		ForwardRenderAlgo::setPoint(p_7, 0.0, (float)h);
		(*((void(__fastcall**)(IModel*, IOModel*))this->quad->_vptr_IModel + 8))(this->quad, &m);
		(*((void(__fastcall**)(IModel*, __int64))this->quad->_vptr_IModel + 4))(this->quad, 2LL);
		IOModel::~IOModel(&m);
	}

	void ForwardRenderAlgo::exec()
	{
		if (this->isShadowPass())
			this->shadowPass->exec();
		if (LincPass::validate(this->lincPass))
			this->mainPass->exec();
		if (this->vlsPass)
			this->vlsPass->exec();
		if (BloomPass::validate(this->bloomPass) && ForwardRenderAlgo::isBloom(this))
			this->bloomPass->exec();
		if (GlowPass::validate(this->glowPass))
			this->glowPass->exec();
		if (LincPass::validate(this->lincPass))
			this->lincPass->exec();
	}

	void ForwardRenderAlgo::freeAlgo()
	{
		IRenderPass* v1;
		unsigned int i;

		for (i = 0; i < std::vector<IRenderPass*>::size(&this->passes); ++i)
		{
			v1 = *std::vector<IRenderPass*>::operator[](&this->passes, i);
			if (v1)
                delete v1;
		}
		std::vector<IRenderPass*>::clear(&this->passes);
	}

	bool ForwardRenderAlgo::isBloom()
	{
		return this->m_isBloom;
	}

	bool ForwardRenderAlgo::isShadowPass()
	{
		return this->m_shadow;
	}

	void ForwardRenderAlgo::makeAlgo(const Adapter& adapter)
	{
		IScene* s;
		ShadowPass* shadowPass;
		IScene* s_1;
		ITextureRectangle* depth;
		GlowPass* glowPass_1;
		IScene* s_2;
		ITextureRectangle* in;
		BloomPass* bloomPass_1;
		IScene* s_3;
		ITextureRectangle* f;
		ITextureRectangle* b;
		ITextureRectangle* d;
		LincPass* lincPass_1;
		IScene* s_4;
		ITextureRectangle* f_1;
		ITextureRectangle* b_1;
		ITextureRectangle* d_1;
		ITextureRectangle* g_1;
		ITextureRectangle* g;
		std::vector<IRenderPass*>::value_type __x;
		std::vector<IRenderPass*>::value_type mainPass;
		std::vector<IRenderPass*>::value_type vlsPass;
		std::vector<IRenderPass*>::value_type bloomPass;
		std::vector<IRenderPass*>::value_type glowPass;
		std::vector<IRenderPass*>::value_type lincPass;

		s = ForwardRenderAlgo::scene(this);
		shadowPass = (ShadowPass*)operator new(0x1D0uLL);
		ShadowPass::ShadowPass(shadowPass, s, adapter);
		this->shadowPass = shadowPass;
		this->mainPass =this->allockMainPass( adapter);
		this->vlsPass = 0LL;
		s_1 = ForwardRenderAlgo::scene(this);
		depth = MainPass::depthBuffer(this->mainPass);
		glowPass_1 = (GlowPass*)operator new(0x38uLL);
		GlowPass::GlowPass(glowPass_1, s_1, adapter, depth);
		this->glowPass = glowPass_1;
		s_2 = ForwardRenderAlgo::scene(this);
		in = this->mainPass->output();
		bloomPass_1 = (BloomPass*)operator new(0x78uLL);
		BloomPass::BloomPass(bloomPass_1, s_2, adapter, in);
		this->bloomPass = bloomPass_1;
		if (this->vlsPass)
		{
			s_3 = ForwardRenderAlgo::scene(this);
			f = VolumetricLightScatteringPass::output(this->vlsPass);
			g = GlowPass::output(this->glowPass);
			b = BloomPass::output(this->bloomPass);
			d = MainPass::depthBuffer(this->mainPass);
			lincPass_1 = (LincPass*)operator new(0x38uLL);
			LincPass::LincPass(lincPass_1, s_3, adapter, this->quad, f, g, b, d);
		}
		else
		{
			s_4 = ForwardRenderAlgo::scene(this);
			f_1 = this->mainPass->output();
			g_1 = GlowPass::output(this->glowPass);
			b_1 = BloomPass::output(this->bloomPass);
			d_1 = MainPass::depthBuffer(this->mainPass);
			lincPass_1 = (LincPass*)operator new(0x38uLL);
			LincPass::LincPass(lincPass_1, s_4, adapter, this->quad, f_1, g_1, b_1, d_1);
		}
		this->lincPass = lincPass_1;
		__x = this->shadowPass;
		std::vector<IRenderPass*>::push_back(&this->passes, &__x);
		mainPass = this->mainPass;
		std::vector<IRenderPass*>::push_back(&this->passes, &mainPass);
		if (this->vlsPass)
		{
			vlsPass = this->vlsPass;
			std::vector<IRenderPass*>::push_back(&this->passes, &vlsPass);
		}
		bloomPass = this->bloomPass;
		std::vector<IRenderPass*>::push_back(&this->passes, &bloomPass);
		glowPass = this->glowPass;
		std::vector<IRenderPass*>::push_back(&this->passes, &glowPass);
		lincPass = this->lincPass;
		std::vector<IRenderPass*>::push_back(&this->passes, &lincPass);
	}

	void ForwardRenderAlgo::recreateAlgo(const Adapter& adapter)
	{
		ForwardRenderAlgo::freeAlgo(this);
		ForwardRenderAlgo::makeAlgo(this, adapter);
	}

	IScene* ForwardRenderAlgo::scene()
	{
		return this->mscene;
	}

	void ForwardRenderAlgo::setBloom(bool use)
	{
		this->m_isBloom = use;
	}

	void ForwardRenderAlgo::setPoint(float* p, float x, float y)
	{
		*p = x;
		p[1] = y;
	}

	void ForwardRenderAlgo::setShadowPass(bool use)
	{
		this->m_shadow = use;
	}

	IRenderAlgoSettings* ForwardRenderAlgo::settings()
	{
		return this->m_settings;
	}

	IRenderPass::Pass::Type ForwardRenderAlgo::type()
	{
		return 0;
	}
}