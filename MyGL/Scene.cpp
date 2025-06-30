#include "Scene.h"
#include "IRender.h"
#include "Render.h"
#include "ModelLoader.h"
#include "ObjectCollection.h"
#include "LightsCollection.h"
#include "ForwardRenderAlgo.h"
#include "SceneGraph.h"
#include "ShaderLoader.h"
#include "TextureLoader.h"

namespace MyGL {
    Scene::Scene(CGL *gl) {
        this->auto_render = 1;
        this->mrender = new Render(gl);;
        this->init();
    }

    Scene::Scene(IRender &r) {
        this->auto_render = 0;
        this->mrender = r;
        this->init();
    }

    Scene::~Scene() {
        if (this->renderAlgo)
            delete this->renderAlgo;
        if (this->dataL)
            delete this->dataL;
        if (this->texLoader)
            delete this->texLoader;
        if (this->shLoader)
            delete this->shLoader;
        if (this->mLoader)
            delete this->mLoader;
        if (this->obj)
            delete this->obj;
        if (this->light)
            delete this->light;
        if (this->sceneGraph)
            delete this->sceneGraph;
        if (this->mrender)
            delete this->mrender;
    }

    ILightsCollection *Scene::allocLightsCollection(Scene &s) {
        return new LightsCollection(s);
    }

    void Scene::allocLoaders() {
        if (!this->texLoader)
            this->texLoader = this->allocTextureLoader();
        if (!this->shLoader)
            this->shLoader = this->allocShaderLoader();
        if (!this->mLoader)
            this->mLoader = this->allocModelLoader();
    }

    IModelLoader *Scene::allocModelLoader() {
        return new ModelLoader(this->render());
    }

    IObjectCollection *Scene::allocObjectCollection(Scene &s) {
        return new ObjectCollection(s);
    }

    IRenderAlgo *Scene::allocRenderAlgo(Scene &s) {
        gadapter adapter(s);
        return new ForwardRenderAlgo(s, &adapter, 1);
    }

    ISceneGraph *Scene::allocSceneGraph(Scene &s) {
        return new SceneGraph(s);
    }

    IShaderLoader *Scene::allocShaderLoader() {
        return new ShaderLoader(this->render());
    }

    ITextureLoader *Scene::allocTextureLoader() {
        return new TextureLoader(this->render());
    }

    void Scene::changeObject(IGraphicsObject *const o, IMaterial *const m) {
        this->obj->onChangeMaterialObject(o, m);
    }

    void Scene::createRenderAlgo() {
        if (!this->renderAlgo)
            this->renderAlgo = this->allocRenderAlgo();
    }

    IData *Scene::dataControl() {
        return this->dataL;
    }

    void Scene::draw() {
        this->createRenderAlgo();
        this->mrender->setScene(this);
        this->upsetLight();
        this->renderAlgo->clearColor();
    }

    void Scene::finitGL() {
        __int64 v1;

        v1 = this->render();
        (*(void (__fastcall **)(__int64)) (*(_QWORD *) v1 + 64LL))(v1);
    }

    ISceneGraph *Scene::graph() {
        return this->sceneGraph;
    }

    void Scene::init() {
        this->dataL = new Data(this->mrender);
        this->texLoader = 0LL;
        this->shLoader = 0LL;
        this->mLoader = 0LL;
        this->obj = 0LL;
        this->light = 0LL;
        this->sceneGraph = 0LL;
        this->renderAlgo = 0LL;
        this->mrender->setScene(this);
    }

