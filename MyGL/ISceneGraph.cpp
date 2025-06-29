#include "ISceneGraph.h"

namespace MyGL {
    ISceneGraph::Visibles::Visibles(ISceneGraph &s) : graph(s) {
        this->count = this->graph.visiblesCount();
    }

    IGraphicsObject *ISceneGraph::Visibles::operator[](int id) {
        return this->graph.visible(id);
    }

    size_t ISceneGraph::Visibles::size() {
        return this->count;
    }

}
