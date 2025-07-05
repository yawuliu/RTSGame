#include "Uniform4f.h"
namespace MyGL {
	Uniform4f::Uniform4f(IShader* sh, CGL::ShaderHandle h)
	{
		this->handle = h;
		this->shader = sh;
		for (int i = 0; i <= 3; ++i)
			this->dat[i] = 0.0;
	}

    CGL::ShaderHandle * Uniform4f::handlePtr()
	{
		return &this->handle;
	}

	bool Uniform4f::isEqual(IUniform* u)
	{
        if (u->owner() == this->owner()) {
            if (this->handle == *u->handlePtr())
                return 1;
        }
        return 0;
	}

	IShader* Uniform4f::owner()
	{
		return this->shader;
	}

	void Uniform4f::sendDataToGPU()
	{
        this->shader->gl()->ext()->glUniform4fARB(this->handle, this->dat[0], this->dat[1], this->dat[2], this->dat[3]);
	}

	void Uniform4f::set(Color color)
	{
		Color colora;
		*(_QWORD*)colora.cdata = *(_QWORD*)color.cdata;
		*(_QWORD*)&colora.cdata[2] = *(_QWORD*)&color.cdata[2];
		this->set(colora.data()[0], colora.data()[1], colora.data()[2], colora.data()[4]);
	}

	void Uniform4f::set(const Float* data)
	{
		this->set(*data,data[1],data[2],data[3]);
	}

	void Uniform4f::set(Float x, Float y, Float z, Float w)
	{
		if (this->dat[0] != x || this->dat[1] != y || this->dat[2] != z || this->dat[3] != w)
		{
			this->dat[0] = x;
			this->dat[1] = y;
			this->dat[2] = z;
			this->dat[3] = w;
			this->shader->updateUniform(
				this);
		}
	}
}