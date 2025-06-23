#pragma once

#include "IVBO.h"
#include "CGL.h"
#include "Data.h"

namespace MyGL {

    class VBO : public IVBO {
    public:
        class Pointer {
        public:
            typedef unsigned int size_type;
        public:
            Pointer(void *buf);

            Pointer(const Pointer &p);

            virtual ~Pointer();

            GLfloat *operator[](size_type id);

            unsigned int size();

        public:

            void *vbo;
        };

    public:
        VBO(IRender &r);

        virtual ~VBO();

        void free();

        void subData(CGL::GLsizei offset, CGL::GLsizei size, void *data);

        void allocate(CGL::GLsizei size);

        void loadData(const CGL::GLfloat *data, CGL::GLsizei s);

        void bind(IVBO::BindMode::Type mode);

        void draw(bool binded, IVBO::PrimitiveType::Type p);

        void uBind();

        CGL::GLuint size();

        VBO::Pointer data();

        IVBO::IPointer *pointerToData();

        void addRef();

        void delRef();

    protected:
        CGL::VertexBufferHandle vertices;
        CGL::GLuint _size;
        size_t refCount;
        IRender &render;
        void *map;
    };

}
