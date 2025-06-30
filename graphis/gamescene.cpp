#include "gamescene.h"

#include <MyGL/CGL.h>
#include <MyGL/SceneGraph.h>
#include <MyGL/Adapter.h>
#include "gamescenegraph.h"
#include "renderalgo.h"

#include "gadapter.h"


GameScene::GameScene() : Scene(new MyGL::CGL()) {
    graph = 0;
}

MyGL::ISceneGraph *GameScene::allocSceneGraph() {
    graph = new GameSceneGraph(this);
    return graph;
}

GameSceneGraph *GameScene::getSceneGraph() {
    return graph;
}

void GameScene::finitGL() {
}

bool GameScene::initGL() {
    return false;
}

MyGL::IRenderAlgo *GameScene::allocRenderAlgo() {
    return new RenderAlgo(this, static_cast<const ::Adapter *>(new ::Adapter(this)));
}

