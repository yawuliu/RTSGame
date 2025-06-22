#include "Scene.h"
#include "IRender.h"

MyGL::Scene::Scene(MyGL::CGL *gl) {
    MyGL::Render *mrender;
    this->auto_render = 1;
    mrender = (MyGL::Render *) operator new(0x188uLL);
    MyGL::Render::Render(mrender, gl);
    this->mrender = mrender;
    this->init();
}

MyGL::Scene::Scene(MyGL::IRender &r) {
    this->auto_render = 0;
    this->mrender = r;
    this->init();
}

MyGL::Scene::~Scene() {
    if (this->renderAlgo)
        (*((void (__fastcall **)(MyGL::IRenderAlgo *)) this->renderAlgo->_vptr_IRenderPass + 1))(
                this->renderAlgo);
    if (this->dataL)
        (*((void (__fastcall **)(MyGL::IData *)) this->dataL->_vptr_IData + 1))(this->dataL);
    if (this->texLoader)
        (*((void (__fastcall **)(MyGL::ITextureLoader *)) this->texLoader->_vptr_ITextureLoader + 1))(
                this->texLoader);
    if (this->shLoader)
        (*((void (__fastcall **)(MyGL::IShaderLoader *)) this->shLoader->_vptr_IShaderLoader + 1))(
                this->shLoader);
    if (this->mLoader)
        (*((void (__fastcall **)(MyGL::IModelLoader *)) this->mLoader->_vptr_IModelLoader + 1))(this->mLoader);
    if (this->obj)
        (*((void (__fastcall **)(MyGL::IObjectCollection *)) this->obj->_vptr_IObjectCollection + 1))(
                this->obj);
    if (this->light)
        (*((void (__fastcall **)(MyGL::ILightsCollection *)) this->light->_vptr_ILightsCollection + 1))(
                this->light);
    if (this->sceneGraph)
        (*((void (__fastcall **)(MyGL::ISceneGraph *)) this->sceneGraph->_vptr_ISceneGraph + 1))(
                this->sceneGraph);
    if (this->mrender)
        (*((void (__fastcall **)(MyGL::IRender *)) this->mrender->_vptr_IRender + 1))(this->mrender);
}

MyGL::ILightsCollection *MyGL::Scene::allocLightsCollection(MyGL::Scene &s) {
    MyGL::LightsCollection *v1;

    v1 = (MyGL::LightsCollection *) operator new(0x18uLL);
    MyGL::LightsCollection::LightsCollection(v1, s);
    return v1;
}

void MyGL::Scene::allocLoaders() {
    if (!this->texLoader)
        this->texLoader = (MyGL::ITextureLoader *) (*(
                (__int64 (__fastcall **)(MyGL::Scene &)) this->_vptr_IScene + 23))(this);
    if (!this->shLoader)
        this->shLoader = (MyGL::IShaderLoader *) (*(
                (__int64 (__fastcall **)(MyGL::Scene &)) this->_vptr_IScene + 24))(this);
    if (!this->mLoader)
        this->mLoader = (MyGL::IModelLoader *) (*(
                (__int64 (__fastcall **)(MyGL::Scene &)) this->_vptr_IScene + 25))(this);
}

MyGL::IModelLoader *MyGL::Scene::allocModelLoader() {
    MyGL::IRender *r;
    MyGL::ModelLoader *v2;

    r = (MyGL::IRender *) (*((__int64 (__fastcall **)(MyGL::Scene &)) this->_vptr_IScene + 3))(this);
    v2 = (MyGL::ModelLoader *) operator new(0x10uLL);
    MyGL::ModelLoader::ModelLoader(v2, r);
    return v2;
}

MyGL::IObjectCollection *MyGL::Scene::allocObjectCollection(MyGL::Scene &s) {
    MyGL::ObjectCollection *v1;

    v1 = (MyGL::ObjectCollection *) operator new(0x18uLL);
    MyGL::ObjectCollection::ObjectCollection(v1, s);
    return v1;
}

MyGL::IRenderAlgo *MyGL::Scene::allocRenderAlgo(MyGL::Scene &s) {
    MyGL::ForwardRenderAlgo *v1;
    MyGL::Adapter adapter;

    MyGL::Adapter::Adapter(&adapter, s);
    v1 = (MyGL::ForwardRenderAlgo *) operator new(0x70uLL);
    MyGL::ForwardRenderAlgo::ForwardRenderAlgo(v1, s, &adapter, 1);
    return v1;
}

MyGL::ISceneGraph *MyGL::Scene::allocSceneGraph(MyGL::Scene &s) {
    MyGL::SceneGraph *v1;

    v1 = (MyGL::SceneGraph *) operator new(0x168uLL);
    MyGL::SceneGraph::SceneGraph(v1, s);
    return v1;
}

MyGL::IShaderLoader *MyGL::Scene::allocShaderLoader() {
    MyGL::IRender *r;
    MyGL::ShaderLoader *v2;

    r = (MyGL::IRender *) (*((__int64 (__fastcall **)(MyGL::Scene &)) this->_vptr_IScene + 3))(this);
    v2 = (MyGL::ShaderLoader *) operator new(0x18uLL);
    MyGL::ShaderLoader::ShaderLoader(v2, r);
    return v2;
}

