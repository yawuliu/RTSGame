#include "StdTechnique.h"

MyGL::StdTechnique::StdTechnique(MyGL::IScene& s)
{
	MyGL::RenderState* rstate;
	MyGL::RenderState* pstate;

	MyGL::AbstractTechnique::AbstractTechnique(this, s);
	MyGL::ObjectMatrix::ObjectMatrix(&this->lMatrix);
	MyGL::StdTechnique::setColorShader(this, 0LL);
	MyGL::StdTechnique::setShadowShader(this, 0LL);
	MyGL::StdTechnique::setDepthShader(this, 0LL);
	MyGL::StdTechnique::setGlowShader(this, 0LL);
	this->opacitySampler = 0LL;
	rstate = (MyGL::RenderState*)operator new(0x30uLL);
	MyGL::RenderState::RenderState(rstate);
	this->rstate = rstate;
	pstate = (MyGL::RenderState*)operator new(0x30uLL);
	MyGL::RenderState::RenderState(pstate);
	this->pstate = pstate;
	(*((void(__fastcall**)(MyGL::IRenderState*, double))this->rstate->_vptr_IRenderState + 3))(
		this->rstate,
		0.5);
	(*((void(__fastcall**)(MyGL::IRenderState*, __int64))this->rstate->_vptr_IRenderState + 5))(
		this->rstate,
		1LL);
	(*((void(__fastcall**)(MyGL::IRenderState*, __int64))this->rstate->_vptr_IRenderState + 20))(
		this->rstate,
		1LL);
	MyGL::StdTechnique::useDepthPass(this, 1);
	MyGL::StdTechnique::useGlow(this, 1);
	MyGL::StdTechnique::useCullFace(this, 1);
	this->updateMat = 0;
}

MyGL::StdTechnique::~StdTechnique()
{
	if (this->rstate)
		(*((void(__fastcall**)(MyGL::IRenderState*))this->rstate->_vptr_IRenderState + 1))(this->rstate);
	if (this->pstate)
		(*((void(__fastcall**)(MyGL::IRenderState*))this->pstate->_vptr_IRenderState + 1))(this->pstate);
	MyGL::ObjectMatrix::~ObjectMatrix(&this->lMatrix);
	MyGL::AbstractTechnique::~AbstractTechnique(this);
}

void MyGL::StdTechnique::bind()
{
	MyGL::IRender* v1;

	if (this->sh)
	{
		v1 = MyGL::AbstractTechnique::render(this);
		(*((void(__fastcall**)(MyGL::IRender*, MyGL::IShader*))v1->_vptr_IRender + 13))(v1, this->sh);
	}
}

const MyGL::IShader* MyGL::StdTechnique::cmpShader(const)
{
	return this->mshader;
}

MyGL::IShader* MyGL::StdTechnique::colorShader()
{
	return this->mshader;
}

void MyGL::StdTechnique::completeDraw(const MyGL::AddBlendPass* a2)
{
	MyGL::StdTechnique::restoreRenderState(this);
}

void MyGL::StdTechnique::completeDraw(const MyGL::ColorPass* a2)
{
	MyGL::StdTechnique::restoreRenderState(this);
}

void MyGL::StdTechnique::completeDraw(const MyGL::DepthPass* a2)
{
	MyGL::StdTechnique::restoreRenderState(this);
}

void MyGL::StdTechnique::completeDraw(const MyGL::GlowPass* a2)
{
	MyGL::StdTechnique::restoreRenderState(this);
}

void MyGL::StdTechnique::completeDraw(const MyGL::ShadowPass* a2)
{
	MyGL::StdTechnique::restoreRenderState(this);
}

void MyGL::StdTechnique::completeDraw(const MyGL::TransparentPass* a2)
{
	MyGL::StdTechnique::restoreRenderState(this);
}

const MyGL::IShader* MyGL::StdTechnique::currentShader(const)
{
	return this->sh;
}

MyGL::IShader* MyGL::StdTechnique::depthShader()
{
	return this->depth;
}

MyGL::IUniformSampler* MyGL::StdTechnique::diffSampler(MyGL::StdTechnique& mtechnique)
{
	return mtechnique->mdiffSampler;
}

