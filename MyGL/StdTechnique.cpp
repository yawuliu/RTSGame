#include "StdTechnique.h"
namespace MyGL {
	StdTechnique::StdTechnique(IScene& s):AbstractTechnique(s)
	{
		RenderState* rstate;
		RenderState* pstate;
        this->setColorShader(0LL);
        this->setShadowShader(0LL);
        this->setDepthShader( 0LL);
        this->setGlowShader( 0LL);
		this->opacitySampler = 0LL;
		rstate = (RenderState*)operator new(0x30uLL);
		RenderState::RenderState(rstate);
		this->rstate = rstate;
		pstate = (RenderState*)operator new(0x30uLL);
		RenderState::RenderState(pstate);
		this->pstate = pstate;
		this->rstate->setAlphaTestRef(0.5);
        this->rstate->setAlphaTestMode(1LL);
        this->rstate->setAlphaCoverage(1LL);
        this->useDepthPass(1);
        this->useGlow( 1);
        this->useCullFace(1);
		this->updateMat = 0;
	}

	StdTechnique::~StdTechnique()
	{
		if (this->rstate)
            delete this->rstate;
		if (this->pstate)
            delete this->pstate;
	}

	void StdTechnique::bind()
	{
		IRender* v1;

		if (this->sh)
		{
			v1 = this->render();
			v1->useShader( this->sh);
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
		this->restoreRenderState();
	}

	void StdTechnique::completeDraw(const ColorPass* a2)
	{
		this->restoreRenderState();
	}

	void StdTechnique::completeDraw(const DepthPass* a2)
	{
		this->restoreRenderState();
	}

	void StdTechnique::completeDraw(const GlowPass* a2)
	{
		this->restoreRenderState();
	}

	void StdTechnique::completeDraw(const ShadowPass* a2)
	{
		this->restoreRenderState();
	}

	void StdTechnique::completeDraw(const TransparentPass* a2)
	{
		this->restoreRenderState();
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
		v4 = this->render();
		v4->getProjectionMatrix(&m);
		ObjectMatrix::mul(&this->lMatrix, &m);
		v5 = this->render();
		v5->getModeViewlMatrix(&m);
		ObjectMatrix::mul(&this->lMatrix, &m);
		other = obj->objectMatrix();
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
			this->rstate->setZTest(1LL);
			this->rstate->setZWriting(0LL);
			this->rstate->setZTestMode(2LL);
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
        this->storeRenderState();
		this->sh = this->depth;
		this->rstate->setZTest(1LL);
		this->rstate->setZTestMode(2LL);
			this->rstate->setColorMask(
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
        this->storeRenderState();
		this->sh = this->glow;
		if (this->sh)
		{
			this->rstate->setBlend(0LL);
			this->rstate->setZTest(1LL);
			this->rstate->setZTestMode(3LL);
			this->rstate->setZWriting( 0LL);
		}
		return this->sh != 0LL;
	}

	bool StdTechnique::passEvent(const ShadowPass* a2)
	{
		this->sh = this->shadow;
		if (this->sh)
		{
            this->storeRenderState();
			this->updateMat = 1;
			this->rstate->setZTest(1LL);
			this->rstate->setZTestMode(2LL);
					this->rstate>setColorMask(
					1LL,
					1LL,
					1LL,
					1LL);
			this->rstate->setBlend(0LL);
			if (this->rstate->cullFaceMode() == 2)
			{
				this->rstate->setCullFaceMode(1LL);
			}
			else if (this->rstate->cullFaceMode() == 1)
			{
				this->rstate->setCullFaceMode(2LL);
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
			this->rstate->setZTest(1LL);
			this->rstate->setZTestMode(2LL);

				this->rstate->setColorMask(
				0LL,
				0LL,
				0LL,
				0LL);
			this->rstate->setBlend(0LL);
		}
		if (pass->isColorPass())
		{
			this->sh = this->mshader;
			this->rstate->setZTest(1LL);
			this->rstate->setZTestMode(6LL);
			this->rstate->setColorMask(
					1LL,
					1LL,
					1LL,
					1LL);
			this->rstate->setBlend(1LL);
		}
		return this->sh != 0LL;
	}

	IRenderState* StdTechnique::renderState()
	{
		return this->rstate;
	}

	void StdTechnique::restoreRenderState()
	{

			this->rstate->copy(this->pstate);
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
				v4 = v3->lights();
				if ((*(unsigned int(__fastcall**)(__int64))(*(_QWORD*)v4 + 40LL))(v4))
				{
					v6 = AbstractTechnique::scene(this);
					v7 = v6->lights();
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
			this->pstate->copy(this->rstate);
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
				mtechnique->rstate->setCullFaceMode(0LL);
		else
				mtechnique->rstate->setCullFaceMode((unsigned int)t);
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