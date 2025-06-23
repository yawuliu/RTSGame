#include "Scene.h"
#include "IRender.h"
namespace MyGL {
	Scene::Scene(CGL* gl) {
		Render* mrender;
		this->auto_render = 1;
		mrender = (Render*) operator new(0x188uLL);
		Render::Render(mrender, gl);
		this->mrender = mrender;
		this->init();
	}

	Scene::Scene(IRender& r) {
		this->auto_render = 0;
		this->mrender = r;
		this->init();
	}

	Scene::~Scene() {
		if (this->renderAlgo)
			(*((void(__fastcall**)(IRenderAlgo*)) this->renderAlgo->_vptr_IRenderPass + 1))(
				this->renderAlgo);
		if (this->dataL)
			(*((void(__fastcall**)(IData*)) this->dataL->_vptr_IData + 1))(this->dataL);
		if (this->texLoader)
			(*((void(__fastcall**)(ITextureLoader*)) this->texLoader->_vptr_ITextureLoader + 1))(
				this->texLoader);
		if (this->shLoader)
			(*((void(__fastcall**)(IShaderLoader*)) this->shLoader->_vptr_IShaderLoader + 1))(
				this->shLoader);
		if (this->mLoader)
			(*((void(__fastcall**)(IModelLoader*)) this->mLoader->_vptr_IModelLoader + 1))(this->mLoader);
		if (this->obj)
			(*((void(__fastcall**)(IObjectCollection*)) this->obj->_vptr_IObjectCollection + 1))(
				this->obj);
		if (this->light)
			(*((void(__fastcall**)(ILightsCollection*)) this->light->_vptr_ILightsCollection + 1))(
				this->light);
		if (this->sceneGraph)
			(*((void(__fastcall**)(ISceneGraph*)) this->sceneGraph->_vptr_ISceneGraph + 1))(
				this->sceneGraph);
		if (this->mrender)
			(*((void(__fastcall**)(IRender*)) this->mrender->_vptr_IRender + 1))(this->mrender);
	}

	ILightsCollection* Scene::allocLightsCollection(Scene& s) {
		LightsCollection* v1;

		v1 = (LightsCollection*) operator new(0x18uLL);
		LightsCollection::LightsCollection(v1, s);
		return v1;
	}

	void Scene::allocLoaders() {
		if (!this->texLoader)
			this->texLoader = (ITextureLoader*)(*(
				(__int64(__fastcall**)(Scene&)) this->_vptr_IScene + 23))(this);
		if (!this->shLoader)
			this->shLoader = (IShaderLoader*)(*(
				(__int64(__fastcall**)(Scene&)) this->_vptr_IScene + 24))(this);
		if (!this->mLoader)
			this->mLoader = (IModelLoader*)(*(
				(__int64(__fastcall**)(Scene&)) this->_vptr_IScene + 25))(this);
	}

	IModelLoader* Scene::allocModelLoader() {
		IRender* r;
		ModelLoader* v2;

		r = (IRender*)(*((__int64(__fastcall**)(Scene&)) this->_vptr_IScene + 3))(this);
		v2 = (ModelLoader*) operator new(0x10uLL);
		ModelLoader::ModelLoader(v2, r);
		return v2;
	}

	IObjectCollection* Scene::allocObjectCollection(Scene& s) {
		ObjectCollection* v1;

		v1 = (ObjectCollection*) operator new(0x18uLL);
		ObjectCollection::ObjectCollection(v1, s);
		return v1;
	}

	IRenderAlgo* Scene::allocRenderAlgo(Scene& s) {
		ForwardRenderAlgo* v1;
		Adapter adapter;

		Adapter::Adapter(&adapter, s);
		v1 = (ForwardRenderAlgo*) operator new(0x70uLL);
		ForwardRenderAlgo::ForwardRenderAlgo(v1, s, &adapter, 1);
		return v1;
	}

	ISceneGraph* Scene::allocSceneGraph(Scene& s) {
		SceneGraph* v1;

		v1 = (SceneGraph*) operator new(0x168uLL);
		SceneGraph::SceneGraph(v1, s);
		return v1;
	}

	IShaderLoader* Scene::allocShaderLoader() {
		IRender* r;
		ShaderLoader* v2;

		r = (IRender*)(*((__int64(__fastcall**)(Scene&)) this->_vptr_IScene + 3))(this);
		v2 = (ShaderLoader*) operator new(0x18uLL);
		ShaderLoader::ShaderLoader(v2, r);
		return v2;
	}