bool MyGL::StdTechnique::drawEvent(const MyGL::IGraphicsObject& obj, const MyGL::IMaterial& a3)
{
	bool v3;
	MyGL::IRender* v4;
	MyGL::IRender* v5;
	const void* other;
	MyGL::ObjectMatrix m;

	if (!this->updateMat)
		return 1;
	this->updateMat = 0;
	MyGL::ObjectMatrix::ObjectMatrix(&m);
	MyGL::ObjectMatrix::identity(&this->lMatrix);
	v4 = MyGL::AbstractTechnique::render(this);
	(*((void(__fastcall**)(MyGL::IRender*, MyGL::ObjectMatrix*))v4->_vptr_IRender + 41))(v4, &m);
	MyGL::ObjectMatrix::mul(&this->lMatrix, &m);
	v5 = MyGL::AbstractTechnique::render(this);
	(*((void(__fastcall**)(MyGL::IRender*, MyGL::ObjectMatrix*))v5->_vptr_IRender + 40))(v5, &m);
	MyGL::ObjectMatrix::mul(&this->lMatrix, &m);
	other = (const void*)(*((__int64(__fastcall**)(const MyGL::IGraphicsObject&))obj->_vptr_IGraphicsObject + 5))(obj);
	MyGL::ObjectMatrix::mul(&this->lMatrix, other);
	v3 = this->sh != 0LL;
	MyGL::ObjectMatrix::~ObjectMatrix(&m);
	return v3;
}

MyGL::IUniformSampler* MyGL::StdTechnique::glowSampler(MyGL::StdTechnique& mtechnique)
{
	return mtechnique->gglowSampler;
}

MyGL::IShader* MyGL::StdTechnique::glowShader()
{
	return this->glow;
}

MyGL::IUniformSampler* MyGL::StdTechnique::normalMapSampler(MyGL::StdTechnique& mtechnique)
{
	return mtechnique->normalSampler;
}

MyGL::IUniformSampler* MyGL::StdTechnique::opacitySampler_toSM(MyGL::StdTechnique& mtechnique)
{
	return mtechnique->opacitySampler;
}

bool MyGL::StdTechnique::passEvent(const MyGL::AddBlendPass* a2)
{
	this->sh = this->mshader;
	if (this->sh)
	{
		MyGL::StdTechnique::storeRenderState(this);
		(*((void(__fastcall**)(MyGL::IRenderState*, __int64))this->rstate->_vptr_IRenderState + 12))(this->rstate, 1LL);
		(*((void(__fastcall**)(MyGL::IRenderState*, _QWORD))this->rstate->_vptr_IRenderState + 10))(this->rstate, 0LL);
		(*((void(__fastcall**)(MyGL::IRenderState*, __int64))this->rstate->_vptr_IRenderState + 16))(this->rstate, 2LL);
	}
	return this->sh != 0LL;
}

bool MyGL::StdTechnique::passEvent(const MyGL::ColorPass* a2)
{
	MyGL::IShader* s;
	__int64 v3;
	__int64 v4;
	__int64 v5;

	MyGL::StdTechnique::storeRenderState(this);
	s = MyGL::StdTechnique::colorShader(this);
	MyGL::StdTechnique::setCurrentShader(this, s);
	v3 = (*((__int64(__fastcall**)(MyGL::StdTechnique&))this->_vptr_ITechnique + 7))(this);
	(*(void(__fastcall**)(__int64, __int64))(*(_QWORD*)v3 + 96LL))(v3, 1LL);
	if (MyGL::StdTechnique::useDepthPass(this))
	{
		v4 = (*((__int64(__fastcall**)(MyGL::StdTechnique&))this->_vptr_ITechnique + 7))(this);
		(*(void(__fastcall**)(__int64, __int64))(*(_QWORD*)v4 + 128LL))(v4, 6LL);
	}
	else
	{
		v5 = (*((__int64(__fastcall**)(MyGL::StdTechnique&))this->_vptr_ITechnique + 7))(this);
		(*(void(__fastcall**)(__int64, __int64))(*(_QWORD*)v5 + 128LL))(v5, 2LL);
	}
	return (*((__int64(__fastcall**)(MyGL::StdTechnique&))this->_vptr_ITechnique + 5))(this) != 0;
}

bool MyGL::StdTechnique::passEvent(const MyGL::DepthPass* a2)
{
	if (!this->useDepth)
		return 0;
	MyGL::StdTechnique::storeRenderState(this);
	this->sh = this->depth;
	(*((void(__fastcall**)(MyGL::IRenderState*, __int64))this->rstate->_vptr_IRenderState + 12))(this->rstate, 1LL);
	(*((void(__fastcall**)(MyGL::IRenderState*, __int64))this->rstate->_vptr_IRenderState + 16))(this->rstate, 2LL);
	(*((void(__fastcall**)(MyGL::IRenderState*, _QWORD, _QWORD, _QWORD, _QWORD))this->rstate->_vptr_IRenderState + 7))(
		this->rstate,
		0LL,
		0LL,
		0LL,
		0LL);
	return this->sh != 0LL;
}

