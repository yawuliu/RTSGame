#pragma once

namespace MyGL {
	class IShader;

	class ITexture2d;

	class IRenderState;

	class IMaterial {
	public:
		virtual void setShader(IShader*) = 0;

		virtual void setShadowShader(IShader*) = 0;

		virtual void setDepthShader(IShader*) = 0;

		virtual void setGlowShader(IShader*) = 0;

		virtual void setShadowTexture(ITexture2d*) = 0;

		virtual void setDiffuseTexture(ITexture2d*) = 0;

		virtual void setSpecularTexture(ITexture2d*) = 0;

		virtual void setNormalTexture(ITexture2d*) = 0;

		virtual void setGlowTexture(ITexture2d*) = 0;

		virtual void useGlow(ITexture2d*) = 0;

		virtual void useGlow(int) = 0;

		virtual void useDepthPass(bool) = 0;

		virtual void useCullFace(bool) = 0;

		virtual IRenderState* renderState() const = 0;
	};
}