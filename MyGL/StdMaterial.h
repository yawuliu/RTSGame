#pragma once

#include <MyGL/IMaterial.h>

namespace MyGL {
	class IScene;

	class IShader;

	class IRenderState;

	class StdTechnique;

	class ITexture2d;

	class StdMaterial : public IMaterial {
	public:
		StdMaterial(IScene*);

		StdMaterial(IScene*, StdTechnique*);

		void setShader(IShader*) override;

		void setShadowShader(IShader*)  override;

		void setDepthShader(IShader*) override;

		void setGlowShader(IShader*) override;

		void setShadowTexture(ITexture2d*) override;

		void setDiffuseTexture(ITexture2d*) override;

		void setSpecularTexture(ITexture2d*) override;

		void setNormalTexture(ITexture2d*) override;

		void setGlowTexture(ITexture2d*) override;

		void useGlow(ITexture2d*) override;

		void useGlow(int) override;

		void useDepthPass(bool) override;

		void useCullFace(bool) override;

		IRenderState* renderState() const override;

	protected:
		IScene* mScene;
		IShader* mShader;
		IShader* mShadowShader;
		IShader* mDepthShader;
		IShader* mGlowShader;
		ITexture2d* mTexture;
		ITexture2d* mShadowTexture;
		ITexture2d* mDiffuseTexture;
		ITexture2d* mSpecularTexture;
		ITexture2d* mNormalTexture;
		ITexture2d* mGlowTexture;
		IRenderState* mState;
		StdTechnique* mTechnique;
		bool mUseGlow;
		bool mUseDepthPass;
		bool mUseCullFace;
	};


}

