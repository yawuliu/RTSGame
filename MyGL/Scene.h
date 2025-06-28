#pragma once

#include "IScene.h"

namespace MyGL {
    class Scene : public IScene {
    public:
        Scene(CGL *gl);

        Scene(IRender &r);

        virtual ~Scene();

        virtual IData *dataControl() override;

        virtual const IRender *render() override;

        virtual ITextureLoader *textureLoader() override;

        virtual IShaderLoader *shaderLoader() override;

        virtual IModelLoader *modelLoader() override;

        virtual ISceneGraph *graph() override;

        virtual IObjectCollection *objects() override;

        virtual void insertObject(IGraphicsObject &o) override;

        virtual void removeObject(IGraphicsObject &o) override;

        virtual void changeObject(IGraphicsObject &o, IMaterial &m) override;

        virtual IRenderAlgoSettings *settings() override;

        virtual void draw() override;

        virtual bool initGL() override;

        virtual void finitGL() override;


        virtual void createRenderAlgo() override;

        virtual void recreateRenderAlgo() override;

        virtual IDataLoader *loader() override;

        virtual ILightsCollection *lights() override;

        virtual void upsetCameraEvent(IRender &a2) override;

        virtual ITextureLoader *allocTextureLoader() override;

        virtual IShaderLoader *allocShaderLoader() override;

        virtual IModelLoader *allocModelLoader() override;

        virtual IObjectCollection *allocObjectCollection() override;

        virtual ILightsCollection *allocLightsCollection() override;

        virtual ISceneGraph *allocSceneGraph() override;

        virtual void initLightsCollection() override;

        virtual IRenderAlgo *allocRenderAlgo() override;

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


