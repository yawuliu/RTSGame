#include "FBO.h"
#include <gl/GL.h>
#include "IRender.h"
namespace MyGL {
	FBO::FBO(IRender& r, unsigned int theWidth, unsigned int theHeight, FBO::Flags::BitMap f)
	{
		v5 = (CGL*)(*((__int64(__fastcall**)(IRender* const))r->_vptr_IRender + 9))(r);
		this->ext = new CGL::ext();
		this->w = theWidth;
		this->h = theHeight;
		this->flags = f;
		this->frameBuffer = 0;
		this->depthBuffer = 0;
		this->stencilBuffer = 0;
		this->create();
	}

	FBO::~FBO()
	{
		if (this->depthBuffer)
			this->ext->glDeleteRenderbuffersEXT(1LL, &this->depthBuffer);
		if (this->stencilBuffer)
			this->ext->glDeleteRenderbuffersEXT(1LL, &this->stencilBuffer);
		if (this->frameBuffer)
			this->ext->glDeleteFramebuffersEXT(1LL, &this->frameBuffer);
	}

	bool FBO::create()
	{
		bool complete;
		GLenum stencilFormat;
		GLenum depthFormat;

		if (this->w > 0x84E7 || this->h > 0x84E7)
			return 0;
		this->ext->glGenFramebuffersEXT(1LL, &this->frameBuffer);
		this->ext->glBindFramebufferEXT(36160LL, this->frameBuffer);
		depthFormat = 0;
		stencilFormat = 0;
		if ((this->flags & 1) != 0)
		{
			depthFormat = 33189;
		}
		else if ((this->flags & 2) != 0)
		{
			depthFormat = 33190;
		}
		else if ((this->flags & 4) != 0)
		{
			depthFormat = 33191;
		}
		else if ((this->flags & 8) != 0)
		{
			depthFormat = 6402;
		}
		if ((this->flags & 0x10) != 0)
		{
			stencilFormat = 36166;
		}
		else if ((this->flags & 0x20) != 0)
		{
			stencilFormat = 36167;
		}
		else if ((this->flags & 0x40) != 0)
		{
			stencilFormat = 36168;
		}
		else if ((this->flags & 0x80) != 0)
		{
			stencilFormat = 36169;
		}
		if (depthFormat)
		{
			this->ext->glGenRenderbuffersEXT(1LL, &this->depthBuffer);
			this->ext->glBindRenderbufferEXT(36161LL, this->depthBuffer);
			this->ext->glRenderbufferStorageEXT(36161LL, depthFormat, this->w, this->h);
			this->ext->glFramebufferRenderbufferEXT(36160LL, 36096LL, 36161LL, this->depthBuffer);
		}
		if (stencilFormat)
		{
			this->ext->glGenRenderbuffersEXT(1LL, &this->stencilBuffer);
			this->ext->glBindRenderbufferEXT(36161LL, this->stencilBuffer);
			this->ext->glRenderbufferStorageEXT(36161LL, stencilFormat, this->w, this->h);
			this->ext->glFramebufferRenderbufferEXT(36160LL, 36128LL, 36161LL, this->stencilBuffer);
		}
		complete = this->ext->glCheckFramebufferStatusEXT(36160LL) == 36053;
		this->ext->glBindFramebufferEXT(36160LL, 0LL);
		return complete;
	}

	std::string FBO::status()
	{
		__int64 v1;
		unsigned int currentFb;
		GLenum complete;

		glGetIntegerv(36006LL, &currentFb);
		if (*(_DWORD*)(v1 + 20) != currentFb)
			(*(void(__fastcall**)(__int64, _QWORD))(*(_QWORD*)(v1 + 32) + 56LL))(36160LL, *(unsigned int*)(v1 + 20));
		complete = (*(__int64(__fastcall**)(__int64))(*(_QWORD*)(v1 + 32) + 80LL))(36160LL);
		std::string::string((std::string*)this);
		if (complete == 36053)
			std::string::operator=(this, "GL_FRAMEBUFFER_COMPLETE_EXT");
		if (complete == 36054)
			std::string::operator=(this, "GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT_EXT");
		if (complete == 36055)
			std::string::operator=(this, "GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT_EXT");
		if (complete == 36057)
			std::string::operator=(this, "GL_FRAMEBUFFER_INCOMPLETE_DIMENSIONS_EXT");
		if (complete == 36057)
			std::string::operator=(this, "GL_FRAMEBUFFER_INCOMPLETE_DIMENSIONS_EXT");
		if (complete == 36058)
			std::string::operator=(this, "GL_FRAMEBUFFER_INCOMPLETE_FORMATS_EXT");
		if (complete == 36059)
			std::string::operator=(this, "GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER_EXT");
		if (complete == 36060)
			std::string::operator=(this, "GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER_EXT");
		if (complete == 36061)
			std::string::operator=(this, "GL_FRAMEBUFFER_UNSUPPORTED_EXT");
		if (*(_DWORD*)(v1 + 20) != currentFb)
			(*(void(__fastcall**)(__int64, _QWORD))(*(_QWORD*)(v1 + 32) + 56LL))(36160LL, currentFb);
		return (std::string)this;
	}

