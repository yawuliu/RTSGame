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

        src = this->srcFrom(fs_0, &okFs);
        if (src) {
            if (this->shEnv) {
                __rhs = (const char *) this->shEnv->getPrecompileSource();
                std::operator+<char>(&__lhs, __rhs);
                v7 = std::string::data(&__lhs);
                taget->loadFragmentSource(v7);
            } else {
                taget->loadFragmentSource(src);
            }
        }
        if (src)
            operator delete[](src);
        src = this->srcFrom(vs, &okVs);
        if (src) {
            if (this->shEnv) {
                __rhs_1 = (const char *) this->shEnv->getPrecompileSource();
                std::operator+<char>(&__lhs_, __rhs_1);
                v10 = std::string::data(&__lhs_);
                taget->loadVertexSource(v10);
            } else {
                taget->loadVertexSource(src);
            }
        }
        if (src)
            delete[] src;
        if (ok)
            *ok = okVs && okFs;
        if (!okVs || !okFs) {
            std::allocator<char>::allocator(&v24);
            std::string::string(&msg, "[Error]: Shader load error [", &v24);
            if (!okVs)
                std::string::append(&msg, vs);
            else
                std::string::append(&msg, fs_0);
            std::string::append(&msg, "]");
            v14 = std::string::data(&msg);
            this->render->gl()->errorCtrl()->loadError(taget, v14);
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

        std::ifstream v7;
        v7.open(file, 4LL);
        if (v7.is_open() != 1) {
            if (ok)
                *ok = 0;
            vv_1 = 0LL;
        } else {
            v7.seekg(0LL, 2LL);
            v8._M_off = v7.tellg();
            v8._M_state = _M_state;
            length = std::fpos<__mbstate_t>::operator long(&v8);
            v7.seekg(0LL, 0LL);
            vv = (char *) operator new[](length + 1);
            v7.read(vv, length);
            v7.close();
            vv[length] = 0;
            if (ok)
                *ok = 1;
            vv_1 = vv;
        }
        return vv_1;
    }
}