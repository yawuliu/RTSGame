#include "ModelLoader.h"

namespace MyGL {
    ModelLoader::ModelLoader(IRender &r) : render(r) {

    }

    IModel *ModelLoader::load(const char *fileName, bool *ok) {
        bool v4;
        CGL *v5;
        IErrorControl *v6;
        void (__fastcall *v7)(IErrorControl *, IModel *const, IOModel *, __int64);
        __int64 v8;
        IModel *taget_1;
        CGL *v10;
        IErrorControl *v11;
        void (__fastcall *v12)(IErrorControl *, IModel *const, IOModel *, __int64);
        __int64 v13;
        IOModel model;
        std::string str;
        std::string str_0;
        std::string fname;
        char v21;
        char v22;
        _BYTE v23[17];

        IOModel::IOModel(&model);
        std::allocator<char>::allocator(&v21);
        std::string::string(&fname, fileName, &v21);
        v4 = !IOModel::load(&model, &fname);
        std::string::~string(&fname);
        std::allocator<char>::~allocator(&v21);
        if (v4) {
            if (ok)
                *ok = 0;
            std::allocator<char>::allocator(&v22);
            std::string::string(&str_0, "[Error]:IOModel load error: \n", &v22);
            std::allocator<char>::~allocator(&v22);
            std::string::append(&str_0, fileName);
            v5 = this->render->gl();
            v6 = CGL::errorCtrl(v5);
            v7 = (void (__fastcall *)(IErrorControl *, IModel *const, IOModel *, __int64)) *(
                    (_QWORD *) v6->_vptr_IErrorControl + 9);
            v8 = std::string::data(&str_0);
            v7(v6, this, &model, v8);
            taget_1 = this;
            std::string::~string(&str_0);
        } else {
            if (!IOModel::size(&model)) {
                std::allocator<char>::allocator(v23);
                std::string::string(&str, "[Warning]:IOModel is NULL: \n", v23);
                std::allocator<char>::~allocator(v23);
                std::string::append(&str, fileName);
                v10 = this->render->gl();
                v11 = CGL::errorCtrl(v10);
                v12 = (void (__fastcall *)(IErrorControl *, IModel *const, IOModel *, __int64)) *(
                        (_QWORD *) v11->_vptr_IErrorControl + 9);
                v13 = std::string::data(&str);
                v12(v11, this, &model, v13);
                std::string::~string(&str);
            }
            (*((void (__fastcall **)(IModel *const, IOModel *)) this->_vptr_IModel + 8))(this,
                                                                                         &model);
            taget_1 = this;
        }
        IOModel::~IOModel(&model);
        return taget_1;
    }

    IModel *ModelLoader::loadBin_v0(const char *fileName, bool *ok) {
        bool v4;
        CGL *v5;
        IErrorControl *v6;
        void (__fastcall *v7)(IErrorControl *, IModel *const, IOModel *, __int64);
        __int64 v8;
        IModel *taget_1;
        CGL *v10;
        IErrorControl *v11;
        void (__fastcall *v12)(IErrorControl *, IModel *const, IOModel *, __int64);
        __int64 v13;
        IOModel model;
        std::string str;
        std::string str_0;
        std::string fname;
        char v21;
        char v22;
        _BYTE v23[17];

        IOModel::IOModel(&model);
        std::allocator<char>::allocator(&v21);
        std::string::string(&fname, fileName, &v21);
        v4 = !IOModel::loadBin_v0(&model, &fname);
        std::string::~string(&fname);
        std::allocator<char>::~allocator(&v21);
        if (v4) {
            if (ok)
                *ok = 0;
            std::allocator<char>::allocator(&v22);
            std::string::string(&str_0, "[Error]:IOModel load error: \n", &v22);
            std::allocator<char>::~allocator(&v22);
            std::string::append(&str_0, fileName);
            v5 = this->render->gl();
            v6 = CGL::errorCtrl(v5);
            v7 = (void (__fastcall *)(IErrorControl *, IModel *const, IOModel *, __int64)) *(
                    (_QWORD *) v6->_vptr_IErrorControl + 9);
            v8 = std::string::data(&str_0);
            v7(v6, this, &model, v8);
            taget_1 = this;
            std::string::~string(&str_0);
        } else {
            if (ok)
                *ok = 1;
            if (!IOModel::size(&model)) {
                std::allocator<char>::allocator(v23);
                std::string::string(&str, "[Warning]:IOModel is NULL: \n", v23);
                std::allocator<char>::~allocator(v23);
                std::string::append(&str, fileName);
                v10 = this->render->gl();
                v11 = CGL::errorCtrl(v10);
                v12 = (void (__fastcall *)(IErrorControl *, IModel *const, IOModel *, __int64)) *(
                        (_QWORD *) v11->_vptr_IErrorControl + 9);
                v13 = std::string::data(&str);
                v12(v11, this, &model, v13);
                std::string::~string(&str);
            }
            (*((void (__fastcall **)(IModel *const, IOModel *)) this->_vptr_IModel + 8))(this,
                                                                                         &model);
            taget_1 = this;
        }
        IOModel::~IOModel(&model);
        return taget_1;
    }
}