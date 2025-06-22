#include "DataLoader.h"

MyGL::DataLoader::DataLoader(const MyGL::IRender& r)
{
	Allocator<MyGL::Texture2d, MyGL::ITexture2d>* textureAllocator;
	Allocator<MyGL::Model, MyGL::IModel>* modelAllocator;
	this->render = r;
	textureAllocator = (Allocator<MyGL::Texture2d, MyGL::ITexture2d> *)operator new(8uLL);
	textureAllocator->_vptr_IAllocator = 0LL;
	MyGL::DataLoader::Allocator<MyGL::Texture2d, MyGL::ITexture2d>::Allocator(textureAllocator);
	this->textureAllocator = textureAllocator;
	this->textureLoad = 0LL;
	modelAllocator = (Allocator<MyGL::Model, MyGL::IModel> *)operator new(8uLL);
	modelAllocator->_vptr_IAllocator = 0LL;
	MyGL::DataLoader::Allocator<MyGL::Model, MyGL::IModel>::Allocator(modelAllocator);
	this->modelAllocator = modelAllocator;
	this->modelLoad = 0LL;
	this->shaderAllocator = 0LL;
	this->shaderLoad = 0LL;
}

MyGL::DataLoader::~DataLoader()
{
	this->setTextureAllocator(0LL);
	this->setModelAllocator(0LL);
	this->setShaderAllocator(0LL);

}

MyGL::IModel* MyGL::DataLoader::loadModel(MyGL::IModel* t, const char* file)
{
	if (this->modelLoad)
		(*((void(__fastcall**)(MyGL::IModelLoader*, MyGL::IModel*, const char*, _QWORD))this->modelLoad->_vptr_IModelLoader
			+ 2))(
				this->modelLoad,
				t,
				file,
				0LL);
	return t;
}

MyGL::IModel* MyGL::DataLoader::loadModel(const char* file)
{
	__int64 v2;

	v2 = (*((__int64(__fastcall**)(MyGL::IDataLoader::IAllocator<MyGL::IModel> *, MyGL::IRender* const))this->modelAllocator->_vptr_IAllocator
		+ 2))(
			this->modelAllocator,
			this->render);
	return (MyGL::IModel*)(*((__int64(__fastcall**)(MyGL::DataLoader* const, __int64, const char*))this->_vptr_IDataLoader
		+ 11))(
			this,
			v2,
			file);
}

MyGL::IModel* MyGL::DataLoader::loadModelBin_v0(MyGL::IModel* t, const char* file)
{
	if (this->modelLoad)
		(*((void(__fastcall**)(MyGL::IModelLoader*, MyGL::IModel*, const char*, _QWORD))this->modelLoad->_vptr_IModelLoader
			+ 3))(
				this->modelLoad,
				t,
				file,
				0LL);
	return t;
}

MyGL::IModel* MyGL::DataLoader::loadModelBin_v0(const char* file)
{
	__int64 v2;

	v2 = (*((__int64(__fastcall**)(MyGL::IDataLoader::IAllocator<MyGL::IModel> *, MyGL::IRender* const))this->modelAllocator->_vptr_IAllocator
		+ 2))(
			this->modelAllocator,
			this->render);
	return (MyGL::IModel*)(*((__int64(__fastcall**)(MyGL::DataLoader* const, __int64, const char*))this->_vptr_IDataLoader
		+ 13))(
			this,
			v2,
			file);
}

MyGL::IShader* MyGL::DataLoader::loadShader(MyGL::IShader* t, const char* vs, const char* fs_0)
{
	if (this->shaderLoad)
		(*((void(__fastcall**)(MyGL::IShaderLoader*, MyGL::IShader*, const char*, const char*, _QWORD))this->shaderLoad->_vptr_IShaderLoader
			+ 2))(
				this->shaderLoad,
				t,
				vs,
				fs_0,
				0LL);
	return t;
}

