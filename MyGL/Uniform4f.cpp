#include "Uniform4f.h"

MyGL::Uniform4f::Uniform4f(MyGL::IShader* sh, MyGL::CGL::ShaderHandle h)
{
	this->handle = h;
	this->shader = sh;
	for (int i = 0; i <= 3; ++i)
		this->dat[i] = 0.0;
}

const void* MyGL::Uniform4f::handlePtr()
{
	return &this->handle;
}

bool MyGL::Uniform4f::isEqual(MyGL::IUniform* u)
{
	__int64 v2;
	MyGL::CGL::ShaderHandle handle;
	bool result;

	v2 = (*(__int64(__fastcall**)(void*))(*(_QWORD*)u + 40LL))(u);
	result = 0;
	if (v2 == (*((__int64(__fastcall**)(MyGL::Uniform4f* const))this->_vptr_IUniform + 5))(this))
	{
		handle = this->handle;
		if (handle == *(_DWORD*)(*(__int64(__fastcall**)(void*))(*(_QWORD*)u + 24LL))(u))
			return 1;
	}
	return result;
}

MyGL::IShader* MyGL::Uniform4f::owner()
{
	return this->shader;
}

void MyGL::Uniform4f::sendDataToGPU()
{
	MyGL::CGL* v1;
	MyGL::privateGLSupportClass* v2;

	v1 = (MyGL::CGL*)(*((__int64(__fastcall**)(MyGL::IShader*))this->shader->_vptr_IShader + 12))(this->shader);
	v2 = MyGL::CGL::ext(v1);
	v2->glUniform4fARB(this->handle, this->dat[0], this->dat[1], this->dat[2], this->dat[3]);
}

void MyGL::Uniform4f::set(MyGL::Color color)
{
	void(__fastcall * v2)(MyGL::Uniform4f*, double, double, double, double);
	const MyGL::Color::ChanelType* v3;
	double v4;
	double v5;
	double v6;
	MyGL::Color colora;
	*(_QWORD*)colora.cdata = *(_QWORD*)color.cdata;
	*(_QWORD*)&colora.cdata[2] = *(_QWORD*)&color.cdata[2];
	v2 = (void(__fastcall*)(MyGL::Uniform4f*, double, double, double, double)) * ((_QWORD*)this->_vptr_IUniform + 8);
	v6 = MyGL::Color::data(&colora)[4];
	v5 = MyGL::Color::data(&colora)[2];
	v4 = MyGL::Color::data(&colora)[1];
	v3 = MyGL::Color::data(&colora);
	v2(this, *v3, v4, v5, v6);
}

void MyGL::Uniform4f::set(const MyGL::Float* data)
{
	(*((void(__fastcall**)(MyGL::Uniform4f* const, const MyGL::Float, const MyGL::Float, const MyGL::Float, const MyGL::Float))this->_vptr_IUniform
		+ 8))(
			this,
			*data,
			data[1],
			data[2],
			data[3]);
}

void MyGL::Uniform4f::set(MyGL::Float x, MyGL::Float y, MyGL::Float z, MyGL::Float w)
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
		(*((void(__fastcall**)(MyGL::IShader*, MyGL::Uniform4f* const))this->shader->_vptr_IShader + 19))(
			this->shader,
			this);
	}
}
