#include "StdTechnique.h"
namespace MyGL {
	StdTechnique::StdTechnique(IScene& s)
	{
		RenderState* rstate;
		RenderState* pstate;

		AbstractTechnique::AbstractTechnique(this, s);
		ObjectMatrix::ObjectMatrix(&this->lMatrix);
		StdTechnique::setColorShader(this, 0LL);
		StdTechnique::setShadowShader(this, 0LL);
		StdTechnique::setDepthShader(this, 0LL);
		StdTechnique::setGlowShader(this, 0LL);
		this->opacitySampler = 0LL;
		rstate = (RenderState*)operator new(0x30uLL);
		RenderState::RenderState(rstate);
		this->rstate = rstate;
		pstate = (RenderState*)operator new(0x30uLL);
		RenderState::RenderState(pstate);
		this->pstate = pstate;
		(*((void(__fastcall**)(IRenderState*, double))this->rstate->_vptr_IRenderState + 3))(
			this->rstate,
			0.5);
		(*((void(__fastcall**)(IRenderState*, __int64))this->rstate->_vptr_IRenderState + 5))(
			this->rstate,
			1LL);
		(*((void(__fastcall**)(IRenderState*, __int64))this->rstate->_vptr_IRenderState + 20))(
			this->rstate,
			1LL);
		StdTechnique::useDepthPass(this, 1);
		StdTechnique::useGlow(this, 1);
		StdTechnique::useCullFace(this, 1);
		this->updateMat = 0;
	}

	StdTechnique::~StdTechnique()
	{
		if (this->rstate)
			(*((void(__fastcall**)(IRenderState*))this->rstate->_vptr_IRenderState + 1))(this->rstate);
		if (this->pstate)
			(*((void(__fastcall**)(IRenderState*))this->pstate->_vptr_IRenderState + 1))(this->pstate);
		ObjectMatrix::~ObjectMatrix(&this->lMatrix);
		AbstractTechnique::~AbstractTechnique(this);
	}

	void StdTechnique::bind()
	{
		IRender* v1;

		if (this->sh)
		{
			v1 = AbstractTechnique::render(this);
			(*((void(__fastcall**)(IRender*, IShader*))v1->_vptr_IRender + 13))(v1, this->sh);
		}
	}

	const IShader* StdTechnique::cmpShader(const)
	{
		return this->mshader;
	}

	IShader* StdTechnique::colorShader()
	{
		return this->mshader;
	}

	void StdTechnique::completeDraw(const AddBlendPass* a2)
	{
		StdTechnique::restoreRenderState(this);
	}

	void StdTechnique::completeDraw(const ColorPass* a2)
	{
		StdTechnique::restoreRenderState(this);
	}

	void StdTechnique::completeDraw(const DepthPass* a2)
	{
		StdTechnique::restoreRenderState(this);
	}

	void StdTechnique::completeDraw(const GlowPass* a2)
	{
		StdTechnique::restoreRenderState(this);
	}

	void StdTechnique::completeDraw(const ShadowPass* a2)
	{
		StdTechnique::restoreRenderState(this);
	}

	void StdTechnique::completeDraw(const TransparentPass* a2)
	{
		StdTechnique::restoreRenderState(this);
	}

	const IShader* StdTechnique::currentShader(const)
	{
		return this->sh;
	}

	IShader* StdTechnique::depthShader()
	{
		return this->depth;
	}

	IUniformSampler* StdTechnique::diffSampler(StdTechnique& mtechnique)
	{
		return mtechnique->mdiffSampler;
	}

