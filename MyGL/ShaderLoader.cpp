#include "ShaderLoader.h"

namespace MyGL {
    ShaderLoader::ShaderLoader(IRender &r) : render(r) {
        setEnvironment(0LL);
    }

    IShaderEnvironment *ShaderLoader::enviroment() {
        return this->shEnv;
    }

    IShader *ShaderLoader::load(IShader &taget, const char *vs, const char *fs_0, bool *ok) {
        void (__fastcall *v5)(IShader *const, __int64);
        const char *__rhs;
        __int64 v7;
        void (__fastcall *v8)(IShader *const, __int64);
        const char *__rhs_1;
        __int64 v10;
        CGL *v11;
        IErrorControl *v12;
        void (__fastcall *v13)(IErrorControl *, IShader *const, __int64);
        __int64 v14;
        std::string msg;
        bool okFs;
        bool okVs;
        std::string __lhs;
        std::string __lhs_;
        char v24;
        char *src;

        src = ShaderLoader::srcFrom(this, fs_0, &okFs);
        if (src) {
            if (this->shEnv) {
                v5 = (void (__fastcall *)(IShader *const, __int64)) *((_QWORD *) taget->_vptr_IShader + 3);
                __rhs = (const char *) (*(
                        (__int64 (__fastcall **)(IShaderEnvironment *)) this->shEnv->_vptr_IShaderEnvironment
                        + 2))(this->shEnv);
                std::operator+<char>(&__lhs, __rhs);
                v7 = std::string::data(&__lhs);
                v5(taget, v7);
                std::string::~string(&__lhs);
            } else {
                (*((void (__fastcall **)(IShader *const, char *)) taget->_vptr_IShader + 3))(taget, src);
            }
        }
        if (src)
            operator delete[](src);
        src = ShaderLoader::srcFrom(this, vs, &okVs);
        if (src) {
            if (this->shEnv) {
                v8 = (void (__fastcall *)(IShader *const, __int64)) *((_QWORD *) taget->_vptr_IShader + 2);
                __rhs_1 = (const char *) (*(
                        (__int64 (__fastcall **)(IShaderEnvironment *)) this->shEnv->_vptr_IShaderEnvironment
                        + 2))(this->shEnv);
                std::operator+<char>(&__lhs_, __rhs_1);
                v10 = std::string::data(&__lhs_);
                v8(taget, v10);
                std::string::~string(&__lhs_);
            } else {
                (*((void (__fastcall **)(IShader *const, char *)) taget->_vptr_IShader + 2))(taget, src);
            }
        }
        if (src)
            operator delete[](src);
        if (ok)
            *ok = okVs && okFs;
        if (!okVs || !okFs) {
            std::allocator<char>::allocator(&v24);
            std::string::string(&msg, "[Error]: Shader load error [", &v24);
            std::allocator<char>::~allocator(&v24);
            if (!okVs)
                std::string::append(&msg, vs);
            else
                std::string::append(&msg, fs_0);
            std::string::append(&msg, "]");
            v11 = this->render->gl();
            v12 = CGL::errorCtrl(v11);
            v13 = (void (__fastcall *)(IErrorControl *, IShader *const, __int64)) *(
                    (_QWORD *) v12->_vptr_IErrorControl
                    + 7);
            v14 = std::string::data(&msg);
            v13(v12, taget, v14);
            std::string::~string(&msg);
        }
        return taget;
    }

    void ShaderLoader::setEnvironment(IShaderEnvironment *env) {
        this->shEnv = env;
    }

    char *ShaderLoader::srcFrom(const char *file, bool *ok) {
        char *vv_1;
        __mbstate_t _M_state;
        _BYTE v7[528];
        std::fpos<__mbstate_t> v8;
        char *vv;
        int length;

        std::ifstream::basic_ifstream(v7);
        std::ifstream::open(v7, file, 4LL);
        if ((unsigned __int8) std::ifstream::is_open(v7) != 1) {
            if (ok)
                *ok = 0;
            vv_1 = 0LL;
        } else {
            std::istream::seekg(v7, 0LL, 2LL);
            v8._M_off = std::istream::tellg((std::istream *) v7);
            v8._M_state = _M_state;
            length = std::fpos<__mbstate_t>::operator long(&v8);
            std::istream::seekg(v7, 0LL, 0LL);
            vv = (char *) operator new[](length + 1);
            std::istream::read((std::istream *) v7, vv, length);
            std::ifstream::close(v7);
            vv[length] = 0;
            if (ok)
                *ok = 1;
            vv_1 = vv;
        }
        std::ifstream::~ifstream(v7);
        return vv_1;
    }
}