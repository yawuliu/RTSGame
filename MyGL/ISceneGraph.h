#pragma once

#include <cstdint>
#include "IGraphicsObject.h"

namespace MyGL {
    class IGraphicsObject;

    class ISceneGraph {
    public:
        ISceneGraph() = default;

        virtual ~ISceneGraph() = default;

        class Visibles {
        public:
            Visibles(ISceneGraph &);

            ISceneGraph *operator[](size_t i);

            size_t size();

        protected:
            ISceneGraph &graph;
            size_t count;
        };

        virtual void addObjectEvent(IGraphicsObject &obj) = 0;

        virtual void delObjectEvent(IGraphicsObject &obj) = 0;

        virtual bool isObjectVisible(const IGraphicsObject &obj) const = 0;

    };
}
