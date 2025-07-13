#pragma once

#include <cstdint>
#include <QOpenGLContext>
#include "DisableCopy.h"

namespace MyGL {
    class IVBO : public DisableCopy {
    public:
        class PrimitiveType {
        public:
            enum Type {
                Triangles = 0x0,
                TrianglesStrip = 0x1,
                Quads = 0x2,
                QuadsStrip = 0x3,
                Count = 0x4,
            };

        };

        class BindMode {
        public:
            enum Type {
                Vertex = 0x0,
                TexCoord = 0x1,
                Normal = 0x2,
                Color = 0x3,
                Count = 0x4,
            };
        };

    public:
        class IPointer {
        public:
            IPointer() = default;

            virtual ~IPointer() = default;//0
            //virtual ~IPointer() = default;//1

            virtual GLfloat *operator[](uint32_t) = 0; // 2

            virtual size_t size() = 0;//3
        };

    public:
        IVBO() = default;

        virtual ~IVBO() = default; // 0
        // virtual ~IVBO() = default;// 1
        virtual void bind(IVBO::BindMode::Type) = 0; // 2

        virtual void draw(bool, IVBO::PrimitiveType::Type) = 0; // 3

        virtual void uBind() = 0; // 4

        virtual void loadData(float const *, int) = 0; // 5

        virtual void allocate(int) = 0; // 6

        virtual void subData(int, int, void *) = 0; // 7

        virtual void free() = 0; // 8

        virtual IPointer *pointerToData() = 0; // 9


    };
}

