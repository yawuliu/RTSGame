#include "UniformSampler.h"
#include "IUniform.h"
#include "privateGLSupportClass.h"
#include "IShader.h"
namespace MyGL {
	UniformSampler::UniformSampler(IShader* sh, CGL::ShaderHandle h)
	{
		this->handle = h;
		this->shader = sh;
		this->dat = 0;
	}

	int UniformSampler::get()
	{
		return this->dat;
	}

	 CGL::ShaderHandle * UniformSampler::handlePtr()
	{
		return &this->handle;
	}

	bool UniformSampler::isEqual(IUniform* u)
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

	IShader* UniformSampler::owner()
	{
		return this->shader;
	}

	void UniformSampler::sendDataToGPU()
	{
        this->shader->gl()->ext()->glUniform1iARB(this->handle, this->dat);
	}

	void UniformSampler::set(int x)
	{
		if (this->dat != x)
		{
			this->dat = x;
			this->shader->updateUniform(this);
		}
	}
}