#pragma once

#include <cstdint>
#include "IGraphicsObject.h"
#include "IRenderPass.h"

namespace MyGL {
    class ISceneGraph {
    public:
        ISceneGraph() = default;

        virtual ~ISceneGraph() = default; // 0
        //1
        class Visibles {
        public:
            Visibles(ISceneGraph &);

            ISceneGraph *operator[](size_t i);

            size_t size();

        protected:
            ISceneGraph &graph;
            size_t count;
        };

        virtual void addObjectEvent(IGraphicsObject &) = 0; // 2

        virtual void delObjectEvent(IGraphicsObject &) = 0;// 3

        virtual void beginFrame() = 0;// 4

        virtual void beginFrame(IRenderPass &) = 0;//5

        virtual void endFrame() = 0;//6

        virtual void isObjectVisible(IGraphicsObject const &) = 0;//7

        virtual void updateVisible() = 0;//8

        virtual void visible(int) = 0;//9

        virtual void visiblesCount() = 0;//10

    };
}
