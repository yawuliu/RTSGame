#include "VBO.h"

namespace MyGL {
	VBO::Pointer::Pointer(void* buf)
	{
		this->vbo = buf;
        this->vbo->addRef();
	}
	VBO::Pointer::Pointer(const Pointer& p)
	{
		addRef(*((VBO* const*)p + 1));
        this->vbo->delRef();
	}
	VBO::Pointer::~Pointer()
	{
        this->vbo->delRef();
	}
	GLfloat* VBO::Pointer::operator[](uint32_t id)
	{
		return (GLfloat*)(4LL * id + *((_QWORD*)this->vbo + 4));
	}
	size_t VBO::Pointer::size()
	{
		return *((_DWORD*)this->vbo + 3);
	}
	VBO::VBO(IRender& r)
	{
		this->render = r;
        this->vertices = 0;
        this->_size = 0;
        this->refCount = 0LL;
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
			v2 = v1->ext();
			v2->glDeleteBuffersARB(1LL, &this->vertices);
			this->vertices = 0;
		}
	}
	void VBO::subData(CGL::GLsizei offset, CGL::GLsizei size, void* data)
	{
		CGL* v4;
		privateGLSupportClass* v5;

		v4 = this->render->gl();
		v5 = v4->ext();
		v5->glBufferSubDataARB(34962LL, offset, size, data);
	}
	void VBO::allocate(CGL::GLsizei size)
	{
		this->loadData( 0LL, (unsigned int)size);
	}
	void VBO::loadData(const CGL::GLfloat* data, CGL::GLsizei s)
	{
		CGL* v3;
		privateGLSupportClass* v4;
		CGL* v5;
		privateGLSupportClass* v6;
		CGL* v7;
		privateGLSupportClass* v8;

		if (!this->vertices)
		{
			v3 = this->render->gl();
			v4 = v3->ext();
			v4->glGenBuffersARB(1LL, &this->vertices);
		}
        this->_size = s;
		v5 = this->render->gl();
		v6 = v5->ext();
		v6->glBindBufferARB(34962LL, this->vertices);
		v7 = this->render->gl();
		v8 =v7->ext();
		v8->glBufferDataARB(34962LL, 4LL * this->_size, data, 35044LL);
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
			v3 = v2->errorCtrl();
			v3->fail(
				0LL,
				"[error]VBO::bind : buffer is already mapped!");
		}
		v4 = this->render->gl();
		v5 = v4->ext();
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
			this->bind(0LL);
		glDrawArrays(VBO::draw(bool, IVBO::PrimitiveType::Type)::primitiveT[p], 0LL, this->_size);
	}
	void VBO::uBind()
	{
		CGL* v1;
		privateGLSupportClass* v2;

		v1 = this->render->gl();
		v2 = v1->ext();
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
		return new VBO::Pointer();
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
			v2 = v1->ext();
			v2->glBindBufferARB(34962LL, this->vertices);
			v3 = this->render->gl();
			v4 = v3->ext();
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
			v2 = v1->ext();
			v2->glBindBufferARB(34962LL, this->vertices);
			this->map = 0LL;
			v3 = this->render->gl();
			v4 = v3->ext();
			v4->glUnmapBufferARB(34962LL);
		}
	}
}