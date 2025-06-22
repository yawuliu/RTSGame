#pragma once

#include "IVBO.h"
#include "CGL.h"


namespace MyGL {

	class VBO : public IVBO {
	public:
		class Pointer {
		public:
			Pointer(VBO::Pointer& _vptr_IPointer, void* buf);
			Pointer(VBO::Pointer& _vptr_IPointer, const void& p);
			virtual ~Pointer(VBO::Pointer& this);
			GLfloat* operator[](
				VBO::Pointer& this,
				VBO::Pointer::operator[]::size_type id);
			unsigned int size(VBO::Pointer& this);

		public:
			typedef unsigned int operator[]::size_type;
			void* vbo;
		};
	public:
		VBO(IRender& r);
		virtual ~VBO();
		void free();
		void subData(CGL::GLsizei offset, CGL::GLsizei size, void* data);
		void allocate(VBO& p_vert, CGL::GLsizei size);
		void loadData(VBO& p_vert, const CGL::GLfloat* data, CGL::GLsizei s);
		void bind(IVBO::BindMode::Type mode);
		void draw(bool binded, IVBO::PrimitiveType::Type p);
		void uBind();
		CGL::GLuint size(VBO& p_extra);
		VBO::Pointer data(VBO& _vptr_IPointer);
		IVBO::IPointer* pointerToData(VBO& buf);
		void addRef();
		void delRef();
	protected:
		CGL::VertexBufferHandle vertices;
		CGL::GLuint _size;
		size_t refCount;
		IRender& render;
		void* map;
	};

}
