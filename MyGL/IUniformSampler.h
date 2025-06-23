#pragma once

#include "IUniform.h"

namespace MyGL {
	class ITexture2d;

	class IUniformSampler : public IUniform {
	public:
		IUniformSampler() = default;

		virtual ~IUniformSampler() = default;
	};
}