	bool FBO::validate()
	{
		unsigned int currentFb;
		bool complete;

		glGetIntegerv(36006LL, &currentFb);
		if (this->frameBuffer != currentFb)
			this->ext->glBindFramebufferEXT(36160LL, this->frameBuffer);
		complete = this->ext->glCheckFramebufferStatusEXT(36160LL) == 36053;
		if (this->frameBuffer != currentFb)
			this->ext->glBindFramebufferEXT(36160LL, currentFb);
		return complete;
	}

	bool FBO::bind()
	{
		if (!this->frameBuffer)
			return 0;
		this->ext->glBindFramebufferEXT(36160LL, this->frameBuffer);
		return 1;
	}

	bool FBO::unbind()
	{
		if (!this->frameBuffer)
			return 0;
		this->ext->glBindFramebufferEXT(36160LL, 0LL);
		return 1;
	}

	bool FBO::attachColorTexture(ITexture2d* target, int no)
	{
		PFNGLFRAMEBUFFERTEXTURE2DEXTPROC glFramebufferTexture2DEXT;
		GLuint* v5;

		if (!this->frameBuffer)
			return 0;
		glFramebufferTexture2DEXT = this->ext->glFramebufferTexture2DEXT;
		v5 = (GLuint*)(*((__int64(__fastcall**)(ITexture2d*))target->_vptr_ITexture + 5))(target);
		glFramebufferTexture2DEXT(36160LL, no + 36064, 3553LL, *v5, 0LL);
		return 1;
	}

	bool FBO::attachDepthTexture(ITexture2d* target)
	{
		PFNGLFRAMEBUFFERTEXTURE2DEXTPROC glFramebufferTexture2DEXT;
		GLuint* v4;

		if (!this->frameBuffer)
			return 0;
		glFramebufferTexture2DEXT = this->ext->glFramebufferTexture2DEXT;
		v4 = (GLuint*)(*((__int64(__fastcall**)(ITexture2d*))target->_vptr_ITexture + 5))(target);
		glFramebufferTexture2DEXT(36160LL, 36096LL, 3553LL, *v4, 0LL);
		return 1;
	}

	bool FBO::attachColorTexture(ITextureRectangle* target, int no)
	{
		PFNGLFRAMEBUFFERTEXTURE2DEXTPROC glFramebufferTexture2DEXT;
		GLuint* v5;

		if (!this->frameBuffer)
			return 0;
		glFramebufferTexture2DEXT = this->ext->glFramebufferTexture2DEXT;
		v5 = (GLuint*)(*((__int64(__fastcall**)(ITextureRectangle*))target->_vptr_ITexture + 5))(target);
		glFramebufferTexture2DEXT(36160LL, no + 36064, 34037LL, *v5, 0LL);
		return 1;
	}

	bool FBO::attachDepthTexture(ITextureRectangle* target)
	{
		PFNGLFRAMEBUFFERTEXTURE2DEXTPROC glFramebufferTexture2DEXT;
		GLuint* v4;

		if (!this->frameBuffer)
			return 0;
		glFramebufferTexture2DEXT = this->ext->glFramebufferTexture2DEXT;
		v4 = (GLuint*)(*((__int64(__fastcall**)(ITextureRectangle*))target->_vptr_ITexture + 5))(target);
		glFramebufferTexture2DEXT(36160LL, 36096LL, 34037LL, *v4, 0LL);
		return 1;
	}

	int FBO::maxColorAttachemnts()
	{
		int n;

		glGetIntegerv(36063LL, &n);
		return n;
	}

	unsigned int FBO::width()
	{
		return this->w;
	}

	unsigned int FBO::height()
	{
		return this->h;
	}

	bool FBO::hasStencil()
	{
		return this->stencilBuffer != 0;
	}

	bool FBO::hasDepth()
	{
		return this->depthBuffer != 0;
	}

	bool FBO::detachColorTexture(int no)
	{
		if (!this->frameBuffer)
			return 0;
		this->ext->glFramebufferTexture2DEXT(36160LL, no + 36064, 3553LL, 0LL, 0LL);
		return 1;
	}

	bool FBO::detachDepthTexture()
	{
		if (!this->frameBuffer)
			return 0;
		this->ext->glFramebufferTexture2DEXT(36160LL, 36096LL, 3553LL, 0LL, 0LL);
		return 1;
	}
}
