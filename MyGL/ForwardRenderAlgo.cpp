#include "ForwardRenderAlgo.h"
#include "IRenderAlgoSettings.h"
#include "IModel.h"
#include "MainPass.h"
#include "GlowPass.h"
#include "BloomPass.h"
#include "LincPass.h"
#include "ShadowPass.h"

inline MyGL::ForwardRenderAlgo::ForwardRenderAlgo(MyGL::IScene& s, const MyGL::Adapter& adapter, bool autoMake)
{
	MyGL::IScene* v4;
	MyGL::IRender* r;
	MyGL::Model* quad;
	MyGL::RenderAlgoSettings<MyGL::ForwardRenderAlgo>* m_settings;
	this->mscene = s;
	std::vector<MyGL::IRenderPass*>::vector(&this->passes);
	v4 = MyGL::ForwardRenderAlgo::scene(this);
	r = (MyGL::IRender*)(*((__int64(__fastcall**)(MyGL::IScene*))v4->_vptr_IScene + 3))(v4);
	quad = (MyGL::Model*)operator new(0xC0uLL);
	MyGL::Model::Model(quad, r);
	this->quad = quad;
	MyGL::ForwardRenderAlgo::buildQuad(this, 0, 0);
	MyGL::ForwardRenderAlgo::setBloom(this, 1);
	MyGL::ForwardRenderAlgo::setShadowPass(this, 1);
	if (autoMake)
		MyGL::ForwardRenderAlgo::makeAlgo(this, adapter);
	m_settings = (MyGL::RenderAlgoSettings<MyGL::ForwardRenderAlgo> *)operator new(0x10uLL);
	MyGL::RenderAlgoSettings<MyGL::ForwardRenderAlgo>::RenderAlgoSettings(m_settings, this);
	this->m_settings = m_settings;
}

inline MyGL::ForwardRenderAlgo::~ForwardRenderAlgo()
{
	this->freeAlgo();
	if (this->quad)
		(*((void(__fastcall**)(MyGL::IModel*))this->quad->_vptr_IModel + 1))(this->quad);
	if (this->m_settings)
		(*((void(__fastcall**)(MyGL::IRenderAlgoSettings*))this->m_settings->_vptr_IRenderAlgoSettings + 1))(this->m_settings);
}

inline MyGL::MainPass* MyGL::ForwardRenderAlgo::allockMainPass(const MyGL::Adapter& adapter)
{
	MyGL::IScene* s;
	MyGL::MainPass* v3;

	s = MyGL::ForwardRenderAlgo::scene(this);
	v3 = (MyGL::MainPass*)operator new(0x48uLL);
	MyGL::MainPass::MainPass(v3, s, adapter, this->quad, 1);
	return v3;
}

inline void MyGL::ForwardRenderAlgo::buildQuad(int w, int h)
{
	float* p;
	float* p_1;
	float* p_2;
	float* p_3;
	float* p_4;
	float* p_5;
	float* p_6;
	float* p_7;
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
	MyGL::ForwardRenderAlgo::setPoint(p, -1.0, -1.0);
	MyGL::IOModel::point(&retstr__1, &m, 1);
	p_1 = MyGL::IIOModel::Point::data(&retstr__1);
	MyGL::ForwardRenderAlgo::setPoint(p_1, 1.0, -1.0);
	MyGL::IOModel::point(&retstr__2, &m, 2);
	p_2 = MyGL::IIOModel::Point::data(&retstr__2);
	MyGL::ForwardRenderAlgo::setPoint(p_2, 1.0, 1.0);
	MyGL::IOModel::point(&retstr__3, &m, 3);
	p_3 = MyGL::IIOModel::Point::data(&retstr__3);
	MyGL::ForwardRenderAlgo::setPoint(p_3, -1.0, 1.0);
	MyGL::IOModel::texCoord(&retstr__4, &m, 0);
	p_4 = MyGL::IIOModel::TexCoord::data(&retstr__4);
	MyGL::ForwardRenderAlgo::setPoint(p_4, 0.0, 0.0);
	MyGL::IOModel::texCoord(&retstr__5, &m, 1);
	p_5 = MyGL::IIOModel::TexCoord::data(&retstr__5);
	MyGL::ForwardRenderAlgo::setPoint(p_5, (float)w, 0.0);
	MyGL::IOModel::texCoord(&retstr__6, &m, 2);
	p_6 = MyGL::IIOModel::TexCoord::data(&retstr__6);
	MyGL::ForwardRenderAlgo::setPoint(p_6, (float)w, (float)h);
	MyGL::IOModel::texCoord(&retstr__7, &m, 3);
	p_7 = MyGL::IIOModel::TexCoord::data(&retstr__7);
	MyGL::ForwardRenderAlgo::setPoint(p_7, 0.0, (float)h);
	(*((void(__fastcall**)(MyGL::IModel*, MyGL::IOModel*))this->quad->_vptr_IModel + 8))(this->quad, &m);
	(*((void(__fastcall**)(MyGL::IModel*, __int64))this->quad->_vptr_IModel + 4))(this->quad, 2LL);
	MyGL::IOModel::~IOModel(&m);
}