	ITextureLoader* Scene::allocTextureLoader() {
		IRender* r;
		TextureLoader* v2;

		r = (IRender*)(*((__int64(__fastcall**)(Scene&)) this->_vptr_IScene + 3))(this);
		v2 = (TextureLoader*) operator new(0x18uLL);
		TextureLoader::TextureLoader(v2, r);
		return v2;
	}

	void Scene::changeObject(IGraphicsObject* const o, IMaterial* const m) {
		(*((void(__fastcall**)(IObjectCollection*, IGraphicsObject* const,
			IMaterial* const)) this->obj->_vptr_IObjectCollection
			+ 4))(
				this->obj,
				o,
				m);
	}

	void Scene::createRenderAlgo() {
		if (!this->renderAlgo)
			this->renderAlgo = (IRenderAlgo*)(*(
				(__int64(__fastcall**)(Scene&)) this->_vptr_IScene + 30))(this);
	}

	IData* Scene::dataControl() {
		return this->dataL;
	}

	void Scene::draw() {
		(*((void(__fastcall**)(Scene&)) this->_vptr_IScene + 18))(this);
		(*((void(__fastcall**)(IRender*, Scene&)) this->mrender->_vptr_IRender + 52))(
			this->mrender, this);
		Scene::upsetLight(this);
		(*((void(__fastcall**)(IRenderAlgo*)) this->renderAlgo->_vptr_IRenderPass + 2))(this->renderAlgo);
	}

	void Scene::finitGL() {
		__int64 v1;

		v1 = (*((__int64(__fastcall**)(Scene&)) this->_vptr_IScene + 3))(this);
		(*(void(__fastcall**)(__int64)) (*(_QWORD*)v1 + 64LL))(v1);
	}

	ISceneGraph* Scene::graph() {
		return this->sceneGraph;
	}

	void Scene::init() {
		Data* dataL;

		dataL = (Data*) operator new(0x18uLL);
		Data::Data(dataL, this->mrender);
		this->dataL = dataL;
		this->texLoader = 0LL;
		this->shLoader = 0LL;
		this->mLoader = 0LL;
		this->obj = 0LL;
		this->light = 0LL;
		this->sceneGraph = 0LL;
		this->renderAlgo = 0LL;
		(*((void(__fastcall**)(IRender*, Scene&)) this->mrender->_vptr_IRender + 52))(
			this->mrender, this);
	}

	bool Scene::initGL() {
		__int64 v1;
		__int64 v2;
		__int64 v3;
		void(__fastcall * v4)(__int64, __int64);
		__int64 v5;
		__int64 v6;
		__int64 v7;
		void(__fastcall * v8)(__int64, __int64);
		__int64 v9;
		__int64 v10;
		__int64 v11;
		void(__fastcall * v12)(__int64, __int64);
		__int64 v13;

		v1 = (*((__int64(__fastcall**)(Scene&)) this->_vptr_IScene + 3))(this);
		if (!(*(unsigned __int8(__fastcall**)(__int64)) (*(_QWORD*)v1 + 48LL))(v1))
			return 0;
		this->obj = (IObjectCollection*)(*(
			(__int64(__fastcall**)(Scene&)) this->_vptr_IScene + 26))(this);
		this->light = (ILightsCollection*)(*(
			(__int64(__fastcall**)(Scene&)) this->_vptr_IScene + 27))(this);
		this->sceneGraph = (ISceneGraph*)(*(
			(__int64(__fastcall**)(Scene&)) this->_vptr_IScene + 28))(this);
		(*((void(__fastcall**)(Scene&)) this->_vptr_IScene + 29))(this);
		Scene::allocLoaders(this);
		v2 = (*((__int64(__fastcall**)(Scene&)) this->_vptr_IScene + 2))(this);
		v3 = (*(__int64(__fastcall**)(__int64)) (*(_QWORD*)v2 + 24LL))(v2);
		v4 = *(void(__fastcall**)(__int64, __int64)) (*(_QWORD*)v3 + 16LL);
		v5 = (*((__int64(__fastcall**)(Scene&)) this->_vptr_IScene + 5))(this);
		v4(v3, v5);
		v6 = (*((__int64(__fastcall**)(Scene&)) this->_vptr_IScene + 2))(this);
		v7 = (*(__int64(__fastcall**)(__int64)) (*(_QWORD*)v6 + 24LL))(v6);
		v8 = *(void(__fastcall**)(__int64, __int64)) (*(_QWORD*)v7 + 56LL);
		v9 = (*((__int64(__fastcall**)(Scene&)) this->_vptr_IScene + 7))(this);
		v8(v7, v9);
		v10 = (*((__int64(__fastcall**)(Scene&)) this->_vptr_IScene + 2))(this);
		v11 = (*(__int64(__fastcall**)(__int64)) (*(_QWORD*)v10 + 24LL))(v10);
		v12 = *(void(__fastcall**)(__int64, __int64)) (*(_QWORD*)v11 + 112LL);
		v13 = (*((__int64(__fastcall**)(Scene&)) this->_vptr_IScene + 6))(this);
		v12(v11, v13);
		return 1;
	}

