#pragma once
#include <MyGL/CGL.h>
#include <MyGL/IShader.h>
#include <MyGL/IUniform1f.h>
#include <MyGL/privateGLSupportClass.h>
#include <MyGL/Data.h>


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


