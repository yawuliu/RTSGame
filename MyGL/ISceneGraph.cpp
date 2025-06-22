#include "ISceneGraph.h"

MyGL::ISceneGraph::Visibles::Visibles(MyGL::ISceneGraph &s):graph(s) {
    this->count = (*(__int64 (__fastcall **)(void *))(*(_QWORD *)this->graph + 80LL))(this->graph);
}

MyGL::ISceneGraph *MyGL::ISceneGraph::Visibles::operator[](size_t i) {
    return (MyGL::IGraphicsObject *)(*(__int64 (__fastcall **)(void *, _QWORD))(*(_QWORD *)this->graph + 72LL))(
            this->graph,
                    (unsigned int)id);
}

size_t MyGL::ISceneGraph::Visibles::size() {
    return this->count;
}


