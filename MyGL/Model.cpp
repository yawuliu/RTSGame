#include "MyGL/Model.h"
#include "MyGL/IVBO.h"
#include "IModelInfo.h"

MyGL::Model::Model(MyGL::IRender &r) {
    this->render = r;
    MyGL::VBO::VBO(&this->vert, r);
    MyGL::VBO::VBO(&this->tex, r);
    MyGL::VBO::VBO(&this->norm, r);
    MyGL::VBO::VBO(&this->extra, r);
    this->type = MyGL::IVBO::PrimitiveType::Type::Triangles;
    this->size = 0;
    mCullInform = (MyGL::ModelInfo *) operator new(0x40uLL);
    this->mCullInform = new MyGL::ModelInfo::ModelInfo();
}

MyGL::Model::~Model() {
    if (this->mCullInform)
        (*((void (__fastcall **)(MyGL::ModelInfo *)) this->mCullInform->_vptr_IModelInfo + 1))(
                this->mCullInform);
}

void MyGL::Model::allocate(size_t s) {
    this->size = s;
    MyGL::VBO::allocate(&this->vert, 3 * this->size);
    MyGL::VBO::allocate(&this->tex, 2 * this->size);
    MyGL::VBO::allocate(&this->norm, 3 * this->size);
    MyGL::VBO::allocate(&this->extra, 4 * this->size);
}

void MyGL::Model::bind() {
    if (MyGL::VBO::size(&this->extra)) {
        glEnableClientState(32886LL);
        (*((void (__fastcall **)(MyGL::IRender *const, MyGL::VBO *, __int64)) this->render->_vptr_IRender +
           19))(
                this->render,
                &this->extra,
                3LL);
    } else {
        glDisableClientState(32886LL);
    }
    (*((void (__fastcall **)(MyGL::IRender *const, MyGL::VBO *, __int64)) this->render->_vptr_IRender + 19))(
            this->render,
            &this->norm,
            2LL);
    (*((void (__fastcall **)(MyGL::IRender *const, MyGL::VBO *, __int64)) this->render->_vptr_IRender + 19))(
            this->render,
            &this->tex,
            1LL);
    (*((void (__fastcall **)(MyGL::IRender *const, MyGL::VBO *, _QWORD)) this->render->_vptr_IRender + 19))(
            this->render,
            &this->vert,
            0LL);
}

MyGL::Model::DataContent::flags MyGL::Model::content() {
    MyGL::Model::DataContent::flags c;

    c = MyGL::Model::DataContent::flags::vertex | MyGL::Model::DataContent::flags::texture |
        MyGL::Model::DataContent::flags::normal;
    if (MyGL::VBO::size(&this->extra))
        return 15;
    return c;
}

const MyGL::IModelInfo *MyGL::Model::cullInfo(const) {
    return this->mCullInform;
}

void MyGL::Model::draw(bool binded) {
    if (!binded)
        (*((void (__fastcall **)(MyGL::Model *const)) this->_vptr_IModel + 2))(this);
    (*((void (__fastcall **)(MyGL::IRender *const, _QWORD, _QWORD)) this->render->_vptr_IRender + 21))(
            this->render,
            (unsigned int) this->type,
            this->size);
}

void MyGL::Model::drawInstance(int Isize, MyGL::CGL::GLint *fist, MyGL::CGL::GLsizei *count, bool binded) {
    MyGL::CGL *v5;
    MyGL::privateGLSupportClass *v6;

    if (Isize >= 0) {
        if (!binded)
            (*((void (__fastcall **)(MyGL::Model *const)) this->_vptr_IModel + 2))(this);
        if (Isize <= 1) {
            glDrawArrays((unsigned int) this->type, (unsigned int) *fist, (unsigned int) *count);
        } else {
            v5 = (MyGL::CGL *) (*((__int64 (__fastcall **)(MyGL::IRender *const)) this->render->_vptr_IRender +
                                  9))(this->render);
            v6 = MyGL::CGL::ext(v5);
            v6->glMultiDrawArraysEXT(this->type, fist, count, Isize);
        }
    } else {
        (*((void (__fastcall **)(MyGL::Model *const, bool)) this->_vptr_IModel + 6))(this, binded);
    }
}

MyGL::IVBO *MyGL::Model::extraBuffer() {
    return &this->extra;
}

void MyGL::Model::free() {
    this->vert.free();
    this->tex.free();
    this->norm.free();
    this->extra.free();
}

