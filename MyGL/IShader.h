#pragma once

#include <string>
#include "DisableCopy.h"
#include "ITexture2d.h"
#include "IUniform4f.h"
#include "IUniformSampler.h"

namespace MyGL {
	class IUniformSampler;

	class IShader : public DisableCopy {
	public:
		IShader() = default;

		virtual ~IShader() = default;

		IUniform4f* uniform4f(const char*);

		virtual IUniformSampler* getUniformSamplerByName(const char*) const = 0;

	protected:

	};
}

