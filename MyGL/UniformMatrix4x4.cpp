#include "UniformMatrix4x4.h"
#include <cstring>
#include "IShader.h"
namespace MyGL {
	UniformMatrix4x4::UniformMatrix4x4(IShader* sh, CGL::ShaderHandle h)
	{
		int i;
		this->handle = h;
		this->shader = sh;
		this->dat = this->data;
		for (i = 0; i <= 15; ++i)
			this->dat[i] = 0.0;
	}

	UniformMatrix4x4::UniformMatrix4x4(IShader* sh, CGL::ShaderHandle h, CGL::GLfloat* dataPtr)
	{
		this->handle = h;
		this->shader = sh;
		this->dat = dataPtr;
		for (int i = 0; i <= 15; ++i)
			this->dat[i] = 0.0;
	}

	const void* UniformMatrix4x4::handlePtr()
	{
		return &this->handle;
	}

	bool UniformMatrix4x4::isEqual(IUniform* u)
	{
		__int64 v2;
		CGL::ShaderHandle handle;
		bool result;

		v2 = (*(__int64(__fastcall**)(void*))(*(_QWORD*)u + 40LL))(u);
		result = 0;
		if (v2 == this->owner())
		{
			handle = this->handle;
			if (handle == *(_DWORD*)(*(__int64(__fastcall**)(void*))(*(_QWORD*)u + 24LL))(u))
				return 1;
		}
		return result;
	}

	IShader* UniformMatrix4x4::owner()
	{
		return this->shader;
	}

	void UniformMatrix4x4::sendDataToGPU()
	{
		CGL* v1;
		privateGLSupportClass* v2;

		v1 = this->shader->gl();
		v2 = v1->ext();
		v2->glUniformMatrix4fv(this->handle, 1LL, 0LL, this->dat);
	}

	void UniformMatrix4x4::set(const Float* data)
	{
		int i;

		for (i = 0; i <= 15; ++i)
			this->dat[i] = _mm_unpacklo_pd((__m128d) * (unsigned __int64*)&data[i], (__m128d) * (unsigned __int64*)&data[i]).m128d_f64[0];

		this->shader->updateUniform(
			this);
	}
}
