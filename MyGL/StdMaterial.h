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

		const IRenderState* renderState();

		void setDepthShader(IShader* sh);

		void setDiffuseTexture(ITexture2d* t);

		void setGlowShader(IShader* sh);

		void setGlowTexture(ITexture2d* sh);

		void setNormalTexture(ITexture2d* sh);

		void setShader(IShader* sh);

		void setShadowShader(IShader* sh);

		void setShadowTexture(ITexture2d* sh);

		void setSpecularTexture(ITexture2d* sh);

		void setUniforms();

		ITechnique* technique();

		void uBind();

		void useCullFace(bool use, IRenderState::CullMode::Type t);

		void useDepthPass(bool use);

		void useGlow(bool use);

		bool useMainTextures();

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

