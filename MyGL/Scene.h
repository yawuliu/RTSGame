#pragma once

#include <map>
#include <string>
#include "IData.h"
#include "IScene.h"
#include "LightsCollection.h"
#include "IObjectCollection.h"
#include "ObjectCollection.h"
#include "IRenderAlgoSettings.h"


namespace MyGL {
	class CGL;

	class Scene : public IScene {
	public:
		Scene(CGL* gl);

		Scene(IRender& r);

		virtual ~Scene();

		ILightsCollection* allocLightsCollection(Scene& s);

		void allocLoaders();

		IModelLoader* allocModelLoader();

		IObjectCollection* allocObjectCollection(Scene& s);

		IRenderAlgo* allocRenderAlgo(Scene& s);

		ISceneGraph* allocSceneGraph(Scene& s);

		IShaderLoader* allocShaderLoader();

		ITextureLoader* allocTextureLoader();

		void changeObject(IGraphicsObject& o, IMaterial& m);

		void createRenderAlgo();

		IData* dataControl();

		void draw();

		void finitGL();

		ISceneGraph* graph();

		void init();

		bool initGL();

		void initLightsCollection();

		void insertObject(IGraphicsObject& o);

		ILightsCollection* lights();

		IDataLoader* loader();

		IModelLoader* modelLoader();

		IObjectCollection* objects();

		void recreateRenderAlgo(Scene& s);

		void removeObject(IGraphicsObject& o);

		IRender* render();

		IRenderAlgoSettings* settings();

		IShaderLoader* shaderLoader();

		ITextureLoader* textureLoader();

		void upsetCameraEvent(IRender& a2);

		void upsetLight();

	protected:
		ITextureLoader* texLoader;
		IShaderLoader* shLoader;
		IModelLoader* mLoader;
		IRenderAlgo* renderAlgo;
		ISceneGraph* sceneGraph;
		IObjectCollection* obj;
		ILightsCollection* light;
		IRender* mrender;
		bool auto_render;
		//             // padding byte
		//        0000004A     // padding byte
		//        0000004B     // padding byte
		//        0000004C     // padding byte
		//        0000004D     // padding byte
		//        0000004E     // padding byte
		//        0000004F     // padding byte
		IData* dataL;
	};
}


