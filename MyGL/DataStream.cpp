#include "DataStream.h"
namespace MyGL {
	DataStream::DataStream(IData* const d, IShaderEnvironment* e)
	{
		this->data = d;
		this->env = e;
	}

	DataStream::DataStream(IData* d, IShaderEnvironment* e)
	{
		this->data = d;
		this->env = e;
	}

	DataStream::DataStream(IScene* s)
	{
		__int64 v2;

		this->data = (IData*)(*((__int64(__fastcall**)(IScene*))s->_vptr_IScene + 2))(s);
		v2 = (*((__int64(__fastcall**)(IScene*))s->_vptr_IScene + 6))(s);
		this->env = (IShaderEnvironment*)(*(__int64(__fastcall**)(__int64))(*(_QWORD*)v2 + 32LL))(v2);
	}

	void* DataStream::add(IModel* model, const std::string& name)
	{
		void(__fastcall * v3)(IData*, __int64, IModel*);
		__int64 v4;

		v3 = (void(__fastcall*)(IData*, __int64, IModel*)) * ((_QWORD*)this->data->_vptr_IData + 8);
		v4 = std::string::data((std::string&)name);
		v3(this->data, v4, model);
		return this;
	}

	void* DataStream::add(IShader* sh, const std::string& name)
	{
		void(__fastcall * v3)(IData*, __int64, IShader*);
		__int64 v4;

		v3 = (void(__fastcall*)(IData*, __int64, IShader*)) * ((_QWORD*)this->data->_vptr_IData + 13);
		v4 = std::string::data((std::string&)name);
		v3(this->data, v4, sh);
		return this;
	}

	void* DataStream::add(ITexture2d* texture, const std::string& name)
	{
		void(__fastcall * v3)(IData*, __int64, ITexture2d*);
		__int64 v4;

		v3 = (void(__fastcall*)(IData*, __int64, ITexture2d*)) * ((_QWORD*)this->data->_vptr_IData + 4);
		v4 = std::string::data((std::string&)name);
		v3(this->data, v4, texture);
		return this;
	}

	void* DataStream::addModel(const std::string& name, const std::string& file)
	{
		void(__fastcall * v3)(IData*, __int64, __int64);
		__int64 v4;
		__int64 v5;

		v3 = (void(__fastcall*)(IData*, __int64, __int64)) * ((_QWORD*)this->data->_vptr_IData + 9);
		v4 = std::string::data((std::string&)file);
		v5 = std::string::data((std::string&)name);
		v3(this->data, v5, v4);
		return this;
	}

	void* DataStream::addModelBin_v0(const std::string& name, const std::string& file)
	{
		void(__fastcall * v3)(IData*, __int64, __int64);
		__int64 v4;
		__int64 v5;

		v3 = (void(__fastcall*)(IData*, __int64, __int64)) * ((_QWORD*)this->data->_vptr_IData + 10);
		v4 = std::string::data((std::string&)file);
		v5 = std::string::data((std::string&)name);
		v3(this->data, v5, v4);
		return this;
	}

	void* DataStream::addShader(const std::string& name, const std::string& vs, const std::string& fs_0)
	{
		void(__fastcall * v4)(IData*, __int64, __int64, __int64, __int64);
		__int64 v5;
		__int64 v6;
		__int64 v7;

		v4 = (void(__fastcall*)(IData*, __int64, __int64, __int64, __int64)) * ((_QWORD*)this->data->_vptr_IData + 14);
		v5 = std::string::data((std::string&)fs_0);
		v6 = std::string::data((std::string&)vs);
		v7 = std::string::data((std::string&)name);
		v4(this->data, v7, v6, v5, 1LL);
		return this;
	}

	void* DataStream::addTexture(const std::string& name, const std::string& file)
	{
		void(__fastcall * v3)(IData*, __int64, __int64);
		__int64 v4;
		__int64 v5;

		v3 = (void(__fastcall*)(IData*, __int64, __int64)) * ((_QWORD*)this->data->_vptr_IData + 5);
		v4 = std::string::data((std::string&)file);
		v5 = std::string::data((std::string&)name);
		v3(this->data, v5, v4);
		return this;
	}

	void DataStream::popShaderDef(const std::string& name)
	{
		(*((void(__fastcall**)(IShaderEnvironment*, const std::string&))this->env->_vptr_IShaderEnvironment + 6))(
			this->env,
			name);
	}

	void DataStream::pushShaderDef(const std::string& name)
	{
		std::string val;
		_BYTE v3[17];

		std::allocator<char>::allocator(v3);
		std::string::string(&val, &unk_4D39E1, v3);
		DataStream::pushShaderDef(this, name, &val);
		std::string::~string(&val);
		std::allocator<char>::~allocator(v3);
	}

	void DataStream::pushShaderDef(const std::string& name, const std::string& val)
	{
		(*((void(__fastcall**)(IShaderEnvironment*, const std::string&, const std::string&))this->env->_vptr_IShaderEnvironment
			+ 5))(
				this->env,
				name,
				val);
	}

	DataStream::DataStream(IScene* const s)
	{
		__int64 v2;

		this->data = (IData*)(*((__int64(__fastcall**)(IScene* const))s->_vptr_IScene + 2))(s);
		v2 = (*((__int64(__fastcall**)(IScene* const))s->_vptr_IScene + 6))(s);
		this->env = (IShaderEnvironment*)(*(__int64(__fastcall**)(__int64))(*(_QWORD*)v2 + 32LL))(v2);
	}
}