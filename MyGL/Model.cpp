#include <QOpenGLContext>
#include "Model.h"
#include "IVBO.h"
#include "IModelInfo.h"

namespace MyGL {
    Model::Model(IRender &r) {
        this->render = r;
        VBO::VBO(&this->vert, r);
        VBO::VBO(&this->tex, r);
        VBO::VBO(&this->norm, r);
        VBO::VBO(&this->extra, r);
        this->type = IVBO::PrimitiveType::Type::Triangles;
        this->size = 0;
        mCullInform = (ModelInfo *) operator new(0x40uLL);
        this->mCullInform = new ModelInfo::ModelInfo();
    }

    Model::~Model() {
        if (this->mCullInform)
            delete this->mCullInform;
    }

    void Model::allocate(size_t s) {
        this->size = s;
        this->vert.allocate(3 * this->size);
        this->tex.allocate(2 * this->size);
        this->norm.allocate(3 * this->size);
        this->extra.allocate(4 * this->size);
    }

    void Model::bind() {
        if (this->extra.size()) {
            glEnableClientState(32886LL);
            this->render > bindVBO(&this->extra, 3LL);
        } else {
            glDisableClientState(32886LL);
        }

        this->render->bindVBO(&this->norm, 2LL);
        this->render->bindVBO(&this->tex, 1LL);
        this->render->bindVBO(&this->vert, 0LL);
    }

    Model::DataContent::flags Model::content() {
        Model::DataContent::flags c;

        c = Model::DataContent::flags::vertex | Model::DataContent::flags::texture |
            Model::DataContent::flags::normal;
        if (this->extra.size())
            return 15;
        return c;
    }

    const IModelInfo *Model::cullInfo(const) {
        return this->mCullInform;
    }

    void Model::draw(bool binded) {
        if (!binded)
            this->bind();

        this->render->drawVBO((unsigned int) this->type, this->size);
    }

    void Model::drawInstance(int Isize, CGL::GLint *fist, CGL::GLsizei *count, bool binded) {
        if (Isize >= 0) {
            if (!binded)
                this->bind();
            if (Isize <= 1) {
                glDrawArrays((unsigned int) this->type, (unsigned int) *fist, (unsigned int) *count);
            } else {
                this->render->gl()->ext()->glMultiDrawArraysEXT(this->type, fist, count, Isize);
            }
        } else {
            this->draw(binded);
        }
    }

    IVBO *Model::extraBuffer() {
        return &this->extra;
    }

    void Model::free() {
        this->vert.free();
        this->tex.free();
        this->norm.free();
        this->extra.free();
    }

    void Model::load(IIOModel *const m) {
        CGL::GLsizei s;
        const CGL::GLfloat *data;
        CGL::GLsizei s_1;
        const CGL::GLfloat *data_1;
        CGL::GLsizei s_2;
        const CGL::GLfloat *data_2;
        CGL::GLsizei s_3;
        const CGL::GLfloat *data_3;

        if (m->size()) {
            s = 3 * m->size();
            data = (const CGL::GLfloat *) m->points();
            this->vert->loadData(data, s);
            s_1 = 2 * m->size();
            data_1 = (const CGL::GLfloat *) m->textureCoords();
            this->tex->loadData(data_1, s_1);
            s_2 = 3 * m->size();
            data_2 = (const CGL::GLfloat *) m->normals();
            this->norm->loadData(data_2, s_2);
            if (m->extraData()) {
                s_3 = 4 * m->size();
                data_3 = (const CGL::GLfloat *) m->extraData();
                this->extra->loadData(data_3, s_3);
            }
            this->type = IVBO::PrimitiveType::Type::Triangles;
            this->size = m->size();
            this->mCullInform->updateFrom(m);
        }
    }

    IVBO *Model::normalBuffer() {
        return &this->norm;
    }

    IVBO::PrimitiveType::Type Model::primitiveType() {
        return this->type;
    }

    void Model::setPrimitivesType(IVBO::PrimitiveType::Type t) {
        this->type = t;
    }

    IVBO *Model::textureBuffer() {
        return &this->tex;
    }

    void Model::uBind() {
        if (VBO::size(&this->extra))
            this->render->ubindVBO(&this->extra);
        this->render->ubindVBO(&this->norm);
        this->render->ubindVBO(&this->tex);
        this->render->ubindVBO(&this->vert);
        glDisableClientState(32886LL);
    }

    void Model::unsetCullInfo() {
        this->mCullInform->setBox(
                -3.4028235e38,
                -3.4028235e38,
                -3.4028235e38,
                3.4028235e38,
                3.4028235e38,
                3.4028235e38);
    }

    IVBO *Model::vertexBuffer() {
        return this->vert;
    }
}