	bool StdTechnique::drawEvent(const IGraphicsObject& obj, const IMaterial& a3)
	{
		bool v3;
		IRender* v4;
		IRender* v5;
		const void* other;
		ObjectMatrix m;

		if (!this->updateMat)
			return 1;
		this->updateMat = 0;
		ObjectMatrix::ObjectMatrix(&m);
		ObjectMatrix::identity(&this->lMatrix);
		v4 = AbstractTechnique::render(this);
		(*((void(__fastcall**)(IRender*, ObjectMatrix*))v4->_vptr_IRender + 41))(v4, &m);
		ObjectMatrix::mul(&this->lMatrix, &m);
		v5 = AbstractTechnique::render(this);
		(*((void(__fastcall**)(IRender*, ObjectMatrix*))v5->_vptr_IRender + 40))(v5, &m);
		ObjectMatrix::mul(&this->lMatrix, &m);
		other = (const void*)(*((__int64(__fastcall**)(const IGraphicsObject&))obj->_vptr_IGraphicsObject + 5))(obj);
		ObjectMatrix::mul(&this->lMatrix, other);
		v3 = this->sh != 0LL;
		ObjectMatrix::~ObjectMatrix(&m);
		return v3;
	}

	IUniformSampler* StdTechnique::glowSampler(StdTechnique& mtechnique)
	{
		return mtechnique->gglowSampler;
	}

	IShader* StdTechnique::glowShader()
	{
		return this->glow;
	}

	IUniformSampler* StdTechnique::normalMapSampler(StdTechnique& mtechnique)
	{
		return mtechnique->normalSampler;
	}

	IUniformSampler* StdTechnique::opacitySampler_toSM(StdTechnique& mtechnique)
	{
		return mtechnique->opacitySampler;
	}

	bool StdTechnique::passEvent(const AddBlendPass* a2)
	{
		this->sh = this->mshader;
		if (this->sh)
		{
			StdTechnique::storeRenderState(this);
			(*((void(__fastcall**)(IRenderState*, __int64))this->rstate->_vptr_IRenderState + 12))(this->rstate, 1LL);
			(*((void(__fastcall**)(IRenderState*, _QWORD))this->rstate->_vptr_IRenderState + 10))(this->rstate, 0LL);
			(*((void(__fastcall**)(IRenderState*, __int64))this->rstate->_vptr_IRenderState + 16))(this->rstate, 2LL);
		}
		return this->sh != 0LL;
	}

	bool StdTechnique::passEvent(const ColorPass* a2)
	{
		IShader* s;
		__int64 v3;
		__int64 v4;
		__int64 v5;

		StdTechnique::storeRenderState(this);
		s = StdTechnique::colorShader(this);
		StdTechnique::setCurrentShader(this, s);
		v3 = (*((__int64(__fastcall**)(StdTechnique&))this->_vptr_ITechnique + 7))(this);
		(*(void(__fastcall**)(__int64, __int64))(*(_QWORD*)v3 + 96LL))(v3, 1LL);
		if (StdTechnique::useDepthPass(this))
		{
			v4 = (*((__int64(__fastcall**)(StdTechnique&))this->_vptr_ITechnique + 7))(this);
			(*(void(__fastcall**)(__int64, __int64))(*(_QWORD*)v4 + 128LL))(v4, 6LL);
		}
		else
		{
			v5 = (*((__int64(__fastcall**)(StdTechnique&))this->_vptr_ITechnique + 7))(this);
			(*(void(__fastcall**)(__int64, __int64))(*(_QWORD*)v5 + 128LL))(v5, 2LL);
		}
		return (*((__int64(__fastcall**)(StdTechnique&))this->_vptr_ITechnique + 5))(this) != 0;
	}

	bool StdTechnique::passEvent(const DepthPass* a2)
	{
		if (!this->useDepth)
			return 0;
		StdTechnique::storeRenderState(this);
		this->sh = this->depth;
		(*((void(__fastcall**)(IRenderState*, __int64))this->rstate->_vptr_IRenderState + 12))(this->rstate, 1LL);
		(*((void(__fastcall**)(IRenderState*, __int64))this->rstate->_vptr_IRenderState + 16))(this->rstate, 2LL);
		(*((void(__fastcall**)(IRenderState*, _QWORD, _QWORD, _QWORD, _QWORD))this->rstate->_vptr_IRenderState + 7))(
			this->rstate,
			0LL,
			0LL,
			0LL,
			0LL);
		return this->sh != 0LL;
	}