MyGL::IShader* MyGL::DataLoader::loadShader(const char* vs, const char* fs_0)
{
	__int64 v3;

	v3 = (*((__int64(__fastcall**)(MyGL::IDataLoader::IAllocator<MyGL::IShader> *, MyGL::IRender* const))this->shaderAllocator->_vptr_IAllocator
		+ 2))(
			this->shaderAllocator,
			this->render);
	return (MyGL::IShader*)(*((__int64(__fastcall**)(MyGL::DataLoader* const, __int64, const char*, const char*))this->_vptr_IDataLoader
		+ 18))(
			this,
			v3,
			vs,
			fs_0);
}

MyGL::ITexture2d* MyGL::DataLoader::loadTexture(MyGL::ITexture2d* t, const char* file)
{
	void(__fastcall * v3)(MyGL::ITextureLoader*, MyGL::ITexture2d*, std::string*, _QWORD);
	std::string v6;
	_BYTE v7[17];

	if (this->textureLoad)
	{
		v3 = (void(__fastcall*)(MyGL::ITextureLoader*, MyGL::ITexture2d*, std::string*, _QWORD)) * ((_QWORD*)this->textureLoad->_vptr_ITextureLoader
			+ 2);
		std::allocator<char>::allocator(v7);
		std::string::string(&v6, file, v7);
		v3(this->textureLoad, t, &v6, 0LL);
		std::string::~string(&v6);
		std::allocator<char>::~allocator(v7);
	}
	return t;
}

MyGL::ITexture2d* MyGL::DataLoader::loadTexture(const char* file)
{
	__int64 v2;

	v2 = (*((__int64(__fastcall**)(MyGL::IDataLoader::IAllocator<MyGL::ITexture2d> *, MyGL::IRender* const))this->textureAllocator->_vptr_IAllocator
		+ 2))(
			this->textureAllocator,
			this->render);
	return (MyGL::ITexture2d*)(*((__int64(__fastcall**)(MyGL::DataLoader* const, __int64, const char*))this->_vptr_IDataLoader
		+ 6))(
			this,
			v2,
			file);
}

MyGL::IModelLoader* MyGL::DataLoader::modelLoader()
{
	return this->modelLoad;
}

void MyGL::DataLoader::setModelAllocator(MyGL::IDataLoader::IAllocator<MyGL::IModel>* modelAllocator)
{
	if (this->modelAllocator)
		(*((void(__fastcall**)(MyGL::IDataLoader::IAllocator<MyGL::IModel> *))this->modelAllocator->_vptr_IAllocator + 1))(this->modelAllocator);
	this->modelAllocator = modelAllocator;
}

void MyGL::DataLoader::setModelLoader(MyGL::IModelLoader* l)
{
	this->modelLoad = l;
}

void MyGL::DataLoader::setShaderAllocator(MyGL::IDataLoader::IAllocator<MyGL::IShader>* shaderAllocator)
{
	if (this->shaderAllocator)
		(*((void(__fastcall**)(MyGL::IDataLoader::IAllocator<MyGL::IShader> *))this->shaderAllocator->_vptr_IAllocator + 1))(this->shaderAllocator);
	this->shaderAllocator = shaderAllocator;
}

void MyGL::DataLoader::setShaderLoader(MyGL::IShaderLoader* l)
{
	this->shaderLoad = l;
}

void MyGL::DataLoader::setTextureAllocator(MyGL::IDataLoader::IAllocator<MyGL::ITexture2d>* textureAllocator)
{
	if (this->textureAllocator)
		(*((void(__fastcall**)(MyGL::IDataLoader::IAllocator<MyGL::ITexture2d> *))this->textureAllocator->_vptr_IAllocator
			+ 1))(this->textureAllocator);
	this->textureAllocator = textureAllocator;
}

void MyGL::DataLoader::setTextureLoader(MyGL::ITextureLoader* l)
{
	this->textureLoad = l;
}

MyGL::IShaderLoader* MyGL::DataLoader::shaderLoader()
{
	return this->shaderLoad;
}

MyGL::ITextureLoader* MyGL::DataLoader::textureLoader()
{
	return this->textureLoad;
}