bool MyGL::StdTechnique::passEvent(const MyGL::GlowPass* a2)
{
	if (!this->useGlowM)
		return 0;
	MyGL::StdTechnique::storeRenderState(this);
	this->sh = this->glow;
	if (this->sh)
	{
		(*((void(__fastcall**)(MyGL::IRenderState*, _QWORD))this->rstate->_vptr_IRenderState + 18))(this->rstate, 0LL);
		(*((void(__fastcall**)(MyGL::IRenderState*, __int64))this->rstate->_vptr_IRenderState + 12))(this->rstate, 1LL);
		(*((void(__fastcall**)(MyGL::IRenderState*, __int64))this->rstate->_vptr_IRenderState + 16))(this->rstate, 3LL);
		(*((void(__fastcall**)(MyGL::IRenderState*, _QWORD))this->rstate->_vptr_IRenderState + 10))(this->rstate, 0LL);
	}
	return this->sh != 0LL;
}

bool MyGL::StdTechnique::passEvent(const MyGL::ShadowPass* a2)
{
	this->sh = this->shadow;
	if (this->sh)
	{
		MyGL::StdTechnique::storeRenderState(this);
		this->updateMat = 1;
		(*((void(__fastcall**)(MyGL::IRenderState*, __int64))this->rstate->_vptr_IRenderState + 12))(this->rstate, 1LL);
		(*((void(__fastcall**)(MyGL::IRenderState*, __int64))this->rstate->_vptr_IRenderState + 16))(this->rstate, 2LL);
		(*((void(__fastcall**)(MyGL::IRenderState*, __int64, __int64, __int64, __int64))this->rstate->_vptr_IRenderState
			+ 7))(
				this->rstate,
				1LL,
				1LL,
				1LL,
				1LL);
		(*((void(__fastcall**)(MyGL::IRenderState*, _QWORD))this->rstate->_vptr_IRenderState + 18))(this->rstate, 0LL);
		if ((*((unsigned int(__fastcall**)(MyGL::IRenderState*))this->rstate->_vptr_IRenderState + 13))(this->rstate) == 2)
		{
			(*((void(__fastcall**)(MyGL::IRenderState*, __int64))this->rstate->_vptr_IRenderState + 14))(this->rstate, 1LL);
		}
		else if ((*((unsigned int(__fastcall**)(MyGL::IRenderState*))this->rstate->_vptr_IRenderState + 13))(this->rstate) == 1)
		{
			(*((void(__fastcall**)(MyGL::IRenderState*, __int64))this->rstate->_vptr_IRenderState + 14))(this->rstate, 2LL);
		}
	}
	return this->sh != 0LL;
}

bool MyGL::StdTechnique::passEvent(const MyGL::TransparentPass* pass)
{
	MyGL::StdTechnique::storeRenderState(this);
	if (MyGL::TransparentPass::isDepthPass(pass))
	{
		this->sh = this->mshader;
		if (this->depth)
			this->sh = this->depth;
		(*((void(__fastcall**)(MyGL::IRenderState*, __int64))this->rstate->_vptr_IRenderState + 12))(this->rstate, 1LL);
		(*((void(__fastcall**)(MyGL::IRenderState*, __int64))this->rstate->_vptr_IRenderState + 16))(this->rstate, 2LL);
		(*((void(__fastcall**)(MyGL::IRenderState*, _QWORD, _QWORD, _QWORD, _QWORD))this->rstate->_vptr_IRenderState + 7))(
			this->rstate,
			0LL,
			0LL,
			0LL,
			0LL);
		(*((void(__fastcall**)(MyGL::IRenderState*, _QWORD))this->rstate->_vptr_IRenderState + 18))(this->rstate, 0LL);
	}
	if (MyGL::TransparentPass::isColorPass(pass))
	{
		this->sh = this->mshader;
		(*((void(__fastcall**)(MyGL::IRenderState*, __int64))this->rstate->_vptr_IRenderState + 12))(this->rstate, 1LL);
		(*((void(__fastcall**)(MyGL::IRenderState*, __int64))this->rstate->_vptr_IRenderState + 16))(this->rstate, 6LL);
		(*((void(__fastcall**)(MyGL::IRenderState*, __int64, __int64, __int64, __int64))this->rstate->_vptr_IRenderState
			+ 7))(
				this->rstate,
				1LL,
				1LL,
				1LL,
				1LL);
		(*((void(__fastcall**)(MyGL::IRenderState*, __int64))this->rstate->_vptr_IRenderState + 18))(this->rstate, 1LL);
	}
	return this->sh != 0LL;
}

