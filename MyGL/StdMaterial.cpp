#include "StdMaterial.h"
#include "StdTechnique.h"
#include "IRenderState.h"
namespace MyGL {
	StdMaterial::StdMaterial(IScene& s, StdTechnique* technique) :AbstractMaterial(s)
	{
		this->diff = 0LL;
		if (technique)
		{
			this->mtechnique = technique;
		}
		else
		{
			this->mtechnique = new StdTechnique();
		}
		this->setShader(0LL);
		this->setShadowShader(0LL);
		this->setDiffuseTexture(0LL);
		this->setShadowTexture(0LL);
		this->setSpecularTexture(0LL);
		this->setGlowTexture(0LL);
		this->setNormalTexture(0LL);
		this->curShader = 0LL;
	}

	StdMaterial::~StdMaterial()
	{
		if (this->mtechnique)
			(*((void(__fastcall**)(StdTechnique*))this->mtechnique->_vptr_ITechnique + 1))(this->mtechnique);
	}

	void StdMaterial::bind()
	{
		__int64 v1;
		__int64 v2;
		const IShader* curShader;
		__int64 v4;
		__int64 v5;
		IRender* v6;
		void(__fastcall * v7)(IRender*, __int64);
		__int64 v8;

		v1 = (*((__int64(__fastcall**)(StdMaterial* const))this->_vptr_IMaterial + 5))(this);
		(*(void(__fastcall**)(__int64))(*(_QWORD*)v1 + 16LL))(v1);
		v2 = (*((__int64(__fastcall**)(StdMaterial* const))this->_vptr_IMaterial + 5))(this);
		(*(void(__fastcall**)(__int64))(*(_QWORD*)v2 + 24LL))(v2);
		curShader = this->curShader;
		v4 = (*((__int64(__fastcall**)(StdMaterial* const))this->_vptr_IMaterial + 5))(this);
		if (curShader != (const IShader*)(*(__int64(__fastcall**)(__int64))(*(_QWORD*)v4 + 40LL))(v4))
			StdMaterial::bindTextures(this);
		v5 = (*((__int64(__fastcall**)(StdMaterial* const))this->_vptr_IMaterial + 5))(this);
		this->curShader = (const IShader*)(*(__int64(__fastcall**)(__int64))(*(_QWORD*)v5 + 40LL))(v5);
		v6 = AbstractMaterial::render(this);
		v7 = (void(__fastcall*)(IRender*, __int64)) * ((_QWORD*)v6->_vptr_IRender + 34);
		v8 = (*((__int64(__fastcall**)(StdMaterial* const))this->_vptr_IMaterial + 11))(this);
		v7(v6, v8);
	}

	void StdMaterial::bindTextures()
	{
		__int64 v1;
		__int64 v2;
		__int64 v3;
		IUniformSampler* v4;
		IRender* v6;
		void(__fastcall * v7)(IRender*, IUniformSampler*, ITexture2d*);
		ITexture2d* glow;
		IUniformSampler* v9;
		__int64 v10;
		__int64 v11;
		__int64 v12;
		IUniformSampler* v13;
		IRender* v15;
		void(__fastcall * v16)(IRender*, IUniformSampler*, ITexture2d*);
		ITexture2d* diff;
		IUniformSampler* v18;

		if (!this->useMainTextures())
		{
			v1 = (*((__int64(__fastcall**)(StdMaterial* const))this->_vptr_IMaterial + 5))(this);
			if ((*(__int64(__fastcall**)(__int64))(*(_QWORD*)v1 + 40LL))(v1)
				&& StdTechnique::glowSampler(this->mtechnique)
				&& (v2 = (*((__int64(__fastcall**)(StdMaterial* const))this->_vptr_IMaterial + 5))(this),
					v3 = (*(__int64(__fastcall**)(__int64))(*(_QWORD*)v2 + 40LL))(v2),
					v4 = StdTechnique::glowSampler(this->mtechnique),
					v3 == (*((__int64(__fastcall**)(IUniformSampler*))v4->_vptr_IUniform + 5))(v4))
				&& this->glow)
			{
				v6 = AbstractMaterial::render(this);
				v7 = (void(__fastcall*)(IRender*, IUniformSampler*, ITexture2d*)) * ((_QWORD*)v6->_vptr_IRender
					+ 16);
				glow = this->glow;
				v9 = StdTechnique::glowSampler(this->mtechnique);
				v7(v6, v9, glow);
			}
			else
			{
				v10 = (*((__int64(__fastcall**)(StdMaterial* const))this->_vptr_IMaterial + 5))(this);
				if ((*(__int64(__fastcall**)(__int64))(*(_QWORD*)v10 + 40LL))(v10))
				{
					if (this->mtechnique->opacitySampler_toSM())
					{
						v11 = (*((__int64(__fastcall**)(StdMaterial* const))this->_vptr_IMaterial + 5))(this);
						v12 = (*(__int64(__fastcall**)(__int64))(*(_QWORD*)v11 + 40LL))(v11);
						v13 = StdTechnique::opacitySampler_toSM(this->mtechnique);
						if (v12 == (*((__int64(__fastcall**)(IUniformSampler*))v13->_vptr_IUniform + 5))(v13))
						{
							if (this->diff)
							{
								v15 = AbstractMaterial::render(this);
								v16 = (void(__fastcall*)(IRender*, IUniformSampler*, ITexture2d*)) * ((_QWORD*)v15->_vptr_IRender + 16);
								diff = this->diff;
								v18 = StdTechnique::opacitySampler_toSM(this->mtechnique);
								v16(v15, v18, diff);
							}
						}
					}
				}
			}
		}
	}

