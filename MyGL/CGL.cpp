#include "CGL.h"
#include "ErrorControl.h"
#include "IErrorControl.h"
#include "privateGLSupportClass.h"


MyGL::CGL::CGL() {
	this->eCtrl = new MyGL::ErrorControl();
	this->autoECtrl = 1;
	this->isDXT_supr = 0;
	this->isFBO_Init = 0;
	this->isVBOInit = 0;
	this->isShadingInit = 0;
	this->isTexturesInit = 0;
	this->maxAnisotropyLevel_val = -1.0;
	this->gLSupport = 0LL;
}

void MyGL::CGL::createExtObject(MyGL::CGL* const glD) {
	if (!glD->gLSupport) {
		glD->gLSupport = new MyGL::privateGLSupportClass::privateGLSupportClass(gLSupport, glD);;
	}
}

MyGL::IErrorControl* MyGL::CGL::errorCtrl()
{
	return this->eCtrl;
}

MyGL::privateGLSupportClass* MyGL::CGL::ext()
{
	return this->gLSupport;
}

MyGL::CGL::GLextFuncPtr MyGL::CGL::getProcAddress(const char* f)
{
	return (MyGL::CGL::GLextFuncPtr)glXGetProcAddressARB(f);
}
void MyGL::CGL::initAnisotropy()
{
	int g_nMaxAnisotropy;

	if (this->maxAnisotropyLevel_val < 0.0)
	{
		this->maxAnisotropyLevel_val = 0.0;
		if (this->MyGL::CGL::isExtensionSupported("GL_EXT_texture_filter_anisotropic"))
		{
			glGetIntegerv(34047LL, &g_nMaxAnisotropy);
			this->maxAnisotropyLevel_val = (double)g_nMaxAnisotropy;
		}
	}
}
MyGL::Bool MyGL::CGL::initFBO_API()
{
	MyGL::privateGLSupportClass* v2;

	if (this->isFBO_Init)
		return 1;
	if (!this->MyGL::CGL::isExtensionSupported("GL_EXT_framebuffer_object"))
		return 0;
	v2 = this->MyGL::CGL::ext();
	this->isFBO_Init = MyGL::privateGLSupportClass::initFBO_API(v2);
	return this->isFBO_Init;
}

MyGL::Bool MyGL::CGL::initShaderAPI()
{
	MyGL::privateGLSupportClass* v3;

	if (this->isShadingInit)
		return 1;
	if (!this->MyGL::CGL::isExtensionSupported("GL_ARB_shader_objects")
		|| !this->MyGL::CGL::isExtensionSupported("GL_ARB_shading_language_100")
		|| !this->MyGL::CGL::isExtensionSupported("GL_ARB_vertex_shader")
		|| !this->MyGL::CGL::isExtensionSupported("GL_ARB_fragment_shader"))
	{
		return 0;
	}
	v3 = this->MyGL::CGL::ext();
	this->isShadingInit = MyGL::privateGLSupportClass::initShadersAPI(v3);
	return this->isShadingInit;
}

MyGL::Bool MyGL::CGL::initTextureAPI()
{
	MyGL::privateGLSupportClass* v2;

	if (this->isTexturesInit)
		return 1;
	this->isDXT_supr = this->MyGL::CGL::isExtensionSupported("GL_EXT_texture_compression_s3tc");
	v2 = this->MyGL::CGL::ext();
	this->isTexturesInit = MyGL::privateGLSupportClass::initTextureAPI(v2);
	return this->isTexturesInit;
}

MyGL::Bool MyGL::CGL::initVBO_API()
{
	MyGL::privateGLSupportClass* v2;

	if (this->isVBOInit)
		return 1;
	if (!this->MyGL::CGL::isExtensionSupported("GL_ARB_vertex_buffer_object"))
		return 0;
	v2 = this->MyGL::CGL::ext();
	this->isVBOInit = MyGL::privateGLSupportClass::initVBO_API(v2);
	return this->isVBOInit;
}
MyGL::Bool MyGL::CGL::isAnisotropySupported()
{
	this->initAnisotropy();
	return this->maxAnisotropyLevel_val > 0.0;
}
MyGL::Bool MyGL::CGL::isDXTFormatSupported()
{
	return this->isDXT_supr;
}
bool MyGL::CGL::isExtensionSupported(const char* name)
{
	char* ext;
	bool r;
	int id;
	int i;

	ext = (char*)glGetString(7939LL);
	i = 0;
	if (ext)
	{
		while (ext[i])
		{
			r = 1;
			while (ext[i] == 32)
				++i;
			id = 0;
			while (ext[i] && ext[i] != 32)
			{
				r = (r & (ext[i++] == name[id])) != 0;
				if (name[id])
					++id;
			}
			if (r && name[id] == 0)
				return 1;
		}
	}
	return 0;
}
MyGL::Float MyGL::CGL::maxAnisotropyLevel()
{
	this->initAnisotropy();
	return this->maxAnisotropyLevel_val;
}
void MyGL::CGL::setErrorCtrl(MyGL::IErrorControl* e)
{
	MyGL::ErrorControl* eCtrl;

	if (e)
	{
		if (this->eCtrl)
			(*((void(__fastcall**)(MyGL::IErrorControl*))this->eCtrl->_vptr_IErrorControl + 1))(this->eCtrl);
		this->eCtrl = e;
		this->autoECtrl = 0;
	}
	else if (!this->autoECtrl)
	{
		eCtrl = (MyGL::ErrorControl*)operator new(0x10uLL);
		MyGL::ErrorControl::ErrorControl(eCtrl);
		this->eCtrl = eCtrl;
		this->autoECtrl = 1;
	}
}
