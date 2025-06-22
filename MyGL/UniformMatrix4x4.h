#pragma once

#include "IUniformMatrix4x4.h"
#include <MyGL/CGL.h>

namespace MyGL {
	class UniformMatrix4x4 : public IUniformMatrix4x4 {
	public:
		UniformMatrix4x4(MyGL::IShader* sh, MyGL::CGL::ShaderHandle h);
		UniformMatrix4x4(MyGL::IShader* sh, MyGL::CGL::ShaderHandle h, MyGL::CGL::GLfloat* dataPtr);
		virtual ~UniformMatrix4x4() = default;
		const void* handlePtr();
		bool isEqual(MyGL::IUniform* u);
		MyGL::IShader* owner();
		void sendDataToGPU();
		void set(const MyGL::Float* data);
	protected:
		MyGL::CGL::ShaderHandle handle;
		MyGL::IShader* shader;
		int dat;
	};
}

