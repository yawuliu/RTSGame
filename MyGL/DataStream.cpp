#include "DataStream.h"

MyGL::DataStream::DataStream(MyGL::IData* const d, MyGL::IShaderEnvironment* e)
{
	this->data = d;
	this->env = e;
}

MyGL::DataStream::DataStream(MyGL::IData* d, MyGL::IShaderEnvironment* e)
{
	this->data = d;
	this->env = e;
}

MyGL::DataStream::DataStream(MyGL::IScene* s)
{
	__int64 v2;

	this->data = (MyGL::IData*)(*((__int64(__fastcall**)(MyGL::IScene*))s->_vptr_IScene + 2))(s);
	v2 = (*((__int64(__fastcall**)(MyGL::IScene*))s->_vptr_IScene + 6))(s);
	this->env = (MyGL::IShaderEnvironment*)(*(__int64(__fastcall**)(__int64))(*(_QWORD*)v2 + 32LL))(v2);
}

void* MyGL::DataStream::add(MyGL::IModel* model, const std::string& name)
{
	void(__fastcall * v3)(MyGL::IData*, __int64, MyGL::IModel*);
	__int64 v4;

	v3 = (void(__fastcall*)(MyGL::IData*, __int64, MyGL::IModel*)) * ((_QWORD*)this->data->_vptr_IData + 8);
	v4 = std::string::data((std::string&)name);
	v3(this->data, v4, model);
	return this;
}

void* MyGL::DataStream::add(MyGL::IShader* sh, const std::string& name)
{
	void(__fastcall * v3)(MyGL::IData*, __int64, MyGL::IShader*);
	__int64 v4;

	v3 = (void(__fastcall*)(MyGL::IData*, __int64, MyGL::IShader*)) * ((_QWORD*)this->data->_vptr_IData + 13);
	v4 = std::string::data((std::string&)name);
	v3(this->data, v4, sh);
	return this;
}

void* MyGL::DataStream::add(MyGL::ITexture2d* texture, const std::string& name)
{
	void(__fastcall * v3)(MyGL::IData*, __int64, MyGL::ITexture2d*);
	__int64 v4;

	v3 = (void(__fastcall*)(MyGL::IData*, __int64, MyGL::ITexture2d*)) * ((_QWORD*)this->data->_vptr_IData + 4);
	v4 = std::string::data((std::string&)name);
	v3(this->data, v4, texture);
	return this;
}

void* MyGL::DataStream::addModel(const std::string& name, const std::string& file)
{
	void(__fastcall * v3)(MyGL::IData*, __int64, __int64);
	__int64 v4;
	__int64 v5;

	v3 = (void(__fastcall*)(MyGL::IData*, __int64, __int64)) * ((_QWORD*)this->data->_vptr_IData + 9);
	v4 = std::string::data((std::string&)file);
	v5 = std::string::data((std::string&)name);
	v3(this->data, v5, v4);
	return this;
}

void* MyGL::DataStream::addModelBin_v0(const std::string& name, const std::string& file)
{
	void(__fastcall * v3)(MyGL::IData*, __int64, __int64);
	__int64 v4;
	__int64 v5;

	v3 = (void(__fastcall*)(MyGL::IData*, __int64, __int64)) * ((_QWORD*)this->data->_vptr_IData + 10);
	v4 = std::string::data((std::string&)file);
	v5 = std::string::data((std::string&)name);
	v3(this->data, v5, v4);
	return this;
}

void* MyGL::DataStream::addShader(const std::string& name, const std::string& vs, const std::string& fs_0)
{
	void(__fastcall * v4)(MyGL::IData*, __int64, __int64, __int64, __int64);
	__int64 v5;
	__int64 v6;
	__int64 v7;

	v4 = (void(__fastcall*)(MyGL::IData*, __int64, __int64, __int64, __int64)) * ((_QWORD*)this->data->_vptr_IData + 14);
	v5 = std::string::data((std::string&)fs_0);
	v6 = std::string::data((std::string&)vs);
	v7 = std::string::data((std::string&)name);
	v4(this->data, v7, v6, v5, 1LL);
	return this;
}

void* MyGL::DataStream::addTexture(const std::string& name, const std::string& file)
{
	void(__fastcall * v3)(MyGL::IData*, __int64, __int64);
	__int64 v4;
	__int64 v5;

	v3 = (void(__fastcall*)(MyGL::IData*, __int64, __int64)) * ((_QWORD*)this->data->_vptr_IData + 5);
	v4 = std::string::data((std::string&)file);
	v5 = std::string::data((std::string&)name);
	v3(this->data, v5, v4);
	return this;
}

void MyGL::DataStream::popShaderDef(const std::string& name)
{
	(*((void(__fastcall**)(MyGL::IShaderEnvironment*, const std::string&))this->env->_vptr_IShaderEnvironment + 6))(
		this->env,
		name);
}

void MyGL::DataStream::pushShaderDef(const std::string& name)
{
	std::string val;
	_BYTE v3[17];

	std::allocator<char>::allocator(v3);
	std::string::string(&val, &unk_4D39E1, v3);
	MyGL::DataStream::pushShaderDef(this, name, &val);
	std::string::~string(&val);
	std::allocator<char>::~allocator(v3);
}

void MyGL::DataStream::pushShaderDef(const std::string& name, const std::string& val)
{
	(*((void(__fastcall**)(MyGL::IShaderEnvironment*, const std::string&, const std::string&))this->env->_vptr_IShaderEnvironment
		+ 5))(
			this->env,
			name,
			val);
}

MyGL::DataStream::DataStream(MyGL::IScene* const s)
{
	__int64 v2;

	this->data = (MyGL::IData*)(*((__int64(__fastcall**)(MyGL::IScene* const))s->_vptr_IScene + 2))(s);
	v2 = (*((__int64(__fastcall**)(MyGL::IScene* const))s->_vptr_IScene + 6))(s);
	this->env = (MyGL::IShaderEnvironment*)(*(__int64(__fastcall**)(__int64))(*(_QWORD*)v2 + 32LL))(v2);
}
