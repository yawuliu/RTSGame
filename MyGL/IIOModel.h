#pragma once

#include "CGL.h"

namespace MyGL {
    class IIOModel {
    public:
        class TexCoord {
        public:
            CGL::GLfloat *d;
            CGL::GLfloat *const x;
            CGL::GLfloat *const y;
        };

        class Point4 {
        public:
            CGL::GLfloat *d;
            CGL::GLfloat *const x;
            CGL::GLfloat *const y;
            CGL::GLfloat *const z;
            CGL::GLfloat *const w;
        };

        class Point {
        public:
            CGL::GLfloat *d;
            CGL::GLfloat *const x;
            CGL::GLfloat *const y;
            CGL::GLfloat *const z;
        };

        typedef Point Normal;

        virtual ~IIOModel() = default; // 0
        // virtual ~IIOModel() = default; // 1
        virtual void loadBin_v0(std::string const &) = 0; // 2
        virtual void load(std::string const &) = 0; //  3
        virtual void saveBin(std::string const &) = 0; // 4
        virtual void save(std::string const &) = 0; // 5
        virtual void allock(uint64_t) = 0; // 6
        virtual void free() = 0; // 7
        virtual void points() = 0; // 8
        virtual void textureCoords() = 0; // 9
        virtual void normals() = 0; // 10
        virtual void extraData() = 0; // 11
        virtual void point(int) = 0; // 12
        virtual void texCoord(int) = 0; // 13
        virtual void normal(int) = 0; // 14
        virtual void exPoint(int) = 0; // 15
        virtual void createExtra() = 0; // 16
        virtual void deleteExtra() = 0; // 17
        virtual void size() = 0; // 18
    };
}

