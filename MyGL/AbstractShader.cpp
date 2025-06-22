#include "MyGL/AbstractShader.h"

MyGL::AbstractShader::AbstractShader(MyGL::IRender *r) : mrender(r) {

}


MyGL::AbstractShader::~AbstractShader()
{
    MyGL::IUniform *v1; // rax
    std::vector<MyGL::IUniform*>::size_type i; // [rsp+18h] [rbp-18h]

    this->_vptr_IShader = (int (**)(...))(&`vtable for'MyGL::AbstractShader + 2);
    for ( i = 0LL; std::vector<MyGL::IUniform *>::size(&this->unif) > i; ++i )
    {
        v1 = *std::vector<MyGL::IUniform *>::operator[](&this->unif, i);
        if ( v1 )
            (*((void (__fastcall **)(MyGL::IUniform *))v1->_vptr_IUniform + 1))(v1);
    }
    std::vector<MyGL::IUniform *>::~vector(&this->unif);
    MyGL::IShader::~IShader(this);
}
MyGL::CGL *MyGL::AbstractShader::gl()
{
    return (MyGL::CGL *)(*((__int64 (__fastcall **)(MyGL::IRender *))this->mrender->_vptr_IRender + 9))(this->mrender);
}
MyGL::IUniform *MyGL::AbstractShader::registerUniform(MyGL::IUniform *u)
{
    std::vector<MyGL::IUniform*> *v2; // rax
    std::vector<MyGL::IUniform*>::reference v3; // rax
    std::vector<MyGL::IUniform*> *v4; // rax
    std::vector<MyGL::IUniform*> *v5; // rax
    MyGL::IUniform *ua; // [rsp+0h] [rbp-20h] BYREF
    MyGL::AbstractShader *thisa; // [rsp+8h] [rbp-18h]
    size_t i; // [rsp+10h] [rbp-10h]
    MyGL::IUniform *rep; // [rsp+18h] [rbp-8h]

    thisa = this;
    ua = u;
    rep = 0LL;
    for ( i = 0LL; ; ++i )
    {
        v5 = MyGL::AbstractShader::uniforms(thisa);
        if ( std::vector<MyGL::IUniform *>::size(v5) <= i )
            break;
        v2 = MyGL::AbstractShader::uniforms(thisa);
        v3 = std::vector<MyGL::IUniform *>::operator[](v2, i);
        if ( (*((unsigned __int8 (__fastcall **)(MyGL::IUniform *, MyGL::IUniform *))(*v3)->_vptr_IUniform + 4))(*v3, ua) )
        {
            v4 = MyGL::AbstractShader::uniforms(thisa);
            rep = *std::vector<MyGL::IUniform *>::operator[](v4, i);
        }
    }
    if ( rep )
    {
        if ( ua )
            (*((void (__fastcall **)(MyGL::IUniform *))ua->_vptr_IUniform + 1))(ua);
        return rep;
    }
    else
    {
        std::vector<MyGL::IUniform *>::push_back(&thisa->unif, &ua);
    }
    return ua;
}

MyGL::IRender *MyGL::AbstractShader::render()
{
    return this->mrender;
}

void MyGL::AbstractShader::sendUniformsToGPU()
{
    std::vector<MyGL::IUniform*> *v1; // rax
    std::vector<MyGL::IUniform*>::reference v2; // rax
    std::vector<MyGL::IUniform*> *v3; // rax
    std::vector<MyGL::IUniform*>::size_type i; // [rsp+18h] [rbp-8h]

    for ( i = 0LL; ; ++i )
    {
        v3 = MyGL::AbstractShader::uniforms(this);
        if ( std::vector<MyGL::IUniform *>::size(v3) <= i )
            break;
        v1 = MyGL::AbstractShader::uniforms(this);
        v2 = std::vector<MyGL::IUniform *>::operator[](v1, i);
        (*((void (__fastcall **)(MyGL::IUniform *))(*v2)->_vptr_IUniform + 2))(*v2);
    }
}



std::vector<MyGL::IUniform*> *MyGL::AbstractShader::uniforms()
{
    return &this->unif;
}
void MyGL::AbstractShader::updateUniform(MyGL::IUniform *uniform)
{
__int64 v2; // rax

v2 = (*((__int64 (__fastcall **)(MyGL::AbstractShader *const))this->_vptr_IShader + 13))(this);
if ( (*(unsigned __int8 (__fastcall **)(__int64, MyGL::AbstractShader *const))(*(_QWORD *)v2 + 112LL))(v2, this) )
(*((void (__fastcall **)(MyGL::IUniform *))uniform->_vptr_IUniform + 2))(uniform);
}