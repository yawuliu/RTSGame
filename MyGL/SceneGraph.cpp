#include "SceneGraph.h"

MyGL::SceneGraph::SceneGraph(MyGL::IScene*) {

}

void MyGL::SceneGraph::addObjectEvent(MyGL::IGraphicsObject* obj) {

}

void MyGL::SceneGraph::delObjectEvent(MyGL::IGraphicsObject* obj) {

}

bool MyGL::SceneGraph::isObjectVisible(const IGraphicsObject* obj) const
{
	return false;
}


void MyGL::SceneGraph::updateCull() {

}

void MyGL::SceneGraph::endFrame() {

}