	bool StdTechnique::passEvent(const GlowPass* a2)
	{
		if (!this->useGlowM)
			return 0;
		StdTechnique::storeRenderState(this);
		this->sh = this->glow;
		if (this->sh)
		{
			(*((void(__fastcall**)(IRenderState*, _QWORD))this->rstate->_vptr_IRenderState + 18))(this->rstate, 0LL);
			(*((void(__fastcall**)(IRenderState*, __int64))this->rstate->_vptr_IRenderState + 12))(this->rstate, 1LL);
			(*((void(__fastcall**)(IRenderState*, __int64))this->rstate->_vptr_IRenderState + 16))(this->rstate, 3LL);
			(*((void(__fastcall**)(IRenderState*, _QWORD))this->rstate->_vptr_IRenderState + 10))(this->rstate, 0LL);
		}
		return this->sh != 0LL;
	}

	bool StdTechnique::passEvent(const ShadowPass* a2)
	{
		this->sh = this->shadow;
		if (this->sh)
		{
			StdTechnique::storeRenderState(this);
			this->updateMat = 1;
			(*((void(__fastcall**)(IRenderState*, __int64))this->rstate->_vptr_IRenderState + 12))(this->rstate, 1LL);
			(*((void(__fastcall**)(IRenderState*, __int64))this->rstate->_vptr_IRenderState + 16))(this->rstate, 2LL);
			(*((void(__fastcall**)(IRenderState*, __int64, __int64, __int64, __int64))this->rstate->_vptr_IRenderState
				+ 7))(
					this->rstate,
					1LL,
					1LL,
					1LL,
					1LL);
			(*((void(__fastcall**)(IRenderState*, _QWORD))this->rstate->_vptr_IRenderState + 18))(this->rstate, 0LL);
			if ((*((unsigned int(__fastcall**)(IRenderState*))this->rstate->_vptr_IRenderState + 13))(this->rstate) == 2)
			{
				(*((void(__fastcall**)(IRenderState*, __int64))this->rstate->_vptr_IRenderState + 14))(this->rstate, 1LL);
			}
			else if ((*((unsigned int(__fastcall**)(IRenderState*))this->rstate->_vptr_IRenderState + 13))(this->rstate) == 1)
			{
				(*((void(__fastcall**)(IRenderState*, __int64))this->rstate->_vptr_IRenderState + 14))(this->rstate, 2LL);
			}
		}
		return this->sh != 0LL;
	}

	bool StdTechnique::passEvent(const TransparentPass* pass)
	{
		StdTechnique::storeRenderState(this);
		if (TransparentPass::isDepthPass(pass))
		{
			this->sh = this->mshader;
			if (this->depth)
				this->sh = this->depth;
			(*((void(__fastcall**)(IRenderState*, __int64))this->rstate->_vptr_IRenderState + 12))(this->rstate, 1LL);
			(*((void(__fastcall**)(IRenderState*, __int64))this->rstate->_vptr_IRenderState + 16))(this->rstate, 2LL);
			(*((void(__fastcall**)(IRenderState*, _QWORD, _QWORD, _QWORD, _QWORD))this->rstate->_vptr_IRenderState + 7))(
				this->rstate,
				0LL,
				0LL,
				0LL,
				0LL);
			(*((void(__fastcall**)(IRenderState*, _QWORD))this->rstate->_vptr_IRenderState + 18))(this->rstate, 0LL);
		}
		if (TransparentPass::isColorPass(pass))
		{
			this->sh = this->mshader;
			(*((void(__fastcall**)(IRenderState*, __int64))this->rstate->_vptr_IRenderState + 12))(this->rstate, 1LL);
			(*((void(__fastcall**)(IRenderState*, __int64))this->rstate->_vptr_IRenderState + 16))(this->rstate, 6LL);
			(*((void(__fastcall**)(IRenderState*, __int64, __int64, __int64, __int64))this->rstate->_vptr_IRenderState
				+ 7))(
					this->rstate,
					1LL,
					1LL,
					1LL,
					1LL);
			(*((void(__fastcall**)(IRenderState*, __int64))this->rstate->_vptr_IRenderState + 18))(this->rstate, 1LL);
		}
		return this->sh != 0LL;
	}

