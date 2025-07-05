#pragma once

#include "IScene.h"

namespace MyGL {
    class Scene : public IScene {
    public:
        explicit Scene(CGL *gl);

        explicit Scene(IRender &r);

        ~Scene() override;

        IData *dataControl() override;

        IRender *render() override;

        ITextureLoader *textureLoader() override;

        IShaderLoader *shaderLoader() override;

        IModelLoader *modelLoader() override;

        ISceneGraph *graph() override;

        IObjectCollection *objects() override;

        void insertObject(IGraphicsObject &o) override;

        void removeObject(IGraphicsObject &o) override;

        void changeObject(IGraphicsObject &o, IMaterial &m) override;

        IRenderAlgoSettings *settings() override;

        void draw() override;

        bool initGL() override;

        void finitGL() override;


        void createRenderAlgo() override;

        void recreateRenderAlgo() override;

        IDataLoader *loader() override;

        ILightsCollection *lights() override;

        void upsetCameraEvent(IRender &a2) override;

        ITextureLoader *allocTextureLoader() override;

        IShaderLoader *allocShaderLoader() override;

        IModelLoader *allocModelLoader() override;

        IObjectCollection *allocObjectCollection() override;

        ILightsCollection *allocLightsCollection() override;

        ISceneGraph *allocSceneGraph() override;

        void initLightsCollection() override;

        IRenderAlgo *allocRenderAlgo() override;

        void allocLoaders();

        void init();

        void upsetLight();

    protected:
        ITextureLoader *texLoader;
        IShaderLoader *shLoader;
        IModelLoader *mLoader;
        IRenderAlgo *renderAlgo;
        ISceneGraph *sceneGraph;
        IObjectCollection *obj;
        ILightsCollection *light;
        IRender *mrender;
        bool auto_render;
        //             // padding byte
        //        0000004A     // padding byte
        //        0000004B     // padding byte
        //        0000004C     // padding byte
        //        0000004D     // padding byte
        //        0000004E     // padding byte
        //        0000004F     // padding byte
        IData *dataL;
    };
}


