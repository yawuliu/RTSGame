#include "SceneGraph.h"

MyGL::SceneGraph::SceneGraph(MyGL::IScene *) {

}

void MyGL::SceneGraph::addObjectEvent(MyGL::IGraphicsObject *obj) {
    ISceneGraph::addObjectEvent(obj);
}

void MyGL::SceneGraph::delObjectEvent(MyGL::IGraphicsObject *obj) {
    ISceneGraph::delObjectEvent(obj);
}

void MyGL::SceneGraph::updateCull() {

}

void MyGL::SceneGraph::endFrame() {

}

bool MyGL::SceneGraph::isObjectVisible(MyGL::IGraphicsObject *obj) {
    return ISceneGraph::isObjectVisible(obj);
}