	IRenderState* StdTechnique::renderState()
	{
		return this->rstate;
	}

	void StdTechnique::restoreRenderState()
	{
		(*((void(__fastcall**)(IRenderState*, IRenderState*))this->rstate->_vptr_IRenderState + 4))(
			this->rstate,
			this->pstate);
	}

	void StdTechnique::setColorShader(StdTechnique& mtechnique, IShader* sh)
	{
		mtechnique->mshader = sh;
		if (mtechnique->mshader)
		{
			mtechnique->mdiffSampler = (IUniformSampler*)(*((__int64(__fastcall**)(IShader*, const char*))mtechnique->mshader->_vptr_IShader
				+ 17))(
					mtechnique->mshader,
					"diffuse_texture");
			mtechnique->mshadowSampler = (IUniformSampler*)(*((__int64(__fastcall**)(IShader*, const char*))mtechnique->mshader->_vptr_IShader
				+ 17))(
					mtechnique->mshader,
					"shadow_map_texture");
			mtechnique->mspecSampler = (IUniformSampler*)(*((__int64(__fastcall**)(IShader*, const char*))mtechnique->mshader->_vptr_IShader
				+ 17))(
					mtechnique->mshader,
					"specular_texture");
			mtechnique->normalSampler = (IUniformSampler*)(*((__int64(__fastcall**)(IShader*, const char*))mtechnique->mshader->_vptr_IShader
				+ 17))(
					mtechnique->mshader,
					"normal_map_texture");
			if (mtechnique->mdiffSampler)
				(*((void(__fastcall**)(IUniformSampler*, _QWORD))mtechnique->mdiffSampler->_vptr_IUniform + 6))(
					mtechnique->mdiffSampler,
					0LL);
			if (mtechnique->mshadowSampler)
				(*((void(__fastcall**)(IUniformSampler*, __int64))mtechnique->mshadowSampler->_vptr_IUniform + 6))(
					mtechnique->mshadowSampler,
					1LL);
			if (mtechnique->mspecSampler)
				(*((void(__fastcall**)(IUniformSampler*, __int64))mtechnique->mspecSampler->_vptr_IUniform + 6))(
					mtechnique->mspecSampler,
					2LL);
			if (mtechnique->normalSampler)
				(*((void(__fastcall**)(IUniformSampler*, __int64))mtechnique->normalSampler->_vptr_IUniform + 6))(
					mtechnique->normalSampler,
					3LL);
			mtechnique->lMat = (IUniformMatrix4x4*)(*((__int64(__fastcall**)(IShader*, const char*))mtechnique->mshader->_vptr_IShader
				+ 16))(
					mtechnique->mshader,
					"lMatrix");
			mtechnique->lDir = (IUniform4f*)(*((__int64(__fastcall**)(IShader*, const char*))mtechnique->mshader->_vptr_IShader
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

	void StdTechnique::setCurrentShader(IShader* s)
	{
		this->sh = s;
	}

	void StdTechnique::setDepthShader(StdTechnique& mtechnique, IShader* sh)
	{
		mtechnique->depth = sh;
	}

	void StdTechnique::setGlowShader(StdTechnique& mtechnique, IShader* sh)
	{
		mtechnique->glow = sh;
		if (mtechnique->glow)
		{
			mtechnique->gglowSampler = (IUniformSampler*)(*((__int64(__fastcall**)(IShader*, const char*))mtechnique->glow->_vptr_IShader
				+ 17))(
					mtechnique->glow,
					"glow_texture");
			if (mtechnique->gglowSampler)
				(*((void(__fastcall**)(IUniformSampler*, _QWORD))mtechnique->gglowSampler->_vptr_IUniform + 6))(
					mtechnique->gglowSampler,
					0LL);
		}
		else
		{
			mtechnique->gglowSampler = 0LL;
		}
	}

	void StdTechnique::setShadowShader(StdTechnique& mtechnique, IShader* sh)
	{
		mtechnique->shadow = sh;
		if (mtechnique->shadow)
			mtechnique->opacitySampler = (IUniformSampler*)(*((__int64(__fastcall**)(IShader*, const char*))mtechnique->shadow->_vptr_IShader
				+ 17))(
					mtechnique->shadow,
					"opacity");
		else
			mtechnique->opacitySampler = 0LL;
	}

	void StdTechnique::setUniforms()
	{
		void(__fastcall * v1)(IUniformMatrix4x4*, const Float*);
		const Float* v2;
		IScene* v3;
		__int64 v4;
		IScene* v6;
		__int64 v7;
		__int64 v8;
		Float* l;

		if (this->mshader == this->sh)
		{
			if (this->lMat)
			{
				v1 = (void(__fastcall*)(IUniformMatrix4x4*, const Float*)) * ((_QWORD*)this->lMat->_vptr_IUniform
					+ 6);
				v2 = ObjectMatrix::data(&this->lMatrix);
				v1(this->lMat, v2);
			}
			if (this->lDir)
			{
				v3 = AbstractTechnique::scene(this);
				v4 = (*((__int64(__fastcall**)(IScene*))v3->_vptr_IScene + 21))(v3);
				if ((*(unsigned int(__fastcall**)(__int64))(*(_QWORD*)v4 + 40LL))(v4))
				{
					v6 = AbstractTechnique::scene(this);
					v7 = (*((__int64(__fastcall**)(IScene*))v6->_vptr_IScene + 21))(v6);
					v8 = (*(__int64(__fastcall**)(__int64, _QWORD))(*(_QWORD*)v7 + 48LL))(v7, 0LL);
					l = (Float*)(*(__int64(__fastcall**)(__int64))(*(_QWORD*)v8 + 104LL))(v8);
					(*((void(__fastcall**)(IUniform4f*, Float, Float, Float, double))this->lDir->_vptr_IUniform
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

	IUniformSampler* StdTechnique::shadowSampler(StdTechnique& mtechnique)
	{
		return mtechnique->mshadowSampler;
	}

	IShader* StdTechnique::shadowShader()
	{
		return this->shadow;
	}

	IUniformSampler* StdTechnique::specularSampler(StdTechnique& mtechnique)
	{
		return mtechnique->mspecSampler;
	}

	void StdTechnique::storeRenderState()
	{
		(*((void(__fastcall**)(IRenderState*, IRenderState*))this->pstate->_vptr_IRenderState + 4))(
			this->pstate,
			this->rstate);
	}

	void StdTechnique::uBind()
	{
		;
	}

	void StdTechnique::useCullFace(StdTechnique& mtechnique, bool use)
	{
		StdTechnique::useCullFace(mtechnique, use, IRenderState::CullMode::Type::back);
	}

	void StdTechnique::useCullFace(StdTechnique& mtechnique, bool use, IRenderState::CullMode::Type t)
	{
		mtechnique->useCull = use;
		if (!mtechnique->useCull)
			(*((void(__fastcall**)(IRenderState*, _QWORD))mtechnique->rstate->_vptr_IRenderState + 14))(
				mtechnique->rstate,
				0LL);
		else
			(*((void(__fastcall**)(IRenderState*, _QWORD))mtechnique->rstate->_vptr_IRenderState + 14))(
				mtechnique->rstate,
				(unsigned int)t);
	}

	void StdTechnique::useDepthPass(StdTechnique& mtechnique, bool use)
	{
		mtechnique->useDepth = use;
	}

	bool StdTechnique::useDepthPass()
	{
		return this->useDepth && this->depth;
	}

	void StdTechnique::useGlow(StdTechnique& mtechnique, bool use)
	{
		mtechnique->useGlowM = use;
	}
}