#pragma once

#include <cstdint>

namespace MyGL {
	class IGraphicsObject;

	class ISceneGraph {
	public:
		class Visibles {
		public:
			Visibles(ISceneGraph*);

			ISceneGraph* operator[](size_t i);

			size_t size();
		};

		virtual void addObjectEvent(IGraphicsObject* obj) = 0;

		virtual void delObjectEvent(IGraphicsObject* obj) = 0;

		virtual bool isObjectVisible(const IGraphicsObject* obj) const = 0;

	};
}