	bool StdMaterial::checkSampler(IUniformSampler* s)
	{
		__int64 v2;
		__int64 v3;
		__int64 v4;
		bool result;

		v2 = (*((__int64(__fastcall**)(StdMaterial* const))this->_vptr_IMaterial + 5))(this);
		result = 0;
		if ((*(__int64(__fastcall**)(__int64))(*(_QWORD*)v2 + 40LL))(v2))
		{
			if (s)
			{
				v3 = (*((__int64(__fastcall**)(StdMaterial* const))this->_vptr_IMaterial + 5))(this);
				v4 = (*(__int64(__fastcall**)(__int64))(*(_QWORD*)v3 + 40LL))(v3);
				if (v4 == (*((__int64(__fastcall**)(IUniformSampler*))s->_vptr_IUniform + 5))(s))
					return 1;
			}
		}
		return result;
	}

	bool StdMaterial::drawEvent(const IGraphicsObject* const obj)
	{
		__int64 v2;

		v2 = (*((__int64(__fastcall**)(StdMaterial* const))this->_vptr_IMaterial + 5))(this);
		return (*(__int64(__fastcall**)(__int64, const IGraphicsObject* const, StdMaterial* const))(*(_QWORD*)v2 + 72LL))(
			v2,
			obj,
			this);
	}

	const ITexture* StdMaterial::getTexture(const unsigned int id)
	{
		if (id)
			return 0LL;
		else
			return this->diff;
	}