MyGL::ITextureLoader *MyGL::Scene::allocTextureLoader() {
    MyGL::IRender *r;
    MyGL::TextureLoader *v2;

    r = (MyGL::IRender *) (*((__int64 (__fastcall **)(MyGL::Scene &)) this->_vptr_IScene + 3))(this);
    v2 = (MyGL::TextureLoader *) operator new(0x18uLL);
    MyGL::TextureLoader::TextureLoader(v2, r);
    return v2;
}

void MyGL::Scene::changeObject(MyGL::IGraphicsObject *const o, MyGL::IMaterial *const m) {
    (*((void (__fastcall **)(MyGL::IObjectCollection *, MyGL::IGraphicsObject *const,
                             MyGL::IMaterial *const)) this->obj->_vptr_IObjectCollection
       + 4))(
            this->obj,
            o,
            m);
}

void MyGL::Scene::createRenderAlgo() {
    if (!this->renderAlgo)
        this->renderAlgo = (MyGL::IRenderAlgo *) (*(
                (__int64 (__fastcall **)(MyGL::Scene &)) this->_vptr_IScene + 30))(this);
}

MyGL::IData *MyGL::Scene::dataControl() {
    return this->dataL;
}

void MyGL::Scene::draw() {
    (*((void (__fastcall **)(MyGL::Scene &)) this->_vptr_IScene + 18))(this);
    (*((void (__fastcall **)(MyGL::IRender *, MyGL::Scene &)) this->mrender->_vptr_IRender + 52))(
            this->mrender, this);
    MyGL::Scene::upsetLight(this);
    (*((void (__fastcall **)(MyGL::IRenderAlgo *)) this->renderAlgo->_vptr_IRenderPass + 2))(this->renderAlgo);
}

void MyGL::Scene::finitGL() {
    __int64 v1;

    v1 = (*((__int64 (__fastcall **)(MyGL::Scene &)) this->_vptr_IScene + 3))(this);
    (*(void (__fastcall **)(__int64)) (*(_QWORD *) v1 + 64LL))(v1);
}

MyGL::ISceneGraph *MyGL::Scene::graph() {
    return this->sceneGraph;
}

void MyGL::Scene::init() {
    MyGL::Data *dataL;

    dataL = (MyGL::Data *) operator new(0x18uLL);
    MyGL::Data::Data(dataL, this->mrender);
    this->dataL = dataL;
    this->texLoader = 0LL;
    this->shLoader = 0LL;
    this->mLoader = 0LL;
    this->obj = 0LL;
    this->light = 0LL;
    this->sceneGraph = 0LL;
    this->renderAlgo = 0LL;
    (*((void (__fastcall **)(MyGL::IRender *, MyGL::Scene &)) this->mrender->_vptr_IRender + 52))(
            this->mrender, this);
}

bool MyGL::Scene::initGL() {
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

    v1 = (*((__int64 (__fastcall **)(MyGL::Scene &)) this->_vptr_IScene + 3))(this);
    if (!(*(unsigned __int8 (__fastcall **)(__int64)) (*(_QWORD *) v1 + 48LL))(v1))
        return 0;
    this->obj = (MyGL::IObjectCollection *) (*(
            (__int64 (__fastcall **)(MyGL::Scene &)) this->_vptr_IScene + 26))(this);
    this->light = (MyGL::ILightsCollection *) (*(
            (__int64 (__fastcall **)(MyGL::Scene &)) this->_vptr_IScene + 27))(this);
    this->sceneGraph = (MyGL::ISceneGraph *) (*(
            (__int64 (__fastcall **)(MyGL::Scene &)) this->_vptr_IScene + 28))(this);
    (*((void (__fastcall **)(MyGL::Scene &)) this->_vptr_IScene + 29))(this);
    MyGL::Scene::allocLoaders(this);
    v2 = (*((__int64 (__fastcall **)(MyGL::Scene &)) this->_vptr_IScene + 2))(this);
    v3 = (*(__int64 (__fastcall **)(__int64)) (*(_QWORD *) v2 + 24LL))(v2);
    v4 = *(void (__fastcall **)(__int64, __int64)) (*(_QWORD *) v3 + 16LL);
    v5 = (*((__int64 (__fastcall **)(MyGL::Scene &)) this->_vptr_IScene + 5))(this);
    v4(v3, v5);
    v6 = (*((__int64 (__fastcall **)(MyGL::Scene &)) this->_vptr_IScene + 2))(this);
    v7 = (*(__int64 (__fastcall **)(__int64)) (*(_QWORD *) v6 + 24LL))(v6);
    v8 = *(void (__fastcall **)(__int64, __int64)) (*(_QWORD *) v7 + 56LL);
    v9 = (*((__int64 (__fastcall **)(MyGL::Scene &)) this->_vptr_IScene + 7))(this);
    v8(v7, v9);
    v10 = (*((__int64 (__fastcall **)(MyGL::Scene &)) this->_vptr_IScene + 2))(this);
    v11 = (*(__int64 (__fastcall **)(__int64)) (*(_QWORD *) v10 + 24LL))(v10);
    v12 = *(void (__fastcall **)(__int64, __int64)) (*(_QWORD *) v11 + 112LL);
    v13 = (*((__int64 (__fastcall **)(MyGL::Scene &)) this->_vptr_IScene + 6))(this);
    v12(v11, v13);
    return 1;
}

