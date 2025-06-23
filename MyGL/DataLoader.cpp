#include "DataLoader.h"
namespace MyGL {
	DataLoader::DataLoader(const IRender& r)
	{
		Allocator<Texture2d, ITexture2d>* textureAllocator;
		Allocator<Model, IModel>* modelAllocator;
		this->render = r;
		textureAllocator = (Allocator<Texture2d, ITexture2d> *)operator new(8uLL);
		textureAllocator->_vptr_IAllocator = 0LL;
		DataLoader::Allocator<Texture2d, ITexture2d>::Allocator(textureAllocator);
		this->textureAllocator = textureAllocator;
		this->textureLoad = 0LL;
		modelAllocator = (Allocator<Model, IModel> *)operator new(8uLL);
		modelAllocator->_vptr_IAllocator = 0LL;
		DataLoader::Allocator<Model, IModel>::Allocator(modelAllocator);
		this->modelAllocator = modelAllocator;
		this->modelLoad = 0LL;
		this->shaderAllocator = 0LL;
		this->shaderLoad = 0LL;
	}

	DataLoader::~DataLoader()
	{
		this->setTextureAllocator(0LL);
		this->setModelAllocator(0LL);
		this->setShaderAllocator(0LL);

	}

	IModel* DataLoader::loadModel(IModel* t, const char* file)
	{
		if (this->modelLoad)
			(*((void(__fastcall**)(IModelLoader*, IModel*, const char*, _QWORD))this->modelLoad->_vptr_IModelLoader
				+ 2))(
					this->modelLoad,
					t,
					file,
					0LL);
		return t;
	}

	IModel* DataLoader::loadModel(const char* file)
	{
		__int64 v2;

		v2 = (*((__int64(__fastcall**)(IDataLoader::IAllocator<IModel> *, IRender* const))this->modelAllocator->_vptr_IAllocator
			+ 2))(
				this->modelAllocator,
				this->render);
		return (IModel*)(*((__int64(__fastcall**)(DataLoader* const, __int64, const char*))this->_vptr_IDataLoader
			+ 11))(
				this,
				v2,
				file);
	}

	IModel* DataLoader::loadModelBin_v0(IModel* t, const char* file)
	{
		if (this->modelLoad)
			(*((void(__fastcall**)(IModelLoader*, IModel*, const char*, _QWORD))this->modelLoad->_vptr_IModelLoader
				+ 3))(
					this->modelLoad,
					t,
					file,
					0LL);
		return t;
	}

	IModel* DataLoader::loadModelBin_v0(const char* file)
	{
		__int64 v2;

		v2 = (*((__int64(__fastcall**)(IDataLoader::IAllocator<IModel> *, IRender* const))this->modelAllocator->_vptr_IAllocator
			+ 2))(
				this->modelAllocator,
				this->render);
		return (IModel*)(*((__int64(__fastcall**)(DataLoader* const, __int64, const char*))this->_vptr_IDataLoader
			+ 13))(
				this,
				v2,
				file);
	}

	IShader* DataLoader::loadShader(IShader* t, const char* vs, const char* fs_0)
	{
		if (this->shaderLoad)
			(*((void(__fastcall**)(IShaderLoader*, IShader*, const char*, const char*, _QWORD))this->shaderLoad->_vptr_IShaderLoader
				+ 2))(
					this->shaderLoad,
					t,
					vs,
					fs_0,
					0LL);
		return t;
	}

	IShader* DataLoader::loadShader(const char* vs, const char* fs_0)
	{
		__int64 v3;

		v3 = (*((__int64(__fastcall**)(IDataLoader::IAllocator<IShader> *, IRender* const))this->shaderAllocator->_vptr_IAllocator
			+ 2))(
				this->shaderAllocator,
				this->render);
		return (IShader*)(*((__int64(__fastcall**)(DataLoader* const, __int64, const char*, const char*))this->_vptr_IDataLoader
			+ 18))(
				this,
				v3,
				vs,
				fs_0);
	}

	ITexture2d* DataLoader::loadTexture(ITexture2d* t, const char* file)
	{
		void(__fastcall * v3)(ITextureLoader*, ITexture2d*, std::string*, _QWORD);
		std::string v6;
		_BYTE v7[17];

		if (this->textureLoad)
		{
			v3 = (void(__fastcall*)(ITextureLoader*, ITexture2d*, std::string*, _QWORD)) * ((_QWORD*)this->textureLoad->_vptr_ITextureLoader
				+ 2);
			std::allocator<char>::allocator(v7);
			std::string::string(&v6, file, v7);
			v3(this->textureLoad, t, &v6, 0LL);
			std::string::~string(&v6);
			std::allocator<char>::~allocator(v7);
		}
		return t;
	}

	ITexture2d* DataLoader::loadTexture(const char* file)
	{
		__int64 v2;

		v2 = (*((__int64(__fastcall**)(IDataLoader::IAllocator<ITexture2d> *, IRender* const))this->textureAllocator->_vptr_IAllocator
			+ 2))(
				this->textureAllocator,
				this->render);
		return (ITexture2d*)(*((__int64(__fastcall**)(DataLoader* const, __int64, const char*))this->_vptr_IDataLoader
			+ 6))(
				this,
				v2,
				file);
	}

	IModelLoader* DataLoader::modelLoader()
	{
		return this->modelLoad;
	}

	void DataLoader::setModelAllocator(IDataLoader::IAllocator<IModel>* modelAllocator)
	{
		if (this->modelAllocator)
			(*((void(__fastcall**)(IDataLoader::IAllocator<IModel> *))this->modelAllocator->_vptr_IAllocator + 1))(this->modelAllocator);
		this->modelAllocator = modelAllocator;
	}

	void DataLoader::setModelLoader(IModelLoader* l)
	{
		this->modelLoad = l;
	}

	void DataLoader::setShaderAllocator(IDataLoader::IAllocator<IShader>* shaderAllocator)
	{
		if (this->shaderAllocator)
			(*((void(__fastcall**)(IDataLoader::IAllocator<IShader> *))this->shaderAllocator->_vptr_IAllocator + 1))(this->shaderAllocator);
		this->shaderAllocator = shaderAllocator;
	}

	void DataLoader::setShaderLoader(IShaderLoader* l)
	{
		this->shaderLoad = l;
	}

	void DataLoader::setTextureAllocator(IDataLoader::IAllocator<ITexture2d>* textureAllocator)
	{
		if (this->textureAllocator)
			(*((void(__fastcall**)(IDataLoader::IAllocator<ITexture2d> *))this->textureAllocator->_vptr_IAllocator
				+ 1))(this->textureAllocator);
		this->textureAllocator = textureAllocator;
	}

	void DataLoader::setTextureLoader(ITextureLoader* l)
	{
		this->textureLoad = l;
	}

	IShaderLoader* DataLoader::shaderLoader()
	{
		return this->shaderLoad;
	}

	ITextureLoader* DataLoader::textureLoader()
	{
		return this->textureLoad;
	}
}