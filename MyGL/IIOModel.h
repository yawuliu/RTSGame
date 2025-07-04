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
        virtual bool loadBin_v0(std::string const &) = 0; // 2
        virtual bool load(std::string const &) = 0; //  3
        virtual bool saveBin(std::string const &) = 0; // 4
        virtual bool save(std::string const &) = 0; // 5
        virtual void allock(uint64_t) = 0; // 6
        virtual void free() = 0; // 7
        virtual const CGL::GLfloat *points() = 0; // 8
        virtual const CGL::GLfloat *textureCoords() = 0; // 9
        virtual const CGL::GLfloat *normals() = 0; // 10
        virtual const CGL::GLfloat *extraData() = 0; // 11
        virtual IIOModel::Point *point(int) = 0; // 12
        virtual IIOModel::TexCoord *texCoord(int) = 0; // 13
        virtual IIOModel::Point *normal(int) = 0; // 14
        virtual IIOModel::Point4 *exPoint(int) = 0; // 15
        virtual void createExtra() = 0; // 16
        virtual void deleteExtra() = 0; // 17
        virtual int size() = 0; // 18
    };
}

