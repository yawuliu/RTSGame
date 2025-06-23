#pragma once

#include <iostream>
#include "IRender.h"
#include "IShaderLoader.h"

namespace MyGL {
	class IShaderEnvironment;

	class ShaderLoader : public IShaderLoader {
	public:
		ShaderLoader(IRender& r);

		virtual ~ShaderLoader() = default;

		IShaderEnvironment* enviroment();

		IShader* load(IShader& taget, const char* vs, const char* fs_0, bool* ok);

		void setEnvironment(IShaderEnvironment* env);

		char* srcFrom(const char* file, bool* ok);

	protected:
		IRender& render;
		IShaderEnvironment* shEnv;
	};
}

