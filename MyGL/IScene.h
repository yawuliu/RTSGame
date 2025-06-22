#pragma once
#include <MyGL/IRender.h>
#include <MyGL/IGraphicsObject.h>
#include <MyGL/Light.h>
#include <MyGL/IMaterial.h>
#include <MyGL/ITextureLoader.h>
#include <MyGL/IShaderLoader.h>
#include <MyGL/IModelLoader.h>
#include <MyGL/ISceneGraph.h>
#include <MyGL/ITexture2d.h>
#include <MyGL/IObjectCollection.h>
namespace MyGL {
    class IScene {
    public:
        IScene() = default;

        virtual ~IScene() = default;

        virtual IData& dataControl() = 0;

        virtual IRender &render() = 0;

        virtual ITextureLoader& textureLoader() = 0;

        virtual IShaderLoader& shaderLoader() = 0;

        virtual IModelLoader& modelLoader() = 0;

        virtual ISceneGraph& graph() = 0;

        virtual IObjectCollection& objects() = 0;

        virtual void insertObject(IGraphicsObject &) = 0;

        virtual void removeObject(IGraphicsObject &) = 0;

        virtual void changeObject(IGraphicsObject &, IMaterial &) = 0;

        virtual ITexture2d& texture(const std::string &name) = 0;

        virtual const IRenderAlgoSettings& settings() = 0;

        virtual void draw() = 0;

        virtual bool initGL() = 0;

        virtual void finitGL()= 0;

        virtual void createRenderAlgo() = 0;

        virtual void recreateRenderAlgo() = 0;

        virtual IDataLoader& loader() = 0;

        virtual ILightsCollection& lights() = 0;

        virtual void upsetCameraEvent(IRender &);

        virtual ITextureLoader& allocTextureLoader(void) = 0;

        virtual IShaderLoader& allocShaderLoader(void) = 0;

        virtual IModelLoader& allocModelLoader(void) = 0;

        virtual IObjectCollection& allocObjectCollection(void) = 0;

        virtual ILightsCollection& allocLightsCollection(void) = 0;

        virtual ISceneGraph& allocSceneGraph(void) = 0;

        virtual void initLightsCollection(void) = 0;

        virtual IRenderAlgo& allocRenderAlgo(void) = 0;
    };
}

