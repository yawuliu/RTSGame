#pragma once

#include "DisableCopy.h"
#include "IModel.h"
#include "IShader.h"

namespace MyGL {
    class IModelLoader;

    class IShaderLoader;

    class ITextureLoader;

    class IDataLoader : public DisableCopy {
    public:
        template<class T>
        class IAllocator {
        public:
            IAllocator() = default;

            virtual ~IAllocator() = default; // 0
            // virtual ~IAllocator() = default; // 1
            virtual void allocate(IRender &) = 0; // 2
        };

    public:
        IDataLoader() = default;

        virtual  ~IDataLoader() = default; // 0
        // virtual  ~IDataLoader() = default; // 1
        virtual void setTextureLoader(ITextureLoader *) = 0; // 2
        virtual ITextureLoader *textureLoader() = 0; // 3
        virtual void setTextureAllocator(IDataLoader::IAllocator<ITexture2d> *) = 0; // 4
        virtual ITexture2d *loadTexture(char const *) = 0; // 5
        virtual ITexture2d *loadTexture(ITexture2d *, char const *) = 0; // 6
        virtual void setModelLoader(IModelLoader *) = 0; // 7
        virtual IModelLoader *modelLoader() = 0; // 8
        virtual void setModelAllocator(IDataLoader::IAllocator<IModel> *) = 0; // 9
        virtual IModel *loadModel(char const *) = 0; // 10
        virtual IModel *loadModel(IModel *, char const *) = 0; // 11
        virtual IModel *loadModelBin_v0(char const *) = 0; // 12
        virtual IModel *loadModelBin_v0(IModel *, char const *) = 0; // 13
        virtual void setShaderLoader(IShaderLoader *) = 0; // 14
        virtual IShaderLoader *shaderLoader() = 0; // 15
        virtual void setShaderAllocator(IDataLoader::IAllocator<IShader> *) = 0; // 16
        virtual IShader *loadShader(char const *, char const *) = 0; // 17
        virtual IShader *loadShader(IShader *, char const *, char const *) = 0; // 18

    };
}



