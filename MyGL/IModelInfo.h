#pragma once

namespace MyGL {
    class IModelInfo {
    public:
        virtual float radius() const = 0;

        virtual float maxX() const = 0;

        virtual float maxY() const = 0;

        virtual float minX() const = 0;

        virtual float minY() const = 0;

        virtual float maxZ() const = 0;

        virtual float minZ() const = 0;
    };
}

