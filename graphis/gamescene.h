#ifndef GAMESCENE_H
#define GAMESCENE_H

#include "MyGL/Scene.h"
#include "MyGL/IRenderAlgo.h"

class GameSceneGraph;

class GameScene : public MyGL::Scene {
public:
	GameScene();

	MyGL::ISceneGraph* allocSceneGraph();

	GameSceneGraph* getSceneGraph();

	void finitGL();

	bool initGL();

private:
	GameSceneGraph* graph;

	MyGL::IRenderAlgo* allocRenderAlgo();
};

#endif // GAMESCENE_H
