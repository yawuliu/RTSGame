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
            (*((void (__fastcall **)(ModelInfo *)) this->mCullInform->_vptr_IModelInfo + 1))(
                    this->mCullInform);
    }

    void Model::allocate(size_t s) {
        this->size = s;
        VBO::allocate(&this->vert, 3 * this->size);
        VBO::allocate(&this->tex, 2 * this->size);
        VBO::allocate(&this->norm, 3 * this->size);
        VBO::allocate(&this->extra, 4 * this->size);
    }

    void Model::bind() {
        if (VBO::size(&this->extra)) {
            glEnableClientState(32886LL);

            this->render > bindVBO(
                    &this->extra,
                    3LL);
        } else {
            glDisableClientState(32886LL);
        }

        this->render->bindVBO(
                &this->norm,
                2LL);

        this->render->bindVBO(
                &this->tex,
                1LL);

        this->render->bindVBO(
                &this->vert,
                0LL);
    }

    Model::DataContent::flags Model::content() {
        Model::DataContent::flags c;

        c = Model::DataContent::flags::vertex | Model::DataContent::flags::texture |
            Model::DataContent::flags::normal;
        if (VBO::size(&this->extra))
            return 15;
        return c;
    }

    const IModelInfo *Model::cullInfo(const) {
        return this->mCullInform;
    }

    void Model::draw(bool binded) {
        if (!binded)
            this->bind();

        this->render->drawVBO(
                (unsigned int) this->type,
                this->size);
    }

    void Model::drawInstance(int Isize, CGL::GLint *fist, CGL::GLsizei *count, bool binded) {
        CGL *v5;
        privateGLSupportClass *v6;

        if (Isize >= 0) {
            if (!binded)
                this->bind();
            if (Isize <= 1) {
                glDrawArrays((unsigned int) this->type, (unsigned int) *fist, (unsigned int) *count);
            } else {
                v5 = this->render->gl();
                v6 = v5->ext();
                v6->glMultiDrawArraysEXT(this->type, fist, count, Isize);
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

        if ((*((unsigned int (__fastcall **)(IIOModel *const)) m->_vptr_IIOModel + 18))(m)) {
            s = 3 * (*((__int64 (__fastcall **)(IIOModel *const)) m->_vptr_IIOModel + 18))(m);
            data = (const CGL::GLfloat *) (*(
                    (__int64 (__fastcall **)(IIOModel *const)) m->_vptr_IIOModel + 8))(m);
            this->vert->loadData(data, s);
            s_1 = 2 * (*((__int64 (__fastcall **)(IIOModel *const)) m->_vptr_IIOModel + 18))(m);
            data_1 = (const CGL::GLfloat *) (*(
                    (__int64 (__fastcall **)(IIOModel *const)) m->_vptr_IIOModel + 9))(m);
            this->tex->loadData(data_1, s_1);
            s_2 = 3 * (*((__int64 (__fastcall **)(IIOModel *const)) m->_vptr_IIOModel + 18))(m);
            data_2 = (const CGL::GLfloat *) (*(
                    (__int64 (__fastcall **)(IIOModel *const)) m->_vptr_IIOModel + 10))(m);
            this->norm->loadData(data_2, s_2);
            if ((*((__int64 (__fastcall **)(IIOModel *const)) m->_vptr_IIOModel + 11))(m)) {
                s_3 = 4 * (*((__int64 (__fastcall **)(IIOModel *const)) m->_vptr_IIOModel + 18))(m);
                data_3 = (const CGL::GLfloat *) (*(
                        (__int64 (__fastcall **)(IIOModel *const)) m->_vptr_IIOModel + 11))(m);
                this->extra->loadData(data_3, s_3);
            }
            this->type = IVBO::PrimitiveType::Type::Triangles;
            this->size = (*((__int64 (__fastcall **)(IIOModel *const)) m->_vptr_IIOModel + 18))(m);
            (*((void (__fastcall **)(ModelInfo *,
                                     IIOModel *const)) this->mCullInform->_vptr_IModelInfo + 9))(
                    this->mCullInform,
                    m);
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

            this->render->ubindVBO(
                    &this->extra);

        this->render->ubindVBO(
                &this->norm);

        this->render->ubindVBO(
                &this->tex);

        this->render->ubindVBO(
                &this->vert);
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