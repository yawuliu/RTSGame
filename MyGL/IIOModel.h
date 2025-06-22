#pragma once

#include <MyGL/CGL.h>

namespace MyGL {
	class IIOModel {
	public:
		class TexCoord {
		public:
			CGL::GLfloat* d;
			CGL::GLfloat* const x;
			CGL::GLfloat* const y;
		};

		class Point4 {
		public:
			CGL::GLfloat* d;
			CGL::GLfloat* const x;
			CGL::GLfloat* const y;
			CGL::GLfloat* const z;
			CGL::GLfloat* const w;
		};

		class Point {
		public:
			CGL::GLfloat* d;
			CGL::GLfloat* const x;
			CGL::GLfloat* const y;
			CGL::GLfloat* const z;
		};
		typedef Point Normal;
	};
}

