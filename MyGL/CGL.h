#pragma once

#include <cstdint>

#include <MyGL/DisableCopy.h>
#include <MyGL/Data.h>

namespace MyGL {
	class IErrorControl;
	class privateGLSupportClass;
	class CGL : public DisableCopy {
	public:
		typedef double GLdouble;
		typedef void* GLextFuncPtr;
		typedef float GLfloat;
		typedef int GLint;
		typedef int GLsizei;
		typedef unsigned int GLuint;
		typedef int ShaderHandle;
		typedef unsigned int TextureHandle;
		typedef unsigned int TextureUnitHandle;
		typedef unsigned int VertexBufferHandle;

	public:
		CGL();

		virtual ~CGL();

		void createExtObject(CGL* const glD);

		IErrorControl* errorCtrl();

		privateGLSupportClass* ext();

		CGL::GLextFuncPtr getProcAddress(const char* f);

		void initAnisotropy();

		Bool initFBO_API();

		template<class T>
		bool initGlExtensionFuncPtr(T func, const char* name) {
			*func = (T)this->getProcAddress(name);
			return *func != 0LL;
		}

		Bool initShaderAPI();

		Bool initTextureAPI();

		Bool initVBO_API();

		Bool isAnisotropySupported();

		Bool isDXTFormatSupported();

		bool isExtensionSupported(const char* name);

		Float maxAnisotropyLevel();

		void setErrorCtrl(IErrorControl* e);

	protected:
		IErrorControl* eCtrl;
		bool autoECtrl;
		bool isDXT_supr;
		bool isFBO_Init;
		bool isVBOInit;
		bool isShadingInit;
		bool isTexturesInit;
		double maxAnisotropyLevel_val;
		int64_t gLSupport;
	};
}


