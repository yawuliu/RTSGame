#pragma once

#include "IVBO.h"
#include "CGL.h"
#include "Data.h"
#include "IRender.h"

namespace MyGL {

    class VBO : public IVBO {
    public:
        class Pointer : public IVBO::IPointer {
        public:
            explicit Pointer(VBO *buf);

            Pointer(const Pointer &p);

            ~Pointer() override;

            GLfloat *operator[](uint32_t id) override;

            size_t size() override;

        public:
            VBO *vbo;
        };

    public:
        explicit VBO(IRender &r);

        ~VBO() override;

        void free() override;

        void subData(CGL::GLsizei offset, CGL::GLsizei size, void *data) override;

        void allocate(CGL::GLsizei size) override;

        void loadData(const CGL::GLfloat *data, CGL::GLsizei s) override;

        void bind(IVBO::BindMode::Type mode) override;

        void draw(bool binded, IVBO::PrimitiveType::Type p) override;

        void uBind() override;

        CGL::GLuint size();

        VBO::Pointer *data();

        IVBO::IPointer *pointerToData() override;

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
