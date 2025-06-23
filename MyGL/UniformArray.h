#pragma once
#include <algorithm>
#include <stdexcept>
#include "CGL.h"
#include "IShader.h"
#include "UniformMatrix4x4.h"
#include "AbstractShader.h"
#include "IUniformArray.h"


namespace MyGL {
	template<typename T>
	class UniformArray :public IUniformArray<T> {
	public:
		class Data {
		public:
			Data(IShader* sh, CGL::ShaderHandle _handle, int s);
			virtual ~Data();
		protected:
			CGL::GLfloat* data;
			std::vector<UniformMatrix4x4*> uniform;
			CGL::ShaderHandle handle;
			int size;
		};
	public:
		UniformArray(IShader* sh, CGL::ShaderHandle handle, int s)
		{
			this->shader = sh;
			this->data = new Data::Data(sh, handle, s);
			this->data->handle = handle;
		}
		virtual ~UniformArray()
		{
			if (this->data)
			{
				delete this->data;
			}
		}
		IUniformMatrix4x4* at(int id)
		{
			return *std::vector<UniformMatrix4x4*>::operator[](&this->data->uniform, id);
		}
		const void* handlePtr()
		{
			return &this->data->handle;
		}
		bool isEqual(IUniform* u)
		{
			__int64 v2;
			CGL::ShaderHandle handle;
			bool result;

			v2 = (*(__int64(__fastcall**)(void*))(*(_QWORD*)u + 40LL))(u);
			result = 0;
			if (v2 == (*((__int64(__fastcall**)(UniformArray<IUniformMatrix4x4> *const))this->_vptr_IUniform + 5))(this))
			{
				handle = this->data->handle;
				if (handle == *(_DWORD*)(*(__int64(__fastcall**)(void*))(*(_QWORD*)u + 24LL))(u))
					return 1;
			}
			return result;
		}
		IUniformMatrix4x4* operator[](int id)
		{
			return (IUniformMatrix4x4*)(*((__int64(__fastcall**)(UniformArray<IUniformMatrix4x4> *const, _QWORD))this->_vptr_IUniform
				+ 6))(
					this,
					(unsigned int)id);
		}
		IShader* owner()
		{
			return this->shader;
		}
		void sendDataToGPU()
		{
			CGL* v1;
			PFNGLUNIFORMMATRIX4FVARBPROC glUniformMatrix4fv;
			CGL::GLfloat* data;
			GLsizei v4;

			v1 = (CGL*)(*((__int64(__fastcall**)(IShader*))this->shader->_vptr_IShader + 12))(this->shader);
			glUniformMatrix4fv = CGL::ext(v1)->glUniformMatrix4fv;
			data = this->data->data;
			v4 = (*((__int64(__fastcall**)(UniformArray<IUniformMatrix4x4> *const))this->_vptr_IUniform + 8))(this);
			glUniformMatrix4fv(this->data->handle, v4, 0LL, data);
		}
		int size()
		{
			return this->data->size;
		}
	private:
		UniformArray<T>::Data* data;
		IShader* shader;
	};
	template<class T>
	UniformArray<T>* uniformArray(AbstractShader* const sh, int location, int s)
	{
		UniformArray<T>* u;

		if (location < 0)
			return 0LL;
		u = (UniformArray<T> *)operator new(0x18uLL);
		UniformArray<T>::UniformArray(u, sh, location, s);
		return (UniformArray<T> *)AbstractShader::registerUniform(sh, u);
	}
	template<typename T>
	 UniformArray<T>::Data::Data(IShader* sh, CGL::ShaderHandle _handle, int s)
	{
		this->size = s;
		this->data = new CGL::GLfloat[64LL * s];
		this->handle = _handle;
		for (int i = 0; i < s; ++i)
		{
			auto x = new UniformMatrix4x4::UniformMatrix4x4(sh, this->handle, &this->data[16 * (int64_t)i]);
			this->uniform.push_back(x);
		}
	}
	template<typename T>
	 UniformArray<T>::Data::~Data()
	{
		for (int i = 0; this->size > i; ++i)
		{
			auto v1 = this->uniform[i];
			if (v1)
				(*((void(__fastcall**)(UniformMatrix4x4*))v1->_vptr_IUniform + 1))(v1);
		}
		delete this->data;
	}
}
