#include "VBO.h"
#include "IErrorControl.h"

namespace MyGL {
    VBO::Pointer::Pointer(VBO *buf) {
        this->vbo = buf;
        this->vbo->addRef();
    }

    VBO::Pointer::Pointer(const Pointer &p) {
        p.vbo->addRef();
        this->vbo->delRef();
    }

    VBO::Pointer::~Pointer() {
        this->vbo->delRef();
    }

    GLfloat *VBO::Pointer::operator[](uint32_t id) {
        return (GLfloat *) ((char *) this->vbo->map + 4 * id);
    }

    size_t VBO::Pointer::size() {
        return this->vbo->_size;
    }

    VBO::VBO(IRender &r) : render(r) {
        this->vertices = 0;
        this->_size = 0;
        this->refCount = 0LL;
    }

    VBO::~VBO() {
        this->free();
    }

    void VBO::free() {
        if (this->vertices) {
            this->render.gl()->ext()->glDeleteBuffersARB(1LL, &this->vertices);
            this->vertices = 0;
        }
    }

    void VBO::subData(CGL::GLsizei offset, CGL::GLsizei size, void *data) {
        this->render.gl()->ext()->glBufferSubDataARB(34962LL, offset, size, data);
    }

    void VBO::allocate(CGL::GLsizei size) {
        this->loadData(0LL, (unsigned int) size);
    }

    void VBO::loadData(const CGL::GLfloat *data, CGL::GLsizei s) {
        if (!this->vertices) {
            this->render.gl()->ext()->glGenBuffersARB(1LL, &this->vertices);
        }
        this->_size = s;
        this->render.gl()->ext()->glBindBufferARB(34962LL, this->vertices);
        this->render.gl()->ext()->glBufferDataARB(34962LL, 4LL * this->_size, data, 35044LL);
    }

    void VBO::bind(IVBO::BindMode::Type mode) {
        CGL *v2;
        IErrorControl *v3;
        CGL *v4;
        privateGLSupportClass *v5;

        if (this->refCount) {
            this->render.gl()->errorCtrl()->fail(0LL, "[error]VBO::bind : buffer is already mapped!");
        }
        this->render.gl()->ext()->glBindBufferARB(34962LL, this->vertices);
        if (mode) {
            switch (mode) {
                case IVBO::BindMode::Type::TexCoord:
                    glTexCoordPointer(2LL, 5126LL, 0LL, 0LL);
                    break;
                case IVBO::BindMode::Type::Normal:
                    glNormalPointer(5126LL, 0LL, 0LL);
                    break;
                case IVBO::BindMode::Type::Color:
                    glColorPointer(4LL, 5126LL, 0LL, 0LL);
                    break;
            }
        } else {
            glVertexPointer(3LL, 5126LL, 0LL, 0LL);
        }
    }

    static const unsigned int primitiveT[5] = {4, 5, 7, 8, 0};

    void VBO::draw(bool binded, IVBO::PrimitiveType::Type p) {

        if (!binded)
            this->bind(IVBO::BindMode::Type::Vertex);
        glDrawArrays(primitiveT[p], 0LL, this->_size);
    }

    void VBO::uBind() {
        this->render.gl()->ext()->glBindBufferARB(34962LL, 0LL);
    }

    CGL::GLuint VBO::size() {
        return this->_size;
    }

    VBO::Pointer VBO::data() {
        return this;
    }

    IVBO::IPointer *VBO::pointerToData() {
        return new Pointer();
    }

    void VBO::addRef() {
        if (++this->refCount == 1) {
            this->render.gl()->ext()->glBindBufferARB(34962LL, this->vertices);
            this->map = this->render.gl()->ext()->glMapBufferARB(34962LL, 35002LL);
        }
    }

    void VBO::delRef() {
        if (!--this->refCount) {
            this->render.gl()->ext()->glBindBufferARB(34962LL, this->vertices);
            this->map = 0LL;
            this->render.gl()->ext()->glUnmapBufferARB(34962LL);
        }
    }
}