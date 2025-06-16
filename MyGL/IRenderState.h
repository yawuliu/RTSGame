#pragma once

namespace MyGL {
	class IRenderState {
	public:
		enum AlphaBlendMode {
			one
		};
		enum AlphaTestMode {
			Always,
			GEqual,
			Greater
		};
		enum CullMode {
			Cull,
			noCull
		};
		enum ZTestMode {
			Equal,
			Less
		};

		virtual void setBlendMode() = 0;

		virtual void setBlendMode(IRenderState::AlphaBlendMode) = 0;

		virtual void setBlendMode(IRenderState::AlphaBlendMode, IRenderState::AlphaBlendMode) = 0;

		virtual void setBlend(bool) = 0;

		virtual void setAlphaTestMode(IRenderState::AlphaTestMode) = 0;

		virtual void setAlphaCoverage(int) = 0;

		virtual void setZTest(int) = 0;

		virtual void setZTestMode(IRenderState::ZTestMode) = 0;

		virtual void setCullFaceMode(IRenderState::CullMode) = 0;

		virtual void setAlphaTestRef(float) = 0;
	};
}