inline void MyGL::ForwardRenderAlgo::exec()
{
	if (this->isShadowPass())
		(*((void(__fastcall**)(MyGL::ShadowPass*))this->shadowPass->_vptr_IRenderPass + 2))(this->shadowPass);
	if (MyGL::LincPass::validate(this->lincPass))
		(*((void(__fastcall**)(MyGL::MainPass*))this->mainPass->_vptr_IRenderPass + 2))(this->mainPass);
	if (this->vlsPass)
		(*((void(__fastcall**)(MyGL::VolumetricLightScatteringPass*))this->vlsPass->_vptr_IRenderPass + 2))(this->vlsPass);
	if (MyGL::BloomPass::validate(this->bloomPass) && MyGL::ForwardRenderAlgo::isBloom(this))
		(*((void(__fastcall**)(MyGL::BloomPass*))this->bloomPass->_vptr_IRenderPass + 2))(this->bloomPass);
	if (MyGL::GlowPass::validate(this->glowPass))
		(*((void(__fastcall**)(MyGL::GlowPass*))this->glowPass->_vptr_IRenderPass + 2))(this->glowPass);
	if (MyGL::LincPass::validate(this->lincPass))
		(*((void(__fastcall**)(MyGL::LincPass*))this->lincPass->_vptr_IRenderPass + 2))(this->lincPass);
}

inline void MyGL::ForwardRenderAlgo::freeAlgo()
{
	MyGL::IRenderPass* v1;
	unsigned int i;

	for (i = 0; i < std::vector<MyGL::IRenderPass*>::size(&this->passes); ++i)
	{
		v1 = *std::vector<MyGL::IRenderPass*>::operator[](&this->passes, i);
		if (v1)
			(*((void(__fastcall**)(MyGL::IRenderPass*))v1->_vptr_IRenderPass + 1))(v1);
	}
	std::vector<MyGL::IRenderPass*>::clear(&this->passes);
}

inline bool MyGL::ForwardRenderAlgo::isBloom()
{
	return this->m_isBloom;
}

inline bool MyGL::ForwardRenderAlgo::isShadowPass()
{
	return this->m_shadow;
}

