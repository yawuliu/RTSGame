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
        DataLoader(const IRender &r);

        virtual ~DataLoader();

        IModel *loadModel(IModel *t, const char *file);

        IModel *loadModel(const char *file);

        IModel *loadModelBin_v0(IModel *t, const char *file);

        IModel *loadModelBin_v0(const char *file);

        IShader *loadShader(IShader *t, const char *vs, const char *fs_0);

        IShader *loadShader(const char *vs, const char *fs_0);

        ITexture2d *loadTexture(ITexture2d *t, const char *file);

        ITexture2d *loadTexture(const char *file);

        IModelLoader *modelLoader();

        void setModelAllocator(IDataLoader::IAllocator<IModel> *modelAllocator);

        void setModelLoader(IModelLoader *l);

        void setShaderAllocator(IDataLoader::IAllocator<IShader> *shaderAllocator);

        void setShaderLoader(IShaderLoader *l);

        void setTextureAllocator(IDataLoader::IAllocator<ITexture2d> *textureAllocator);

        void setTextureLoader(ITextureLoader *l);

        IShaderLoader *shaderLoader();

        ITextureLoader *textureLoader();

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



