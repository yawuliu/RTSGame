#include "Uniform1f.h"
namespace MyGL {
	Uniform1f::Uniform1f(IShader* sh, CGL::ShaderHandle h)
	{
		this->handle = h;
		this->shader = sh;
		this->dat = 0.0;
	}

	const void* Uniform1f::handlePtr()
	{
		return &this->handle;
	}

	bool Uniform1f::isEqual(IUniform* u)
	{
		__int64 v2;
		CGL::ShaderHandle handle;
		bool result;

		v2 = (*(__int64(__fastcall**)(void*))(*(_QWORD*)u + 40LL))(u);
		result = 0;
		if (v2 == (*((__int64(__fastcall**)(Uniform1f* const))this->_vptr_IUniform + 5))(this))
		{
			handle = this->handle;
			if (handle == *(_DWORD*)(*(__int64(__fastcall**)(void*))(*(_QWORD*)u + 24LL))(u))
				return 1;
		}
		return result;
	}

	IShader* Uniform1f::owner()
	{
		return this->shader;
	}

	void Uniform1f::sendDataToGPU()
	{
		CGL* v1;
		privateGLSupportClass* v2;

		v1 = (CGL*)(*((__int64(__fastcall**)(IShader*))this->shader->_vptr_IShader + 12))(this->shader);
		v2 = CGL::ext(v1);
		v2->glUniform1fARB(this->handle, this->dat);
	}

	void Uniform1f::set(Float x)
	{
		if (this->dat != x)
		{
			this->dat = x;
			(*((void(__fastcall**)(IShader*, Uniform1f* const))this->shader->_vptr_IShader + 19))(
				this->shader,
				this);
		}
	}
}