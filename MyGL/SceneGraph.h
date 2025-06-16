#pragma once

#include <vector>
#include "MyGL/ISceneGraph.h"

namespace MyGL {
	class IScene;

	class IGraphicsObject;

	class SceneGraph : public ISceneGraph {
	public:
		SceneGraph(IScene*);

		void updateCull();

		void endFrame();

		void addObjectEvent(IGraphicsObject* obj) override;

		void delObjectEvent(IGraphicsObject* obj) override;


		// ͨ�� ISceneGraph �̳�
		bool isObjectVisible(const IGraphicsObject* obj) const override;
	};
}