void MyGL::Model::load(MyGL::IIOModel *const m) {
    MyGL::CGL::GLsizei s;
    const MyGL::CGL::GLfloat *data;
    MyGL::CGL::GLsizei s_1;
    const MyGL::CGL::GLfloat *data_1;
    MyGL::CGL::GLsizei s_2;
    const MyGL::CGL::GLfloat *data_2;
    MyGL::CGL::GLsizei s_3;
    const MyGL::CGL::GLfloat *data_3;

    if ((*((unsigned int (__fastcall **)(MyGL::IIOModel *const)) m->_vptr_IIOModel + 18))(m)) {
        s = 3 * (*((__int64 (__fastcall **)(MyGL::IIOModel *const)) m->_vptr_IIOModel + 18))(m);
        data = (const MyGL::CGL::GLfloat *) (*(
                (__int64 (__fastcall **)(MyGL::IIOModel *const)) m->_vptr_IIOModel + 8))(m);
        MyGL::VBO::loadData(&this->vert, data, s);
        s_1 = 2 * (*((__int64 (__fastcall **)(MyGL::IIOModel *const)) m->_vptr_IIOModel + 18))(m);
        data_1 = (const MyGL::CGL::GLfloat *) (*(
                (__int64 (__fastcall **)(MyGL::IIOModel *const)) m->_vptr_IIOModel + 9))(m);
        MyGL::VBO::loadData(&this->tex, data_1, s_1);
        s_2 = 3 * (*((__int64 (__fastcall **)(MyGL::IIOModel *const)) m->_vptr_IIOModel + 18))(m);
        data_2 = (const MyGL::CGL::GLfloat *) (*(
                (__int64 (__fastcall **)(MyGL::IIOModel *const)) m->_vptr_IIOModel + 10))(m);
        MyGL::VBO::loadData(&this->norm, data_2, s_2);
        if ((*((__int64 (__fastcall **)(MyGL::IIOModel *const)) m->_vptr_IIOModel + 11))(m)) {
            s_3 = 4 * (*((__int64 (__fastcall **)(MyGL::IIOModel *const)) m->_vptr_IIOModel + 18))(m);
            data_3 = (const MyGL::CGL::GLfloat *) (*(
                    (__int64 (__fastcall **)(MyGL::IIOModel *const)) m->_vptr_IIOModel + 11))(m);
            MyGL::VBO::loadData(&this->extra, data_3, s_3);
        }
        this->type = MyGL::IVBO::PrimitiveType::Type::Triangles;
        this->size = (*((__int64 (__fastcall **)(MyGL::IIOModel *const)) m->_vptr_IIOModel + 18))(m);
        (*((void (__fastcall **)(MyGL::ModelInfo *,
                                 MyGL::IIOModel *const)) this->mCullInform->_vptr_IModelInfo + 9))(
                this->mCullInform,
                m);
    }
}

MyGL::IVBO *MyGL::Model::normalBuffer() {
    return &this->norm;
}

MyGL::IVBO::PrimitiveType::Type MyGL::Model::primitiveType() {
    return this->type;
}

void MyGL::Model::setPrimitivesType(MyGL::IVBO::PrimitiveType::Type t) {
    this->type = t;
}

MyGL::IVBO *MyGL::Model::textureBuffer() {
    return &this->tex;
}

void MyGL::Model::uBind() {
    if (MyGL::VBO::size(&this->extra))
        (*((void (__fastcall **)(MyGL::IRender *const, MyGL::VBO *)) this->render->_vptr_IRender + 20))(
                this->render,
                &this->extra);
    (*((void (__fastcall **)(MyGL::IRender *const, MyGL::VBO *)) this->render->_vptr_IRender + 20))(
            this->render,
            &this->norm);
    (*((void (__fastcall **)(MyGL::IRender *const, MyGL::VBO *)) this->render->_vptr_IRender + 20))(
            this->render,
            &this->tex);
    (*((void (__fastcall **)(MyGL::IRender *const, MyGL::VBO *)) this->render->_vptr_IRender + 20))(
            this->render,
            &this->vert);
    glDisableClientState(32886LL);
}

void MyGL::Model::unsetCullInfo() {
    this->mCullInform->setBox(
            -3.4028235e38,
            -3.4028235e38,
            -3.4028235e38,
            3.4028235e38,
            3.4028235e38,
            3.4028235e38);
}

MyGL::IVBO *MyGL::Model::vertexBuffer() {
    return this->vert;
}
