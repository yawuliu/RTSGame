//
// Created by liuyawu on 23-1-1.
//

#include "VBO.h"

namespace MyGL {
	VBO::Pointer::Pointer(void* buf)
	{
		MyGL::IVBO::IPointer::IPointer(_vptr_IPointer);

		_vptr_IPointer->vbo = buf;
		MyGL::VBO::addRef((MyGL::VBO* const)_vptr_IPointer->vbo);
	}
	VBO::Pointer::Pointer(const void* const p)
	{
		MyGL::IVBO::IPointer::IPointer(_vptr_IPointer);

		MyGL::VBO::addRef(*((MyGL::VBO* const*)p + 1));
		MyGL::VBO::delRef((MyGL::VBO* const)_vptr_IPointer->vbo);
		_vptr_IPointer->vbo = (void*)*((_QWORD*)p + 1);
	}
	VBO::Pointer::~Pointer()
	{

		MyGL::VBO::delRef((MyGL::VBO* const)this->vbo);
		MyGL::IVBO::IPointer::~IPointer(this);
	}
	GLfloat* VBO::Pointer::operator[](MyGL::VBO::Pointer* const this, MyGL::VBO::Pointer::operator[]::size_type id)
	{
		return (GLfloat*)(4LL * id + *((_QWORD*)this->vbo + 4));
	}
	unsigned int VBO::Pointer::size(MyGL::VBO::Pointer* const this)
	{
		return *((_DWORD*)this->vbo + 3);
	}
	VBO::VBO(MyGL::IRender& r)
	{
		MyGL::IVBO::IVBO(p_vert);
		p_vert->_vptr_IVBO = (int (**)(...))(&`vtable for'MyGL::VBO + 2);
			p_vert->render = r;
		p_vert->vertices = 0;
		p_vert->_size = 0;
		p_vert->refCount = 0LL;
	}
	VBO::~VBO()
	{
		this->_vptr_IVBO = (int (**)(...))(&`vtable for'MyGL::VBO + 2);
			MyGL::VBO::free(this);
		MyGL::IVBO::~IVBO(this);
	}
	void VBO::free()
	{
		MyGL::CGL* v1;
		MyGL::privateGLSupportClass* v2;

		if (this->vertices)
		{
			v1 = (MyGL::CGL*)(*((__int64(__fastcall**)(MyGL::IRender* const))this->render->_vptr_IRender + 9))(this->render);
			v2 = MyGL::CGL::ext(v1);
			v2->glDeleteBuffersARB(1LL, &this->vertices);
			this->vertices = 0;
		}
	}
	void VBO::subData(MyGL::CGL::GLsizei offset, MyGL::CGL::GLsizei size, void* data)
	{
		MyGL::CGL* v4;
		MyGL::privateGLSupportClass* v5;

		v4 = (MyGL::CGL*)(*((__int64(__fastcall**)(MyGL::IRender* const))this->render->_vptr_IRender + 9))(this->render);
		v5 = MyGL::CGL::ext(v4);
		v5->glBufferSubDataARB(34962LL, offset, size, data);
	}
	void VBO::allocate(MyGL::VBO* const p_vert, MyGL::CGL::GLsizei size)
	{
		(*((void(__fastcall**)(MyGL::VBO* const, _QWORD, _QWORD))p_vert->_vptr_IVBO + 5))(p_vert, 0LL, (unsigned int)size);
	}
	void VBO::loadData(MyGL::VBO* const p_vert, const MyGL::CGL::GLfloat* data, MyGL::CGL::GLsizei s)
	{
		MyGL::CGL* v3;
		MyGL::privateGLSupportClass* v4;
		MyGL::CGL* v5;
		MyGL::privateGLSupportClass* v6;
		MyGL::CGL* v7;
		MyGL::privateGLSupportClass* v8;

		if (!p_vert->vertices)
		{
			v3 = (MyGL::CGL*)(*((__int64(__fastcall**)(MyGL::IRender* const))p_vert->render->_vptr_IRender + 9))(p_vert->render);
			v4 = MyGL::CGL::ext(v3);
			v4->glGenBuffersARB(1LL, &p_vert->vertices);
		}
		p_vert->_size = s;
		v5 = (MyGL::CGL*)(*((__int64(__fastcall**)(MyGL::IRender* const))p_vert->render->_vptr_IRender + 9))(p_vert->render);
		v6 = MyGL::CGL::ext(v5);
		v6->glBindBufferARB(34962LL, p_vert->vertices);
		v7 = (MyGL::CGL*)(*((__int64(__fastcall**)(MyGL::IRender* const))p_vert->render->_vptr_IRender + 9))(p_vert->render);
		v8 = MyGL::CGL::ext(v7);
		v8->glBufferDataARB(34962LL, 4LL * p_vert->_size, data, 35044LL);
	}
	void VBO::bind(MyGL::IVBO::BindMode::Type mode)
	{
		MyGL::CGL* v2;
		MyGL::IErrorControl* v3;
		MyGL::CGL* v4;
		MyGL::privateGLSupportClass* v5;

		if (this->refCount)
		{
			v2 = (MyGL::CGL*)(*((__int64(__fastcall**)(MyGL::IRender* const))this->render->_vptr_IRender + 9))(this->render);
			v3 = MyGL::CGL::errorCtrl(v2);
			(*((void(__fastcall**)(MyGL::IErrorControl*, _QWORD, const char*))v3->_vptr_IErrorControl + 6))(
				v3,
				0LL,
				"[error]VBO::bind : buffer is already mapped!");
		}
		v4 = (MyGL::CGL*)(*((__int64(__fastcall**)(MyGL::IRender* const))this->render->_vptr_IRender + 9))(this->render);
		v5 = MyGL::CGL::ext(v4);
		v5->glBindBufferARB(34962LL, this->vertices);
		if (mode)
		{
			switch (mode)
			{
			case MyGL::IVBO::BindMode::Type::TexCoord:
				glTexCoordPointer(2LL, 5126LL, 0LL, 0LL);
				break;
			case MyGL::IVBO::BindMode::Type::Normal:
				glNormalPointer(5126LL, 0LL, 0LL);
				break;
			case MyGL::IVBO::BindMode::Type::Color:
				glColorPointer(4LL, 5126LL, 0LL, 0LL);
				break;
			}
		}
		else
		{
			glVertexPointer(3LL, 5126LL, 0LL, 0LL);
		}
	}
	void VBO::draw(bool binded, MyGL::IVBO::PrimitiveType::Type p)
	{
		if (!binded)
			(*((void(__fastcall**)(MyGL::VBO* const, _QWORD))this->_vptr_IVBO + 2))(this, 0LL);
		glDrawArrays(MyGL::VBO::draw(bool, MyGL::IVBO::PrimitiveType::Type)::primitiveT[p], 0LL, this->_size);
	}
	void VBO::uBind()
	{
		MyGL::CGL* v1;
		MyGL::privateGLSupportClass* v2;

		v1 = (MyGL::CGL*)(*((__int64(__fastcall**)(MyGL::IRender* const))this->render->_vptr_IRender + 9))(this->render);
		v2 = MyGL::CGL::ext(v1);
		v2->glBindBufferARB(34962LL, 0LL);
	}
	MyGL::CGL::GLuint VBO::size(MyGL::VBO* const p_extra)
	{
		return p_extra->_size;
	}
	MyGL::VBO::Pointer VBO::data(MyGL::VBO* const _vptr_IPointer)
	{
		void* buf;
		MyGL::VBO::Pointer result;

		MyGL::VBO::Pointer::Pointer((MyGL::VBO::Pointer* const)_vptr_IPointer, buf);
		result._vptr_IPointer = (int (**)(...))_vptr_IPointer;
		return result;
	}
	MyGL::IVBO::IPointer* VBO::pointerToData(MyGL::VBO* const buf)
	{
		MyGL::VBO::Pointer* _vptr_IPointer;

		_vptr_IPointer = (MyGL::VBO::Pointer*)operator new(0x10uLL);
		MyGL::VBO::Pointer::Pointer(_vptr_IPointer, buf);
		return _vptr_IPointer;
	}
	void VBO::addRef()
	{
		MyGL::CGL* v1;
		MyGL::privateGLSupportClass* v2;
		MyGL::CGL* v3;
		MyGL::privateGLSupportClass* v4;

		if (++this->refCount == 1)
		{
			v1 = (MyGL::CGL*)(*((__int64(__fastcall**)(MyGL::IRender* const))this->render->_vptr_IRender + 9))(this->render);
			v2 = MyGL::CGL::ext(v1);
			v2->glBindBufferARB(34962LL, this->vertices);
			v3 = (MyGL::CGL*)(*((__int64(__fastcall**)(MyGL::IRender* const))this->render->_vptr_IRender + 9))(this->render);
			v4 = MyGL::CGL::ext(v3);
			this->map = v4->glMapBufferARB(34962LL, 35002LL);
		}
	}
	void VBO::delRef()
	{
		MyGL::CGL* v1;
		MyGL::privateGLSupportClass* v2;
		MyGL::CGL* v3;
		MyGL::privateGLSupportClass* v4;

		if (!--this->refCount)
		{
			v1 = (MyGL::CGL*)(*((__int64(__fastcall**)(MyGL::IRender* const))this->render->_vptr_IRender + 9))(this->render);
			v2 = MyGL::CGL::ext(v1);
			v2->glBindBufferARB(34962LL, this->vertices);
			this->map = 0LL;
			v3 = (MyGL::CGL*)(*((__int64(__fastcall**)(MyGL::IRender* const))this->render->_vptr_IRender + 9))(this->render);
			v4 = MyGL::CGL::ext(v3);
			v4->glUnmapBufferARB(34962LL);
		}
	}
}