#include "privateGLSupportClass.h"

MyGL::privateGLSupportClass::privateGLSupportClass(MyGL::CGL& glD) {
	this->gl = glD;
	this->wasFBOInit = 0;
	this->wasInitShaders = 0;
	this->wasInitTextureAPI = 0;
	this->wasInitVBO = 0;
}

const void* MyGL::privateGLSupportClass::toGlColorSystem(MyGL::IRender& render, MyGL::ITexture::Format::Type colorSystem)
{
	MyGL::CGL* v2;

	v2 = (MyGL::CGL*)(*((__int64(__fastcall**)(MyGL::IRender*))render->_vptr_IRender + 9))(render);
	if (MyGL::CGL::isDXTFormatSupported(v2)
		&& (colorSystem == MyGL::ITexture::Format::Type::RGB_DXT1
			|| colorSystem == MyGL::ITexture::Format::Type::RGBA_DXT1
			|| colorSystem == MyGL::ITexture::Format::Type::RGBA_DXT3
			|| colorSystem == MyGL::ITexture::Format::Type::RGBA_DXT5))
	{
		return &toGlColorSystem(MyGL::IRender*, MyGL::ITexture::Format::Type)::dxtFormat[colorSystem - 15];
	}
	else
	{
		return &toGlColorSystem(MyGL::IRender*, MyGL::ITexture::Format::Type)::gpuFormat[colorSystem];
	}
}

const void* MyGL::privateGLSupportClass::toGlInputFormat(MyGL::IRender& a1, MyGL::ITexture::InputFormat::Type imgColorSystem)
{
	return &toGlInputFormat(MyGL::IRender*, MyGL::ITexture::InputFormat::Type)::inputFormat[imgColorSystem];
}

bool MyGL::privateGLSupportClass::initVBO_API()
{
	bool wasInitVBO;

	if (this->wasInitVBO)
		return true;
	wasInitVBO = initGlExtensionFuncPtr(

		&this->glGenBuffersARB,
		"glGenBuffersARB")
		&& initGlExtensionFuncPtr(

			&this->glBindBufferARB,
			"glBindBufferARB")
		&& initGlExtensionFuncPtr(

			&this->glBufferDataARB,
			"glBufferDataARB")
		&& initGlExtensionFuncPtr(

			&this->glDeleteBuffersARB,
			"glDeleteBuffersARB")
		&& initGlExtensionFuncPtr(

			&this->glMultiDrawArraysEXT,
			"glMultiDrawArraysEXT")
		&& initGlExtensionFuncPtr(

			&this->glMapBufferARB,
			"glMapBufferARB")
		&& initGlExtensionFuncPtr(

			&this->glUnmapBufferARB,
			"glUnmapBufferARB")
		&& initGlExtensionFuncPtr(

			&this->glBufferSubDataARB,
			"glBufferSubDataARB");
	this->wasInitVBO = wasInitVBO;
	return this->wasInitVBO;
}

bool MyGL::privateGLSupportClass::initTextureAPI()
{
	if (this->wasInitTextureAPI)
		return true;
	this->wasInitTextureAPI = initGlExtensionFuncPtr(
		&this->glActiveTextureARB,
		"glActiveTextureARB");
	return this->wasInitTextureAPI;
}

bool MyGL::privateGLSupportClass::initShadersAPI()
{
	bool wasInitShaders;

	if (this->wasInitShaders)
		return true;
	wasInitShaders = initGlExtensionFuncPtr(
		&this->glUniform1fARB,
		"glUniform1fARB")
		&& initGlExtensionFuncPtr(
			&this->glUniform1iARB,
			"glUniform1iARB")
		&& initGlExtensionFuncPtr(
			&this->glUniform4fARB,
			"glUniform4fARB")
		&& initGlExtensionFuncPtr(
			&this->glUniform4iARB,
			"glUniform4iARB")
		&& initGlExtensionFuncPtr(
			&this->glUniformMatrix4fv,
			"glUniformMatrix4fv");
	this->wasInitShaders = wasInitShaders;
	return this->wasInitShaders;
}

bool MyGL::privateGLSupportClass::initFBO_API()
{
	bool wasFBOInit;

	if (this->wasFBOInit)
		return true;
	wasFBOInit = initGlExtensionFuncPtr(
		&this->glIsRenderbufferEXT,
		"glIsRenderbufferEXT")
		&& initGlExtensionFuncPtr(
			&this->glBindRenderbufferEXT,
			"glBindRenderbufferEXT")
		&& initGlExtensionFuncPtr(
			&this->glDeleteRenderbuffersEXT,
			"glDeleteRenderbuffersEXT")
		&& initGlExtensionFuncPtr(
			&this->glGenRenderbuffersEXT,
			"glGenRenderbuffersEXT")
		&& initGlExtensionFuncPtr(
			&this->glRenderbufferStorageEXT,
			"glRenderbufferStorageEXT")
		&& initGlExtensionFuncPtr(
			&this->glGetRenderbufferParameterivEXT,
			"glGetRenderbufferParameterivEXT")
		&& initGlExtensionFuncPtr(
			&this->glIsFramebufferEXT,
			"glIsFramebufferEXT")
		&& initGlExtensionFuncPtr(
			&this->glBindFramebufferEXT,
			"glBindFramebufferEXT")
		&& initGlExtensionFuncPtr(
			&this->glDeleteFramebuffersEXT,
			"glDeleteFramebuffersEXT")
		&& initGlExtensionFuncPtr(
			&this->glGenFramebuffersEXT,
			"glGenFramebuffersEXT")
		&& initGlExtensionFuncPtr(
			&this->glCheckFramebufferStatusEXT,
			"glCheckFramebufferStatusEXT")
		&& initGlExtensionFuncPtr(
			&this->glFramebufferTexture1DEXT,
			"glFramebufferTexture1DEXT")
		&& initGlExtensionFuncPtr(
			&this->glFramebufferTexture2DEXT,
			"glFramebufferTexture2DEXT")
		&& initGlExtensionFuncPtr(
			&this->glFramebufferTexture3DEXT,
			"glFramebufferTexture3DEXT")
		&& initGlExtensionFuncPtr(
			&this->glFramebufferRenderbufferEXT,
			"glFramebufferRenderbufferEXT")
		&& initGlExtensionFuncPtr(
			&this->glRenderbufferStorageEXT,
			"glRenderbufferStorageEXT")
		&& initGlExtensionFuncPtr(
			&this->glGetFramebufferAttachmentParameterivEXT,
			"glGetFramebufferAttachmentParameterivEXT")
		&& initGlExtensionFuncPtr(
			&this->glGenRenderbuffersEXT,
			"glGenRenderbuffersEXT")
		&& initGlExtensionFuncPtr(
			&this->glGenerateMipmapEXT,
			"glGenerateMipmapEXT");
	this->wasFBOInit = wasFBOInit;
	return this->wasFBOInit;
}

bool MyGL::privateGLSupportClass::initColorAPI()
{
	return initGlExtensionFuncPtr(&this->glClampColorARB, "glClampColorARB");
}