	void Scene::initLightsCollection() {
		ILightsCollection* c;
		Light* v2;

		c = (ILightsCollection*)(*((__int64(__fastcall**)(Scene&)) this->_vptr_IScene + 21))(
			this);
		v2 = (Light*) operator new(0x68uLL);
		Light::Light(v2, c);
		(*((void(__fastcall**)(Light*, __int64)) v2->_vptr_ILight + 6))(v2, 1LL);
	}

	void Scene::insertObject(IGraphicsObject* const o) {
		__int64 v2;

		(*((void(__fastcall**)(IObjectCollection*,
			IGraphicsObject* const)) this->obj->_vptr_IObjectCollection
			+ 2))(
				this->obj,
				o);
		v2 = (*((__int64(__fastcall**)(Scene&)) this->_vptr_IScene + 8))(this);
		(*(void(__fastcall**)(__int64, IGraphicsObject* const)) (*(_QWORD*)v2 + 16LL))(v2, o);
	}

	ILightsCollection* Scene::lights() {
		return this->light;
	}

	IDataLoader* Scene::loader() {
		__int64 v1;

		v1 = (*((__int64(__fastcall**)(Scene&)) this->_vptr_IScene + 2))(this);
		return (IDataLoader*)(*(__int64(__fastcall**)(__int64)) (*(_QWORD*)v1 + 24LL))(v1);
	}

	IModelLoader* Scene::modelLoader() {
		return this->mLoader;
	}

	IObjectCollection* Scene::objects() {
		return this->obj;
	}

	void Scene::recreateRenderAlgo(Scene& s) {
		void(__fastcall * v1)(IRenderAlgo*, Adapter*);
		Adapter adapter;

		(*((void(__fastcall**)(Scene&)) s->_vptr_IScene + 18))(s);
		v1 = (void(__fastcall*)(IRenderAlgo*, Adapter*)) * (
			(_QWORD*)s->renderAlgo->_vptr_IRenderPass + 6);
		Adapter::Adapter(&adapter, s);
		v1(s->renderAlgo, &adapter);
	}

	void Scene::removeObject(IGraphicsObject* const o) {
		__int64 v2;

		(*((void(__fastcall**)(IObjectCollection*,
			IGraphicsObject* const)) this->obj->_vptr_IObjectCollection
			+ 3))(
				this->obj,
				o);
		v2 = (*((__int64(__fastcall**)(Scene&)) this->_vptr_IScene + 8))(this);
		(*(void(__fastcall**)(__int64, IGraphicsObject* const)) (*(_QWORD*)v2 + 24LL))(v2, o);
	}

	IRender* Scene::render() {
		return this->mrender;
	}

	IRenderAlgoSettings* Scene::settings() {
		(*((void(__fastcall**)(Scene&)) this->_vptr_IScene + 18))(this);
		if (this->renderAlgo)
			return (IRenderAlgoSettings*)(*(
				(__int64(__fastcall**)(IRenderAlgo*)) this->renderAlgo->_vptr_IRenderPass
				+ 4))(this->renderAlgo);
		else
			return 0LL;
	}

	IShaderLoader* Scene::shaderLoader() {
		return this->shLoader;
	}

	ITextureLoader* Scene::textureLoader() {
		return this->texLoader;
	}

	void Scene::upsetCameraEvent(IRender& a2) {
		this->upsetLight();
	}

	void Scene::upsetLight() {
		__int64 v1;
		__int64 v2;
		__int64 v3;
		int i;

		for (i = 0;; ++i) {
			v3 = (*((__int64(__fastcall**)(Scene&)) this->_vptr_IScene + 21))(this);
			if ((*(int(__fastcall**)(__int64)) (*(_QWORD*)v3 + 40LL))(v3) <= i)
				break;
			v1 = (*((__int64(__fastcall**)(Scene&)) this->_vptr_IScene + 21))(this);
			v2 = (*(__int64(__fastcall**)(__int64, _QWORD)) (*(_QWORD*)v1 + 48LL))(v1, (unsigned int)i);
			(*(void(__fastcall**)(__int64)) (*(_QWORD*)v2 + 96LL))(v2);
		}
	}
}