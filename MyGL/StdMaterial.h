#pragma once

#include <string>
#include "AbstractMaterial.h"
#include "IUniformSampler.h"
#include "IRenderState.h"
#include "StdTechnique.h"

namespace MyGL {
	class IScene;

	class IShader;

	class StdTechnique;

	class ITexture2d;

	class StdMaterial : public AbstractMaterial {
	public:
		StdMaterial(IScene& s, StdTechnique* technique);

		virtual ~StdMaterial();

		void bind();

		void bindTextures();

		bool checkSampler(IUniformSampler* s);

		bool drawEvent(const IGraphicsObject& obj);

		const ITexture* getTexture(const unsigned int id);

		const std::string& name();

		const IRenderState* renderState() {
			__int64 v1;

			v1 = (*((__int64(__fastcall**)(const StdMaterial* const)) this->_vptr_IMaterial + 6))(this);
			return (const IRenderState*)(*(__int64(__fastcall**)(__int64)) (*(_QWORD*)v1 + 64LL))(v1);
		}

		void setDepthShader(IShader* sh) {
			this->mtechnique->setDepthShader(sh);
		}

		void setDiffuseTexture(ITexture2d* t) {
			m->diff = t;
		}

		void setGlowShader(IShader* sh) {
			this->mtechnique->setGlowShader(sh);
		}

		void setGlowTexture(ITexture2d* sh) {
			this->glow = sh;
		}

		void setNormalTexture(ITexture2d* sh) {
			m->normal = sh;
		}

		void setShader(IShader* sh) {
			this->mtechnique->setColorShader(sh);
		}

		void setShadowShader(IShader* sh) {
			this->mtechnique->setShadowShader(sh);
		}

		void setShadowTexture(ITexture2d* sh) {
			this->shadowMap = sh;
		}

		void setSpecularTexture(ITexture2d* sh) {
			this->spec = sh;
		}

		void setUniforms() {
			(*((void(__fastcall**)(StdMaterial* const)) this->_vptr_IMaterial + 2))(this);
		}

		ITechnique* technique() {
			return this->mtechnique;
		}

		void uBind() {
			this->curShader = 0LL;
		}

		void useCullFace(bool use, IRenderState::CullMode::Type t) {
			this->mtechnique->useCullFace(use, t);
		}

		void useDepthPass(bool use) {
			this->mtechnique->useDepthPass(use);
		}

		void useGlow(bool use) {
			this->mtechnique->useGlow(use);
		}

		bool useMainTextures() {
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

	protected:
		IScene* curShader;
		IShader* mShader;
		IShader* mShadowShader;
		IShader* mDepthShader;
		IShader* mGlowShader;
		ITexture2d* mTexture;
		ITexture2d* shadowMap;
		ITexture2d* diff;
		ITexture2d* spec;
		ITexture2d* normal;
		ITexture2d* glow;
		IRenderState* mState;
		StdTechnique* mtechnique;
		bool mUseGlow;
		bool mUseDepthPass;
		bool mUseCullFace;
	};


}

