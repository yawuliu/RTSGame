#pragma once
#include "CGL.h"
#include "IShader.h"
#include "IUniform1f.h"
#include "privateGLSupportClass.h"
#include "Data.h"


namespace MyGL {
	class IUniform;
	class Uniform1f : public IUniform1f {
	public:
		Uniform1f(IShader* sh, CGL::ShaderHandle h);
		virtual ~Uniform1f() = default;
		const void* handlePtr();
		bool isEqual(IUniform* u);
		IShader* owner();
		void sendDataToGPU();
		void set(Float x);
	private:
		CGL::ShaderHandle handle;
		IShader* shader;
		double dat;
	};
}


