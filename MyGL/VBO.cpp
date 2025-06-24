#include "VBO.h"

namespace MyGL {
	VBO::Pointer::Pointer(void* buf)
	{
		IVBO::IPointer::IPointer(_vptr_IPointer);

		_vptr_IPointer->vbo = buf;
		VBO::addRef((VBO* const)_vptr_IPointer->vbo);
	}
	VBO::Pointer::Pointer(const Pointer& p)
	{
		IVBO::IPointer::IPointer(_vptr_IPointer);

		VBO::addRef(*((VBO* const*)p + 1));
		VBO::delRef((VBO* const)_vptr_IPointer->vbo);
		_vptr_IPointer->vbo = (void*)*((_QWORD*)p + 1);
	}
	VBO::Pointer::~Pointer()
	{

		VBO::delRef((VBO* const)this->vbo);
		IVBO::IPointer::~IPointer(this);
	}
	GLfloat* VBO::Pointer::operator[](size_type id)
	{
		return (GLfloat*)(4LL * id + *((_QWORD*)this->vbo + 4));
	}
	unsigned int VBO::Pointer::size()
	{
		return *((_DWORD*)this->vbo + 3);
	}
	VBO::VBO(IRender& r)
	{
		IVBO::IVBO(p_vert);

			p_vert->render = r;
		p_vert->vertices = 0;
		p_vert->_size = 0;
		p_vert->refCount = 0LL;
	}
	VBO::~VBO()
	{

        this->free();

	}
	void VBO::free()
	{
		CGL* v1;
		privateGLSupportClass* v2;

		if (this->vertices)
		{
			v1 = this->render->gl();
			v2 = CGL::ext(v1);
			v2->glDeleteBuffersARB(1LL, &this->vertices);
			this->vertices = 0;
		}
	}
	void VBO::subData(CGL::GLsizei offset, CGL::GLsizei size, void* data)
	{
		CGL* v4;
		privateGLSupportClass* v5;

		v4 = this->render->gl();
		v5 = CGL::ext(v4);
		v5->glBufferSubDataARB(34962LL, offset, size, data);
	}
	void VBO::allocate(CGL::GLsizei size)
	{
		(*((void(__fastcall**)(VBO* const, _QWORD, _QWORD))p_vert->_vptr_IVBO + 5))(p_vert, 0LL, (unsigned int)size);
	}
	void VBO::loadData(const CGL::GLfloat* data, CGL::GLsizei s)
	{
		CGL* v3;
		privateGLSupportClass* v4;
		CGL* v5;
		privateGLSupportClass* v6;
		CGL* v7;
		privateGLSupportClass* v8;

		if (!p_vert->vertices)
		{
			v3 = p_vert->render->gl();
			v4 = CGL::ext(v3);
			v4->glGenBuffersARB(1LL, &p_vert->vertices);
		}
		p_vert->_size = s;
		v5 = p_vert->render->gl();
		v6 = CGL::ext(v5);
		v6->glBindBufferARB(34962LL, p_vert->vertices);
		v7 = p_vert->render->gl();
		v8 = CGL::ext(v7);
		v8->glBufferDataARB(34962LL, 4LL * p_vert->_size, data, 35044LL);
	}
	void VBO::bind(IVBO::BindMode::Type mode)
	{
		CGL* v2;
		IErrorControl* v3;
		CGL* v4;
		privateGLSupportClass* v5;

		if (this->refCount)
		{
			v2 = this->render->gl();
			v3 = CGL::errorCtrl(v2);
			(*((void(__fastcall**)(IErrorControl*, _QWORD, const char*))v3->_vptr_IErrorControl + 6))(
				v3,
				0LL,
				"[error]VBO::bind : buffer is already mapped!");
		}
		v4 = this->render->gl();
		v5 = CGL::ext(v4);
		v5->glBindBufferARB(34962LL, this->vertices);
		if (mode)
		{
			switch (mode)
			{
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
		}
		else
		{
			glVertexPointer(3LL, 5126LL, 0LL, 0LL);
		}
	}
	void VBO::draw(bool binded, IVBO::PrimitiveType::Type p)
	{
		if (!binded)
			(*((void(__fastcall**)(VBO* const, _QWORD))this->_vptr_IVBO + 2))(this, 0LL);
		glDrawArrays(VBO::draw(bool, IVBO::PrimitiveType::Type)::primitiveT[p], 0LL, this->_size);
	}
	void VBO::uBind()
	{
		CGL* v1;
		privateGLSupportClass* v2;

		v1 = this->render->gl();
		v2 = CGL::ext(v1);
		v2->glBindBufferARB(34962LL, 0LL);
	}
	CGL::GLuint VBO::size(VBO* const p_extra)
	{
		return p_extra->_size;
	}
	VBO::Pointer VBO::data()
	{
		void* buf;
		VBO::Pointer result;

		VBO::Pointer::Pointer((VBO::Pointer* const)this, buf);
		result.this = (int (**)(...))this;
		return result;
	}
	IVBO::IPointer* VBO::pointerToData()
	{
		VBO::Pointer* _vptr_IPointer;

		_vptr_IPointer = (VBO::Pointer*)operator new(0x10uLL);
		VBO::Pointer::Pointer(_vptr_IPointer, buf);
		return _vptr_IPointer;
	}
	void VBO::addRef()
	{
		CGL* v1;
		privateGLSupportClass* v2;
		CGL* v3;
		privateGLSupportClass* v4;

		if (++this->refCount == 1)
		{
			v1 = this->render->gl();
			v2 = CGL::ext(v1);
			v2->glBindBufferARB(34962LL, this->vertices);
			v3 = this->render->gl();
			v4 = CGL::ext(v3);
			this->map = v4->glMapBufferARB(34962LL, 35002LL);
		}
	}
	void VBO::delRef()
	{
		CGL* v1;
		privateGLSupportClass* v2;
		CGL* v3;
		privateGLSupportClass* v4;

		if (!--this->refCount)
		{
			v1 = this->render->gl();
			v2 = CGL::ext(v1);
			v2->glBindBufferARB(34962LL, this->vertices);
			this->map = 0LL;
			v3 = this->render->gl();
			v4 = CGL::ext(v3);
			v4->glUnmapBufferARB(34962LL);
		}
	}
}