inline void MyGL::ForwardRenderAlgo::makeAlgo(const MyGL::Adapter& adapter)
{
	MyGL::IScene* s;
	MyGL::ShadowPass* shadowPass;
	MyGL::IScene* s_1;
	MyGL::ITextureRectangle* depth;
	MyGL::GlowPass* glowPass_1;
	MyGL::IScene* s_2;
	MyGL::ITextureRectangle* in;
	MyGL::BloomPass* bloomPass_1;
	MyGL::IScene* s_3;
	MyGL::ITextureRectangle* f;
	MyGL::ITextureRectangle* b;
	MyGL::ITextureRectangle* d;
	MyGL::LincPass* lincPass_1;
	MyGL::IScene* s_4;
	MyGL::ITextureRectangle* f_1;
	MyGL::ITextureRectangle* b_1;
	MyGL::ITextureRectangle* d_1;
	MyGL::ITextureRectangle* g_1;
	MyGL::ITextureRectangle* g;
	std::vector<MyGL::IRenderPass*>::value_type __x;
	std::vector<MyGL::IRenderPass*>::value_type mainPass;
	std::vector<MyGL::IRenderPass*>::value_type vlsPass;
	std::vector<MyGL::IRenderPass*>::value_type bloomPass;
	std::vector<MyGL::IRenderPass*>::value_type glowPass;
	std::vector<MyGL::IRenderPass*>::value_type lincPass;

	s = MyGL::ForwardRenderAlgo::scene(this);
	shadowPass = (MyGL::ShadowPass*)operator new(0x1D0uLL);
	MyGL::ShadowPass::ShadowPass(shadowPass, s, adapter);
	this->shadowPass = shadowPass;
	this->mainPass = (MyGL::MainPass*)(*((__int64(__fastcall**)(MyGL::ForwardRenderAlgo&, const MyGL::Adapter&))this->_vptr_IRenderPass
		+ 7))(
			this,
			adapter);
	this->vlsPass = 0LL;
	s_1 = MyGL::ForwardRenderAlgo::scene(this);
	depth = MyGL::MainPass::depthBuffer(this->mainPass);
	glowPass_1 = (MyGL::GlowPass*)operator new(0x38uLL);
	MyGL::GlowPass::GlowPass(glowPass_1, s_1, adapter, depth);
	this->glowPass = glowPass_1;
	s_2 = MyGL::ForwardRenderAlgo::scene(this);
	in = (MyGL::ITextureRectangle*)(*((__int64(__fastcall**)(MyGL::MainPass*))this->mainPass->_vptr_IRenderPass + 4))(this->mainPass);
	bloomPass_1 = (MyGL::BloomPass*)operator new(0x78uLL);
	MyGL::BloomPass::BloomPass(bloomPass_1, s_2, adapter, in);
	this->bloomPass = bloomPass_1;
	if (this->vlsPass)
	{
		s_3 = MyGL::ForwardRenderAlgo::scene(this);
		f = MyGL::VolumetricLightScatteringPass::output(this->vlsPass);
		g = MyGL::GlowPass::output(this->glowPass);
		b = MyGL::BloomPass::output(this->bloomPass);
		d = MyGL::MainPass::depthBuffer(this->mainPass);
		lincPass_1 = (MyGL::LincPass*)operator new(0x38uLL);
		MyGL::LincPass::LincPass(lincPass_1, s_3, adapter, this->quad, f, g, b, d);
	}
	else
	{
		s_4 = MyGL::ForwardRenderAlgo::scene(this);
		f_1 = (MyGL::ITextureRectangle*)(*((__int64(__fastcall**)(MyGL::MainPass*))this->mainPass->_vptr_IRenderPass + 4))(this->mainPass);
		g_1 = MyGL::GlowPass::output(this->glowPass);
		b_1 = MyGL::BloomPass::output(this->bloomPass);
		d_1 = MyGL::MainPass::depthBuffer(this->mainPass);
		lincPass_1 = (MyGL::LincPass*)operator new(0x38uLL);
		MyGL::LincPass::LincPass(lincPass_1, s_4, adapter, this->quad, f_1, g_1, b_1, d_1);
	}
	this->lincPass = lincPass_1;
	__x = this->shadowPass;
	std::vector<MyGL::IRenderPass*>::push_back(&this->passes, &__x);
	mainPass = this->mainPass;
	std::vector<MyGL::IRenderPass*>::push_back(&this->passes, &mainPass);
	if (this->vlsPass)
	{
		vlsPass = this->vlsPass;
		std::vector<MyGL::IRenderPass*>::push_back(&this->passes, &vlsPass);
	}
	bloomPass = this->bloomPass;
	std::vector<MyGL::IRenderPass*>::push_back(&this->passes, &bloomPass);
	glowPass = this->glowPass;
	std::vector<MyGL::IRenderPass*>::push_back(&this->passes, &glowPass);
	lincPass = this->lincPass;
	std::vector<MyGL::IRenderPass*>::push_back(&this->passes, &lincPass);
}

inline void MyGL::ForwardRenderAlgo::recreateAlgo(const MyGL::Adapter& adapter)
{
	MyGL::ForwardRenderAlgo::freeAlgo(this);
	MyGL::ForwardRenderAlgo::makeAlgo(this, adapter);
}

inline MyGL::IScene* MyGL::ForwardRenderAlgo::scene()
{
	return this->mscene;
}

inline void MyGL::ForwardRenderAlgo::setBloom(bool use)
{
	this->m_isBloom = use;
}

inline void MyGL::ForwardRenderAlgo::setPoint(float* p, float x, float y)
{
	*p = x;
	p[1] = y;
}

inline void MyGL::ForwardRenderAlgo::setShadowPass(bool use)
{
	this->m_shadow = use;
}

inline MyGL::IRenderAlgoSettings* MyGL::ForwardRenderAlgo::settings()
{
	return this->m_settings;
}

inline MyGL::IRenderPass::Pass::Type MyGL::ForwardRenderAlgo::type()
{
	return 0;
}
