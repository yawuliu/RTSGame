#pragma once

#include "IIOModel.h"

namespace MyGL {
    class IModelInfo {
    public:
        IModelInfo() = default;

        virtual ~IModelInfo() = default; // 0
        // virtual ~IModelInfo() = default; // 1
        virtual void minX() = 0; // 2
        virtual void minY() = 0; // 3
        virtual void minZ() = 0; // 4
        virtual void maxX() = 0; // 5
        virtual void maxY() = 0; // 6
        virtual void maxZ() = 0; // 7
        virtual void radius() = 0; // 8
        virtual void updateFrom(IIOModel &) = 0; // 9
        virtual void operator=(IModelInfo const &) = 0; // 10
    };
}

