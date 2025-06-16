#pragma once

#include <MyGL/IUniformSampler.h>

namespace MyGL {
	class UniformSampler : public IUniformSampler {
	public:
		UniformSampler();

		// Í¨¹ý IUniformSampler ¼Ì³Ð
		void Bind(int textureUnit) override;
		void Unbind() override;
		const char* GetName() const override;
		void setTexture(ITexture2d*) override;
	};
}



