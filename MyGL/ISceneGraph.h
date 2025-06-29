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

            IGraphicsObject *operator[](int i);

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

        virtual bool isObjectVisible(IGraphicsObject const &) = 0;//7

        virtual void updateVisible() = 0;//8

        virtual IGraphicsObject *visible(int) = 0;//9

        virtual int visiblesCount() = 0;//10

    };
}
