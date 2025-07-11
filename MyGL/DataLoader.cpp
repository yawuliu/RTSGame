#include "DataLoader.h"
#include "IModelLoader.h"
#include "Texture2d.h"
#include "Model.h"
#include "IShaderLoader.h"
#include "ITextureLoader.h"

namespace MyGL {
    DataLoader::DataLoader(IRender &r) : render(r) {
        this->textureAllocator = new Allocator<Texture2d, ITexture2d>();
        this->textureLoad = nullptr;
        this->modelAllocator = new Allocator<Model, IModel>();;
        this->modelLoad = nullptr;
        this->shaderAllocator = nullptr;
        this->shaderLoad = nullptr;
    }

    DataLoader::~DataLoader() {
        this->setTextureAllocator(nullptr);
        this->setModelAllocator(nullptr);
        this->setShaderAllocator(nullptr);

    }

    IModel *DataLoader::loadModel(IModel *t, const char *file) {
        if (this->modelLoad)
            this->modelLoad->load(t, file, 0LL);
        return t;
    }

    IModel *DataLoader::loadModel(const char *file) {
        return this->loadModel(this->modelAllocator->allocate(this->render), file);
    }

    IModel *DataLoader::loadModelBin_v0(IModel *t, const char *file) {
        if (this->modelLoad)
            this->modelLoad->loadBin_v0(t, file, 0LL);
        return t;
    }

    IModel *DataLoader::loadModelBin_v0(const char *file) {
        return this->loadModelBin_v0(this->modelAllocator->allocate(this->render), file);
    }

    IShader *DataLoader::loadShader(IShader *t, const char *vs, const char *fs_0) {
        if (this->shaderLoad)
            this->shaderLoad->load(t, vs, fs_0, 0LL);
        return t;
    }

    IShader *DataLoader::loadShader(const char *vs, const char *fs_0) {
        return this->loadShader(this->shaderAllocator->allocate(this->render), vs, fs_0);
    }

    ITexture2d *DataLoader::loadTexture(ITexture2d *t, const char *file) {
        if (this->textureLoad) {
            this->textureLoad->load(t, file, 0LL);
        }
        return t;
    }

    ITexture2d *DataLoader::loadTexture(const char *file) {
        return this->loadTexture(this->textureAllocator->allocate(this->render), file);
    }

    IModelLoader *DataLoader::modelLoader() {
        return this->modelLoad;
    }

    void DataLoader::setModelAllocator(IDataLoader::IAllocator<IModel> *modelAllocator) {
        if (this->modelAllocator)
            delete this->modelAllocator;
        this->modelAllocator = modelAllocator;
    }

    void DataLoader::setModelLoader(IModelLoader *l) {
        this->modelLoad = l;
    }

    void DataLoader::setShaderAllocator(IDataLoader::IAllocator<IShader> *shaderAllocator) {
        if (this->shaderAllocator)
            delete this->shaderAllocator;
        this->shaderAllocator = shaderAllocator;
    }

    void DataLoader::setShaderLoader(IShaderLoader *l) {
        this->shaderLoad = l;
    }

    void DataLoader::setTextureAllocator(IDataLoader::IAllocator<ITexture2d> *textureAllocator) {
        if (this->textureAllocator)
            delete this->textureAllocator;
        this->textureAllocator = textureAllocator;
    }

    void DataLoader::setTextureLoader(ITextureLoader *l) {
        this->textureLoad = l;
    }

    IShaderLoader *DataLoader::shaderLoader() {
        return this->shaderLoad;
    }

    ITextureLoader *DataLoader::textureLoader() {
        return this->textureLoad;
    }
}