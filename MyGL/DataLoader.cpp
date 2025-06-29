#include "DataLoader.h"
#include "IModelLoader.h"

namespace MyGL {
	DataLoader::DataLoader(const IRender& r)
	{
		this->render = r;
		this->textureAllocator = new Allocator<Texture2d, ITexture2d>();
		this->textureLoad = 0LL;
		this->modelAllocator = new Allocator<Model, IModel>();;
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
			this->modelLoad->load(t,file,0LL);
		return t;
	}

	IModel* DataLoader::loadModel(const char* file)
	{
		return this->loadModel(this->modelAllocator->allocate(this->render),file);
	}

	IModel* DataLoader::loadModelBin_v0(IModel* t, const char* file)
	{
		if (this->modelLoad)
			this->modelLoad->loadBin_v0(t,file,0LL);
		return t;
	}

	IModel* DataLoader::loadModelBin_v0(const char* file)
	{
		return this->loadModelBin_v0(this->modelAllocator->allocate(this->render), file);
	}

	IShader* DataLoader::loadShader(IShader* t, const char* vs, const char* fs_0)
	{
		if (this->shaderLoad)
			this->shaderLoad->loadt,vs,fs_0, 0LL);
		return t;
	}

	IShader* DataLoader::loadShader(const char* vs, const char* fs_0)
	{
		return this->loadShader(this->shaderAllocator->allocate(this->render),vs,fs_0);
	}

	ITexture2d* DataLoader::loadTexture(ITexture2d* t, const char* file)
	{
		if (this->textureLoad)
		{
            this->textureLoad->load( t, file, 0LL);
		}
		return t;
	}

	ITexture2d* DataLoader::loadTexture(const char* file)
	{
		return this->loadTexture(this->textureAllocator->allocate(this->render), file);
	}

	IModelLoader* DataLoader::modelLoader()
	{
		return this->modelLoad;
	}

	void DataLoader::setModelAllocator(IDataLoader::IAllocator<IModel>* modelAllocator)
	{
		if (this->modelAllocator)
			delete this->modelAllocator;
		this->modelAllocator = modelAllocator;
	}

	void DataLoader::setModelLoader(IModelLoader* l)
	{
		this->modelLoad = l;
	}

	void DataLoader::setShaderAllocator(IDataLoader::IAllocator<IShader>* shaderAllocator)
	{
		if (this->shaderAllocator)
			delete this->shaderAllocator;
		this->shaderAllocator = shaderAllocator;
	}

	void DataLoader::setShaderLoader(IShaderLoader* l)
	{
		this->shaderLoad = l;
	}

	void DataLoader::setTextureAllocator(IDataLoader::IAllocator<ITexture2d>* textureAllocator)
	{
		if (this->textureAllocator)
			delete this->textureAllocator;
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