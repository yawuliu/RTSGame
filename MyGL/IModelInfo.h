#pragma once

#include "IIOModel.h"

namespace MyGL {
    class IModelInfo {
    public:
        IModelInfo() = default;

        virtual ~IModelInfo() = default; // 0
        // virtual ~IModelInfo() = default; // 1
        virtual double minX() = 0; // 2
        virtual double minY() = 0; // 3
        virtual double minZ() = 0; // 4
        virtual double maxX() = 0; // 5
        virtual double maxY() = 0; // 6
        virtual double maxZ() = 0; // 7
        virtual double radius() = 0; // 8
        virtual void updateFrom(IIOModel &) = 0; // 9
        virtual IModelInfo &operator=(IModelInfo const &) = 0; // 10
    };
}

