#include "UniformMatrix4x4.h"
#include <cstring>
#include "IShader.h"

 MyGL::UniformMatrix4x4::UniformMatrix4x4(MyGL::IShader* sh, MyGL::CGL::ShaderHandle h)
{
	int i;
	this->handle = h;
	this->shader = sh;
	this->dat = this->data;
	for (i = 0; i <= 15; ++i)
		this->dat[i] = 0.0;
}

 MyGL::UniformMatrix4x4::UniformMatrix4x4(MyGL::IShader* sh, MyGL::CGL::ShaderHandle h, MyGL::CGL::GLfloat* dataPtr)
{
	this->handle = h;
	this->shader = sh;
	this->dat = dataPtr;
	for (int i = 0; i <= 15; ++i)
		this->dat[i] = 0.0;
}

 const void* MyGL::UniformMatrix4x4::handlePtr()
{
	return &this->handle;
}

 bool MyGL::UniformMatrix4x4::isEqual(MyGL::IUniform* u)
{
	__int64 v2;
	MyGL::CGL::ShaderHandle handle;
	bool result;

	v2 = (*(__int64(__fastcall**)(void*))(*(_QWORD*)u + 40LL))(u);
	result = 0;
	if (v2 == (*((__int64(__fastcall**)(MyGL::UniformMatrix4x4* const))this->_vptr_IUniform + 5))(this))
	{
		handle = this->handle;
		if (handle == *(_DWORD*)(*(__int64(__fastcall**)(void*))(*(_QWORD*)u + 24LL))(u))
			return 1;
	}
	return result;
}

 MyGL::IShader* MyGL::UniformMatrix4x4::owner()
{
	return this->shader;
}

 void MyGL::UniformMatrix4x4::sendDataToGPU()
{
	MyGL::CGL* v1;
	MyGL::privateGLSupportClass* v2;

	v1 = (MyGL::CGL*)(*((__int64(__fastcall**)(MyGL::IShader*))this->shader->_vptr_IShader + 12))(this->shader);
	v2 = MyGL::CGL::ext(v1);
	v2->glUniformMatrix4fv(this->handle, 1LL, 0LL, this->dat);
}

 void MyGL::UniformMatrix4x4::set(const MyGL::Float* data)
{
	int i;

	for (i = 0; i <= 15; ++i)
		this->dat[i] = _mm_unpacklo_pd((__m128d) * (unsigned __int64*)&data[i], (__m128d) * (unsigned __int64*)&data[i]).m128d_f64[0];
	(*((void(__fastcall**)(MyGL::IShader*, MyGL::UniformMatrix4x4* const))this->shader->_vptr_IShader + 19))(
		this->shader,
		this);
}
