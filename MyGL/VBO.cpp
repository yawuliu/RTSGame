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
		if (this->vertices)
		{
            this->render->gl()->ext()->glDeleteBuffersARB(1LL, &this->vertices);
			this->vertices = 0;
		}
	}
	void VBO::subData(CGL::GLsizei offset, CGL::GLsizei size, void* data)
	{
        this->render->gl()->ext()->glBufferSubDataARB(34962LL, offset, size, data);
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
            this->render->gl()->ext()->glGenBuffersARB(1LL, &this->vertices);
		}
        this->_size = s;
        this->render->gl()->ext()->glBindBufferARB(34962LL, this->vertices);
        this->render->gl()->ext()->glBufferDataARB(34962LL, 4LL * this->_size, data, 35044LL);
	}
	void VBO::bind(IVBO::BindMode::Type mode)
	{
		CGL* v2;
		IErrorControl* v3;
		CGL* v4;
		privateGLSupportClass* v5;

		if (this->refCount)
		{
            this->render->gl()->errorCtrl()->fail(
				0LL,
				"[error]VBO::bind : buffer is already mapped!");
		}
        this->render->gl()->ext()->glBindBufferARB(34962LL, this->vertices);
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
        this->render->gl()->ext()->glBindBufferARB(34962LL, 0LL);
	}
	CGL::GLuint VBO::size()
	{
		return this->_size;
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
		if (++this->refCount == 1)
		{
            this->render->gl()->ext()->glBindBufferARB(34962LL, this->vertices);
			this->map = this->render->gl()->ext()->glMapBufferARB(34962LL, 35002LL);
		}
	}
	void VBO::delRef()
	{
		if (!--this->refCount)
		{
            this->render->gl()->ext()->glBindBufferARB(34962LL, this->vertices);
			this->map = 0LL;
            this->render->gl()->ext()->glUnmapBufferARB(34962LL);
		}
	}
}