MyGL::IRenderState* MyGL::StdTechnique::renderState()
{
	return this->rstate;
}

void MyGL::StdTechnique::restoreRenderState()
{
	(*((void(__fastcall**)(MyGL::IRenderState*, MyGL::IRenderState*))this->rstate->_vptr_IRenderState + 4))(
		this->rstate,
		this->pstate);
}

void MyGL::StdTechnique::setColorShader(MyGL::StdTechnique& mtechnique, MyGL::IShader* sh)
{
	mtechnique->mshader = sh;
	if (mtechnique->mshader)
	{
		mtechnique->mdiffSampler = (MyGL::IUniformSampler*)(*((__int64(__fastcall**)(MyGL::IShader*, const char*))mtechnique->mshader->_vptr_IShader
			+ 17))(
				mtechnique->mshader,
				"diffuse_texture");
		mtechnique->mshadowSampler = (MyGL::IUniformSampler*)(*((__int64(__fastcall**)(MyGL::IShader*, const char*))mtechnique->mshader->_vptr_IShader
			+ 17))(
				mtechnique->mshader,
				"shadow_map_texture");
		mtechnique->mspecSampler = (MyGL::IUniformSampler*)(*((__int64(__fastcall**)(MyGL::IShader*, const char*))mtechnique->mshader->_vptr_IShader
			+ 17))(
				mtechnique->mshader,
				"specular_texture");
		mtechnique->normalSampler = (MyGL::IUniformSampler*)(*((__int64(__fastcall**)(MyGL::IShader*, const char*))mtechnique->mshader->_vptr_IShader
			+ 17))(
				mtechnique->mshader,
				"normal_map_texture");
		if (mtechnique->mdiffSampler)
			(*((void(__fastcall**)(MyGL::IUniformSampler*, _QWORD))mtechnique->mdiffSampler->_vptr_IUniform + 6))(
				mtechnique->mdiffSampler,
				0LL);
		if (mtechnique->mshadowSampler)
			(*((void(__fastcall**)(MyGL::IUniformSampler*, __int64))mtechnique->mshadowSampler->_vptr_IUniform + 6))(
				mtechnique->mshadowSampler,
				1LL);
		if (mtechnique->mspecSampler)
			(*((void(__fastcall**)(MyGL::IUniformSampler*, __int64))mtechnique->mspecSampler->_vptr_IUniform + 6))(
				mtechnique->mspecSampler,
				2LL);
		if (mtechnique->normalSampler)
			(*((void(__fastcall**)(MyGL::IUniformSampler*, __int64))mtechnique->normalSampler->_vptr_IUniform + 6))(
				mtechnique->normalSampler,
				3LL);
		mtechnique->lMat = (MyGL::IUniformMatrix4x4*)(*((__int64(__fastcall**)(MyGL::IShader*, const char*))mtechnique->mshader->_vptr_IShader
			+ 16))(
				mtechnique->mshader,
				"lMatrix");
		mtechnique->lDir = (MyGL::IUniform4f*)(*((__int64(__fastcall**)(MyGL::IShader*, const char*))mtechnique->mshader->_vptr_IShader
			+ 15))(
				mtechnique->mshader,
				"lDirection");
	}
	else
	{
		mtechnique->mdiffSampler = 0LL;
		mtechnique->mshadowSampler = 0LL;
		mtechnique->mspecSampler = 0LL;
		mtechnique->normalSampler = 0LL;
		mtechnique->lMat = 0LL;
		mtechnique->lDir = 0LL;
	}
}

void MyGL::StdTechnique::setCurrentShader(MyGL::IShader* s)
{
	this->sh = s;
}

void MyGL::StdTechnique::setDepthShader(MyGL::StdTechnique& mtechnique, MyGL::IShader* sh)
{
	mtechnique->depth = sh;
}

void MyGL::StdTechnique::setGlowShader(MyGL::StdTechnique& mtechnique, MyGL::IShader* sh)
{
	mtechnique->glow = sh;
	if (mtechnique->glow)
	{
		mtechnique->gglowSampler = (MyGL::IUniformSampler*)(*((__int64(__fastcall**)(MyGL::IShader*, const char*))mtechnique->glow->_vptr_IShader
			+ 17))(
				mtechnique->glow,
				"glow_texture");
		if (mtechnique->gglowSampler)
			(*((void(__fastcall**)(MyGL::IUniformSampler*, _QWORD))mtechnique->gglowSampler->_vptr_IUniform + 6))(
				mtechnique->gglowSampler,
				0LL);
	}
	else
	{
		mtechnique->gglowSampler = 0LL;
	}
}

