#include "Uniform4f.h"
namespace MyGL {
	Uniform4f::Uniform4f(IShader* sh, CGL::ShaderHandle h)
	{
		this->handle = h;
		this->shader = sh;
		for (int i = 0; i <= 3; ++i)
			this->dat[i] = 0.0;
	}

	const void* Uniform4f::handlePtr()
	{
		return &this->handle;
	}

	bool Uniform4f::isEqual(IUniform* u)
	{
		__int64 v2;
		CGL::ShaderHandle handle;
		bool result;

		v2 = (*(__int64(__fastcall**)(void*))(*(_QWORD*)u + 40LL))(u);
		result = 0;
		if (v2 == (*((__int64(__fastcall**)(Uniform4f* const))this->_vptr_IUniform + 5))(this))
		{
			handle = this->handle;
			if (handle == *(_DWORD*)(*(__int64(__fastcall**)(void*))(*(_QWORD*)u + 24LL))(u))
				return 1;
		}
		return result;
	}

	IShader* Uniform4f::owner()
	{
		return this->shader;
	}

	void Uniform4f::sendDataToGPU()
	{
		CGL* v1;
		privateGLSupportClass* v2;

		v1 = (CGL*)(*((__int64(__fastcall**)(IShader*))this->shader->_vptr_IShader + 12))(this->shader);
		v2 = CGL::ext(v1);
		v2->glUniform4fARB(this->handle, this->dat[0], this->dat[1], this->dat[2], this->dat[3]);
	}

	void Uniform4f::set(Color color)
	{
		void(__fastcall * v2)(Uniform4f*, double, double, double, double);
		const Color::ChanelType* v3;
		double v4;
		double v5;
		double v6;
		Color colora;
		*(_QWORD*)colora.cdata = *(_QWORD*)color.cdata;
		*(_QWORD*)&colora.cdata[2] = *(_QWORD*)&color.cdata[2];
		v2 = (void(__fastcall*)(Uniform4f*, double, double, double, double)) * ((_QWORD*)this->_vptr_IUniform + 8);
		v6 = Color::data(&colora)[4];
		v5 = Color::data(&colora)[2];
		v4 = Color::data(&colora)[1];
		v3 = Color::data(&colora);
		v2(this, *v3, v4, v5, v6);
	}

	void Uniform4f::set(const Float* data)
	{
		(*((void(__fastcall**)(Uniform4f* const, const Float, const Float, const Float, const Float))this->_vptr_IUniform
			+ 8))(
				this,
				*data,
				data[1],
				data[2],
				data[3]);
	}

	void Uniform4f::set(Float x, Float y, Float z, Float w)
	{
		float x_1;
		float y_1;
		float z_1;

		if (this->dat[0] != x || this->dat[1] != y || this->dat[2] != z || this->dat[3] != w)
		{
			x_1 = x;
			this->dat[0] = x_1;
			y_1 = y;
			this->dat[1] = y_1;
			z_1 = z;
			this->dat[2] = z_1;
			this->dat[3] = w;
			(*((void(__fastcall**)(IShader*, Uniform4f* const))this->shader->_vptr_IShader + 19))(
				this->shader,
				this);
		}
	}
}