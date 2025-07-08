#pragma once

#include <string>
#include "IGraphicsObject.h"
#include "IMaterial.h"
#include "IRender.h"

namespace MyGL {
    class IData;

    class ISceneGraph;

    class IRenderAlgoSettings;

    class IObjectCollection;

    class ILightsCollection;

    class ITextureLoader;

    class IShaderLoader;

    class IModelLoader;

    class IRenderAlgo;

    class IDataLoader;

    class IScene {
    public:
        IScene() = default;

        virtual ~IScene() = default; // 0
        // virtual void ~IScene() = 0; // 1
        virtual IData *dataControl() = 0; // 2
        virtual IRender &render() = 0; // 3
        // virtual void render() = 0; // 4
        virtual ITextureLoader *textureLoader() = 0;//5
        virtual IShaderLoader *shaderLoader() = 0; //6
        virtual IModelLoader *modelLoader() = 0;//7
        virtual ISceneGraph *graph() = 0;//8
        virtual IObjectCollection *objects() = 0;//9
        virtual void insertObject(IGraphicsObject &) = 0;//10
        virtual void removeObject(IGraphicsObject &) = 0;//11
        virtual void changeObject(IGraphicsObject &, IMaterial &) = 0;//12
        virtual IRenderAlgoSettings *settings() = 0;//13
        //virtual void settings() = 0;//14
        virtual void draw() = 0;//15
        virtual bool initGL() = 0;//16
        virtual void finitGL() = 0;//17
        virtual void createRenderAlgo() = 0;//18
        virtual void recreateRenderAlgo() = 0;//19
        virtual IDataLoader *loader() = 0;//20
        virtual ILightsCollection *lights() = 0;//21
        virtual void upsetCameraEvent(IRender &) = 0;//22
        virtual ITextureLoader *allocTextureLoader() = 0;//23
        virtual IShaderLoader *allocShaderLoader() = 0;//24
        virtual IModelLoader *allocModelLoader() = 0;//25
        virtual IObjectCollection *allocObjectCollection() = 0;//26
        virtual ILightsCollection *allocLightsCollection() = 0;//27
        virtual ISceneGraph *allocSceneGraph() = 0;//28
        virtual void initLightsCollection() = 0;//29
        virtual IRenderAlgo *allocRenderAlgo() = 0;//30
    };
}