void MyGL::StdTechnique::setShadowShader(MyGL::StdTechnique& mtechnique, MyGL::IShader* sh)
{
	mtechnique->shadow = sh;
	if (mtechnique->shadow)
		mtechnique->opacitySampler = (MyGL::IUniformSampler*)(*((__int64(__fastcall**)(MyGL::IShader*, const char*))mtechnique->shadow->_vptr_IShader
			+ 17))(
				mtechnique->shadow,
				"opacity");
	else
		mtechnique->opacitySampler = 0LL;
}

void MyGL::StdTechnique::setUniforms()
{
	void(__fastcall * v1)(MyGL::IUniformMatrix4x4*, const MyGL::Float*);
	const MyGL::Float* v2;
	MyGL::IScene* v3;
	__int64 v4;
	MyGL::IScene* v6;
	__int64 v7;
	__int64 v8;
	MyGL::Float* l;

	if (this->mshader == this->sh)
	{
		if (this->lMat)
		{
			v1 = (void(__fastcall*)(MyGL::IUniformMatrix4x4*, const MyGL::Float*)) * ((_QWORD*)this->lMat->_vptr_IUniform
				+ 6);
			v2 = MyGL::ObjectMatrix::data(&this->lMatrix);
			v1(this->lMat, v2);
		}
		if (this->lDir)
		{
			v3 = MyGL::AbstractTechnique::scene(this);
			v4 = (*((__int64(__fastcall**)(MyGL::IScene*))v3->_vptr_IScene + 21))(v3);
			if ((*(unsigned int(__fastcall**)(__int64))(*(_QWORD*)v4 + 40LL))(v4))
			{
				v6 = MyGL::AbstractTechnique::scene(this);
				v7 = (*((__int64(__fastcall**)(MyGL::IScene*))v6->_vptr_IScene + 21))(v6);
				v8 = (*(__int64(__fastcall**)(__int64, _QWORD))(*(_QWORD*)v7 + 48LL))(v7, 0LL);
				l = (MyGL::Float*)(*(__int64(__fastcall**)(__int64))(*(_QWORD*)v8 + 104LL))(v8);
				(*((void(__fastcall**)(MyGL::IUniform4f*, MyGL::Float, MyGL::Float, MyGL::Float, double))this->lDir->_vptr_IUniform
					+ 8))(
						this->lDir,
						*l,
						l[1],
						l[2],
						1.0);
			}
		}
	}
}

MyGL::IUniformSampler* MyGL::StdTechnique::shadowSampler(MyGL::StdTechnique& mtechnique)
{
	return mtechnique->mshadowSampler;
}

MyGL::IShader* MyGL::StdTechnique::shadowShader()
{
	return this->shadow;
}

MyGL::IUniformSampler* MyGL::StdTechnique::specularSampler(MyGL::StdTechnique& mtechnique)
{
	return mtechnique->mspecSampler;
}

void MyGL::StdTechnique::storeRenderState()
{
	(*((void(__fastcall**)(MyGL::IRenderState*, MyGL::IRenderState*))this->pstate->_vptr_IRenderState + 4))(
		this->pstate,
		this->rstate);
}

void MyGL::StdTechnique::uBind()
{
	;
}

void MyGL::StdTechnique::useCullFace(MyGL::StdTechnique& mtechnique, bool use)
{
	MyGL::StdTechnique::useCullFace(mtechnique, use, MyGL::IRenderState::CullMode::Type::back);
}

void MyGL::StdTechnique::useCullFace(MyGL::StdTechnique& mtechnique, bool use, MyGL::IRenderState::CullMode::Type t)
{
	mtechnique->useCull = use;
	if (!mtechnique->useCull)
		(*((void(__fastcall**)(MyGL::IRenderState*, _QWORD))mtechnique->rstate->_vptr_IRenderState + 14))(
			mtechnique->rstate,
			0LL);
	else
		(*((void(__fastcall**)(MyGL::IRenderState*, _QWORD))mtechnique->rstate->_vptr_IRenderState + 14))(
			mtechnique->rstate,
			(unsigned int)t);
}

void MyGL::StdTechnique::useDepthPass(MyGL::StdTechnique& mtechnique, bool use)
{
	mtechnique->useDepth = use;
}

bool MyGL::StdTechnique::useDepthPass()
{
	return this->useDepth && this->depth;
}

void MyGL::StdTechnique::useGlow(MyGL::StdTechnique& mtechnique, bool use)
{
	mtechnique->useGlowM = use;
}
