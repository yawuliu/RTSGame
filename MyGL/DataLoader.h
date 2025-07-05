#pragma once

#include "Texture2d.h"
#include "IDataLoader.h"
#include "IModel.h"
#include "Model.h"
#include "IRender.h"
#include "AbstractShader.h"
#include "StdMaterial.h"
#include "ErrorControl.h"

namespace MyGL {
    class IModelLoader;

    class IShaderLoader;

    class ITextureLoader;

    class DataLoader : public IDataLoader {
    public:
        template<typename T>
        class IAllocator {
        public:
            IAllocator() = default;
        };

        template<typename T, typename N>
        class Allocator : public IAllocator<N> {
        public:
            Allocator() = default;
        };

    public:
        explicit DataLoader(IRender &r);

        ~DataLoader() override;

        IModel *loadModel(IModel *t, const char *file) override;

        IModel *loadModel(const char *file) override;

        IModel *loadModelBin_v0(IModel *t, const char *file) override;

        IModel *loadModelBin_v0(const char *file) override;

        IShader *loadShader(IShader *t, const char *vs, const char *fs_0) override;

        IShader *loadShader(const char *vs, const char *fs_0) override;

        ITexture2d *loadTexture(ITexture2d *t, const char *file) override;

        ITexture2d *loadTexture(const char *file) override;

        IModelLoader *modelLoader() override;

        void setModelAllocator(IDataLoader::IAllocator<IModel> *modelAllocator) override;

        void setModelLoader(IModelLoader *l) override;

        void setShaderAllocator(IDataLoader::IAllocator<IShader> *shaderAllocator) override;

        void setShaderLoader(IShaderLoader *l) override;

        void setTextureAllocator(IDataLoader::IAllocator<ITexture2d> *textureAllocator) override;

        void setTextureLoader(ITextureLoader *l) override;

        IShaderLoader *shaderLoader() override;

        ITextureLoader *textureLoader() override;

    protected:
        IRender &render;
        ITextureLoader *textureLoad;
        IDataLoader::IAllocator<ITexture2d> *textureAllocator;
        IModelLoader *modelLoad;
        IDataLoader::IAllocator<IModel> *modelAllocator;
        IShaderLoader *shaderLoad;
        IDataLoader::IAllocator<IShader> *shaderAllocator;
    };

}



