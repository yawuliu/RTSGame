#pragma once

#include <cstdint>
#include <fstream>
#include <ostream>
#include "IIOModel.h"
#include "CGL.h"

namespace MyGL {

    class IOModel : public IIOModel {
    public:
        typedef MyGL::IIOModel::Point Normal;
    public:
        IOModel();

        ~IOModel() override;

        void allock(size_t vertexCount) override;

        void computeTBN();

        void createExtra() override;

        void deleteExtra() override;

        IIOModel::Point4 *exPoint(int i) override;

        const CGL::GLfloat *extraData() override;

        void free() override;

        bool load(const std::string &fname) override;

        bool loadBin_v0(const std::string &fname) override;

        IOModel::Normal *normal(int i) override;

        const CGL::GLfloat *normals() override;

        IIOModel::Point *point(int i) override;

        const CGL::GLfloat *points() override;

        bool save(const std::string &fname) override;

        bool saveBin(const std::string &fname) override;

        int size() override;

        IIOModel::TexCoord *texCoord(int i) override;

        const CGL::GLfloat *textureCoords() override;

    protected:
        CGL::GLfloat *vert;
        CGL::GLfloat *tex;
        CGL::GLfloat *norm;
        CGL::GLfloat *extra;
        int msize;
        //0000002C     // padding byte
        //    0000002D     // padding byte
        //    0000002E     // padding byte
        //    0000002F     // padding byte
        void *shadow_data;
    };
}