void MyGL::Scene::initLightsCollection() {
    MyGL::ILightsCollection *c;
    MyGL::Light *v2;

    c = (MyGL::ILightsCollection *) (*((__int64 (__fastcall **)(MyGL::Scene &)) this->_vptr_IScene + 21))(
            this);
    v2 = (MyGL::Light *) operator new(0x68uLL);
    MyGL::Light::Light(v2, c);
    (*((void (__fastcall **)(MyGL::Light *, __int64)) v2->_vptr_ILight + 6))(v2, 1LL);
}

void MyGL::Scene::insertObject(MyGL::IGraphicsObject *const o) {
    __int64 v2;

    (*((void (__fastcall **)(MyGL::IObjectCollection *,
                             MyGL::IGraphicsObject *const)) this->obj->_vptr_IObjectCollection
       + 2))(
            this->obj,
            o);
    v2 = (*((__int64 (__fastcall **)(MyGL::Scene &)) this->_vptr_IScene + 8))(this);
    (*(void (__fastcall **)(__int64, MyGL::IGraphicsObject *const)) (*(_QWORD *) v2 + 16LL))(v2, o);
}

MyGL::ILightsCollection *MyGL::Scene::lights() {
    return this->light;
}

MyGL::IDataLoader *MyGL::Scene::loader() {
    __int64 v1;

    v1 = (*((__int64 (__fastcall **)(MyGL::Scene &)) this->_vptr_IScene + 2))(this);
    return (MyGL::IDataLoader *) (*(__int64 (__fastcall **)(__int64)) (*(_QWORD *) v1 + 24LL))(v1);
}

MyGL::IModelLoader *MyGL::Scene::modelLoader() {
    return this->mLoader;
}

MyGL::IObjectCollection *MyGL::Scene::objects() {
    return this->obj;
}

void MyGL::Scene::recreateRenderAlgo(MyGL::Scene &s) {
    void (__fastcall *v1)(MyGL::IRenderAlgo *, MyGL::Adapter *);
    MyGL::Adapter adapter;

    (*((void (__fastcall **)(MyGL::Scene &)) s->_vptr_IScene + 18))(s);
    v1 = (void (__fastcall *)(MyGL::IRenderAlgo *, MyGL::Adapter *)) *(
            (_QWORD *) s->renderAlgo->_vptr_IRenderPass + 6);
    MyGL::Adapter::Adapter(&adapter, s);
    v1(s->renderAlgo, &adapter);
}

void MyGL::Scene::removeObject(MyGL::IGraphicsObject *const o) {
    __int64 v2;

    (*((void (__fastcall **)(MyGL::IObjectCollection *,
                             MyGL::IGraphicsObject *const)) this->obj->_vptr_IObjectCollection
       + 3))(
            this->obj,
            o);
    v2 = (*((__int64 (__fastcall **)(MyGL::Scene &)) this->_vptr_IScene + 8))(this);
    (*(void (__fastcall **)(__int64, MyGL::IGraphicsObject *const)) (*(_QWORD *) v2 + 24LL))(v2, o);
}

MyGL::IRender *MyGL::Scene::render() {
    return this->mrender;
}

MyGL::IRenderAlgoSettings *MyGL::Scene::settings() {
    (*((void (__fastcall **)(MyGL::Scene &)) this->_vptr_IScene + 18))(this);
    if (this->renderAlgo)
        return (MyGL::IRenderAlgoSettings *) (*(
                (__int64 (__fastcall **)(MyGL::IRenderAlgo *)) this->renderAlgo->_vptr_IRenderPass
                + 4))(this->renderAlgo);
    else
        return 0LL;
}

MyGL::IShaderLoader *MyGL::Scene::shaderLoader() {
    return this->shLoader;
}

MyGL::ITextureLoader *MyGL::Scene::textureLoader() {
    return this->texLoader;
}

void MyGL::Scene::upsetCameraEvent(MyGL::IRender &a2) {
    this->upsetLight();
}

void MyGL::Scene::upsetLight() {
    __int64 v1;
    __int64 v2;
    __int64 v3;
    int i;

    for (i = 0;; ++i) {
        v3 = (*((__int64 (__fastcall **)(MyGL::Scene &)) this->_vptr_IScene + 21))(this);
        if ((*(int (__fastcall **)(__int64)) (*(_QWORD *) v3 + 40LL))(v3) <= i)
            break;
        v1 = (*((__int64 (__fastcall **)(MyGL::Scene &)) this->_vptr_IScene + 21))(this);
        v2 = (*(__int64 (__fastcall **)(__int64, _QWORD)) (*(_QWORD *) v1 + 48LL))(v1, (unsigned int) i);
        (*(void (__fastcall **)(__int64)) (*(_QWORD *) v2 + 96LL))(v2);
    }
}
