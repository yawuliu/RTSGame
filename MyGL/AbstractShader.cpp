#include "AbstractShader.h"

namespace MyGL {
	AbstractShader::AbstractShader(IRender* r) : mrender(r) {

	}


	AbstractShader::~AbstractShader()
	{
		IUniform* v1;
		std::vector<IUniform*>::size_type i;
		for (i = 0LL; std::vector<IUniform*>::size(&this->unif) > i; ++i)
		{
			v1 = *std::vector<IUniform*>::operator[](&this->unif, i);
			if (v1)
				(*((void(__fastcall**)(IUniform*))v1->_vptr_IUniform + 1))(v1);
		}
		std::vector<IUniform*>::~vector(&this->unif);
		IShader::~IShader(this);
	}
	CGL* AbstractShader::gl()
	{
		return (CGL*)(*((__int64(__fastcall**)(IRender*))this->mrender->_vptr_IRender + 9))(this->mrender);
	}
	IUniform* AbstractShader::registerUniform(IUniform* u)
	{
		std::vector<IUniform*>* v2;
		std::vector<IUniform*>::reference v3;
		std::vector<IUniform*>* v4;
		std::vector<IUniform*>* v5;
		IUniform* ua;
		AbstractShader* thisa;
		size_t i;
		IUniform* rep;

		thisa = this;
		ua = u;
		rep = 0LL;
		for (i = 0LL; ; ++i)
		{
			v5 = this->uniforms();
			if (std::vector<IUniform*>::size(v5) <= i)
				break;
			v2 = this->uniforms();
			v3 = std::vector<IUniform*>::operator[](v2, i);
			if ((*((unsigned __int8(__fastcall**)(IUniform*, IUniform*))(*v3)->_vptr_IUniform + 4))(*v3, ua))
			{
				v4 = this->uniforms();
				rep = *std::vector<IUniform*>::operator[](v4, i);
			}
		}
		if (rep)
		{
			if (ua)
				(*((void(__fastcall**)(IUniform*))ua->_vptr_IUniform + 1))(ua);
			return rep;
		}
		else
		{
			std::vector<IUniform*>::push_back(&thisa->unif, &ua);
		}
		return ua;
	}

	IRender* AbstractShader::render()
	{
		return this->mrender;
	}

	void AbstractShader::sendUniformsToGPU()
	{
		std::vector<IUniform*>* v1;
		std::vector<IUniform*>::reference v2;
		std::vector<IUniform*>* v3;
		std::vector<IUniform*>::size_type i;

		for (i = 0LL; ; ++i)
		{
			v3 = this->uniforms();
			if (std::vector<IUniform*>::size(v3) <= i)
				break;
			v1 = this->uniforms();
			v2 = std::vector<IUniform*>::operator[](v1, i);
			(*((void(__fastcall**)(IUniform*))(*v2)->_vptr_IUniform + 2))(*v2);
		}
	}



	std::vector<IUniform*>* AbstractShader::uniforms()
	{
		return &this->unif;
	}
	void AbstractShader::updateUniform(IUniform* uniform)
	{
		__int64 v2;

		v2 = (*((__int64(__fastcall**)(AbstractShader* const))this->_vptr_IShader + 13))(this);
		if ((*(unsigned __int8(__fastcall**)(__int64, AbstractShader* const))(*(_QWORD*)v2 + 112LL))(v2, this))
			(*((void(__fastcall**)(IUniform*))uniform->_vptr_IUniform + 2))(uniform);
	}

}