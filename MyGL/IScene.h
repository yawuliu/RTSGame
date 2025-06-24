#pragma once

#include <string>
#include "IRender.h"
#include "IGraphicsObject.h"
#include "Light.h"
#include "IMaterial.h"
#include "ITextureLoader.h"
#include "IShaderLoader.h"
#include "IModelLoader.h"
#include "ISceneGraph.h"
#include "ITexture2d.h"
#include "IObjectCollection.h"
#include "IRenderAlgoSettings.h"
#include "ILightsCollection.h"


namespace MyGL {
    class IScene {
    public:
        IScene() = default;

        virtual ~IScene() = default; // 0
        // virtual void ~IScene() = 0; // 1
        virtual void dataControl() = 0; // 2
        virtual void render() = 0; // 3
        // virtual void render() = 0; // 4
        virtual void textureLoader() = 0;//5
        virtual void shaderLoader() = 0; //6
        virtual void modelLoader() = 0;//7
        virtual void graph() = 0;//8
        virtual void objects() = 0;//9
        virtual void insertObject(MyGL::IGraphicsObject &) = 0;//10
        virtual void removeObject(MyGL::IGraphicsObject &) = 0;//11
        virtual void changeObject(MyGL::IGraphicsObject &, MyGL::IMaterial &) = 0;//12
        virtual void settings() = 0;//13
        //virtual void settings() = 0;//14
        virtual void draw() = 0;//15
        virtual void initGL() = 0;//16
        virtual void finitGL() = 0;//17
        virtual void createRenderAlgo() = 0;//18
        virtual void recreateRenderAlgo() = 0;//19
        virtual void loader() = 0;//20
        virtual void lights() = 0;//21
        virtual void upsetCameraEvent(MyGL::IRender &) = 0;//22
        virtual void allocTextureLoader() = 0;//23
        virtual void allocShaderLoader() = 0;//24
        virtual void allocModelLoader() = 0;//25
        virtual void allocObjectCollection() = 0;//26
        virtual void allocLightsCollection() = 0;//27
        virtual void allocSceneGraph() = 0;//28
        virtual void initLightsCollection() = 0;//29
        virtual void allocRenderAlgo() = 0;//30
    };
}

