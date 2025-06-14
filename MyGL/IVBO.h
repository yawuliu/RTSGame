#pragma once

#include <cstdint>

namespace MyGL {
    class IVBO {
    public:
        enum PrimitiveType {
            Quads
        };

        class IPointer {
        public:
            float &operator[](size_t i);

            float data[0];
        };

        virtual IPointer *pointerToData() = 0;

        virtual void subData(size_t, int, float[]) = 0;
    };
}