	const std::string& StdMaterial::name()
	{
		_BYTE v2[17];

		if (!(_BYTE)`guard variable for'StdMaterial::name(void)::mat_name
			&& __cxa_guard_acquire(&`guard variable for'StdMaterial::name(void)::mat_name) )
		{
			std::allocator<char>::allocator(v2);
			std::string::string(&StdMaterial::name(void)const::mat_name, "FFPMaterial", v2);
			__cxa_guard_release(&`guard variable for'StdMaterial::name(void)::mat_name);
				__cxa_atexit((void (*)(void*)) & std::string::~string, &StdMaterial::name(void)const::mat_name, &_dso_handle);
			std::allocator<char>::~allocator(v2);
		}
		inline const IRenderState* StdMaterial::renderState() {
			__int64 v1;

			v1 = (*((__int64(__fastcall**)(const StdMaterial* const)) this->_vptr_IMaterial + 6))(this);
			return (const IRenderState*)(*(__int64(__fastcall**)(__int64)) (*(_QWORD*)v1 + 64LL))(v1);
		}
		inline void StdMaterial::setDepthShader(IShader * sh) {
			this->mtechnique->setDepthShader(sh);
		}
		inline void StdMaterial::setDiffuseTexture(ITexture2d * t) {
			m->diff = t;
		}
		inline void StdMaterial::setGlowShader(IShader * sh) {
			this->mtechnique->setGlowShader(sh);
		}
		inline void StdMaterial::setGlowTexture(ITexture2d * sh) {
			this->glow = sh;
		}
		inline void StdMaterial::setNormalTexture(ITexture2d * sh) {
			m->normal = sh;
		}
		inline void StdMaterial::setShader(IShader * sh) {
			this->mtechnique->setColorShader(sh);
		}
		inline void StdMaterial::setShadowShader(IShader * sh) {
			this->mtechnique->setShadowShader(sh);
		}
		inline void StdMaterial::setShadowTexture(ITexture2d * sh) {
			this->shadowMap = sh;
		}
		inline void StdMaterial::setSpecularTexture(ITexture2d * sh) {
			this->spec = sh;
		}
		inline void StdMaterial::setUniforms() {
			(*((void(__fastcall**)(StdMaterial* const)) this->_vptr_IMaterial + 2))(this);
		}
		inline ITechnique* StdMaterial::technique() {
			return this->mtechnique;
		}
		inline void StdMaterial::uBind() {
			this->curShader = 0LL;
		}
		inline void StdMaterial::useCullFace(bool use, IRenderState::CullMode::Type t) {
			this->mtechnique->useCullFace(use, t);
		}
		inline void StdMaterial::useDepthPass(bool use) {
			this->mtechnique->useDepthPass(use);
		}
		inline void StdMaterial::useGlow(bool use) {
			this->mtechnique->useGlow(use);
		}
		inline bool StdMaterial::useMainTextures() {
			IUniformSampler* s;
			IRender* v3;
			void(__fastcall * v4)(IRender*, IUniformSampler*, ITexture2d*);
			ITexture2d* diff;
			IUniformSampler* v6;
			IUniformSampler* s_1;
			IRender* v9;
			void(__fastcall * v10)(IRender*, IUniformSampler*, ITexture2d*);
			ITexture2d* shadowMap;
			IUniformSampler* v12;
			IUniformSampler* s_2;
			IRender* v15;
			void(__fastcall * v16)(IRender*, IUniformSampler*, ITexture2d*);
			ITexture2d* spec;
			IUniformSampler* v18;
			IUniformSampler* s_3;
			IRender* v21;
			void(__fastcall * v22)(IRender*, IUniformSampler*, ITexture2d*);
			ITexture2d* normal;
			IUniformSampler* v24;
			bool ok;

			ok = 0;
			s = this->mtechnique->diffSampler();
			if (StdMaterial::checkSampler(this, s) && this->diff) {
				v3 = AbstractMaterial::render(this);
				v4 = (void(__fastcall*)(IRender*, IUniformSampler*, ITexture2d*)) * ((_QWORD*)v3->_vptr_IRender
					+ 16);
				diff = this->diff;
				v6 = this->mtechnique->diffSampler();
				v4(v3, v6, diff);
				ok = 1;
			}
			s_1 = this->mtechnique->shadowSampler();
			if (StdMaterial::checkSampler(this, s_1) && this->shadowMap) {
				v9 = AbstractMaterial::render(this);
				v10 = (void(__fastcall*)(IRender*, IUniformSampler*, ITexture2d*)) * ((_QWORD*)v9->_vptr_IRender
					+ 16);
				shadowMap = this->shadowMap;
				v12 = this->mtechnique->shadowSampler();
				v10(v9, v12, shadowMap);
				ok = 1;
			}
			s_2 = this->mtechnique->specularSampler();
			if (StdMaterial::checkSampler(this, s_2) && this->spec) {
				v15 = AbstractMaterial::render(this);
				v16 = (void(__fastcall*)(IRender*, IUniformSampler*, ITexture2d*)) * ((_QWORD*)v15->_vptr_IRender
					+ 16);
				spec = this->spec;
				v18 = this->mtechnique->specularSampler();
				v16(v15, v18, spec);
				ok = 1;
			}
			s_3 = this->mtechnique->normalMapSampler();
			if (StdMaterial::checkSampler(this, s_3) && this->normal) {
				v21 = AbstractMaterial::render(this);
				v22 = (void(__fastcall*)(IRender*, IUniformSampler*, ITexture2d*)) * ((_QWORD*)v21->_vptr_IRender
					+ 16);
				normal = this->normal;
				v24 = this->mtechnique->normalMapSampler();
				v22(v21, v24, normal);
				return 1;
			}
			return ok;
		}
		return &StdMaterial::name(void)const::mat_name;
	}
}