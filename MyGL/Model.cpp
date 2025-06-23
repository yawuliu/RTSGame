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
            (*((void (__fastcall **)(IRender *const, VBO *, __int64)) this->render->_vptr_IRender +
               19))(
                    this->render,
                    &this->extra,
                    3LL);
        } else {
            glDisableClientState(32886LL);
        }
        (*((void (__fastcall **)(IRender *const, VBO *, __int64)) this->render->_vptr_IRender + 19))(
                this->render,
                &this->norm,
                2LL);
        (*((void (__fastcall **)(IRender *const, VBO *, __int64)) this->render->_vptr_IRender + 19))(
                this->render,
                &this->tex,
                1LL);
        (*((void (__fastcall **)(IRender *const, VBO *, _QWORD)) this->render->_vptr_IRender + 19))(
                this->render,
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
            (*((void (__fastcall **)(Model *const)) this->_vptr_IModel + 2))(this);
        (*((void (__fastcall **)(IRender *const, _QWORD, _QWORD)) this->render->_vptr_IRender + 21))(
                this->render,
                (unsigned int) this->type,
                this->size);
    }

    void Model::drawInstance(int Isize, CGL::GLint *fist, CGL::GLsizei *count, bool binded) {
        CGL *v5;
        privateGLSupportClass *v6;

        if (Isize >= 0) {
            if (!binded)
                (*((void (__fastcall **)(Model *const)) this->_vptr_IModel + 2))(this);
            if (Isize <= 1) {
                glDrawArrays((unsigned int) this->type, (unsigned int) *fist, (unsigned int) *count);
            } else {
                v5 = (CGL *) (*((__int64 (__fastcall **)(IRender *const)) this->render->_vptr_IRender +
                                9))(this->render);
                v6 = CGL::ext(v5);
                v6->glMultiDrawArraysEXT(this->type, fist, count, Isize);
            }
        } else {
            (*((void (__fastcall **)(Model *const, bool)) this->_vptr_IModel + 6))(this, binded);
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
            VBO::loadData(&this->vert, data, s);
            s_1 = 2 * (*((__int64 (__fastcall **)(IIOModel *const)) m->_vptr_IIOModel + 18))(m);
            data_1 = (const CGL::GLfloat *) (*(
                    (__int64 (__fastcall **)(IIOModel *const)) m->_vptr_IIOModel + 9))(m);
            VBO::loadData(&this->tex, data_1, s_1);
            s_2 = 3 * (*((__int64 (__fastcall **)(IIOModel *const)) m->_vptr_IIOModel + 18))(m);
            data_2 = (const CGL::GLfloat *) (*(
                    (__int64 (__fastcall **)(IIOModel *const)) m->_vptr_IIOModel + 10))(m);
            VBO::loadData(&this->norm, data_2, s_2);
            if ((*((__int64 (__fastcall **)(IIOModel *const)) m->_vptr_IIOModel + 11))(m)) {
                s_3 = 4 * (*((__int64 (__fastcall **)(IIOModel *const)) m->_vptr_IIOModel + 18))(m);
                data_3 = (const CGL::GLfloat *) (*(
                        (__int64 (__fastcall **)(IIOModel *const)) m->_vptr_IIOModel + 11))(m);
                VBO::loadData(&this->extra, data_3, s_3);
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
            (*((void (__fastcall **)(IRender *const, VBO *)) this->render->_vptr_IRender + 20))(
                    this->render,
                    &this->extra);
        (*((void (__fastcall **)(IRender *const, VBO *)) this->render->_vptr_IRender + 20))(
                this->render,
                &this->norm);
        (*((void (__fastcall **)(IRender *const, VBO *)) this->render->_vptr_IRender + 20))(
                this->render,
                &this->tex);
        (*((void (__fastcall **)(IRender *const, VBO *)) this->render->_vptr_IRender + 20))(
                this->render,
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