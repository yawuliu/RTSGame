#include "UniformSampler.h"
#include "IUniform.h"
#include "privateGLSupportClass.h"
#include "IShader.h"

MyGL::UniformSampler::UniformSampler(MyGL::IShader* sh, MyGL::CGL::ShaderHandle h)
{
	this->handle = h;
	this->shader = sh;
	this->dat = 0;
}

int MyGL::UniformSampler::get()
{
	return this->dat;
}

const void* MyGL::UniformSampler::handlePtr()
{
	return &this->handle;
}

bool MyGL::UniformSampler::isEqual(MyGL::IUniform* u)
{
	__int64 v2;
	MyGL::CGL::ShaderHandle handle;
	bool result;

	v2 = (*(__int64(__fastcall**)(void*))(*(_QWORD*)u + 40LL))(u);
	result = 0;
	if (v2 == (*((__int64(__fastcall**)(MyGL::UniformSampler* const))this->_vptr_IUniform + 5))(this))
	{
		handle = this->handle;
		if (handle == *(_DWORD*)(*(__int64(__fastcall**)(void*))(*(_QWORD*)u + 24LL))(u))
			return 1;
	}
	return result;
}

MyGL::IShader* MyGL::UniformSampler::owner()
{
	return this->shader;
}

void MyGL::UniformSampler::sendDataToGPU()
{
	MyGL::CGL* v1;
	MyGL::privateGLSupportClass* v2;

	v1 = (MyGL::CGL*)(*((__int64(__fastcall**)(MyGL::IShader*))this->shader->_vptr_IShader + 12))(this->shader);
	v2 = MyGL::CGL::ext(v1);
	v2->glUniform1iARB(this->handle, this->dat);
}

void MyGL::UniformSampler::set(int x)
{
	if (this->dat != x)
	{
		this->dat = x;
		(*((void(__fastcall**)(MyGL::IShader*, MyGL::UniformSampler* const))this->shader->_vptr_IShader + 19))(
			this->shader,
			this);
	}
}