    bool Scene::initGL() {
        __int64 v1;
        __int64 v2;
        __int64 v3;
        void (__fastcall *v4)(__int64, __int64);
        __int64 v5;
        __int64 v6;
        __int64 v7;
        void (__fastcall *v8)(__int64, __int64);
        __int64 v9;
        __int64 v10;
        __int64 v11;
        void (__fastcall *v12)(__int64, __int64);
        __int64 v13;

        v1 = this->render();
        if (!(*(unsigned __int8 (__fastcall **)(__int64)) (*(_QWORD *) v1 + 48LL))(v1))
            return 0;
        this->obj = this->allocObjectCollection();
        this->light = this->allocLightsCollection();
        this->sceneGraph = this->allocSceneGraph();
        this->initLightsCollection();
        this->allocLoaders();
        v2 = this->dataControl();
        v3 = (*(__int64 (__fastcall **)(__int64)) (*(_QWORD *) v2 + 24LL))(v2);
        v4 = *(void (__fastcall **)(__int64, __int64)) (*(_QWORD *) v3 + 16LL);
        v5 = this->textureLoader();
        v4(v3, v5);
        v6 = this->dataControl();
        v7 = (*(__int64 (__fastcall **)(__int64)) (*(_QWORD *) v6 + 24LL))(v6);
        v8 = *(void (__fastcall **)(__int64, __int64)) (*(_QWORD *) v7 + 56LL);
        v9 = this->modelLoader();
        v8(v7, v9);
        v10 = this->dataControl();
        v11 = (*(__int64 (__fastcall **)(__int64)) (*(_QWORD *) v10 + 24LL))(v10);
        v12 = *(void (__fastcall **)(__int64, __int64)) (*(_QWORD *) v11 + 112LL);
        v13 = this->shaderLoader();
        v12(v11, v13);
        return 1;
    }

    void Scene::initLightsCollection() {
        Light *v2 = new Light(this->lights());;
        v2->setShadowCast(1LL);
    }

    void Scene::insertObject(IGraphicsObject *const o) {
        __int64 v2;

        this->obj->addObject(o);
        v2 = this->graph();
        (*(void (__fastcall **)(__int64, IGraphicsObject *const)) (*(_QWORD *) v2 + 16LL))(v2, o);
    }

    ILightsCollection *Scene::lights() {
        return this->light;
    }

    IDataLoader *Scene::loader() {
        __int64 v1;

        v1 = this->dataControl();
        return (IDataLoader *) (*(__int64 (__fastcall **)(__int64)) (*(_QWORD *) v1 + 24LL))(v1);
    }

    IModelLoader *Scene::modelLoader() {
        return this->mLoader;
    }

    IObjectCollection *Scene::objects() {
        return this->obj;
    }

    void Scene::recreateRenderAlgo(Scene &s) {
        void (__fastcall *v1)(IRenderAlgo *, gadapter *);
        gadapter adapter(s);
        s.renderAlgo->recreateAlgo(&adapter);
    }

    void Scene::removeObject(IGraphicsObject *const o) {
        __int64 v2;

        this->obj->delObject(o);
        v2 = this->graph();
        (*(void (__fastcall **)(__int64, IGraphicsObject *const)) (*(_QWORD *) v2 + 24LL))(v2, o);
    }

    IRender *Scene::render() {
        return this->mrender;
    }

    IRenderAlgoSettings *Scene::settings() {
        this->createRenderAlgo();
        if (this->renderAlgo)
            return this->renderAlgo->output();
        else
            return 0LL;
    }

    IShaderLoader *Scene::shaderLoader() {
        return this->shLoader;
    }

    ITextureLoader *Scene::textureLoader() {
        return this->texLoader;
    }

    void Scene::upsetCameraEvent(IRender &a2) {
        this->upsetLight();
    }

    void Scene::upsetLight() {
        __int64 v1;
        __int64 v2;
        __int64 v3;
        int i;

        for (i = 0;; ++i) {
            v3 = this->lights();
            if ((*(int (__fastcall **)(__int64)) (*(_QWORD *) v3 + 40LL))(v3) <= i)
                break;
            v1 = this->lights();
            v2 = (*(__int64 (__fastcall **)(__int64, _QWORD)) (*(_QWORD *) v1 + 48LL))(v1, (unsigned int) i);
            (*(void (__fastcall **)(__int64)) (*(_QWORD *) v2 + 96LL))(v2);
        }
    }
}