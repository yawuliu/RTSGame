#include "ISceneGraph.h"
namespace MyGL {
	ISceneGraph::Visibles::Visibles(ISceneGraph& s) :graph(s) {
		this->count = (*(__int64(__fastcall**)(void*))(*(_QWORD*)this->graph + 80LL))(this->graph);
	}

	ISceneGraph* ISceneGraph::Visibles::operator[](size_t i) {
		return (IGraphicsObject*)(*(__int64(__fastcall**)(void*, _QWORD))(*(_QWORD*)this->graph + 72LL))(
			this->graph,
			(unsigned int)id);
	}

	size_t ISceneGraph::Visibles::size() {
		return this->count;
	}

}
