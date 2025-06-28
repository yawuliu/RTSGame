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
			delete this->mtechnique;
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

		v1 = this->technique();
		(*(void(__fastcall**)(__int64))(*(_QWORD*)v1 + 16LL))(v1);
		v2 = this->technique();
		(*(void(__fastcall**)(__int64))(*(_QWORD*)v2 + 24LL))(v2);
		v4 = this->technique();
		if (this->curShader != (const IShader*)(*(__int64(__fastcall**)(__int64))(*(_QWORD*)v4 + 40LL))(v4))
            this->bindTextures();
		v5 = this->technique();
		this->curShader = (const IShader*)(*(__int64(__fastcall**)(__int64))(*(_QWORD*)v5 + 40LL))(v5);
        this->render()->setRenderState(this->renderState());
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
			v1 = this->technique();
			if ((*(__int64(__fastcall**)(__int64))(*(_QWORD*)v1 + 40LL))(v1)
				&& this->mtechnique->glowSampler()
				&& (v2 = this->technique(),
					v3 = (*(__int64(__fastcall**)(__int64))(*(_QWORD*)v2 + 40LL))(v2),
					v4 = this->mtechnique->glowSampler(),
					v3 == v4->owner())
				&& this->glow)
			{
				v6 = this->render();
				glow = this->glow;
				v9 = this->mtechnique->glowSampler();
                v6->bindTexture(v9, glow);
			}
			else
			{
				v10 = this->technique();
				if ((*(__int64(__fastcall**)(__int64))(*(_QWORD*)v10 + 40LL))(v10))
				{
					if (this->mtechnique->opacitySampler_toSM())
					{
						v11 = this->technique();
						v12 = (*(__int64(__fastcall**)(__int64))(*(_QWORD*)v11 + 40LL))(v11);
						if (v12 == this->mtechnique->opacitySampler_toSM()->owner())
						{
							if (this->diff)
							{
                                this->render()->bindTexture(this->mtechnique->opacitySampler_toSM(), this->diff);
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

		v2 = this->technique();
		result = 0;
		if ((*(__int64(__fastcall**)(__int64))(*(_QWORD*)v2 + 40LL))(v2))
		{
			if (s)
			{
				v3 = this->technique();
				v4 = (*(__int64(__fastcall**)(__int64))(*(_QWORD*)v3 + 40LL))(v3);
				if (v4 == s->owner())
					return 1;
			}
		}
		return result;
	}

	bool StdMaterial::drawEvent(const IGraphicsObject* const obj)
	{
		__int64 v2;

		v2 = this->technique();;
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

		}
    }
}