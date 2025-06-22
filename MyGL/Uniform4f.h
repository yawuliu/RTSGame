#pragma once

#include <MyGL/IShader.h>
#include <MyGL/CGL.h>
#include <MyGL/IUniform4f.h>
#include <MyGL/Color.h>
#include "Data.h"

namespace MyGL {
	class IUniform;
	class Uniform4f : public IUniform4f {
	public:
		Uniform4f(IShader* sh, CGL::ShaderHandle h);
		virtual ~Uniform4f() = default;
		const void* handlePtr();
		bool isEqual(IUniform* u);
		IShader* owner();
		void sendDataToGPU();
		void set(Color color);
		void set(const Float* data);
		void set(Float x, Float y, Float z, Float w);
	private:
		CGL::ShaderHandle handle;
		IShader* shader;
		int dat[4];
	};
}


