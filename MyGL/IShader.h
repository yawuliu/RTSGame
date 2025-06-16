#pragma once

#include <string>
#include <MyGL/ITexture2d.h>
#include <MyGL/IUniform4f.h>

namespace MyGL {
	class IUniformSampler;
	class IShader {
	public:
		MyGL::IUniform4f* uniform4f(const char*);
		virtual IUniformSampler* getUniformSamplerByName(const char*) const = 0;
	protected:

	};
}

