#pragma once

#include "IUniformSampler.h"
#include "CGL.h"
namespace MyGL {
	class IUniform;
	class IShader;
	class UniformSampler : public IUniformSampler {
	public:
		UniformSampler(IShader* sh, CGL::ShaderHandle h);
		virtual ~UniformSampler() = default;

		int get();
		const void* handlePtr();
		bool isEqual(IUniform* u);
		IShader* owner();
		void sendDataToGPU();
		void set(int x);
	protected:
		CGL::ShaderHandle handle;
		IShader* shader;
		int dat;
	};
}



