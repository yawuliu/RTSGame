#include "ISceneGraph.h"

MyGL::ISceneGraph::Visibles::Visibles(MyGL::ISceneGraph *) {

}

MyGL::ISceneGraph *MyGL::ISceneGraph::Visibles::operator[](size_t i) {
    return nullptr;
}

size_t MyGL::ISceneGraph::Visibles::size() {
    return 0;
}


