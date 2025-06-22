#include "Render.h"

MyGL::Render::Render(MyGL::CGL& glDevice)
{
	MyGL::Color::Color(&this->clrColor);
	this->glDev = glDevice;
	this->autoDel = 0;
	this->init();
}

MyGL::Render::Render(MyGL::CGL* glDevice)
{
	MyGL::Color::Color(&this->clrColor);
	this->glDev = glDevice;
	this->autoDel = 1;
	this->init();
}

MyGL::Render::~Render()
{
	MyGL::CGL* glDev;


	if (this->autoDel)
	{
		glDev = this->glDev;
		if (glDev)
		{
			MyGL::CGL::~CGL(this->glDev);
			operator delete(glDev);
		}
	}
	if (this->defState)
		(*((void(__fastcall**)(MyGL::IRenderState*))this->defState->_vptr_IRenderState + 1))(this->defState);
	if (this->state)
		(*((void(__fastcall**)(MyGL::IRenderState*))this->state->_vptr_IRenderState + 1))(this->state);
	MyGL::IRender::~IRender(this);
}

unsigned int MyGL::Render::batchCount()
{
	return this->batchCount_val;
}

void MyGL::Render::begin()
{
	MyGL::CGL* v1;
	MyGL::IErrorControl* v2;

	v1 = (MyGL::CGL*)(*((__int64(__fastcall**)(MyGL::Render* const))this->_vptr_IRender + 9))(this);
	v2 = MyGL::CGL::errorCtrl(v1);
	(*((void(__fastcall**)(MyGL::IErrorControl*, bool, const char*))v2->_vptr_IErrorControl + 4))(
		v2,
		!this->isWork,
		"Render is already activated");
	this->isWork = 1;
	(*((void(__fastcall**)(MyGL::Render* const))this->_vptr_IRender + 31))(this);
	upsetRState(this);
}

void MyGL::Render::bindCamera()
{
	__int64 v1;
	float zFar_1;
	float zNear_1;
	double* x_1;
	double* src;
	__int64 v6;
	__int64 v7;
	__int64 v8;
	__int64 v9;
	__int64 v10;
	__int64 v11;
	__int64 v12;
	double* x_2;
	double* src_1;
	glm::detail::tmat4x4<double> mview;
	glm::detail::tmat4x4<double> proj;
	int vp[4];
	glm::detail::tmat4x4<float> m;
	float zFar;
	float zNear;
	float aspect;
	float fovy;
	glm::detail::tmat4x4<double> retstr_;
	glm::detail::tvec3<double> v;
	double z;
	int y;
	int x;
	glm::detail::tmat4x4<double> retstr__1;
	glm::detail::tvec3<double> v29;
	value_type s;
	glm::detail::tmat4x4<double> retstr__2;
	glm::detail::tvec3<double> v32;
	int z_;
	int y_;
	int x_;
	double angle;
	glm::detail::tmat4x4<double> retstr__3;
	glm::detail::tvec3<double> v38;
	int z__1;
	int y__1;
	int x__1;
	double angle_;
	glm::detail::tmat4x4<double> retstr__4;
	glm::detail::tvec3<double> v44;
	value_type s2;
	value_type s1;
	value_type s0[3];

	if (this->cam)
	{
		glMatrixMode(5889LL);
		glm::detail::tmat4x4<double>::tmat4x4(&proj);
		v1 = (*((__int64(__fastcall**)(MyGL::Render* const))this->_vptr_IRender + 32))(this);
		if ((*(unsigned __int8(__fastcall**)(__int64))(*(_QWORD*)v1 + 112LL))(v1))
		{
			glGetIntegerv(2978LL, vp);
			zFar_1 = _mm_unpacklo_pd((__m128d) * (unsigned __int64*)&this->zFar, (__m128d) * (unsigned __int64*)&this->zFar).m128d_f64[0];
			zFar = zFar_1;
			zNear_1 = _mm_unpacklo_pd((__m128d) * (unsigned __int64*)&this->zNear, (__m128d) * (unsigned __int64*)&this->zNear).m128d_f64[0];
			zNear = zNear_1;
			aspect = (float)vp[2] / (float)vp[3];
			fovy = 30.0;
			glm::gtc::matrix_projection::perspective<float>(&m, &fovy, &aspect, &zNear, &zFar);
			glm::detail::tmat4x4<double>::operator=<float>(&proj, &m);
		}
		x_1 = glm::gtc::type_ptr::value_ptr<double>(&proj);
		glLoadMatrix(this, x_1);
		src = glm::gtc::type_ptr::value_ptr<double>(&proj);
		memcpy(this->projectionMat, src, sizeof(this->projectionMat));
		glMatrixMode(5888LL);
		glm::detail::tmat4x4<double>::tmat4x4(&mview);
		v6 = (*((__int64(__fastcall**)(MyGL::Render* const))this->_vptr_IRender + 32))(this);
		z = -(*(double(__fastcall**)(__int64))(*(_QWORD*)v6 + 80LL))(v6);
		y = 0;
		x = 0;
		glm::detail::tvec3<double>::tvec3<int, int, double>(&v, &x, &y, &z);
		glm::gtc::matrix_transform::translate<double>(&retstr_, &mview, &v);
		glm::detail::tmat4x4<double>::operator=(&mview, &retstr_);
		v7 = (*((__int64(__fastcall**)(MyGL::Render* const))this->_vptr_IRender + 32))(this);
		s = (*(double(__fastcall**)(__int64))(*(_QWORD*)v7 + 88LL))(v7);
		glm::detail::tvec3<double>::tvec3(&v29, &s);
		glm::gtc::matrix_transform::scale<double>(&retstr__1, &mview, &v29);
		glm::detail::tmat4x4<double>::operator=(&mview, &retstr__1);
		z_ = 0;
		y_ = 0;
		x_ = 1;
		glm::detail::tvec3<double>::tvec3<int, int, int>(&v32, &x_, &y_, &z_);
		v8 = (*((__int64(__fastcall**)(MyGL::Render* const))this->_vptr_IRender + 32))(this);
		angle = (*(double(__fastcall**)(__int64))(*(_QWORD*)v8 + 96LL))(v8);
		glm::gtc::matrix_transform::rotate<double>(&retstr__2, &mview, &angle, &v32);
		glm::detail::tmat4x4<double>::operator=(&mview, &retstr__2);
		z__1 = 1;
		y__1 = 0;
		x__1 = 0;
		glm::detail::tvec3<double>::tvec3<int, int, int>(&v38, &x__1, &y__1, &z__1);
		v9 = (*((__int64(__fastcall**)(MyGL::Render* const))this->_vptr_IRender + 32))(this);
		angle_ = (*(double(__fastcall**)(__int64))(*(_QWORD*)v9 + 104LL))(v9);
		glm::gtc::matrix_transform::rotate<double>(&retstr__3, &mview, &angle_, &v38);
		glm::detail::tmat4x4<double>::operator=(&mview, &retstr__3);
		v10 = (*((__int64(__fastcall**)(MyGL::Render* const))this->_vptr_IRender + 32))(this);
		s2 = -(*(double(__fastcall**)(__int64))(*(_QWORD*)v10 + 72LL))(v10);
		v11 = (*((__int64(__fastcall**)(MyGL::Render* const))this->_vptr_IRender + 32))(this);
		s1 = -(*(double(__fastcall**)(__int64))(*(_QWORD*)v11 + 64LL))(v11);
		v12 = (*((__int64(__fastcall**)(MyGL::Render* const))this->_vptr_IRender + 32))(this);
		s0[0] = -(*(double(__fastcall**)(__int64))(*(_QWORD*)v12 + 56LL))(v12);
		glm::detail::tvec3<double>::tvec3(&v44, s0, &s1, &s2);
		glm::gtc::matrix_transform::translate<double>(&retstr__4, &mview, &v44);
		glm::detail::tmat4x4<double>::operator=(&mview, &retstr__4);
		x_2 = glm::gtc::type_ptr::value_ptr<double>(&mview);
		glLoadMatrix(this, x_2);
		src_1 = glm::gtc::type_ptr::value_ptr<double>(&mview);
		memcpy(this->modelView, src_1, sizeof(this->modelView));
		if (this->scene)
			(*((void(__fastcall**)(MyGL::IScene*, MyGL::Render* const))this->scene->_vptr_IScene + 22))(this->scene, this);
	}
}

void MyGL::Render::bindMaterial(MyGL::IMaterial* material)
{
	if (this->currMaterial == material)
	{
		(*((void(__fastcall**)(MyGL::IMaterial*))material->_vptr_IMaterial + 3))(material);
	}
	else
	{
		(*((void(__fastcall**)(MyGL::Render* const))this->_vptr_IRender + 28))(this);
		this->currMaterial = material;
		(*((void(__fastcall**)(MyGL::IMaterial*))material->_vptr_IMaterial + 2))(material);
	}
}

void MyGL::Render::bindModel(MyGL::IModel* m)
{
	if (this->currModel != m)
	{
		(*((void(__fastcall**)(MyGL::Render* const))this->_vptr_IRender + 23))(this);
		this->currModel = m;
		(*((void(__fastcall**)(MyGL::IModel*))m->_vptr_IModel + 2))(m);
		++this->batchCount_val;
	}
}

void MyGL::Render::bindTexture(MyGL::IUniformSampler* sampler, MyGL::ITexture* tex)
{
	void(__fastcall * v3)(MyGL::Render* const, _QWORD, MyGL::ITexture*);
	unsigned int v4;

	v3 = (void(__fastcall*)(MyGL::Render* const, _QWORD, MyGL::ITexture*)) * ((_QWORD*)this->_vptr_IRender + 15);
	v4 = (*((__int64(__fastcall**)(MyGL::IUniformSampler*))sampler->_vptr_IUniform + 7))(sampler);
	v3(this, v4, tex);
}

void MyGL::Render::bindTexture(MyGL::CGL::TextureUnitHandle tx_unit, MyGL::ITexture* tex)
{
	MyGL::CGL* v3;
	MyGL::privateGLSupportClass* v4;

	v3 = (MyGL::CGL*)(*((__int64(__fastcall**)(MyGL::Render* const))this->_vptr_IRender + 9))(this);
	v4 = MyGL::CGL::ext(v3);
	v4->glActiveTextureARB(tx_unit + 33984);
	(*((void(__fastcall**)(MyGL::ITexture*))tex->_vptr_ITexture + 3))(tex);
}

void MyGL::Render::bindVBO(MyGL::IVBO* vbo, MyGL::IVBO::BindMode::Type mode)
{
	(*((void(__fastcall**)(MyGL::IVBO*, _QWORD))vbo->_vptr_IVBO + 2))(vbo, (unsigned int)mode);
}

MyGL::ICamera* MyGL::Render::camera()
{
	return this->cam;
}

void MyGL::Render::clear(MyGL::Color c, clear::ClearMode mode)
{
	double ca;
	double tmp;

	ca = *(double*)c.cdata;
	tmp = (*((double(__fastcall**)(MyGL::Render* const))this->_vptr_IRender + 3))(this);
	(*((void(__fastcall**)(MyGL::Render* const, double, double))this->_vptr_IRender + 2))(
		this,
		ca,
		*(double*)&c.cdata[2]);
	(*((void(__fastcall**)(MyGL::Render* const, _QWORD))this->_vptr_IRender + 4))(this, (unsigned int)mode);
	(*((void(__fastcall**)(MyGL::Render* const, double, double))this->_vptr_IRender + 2))(
		this,
		tmp,
		*(double*)&c.cdata[2]);
}

void MyGL::Render::clear(clear::ClearMode mode)
{
	GLbitfield bits;

	bits = 0;
	if ((mode & 1) != 0)
	{
		bits = 0x4000;
		glColorMask(1LL, 1LL, 1LL, 1LL);
	}
	if ((mode & 2) != 0)
	{
		bits |= 0x100u;
		glDepthMask(1LL);
	}
	glClear(bits);
}

void MyGL::Render::clearColor(a_1, MyGL::Color c)
{
	float v2;
	float v3;
	float v4;
	float v5;
	MyGL::Color ca;
	MyGL::Render* thisa;

	thisa = thisa_1;
	*(_QWORD*)ca.cdata = *(_QWORD*)c.cdata;
	*(_QWORD*)&ca.cdata[2] = *(_QWORD*)&c.cdata[2];
	MyGL::Color::operator=(&thisa_1->clrColor, &ca);
	v5 = MyGL::Color::a(&ca);
	v4 = MyGL::Color::b(&ca);
	v3 = MyGL::Color::g(&ca);
	v2 = MyGL::Color::r(&ca);
	glClearColor(v2, v3, v4, v5);
}

MyGL::Color MyGL::Render::clearColor()
{
	__int64 v1;
	__int64 v2;
	MyGL::Color result;

	v1 = *(_QWORD*)this->clrColor.cdata;
	v2 = *(_QWORD*)&this->clrColor.cdata[2];
	*(_QWORD*)&result.cdata[2] = v2;
	*(_QWORD*)result.cdata = v1;
	return result;
}

unsigned int MyGL::Render::dipCount()
{
	return this->dipCount_val;
}

void MyGL::Render::draw(MyGL::IGraphicsObject* const obj)
{
	__int64 v2;
	void(__fastcall * v3)(MyGL::Render* const, __int64);
	__int64 v4;
	void(__fastcall * v5)(MyGL::Render* const, __int64, __int64);
	__int64 v6;
	__int64 v7;

	if ((*((unsigned __int8(__fastcall**)(MyGL::IGraphicsObject* const))obj->_vptr_IGraphicsObject + 9))(obj))
	{
		v2 = (*((__int64(__fastcall**)(MyGL::IGraphicsObject* const))obj->_vptr_IGraphicsObject + 3))(obj);
		if ((*(unsigned __int8(__fastcall**)(__int64, MyGL::IGraphicsObject* const))(*(_QWORD*)v2 + 96LL))(v2, obj))
		{
			v3 = (void(__fastcall*)(MyGL::Render* const, __int64)) * ((_QWORD*)this->_vptr_IRender + 27);
			v4 = (*((__int64(__fastcall**)(MyGL::IGraphicsObject* const))obj->_vptr_IGraphicsObject + 3))(obj);
			v3(this, v4);
			v5 = (void(__fastcall*)(MyGL::Render* const, __int64, __int64)) * ((_QWORD*)this->_vptr_IRender + 25);
			v6 = (*((__int64(__fastcall**)(MyGL::IGraphicsObject* const))obj->_vptr_IGraphicsObject + 5))(obj);
			v7 = (*((__int64(__fastcall**)(MyGL::IGraphicsObject* const))obj->_vptr_IGraphicsObject + 7))(obj);
			v5(this, v7, v6);
		}
	}
}

void MyGL::Render::drawModel(MyGL::IModel* m)
{
	(*((void(__fastcall**)(MyGL::Render* const, MyGL::IModel*))this->_vptr_IRender + 22))(this, m);
	(*((void(__fastcall**)(MyGL::IModel*, __int64))m->_vptr_IModel + 6))(m, 1LL);
}

void MyGL::Render::drawModel(MyGL::IModel* m, const MyGL::ObjectMatrix* const objMatrix)
{
	const double* x;

	x = MyGL::ObjectMatrix::data(objMatrix);
	glMultMatrix(this, x);
	(*((void(__fastcall**)(MyGL::Render* const, MyGL::IModel*))this->_vptr_IRender + 24))(this, m);
	glLoadMatrix(this, this->modelView);
}

void MyGL::Render::drawVBO(MyGL::IVBO::PrimitiveType::Type p, MyGL::CGL::GLsizei size)
{
	if (p)
	{
		if (p == MyGL::IVBO::PrimitiveType::Type::TrianglesStrip)
		{
			this->polyCount_val = this->polyCount_val + size - 2;
		}
		else if (p == MyGL::IVBO::PrimitiveType::Type::Quads)
		{
			this->polyCount_val += size / 2;
		}
	}
	else
	{
		this->polyCount_val += size / 3;
	}
	glDrawArrays(drawVBO(MyGL::IVBO::PrimitiveType::Type, int)::primitiveT[p], 0LL, (unsigned int)size);
	++this->dipCount_val;
}

void MyGL::Render::end()
{
	MyGL::CGL* v1;
	MyGL::IErrorControl* v2;

	v1 = (MyGL::CGL*)(*((__int64(__fastcall**)(MyGL::Render* const))this->_vptr_IRender + 9))(this);
	v2 = MyGL::CGL::errorCtrl(v1);
	(*((void(__fastcall**)(MyGL::IErrorControl*, bool, const char*))v2->_vptr_IErrorControl + 4))(
		v2,
		this->isWork,
		"Render is not activated");
	(*((void(__fastcall**)(MyGL::Render* const))this->_vptr_IRender + 28))(this);
	(*((void(__fastcall**)(MyGL::Render* const, _QWORD))this->_vptr_IRender + 13))(this, 0LL);
	(*((void(__fastcall**)(MyGL::Render* const))this->_vptr_IRender + 23))(this);
	this->isWork = 0;
	(*((void(__fastcall**)(MyGL::Render* const))this->_vptr_IRender + 36))(this);
}

void MyGL::Render::finitGL()
{
	;
}

std::string MyGL::Render::getError()
{
	char v2;
	char v3;
	char v4;
	char v5;
	char v6;
	char v7;
	char v8;
	char v9;
	GLenum err;

	err = glGetError();
	if (err)
	{
		switch (err)
		{
		case 0x500u:
			std::allocator<char>::allocator(&v3);
			std::string::string(this, "GL_INVALID_ENUM", &v3);
			std::allocator<char>::~allocator(&v3);
			break;
		case 0x501u:
			std::allocator<char>::allocator(&v4);
			std::string::string(this, "GL_INVALID_VALUE", &v4);
			std::allocator<char>::~allocator(&v4);
			break;
		case 0x502u:
			std::allocator<char>::allocator(&v5);
			std::string::string(this, "GL_INVALID_OPERATION", &v5);
			std::allocator<char>::~allocator(&v5);
			break;
		case 0x503u:
			std::allocator<char>::allocator(&v6);
			std::string::string(this, "GL_STACK_OVERFLOW", &v6);
			std::allocator<char>::~allocator(&v6);
			break;
		case 0x504u:
			std::allocator<char>::allocator(&v7);
			std::string::string(this, "GL_STACK_UNDERFLOW", &v7);
			std::allocator<char>::~allocator(&v7);
			break;
		case 0x505u:
			std::allocator<char>::allocator(&v8);
			std::string::string(this, "GL_OUT_OF_MEMORY", &v8);
			std::allocator<char>::~allocator(&v8);
			break;
		default:
			std::allocator<char>::allocator(&v9);
			std::string::string(this, &unk_4D3AB3, &v9);
			std::allocator<char>::~allocator(&v9);
			break;
		}
	}
	else
	{
		std::allocator<char>::allocator(&v2);
		std::string::string(this, &unk_4D3AB3, &v2);
		std::allocator<char>::~allocator(&v2);
	}
	return (std::string)this;
}

void MyGL::Render::getModeViewlMatrix(MyGL::ObjectMatrix* const out)
{
	MyGL::ObjectMatrix::setData(out, this->modelView);
}

void MyGL::Render::getModeViewlMatrix(MyGL::Float* out)
{
	memcpy(out, this->modelView, 0x80uLL);
}

void MyGL::Render::getProjectionMatrix(MyGL::ObjectMatrix* const out)
{
	MyGL::ObjectMatrix::setData(out, this->projectionMat);
}

void MyGL::Render::getProjectionMatrix(MyGL::Float* out)
{
	memcpy(out, this->projectionMat, 0x80uLL);
}

void MyGL::Render::getTransformMatrix(MyGL::ObjectMatrix* const out)
{
	const MyGL::Float* data;
	MyGL::ObjectMatrix pm;
	MyGL::ObjectMatrix mv;

	MyGL::ObjectMatrix::ObjectMatrix(&mv);
	MyGL::ObjectMatrix::ObjectMatrix(&pm);
	(*((void(__fastcall**)(MyGL::Render* const, MyGL::ObjectMatrix*))this->_vptr_IRender + 40))(this, &mv);
	(*((void(__fastcall**)(MyGL::Render* const, MyGL::ObjectMatrix*))this->_vptr_IRender + 41))(this, &pm);
	MyGL::ObjectMatrix::mul(&mv, &pm);
	data = MyGL::ObjectMatrix::data(&mv);
	MyGL::ObjectMatrix::setData(out, data);
	MyGL::ObjectMatrix::~ObjectMatrix(&pm);
	MyGL::ObjectMatrix::~ObjectMatrix(&mv);
}

void MyGL::Render::getViewport(int* const x, int* const y, int* const w, int* const h)
{
	int v[4];

	glGetIntegerv(2978LL, v);
	*x = v[0];
	*y = v[1];
	*w = v[2];
	*h = v[3];
}

MyGL::CGL* MyGL::Render::gl()
{
	return this->glDev;
}

void MyGL::Render::glLoadMatrix(const double* x)
{
	glLoadMatrixd(x);
}

void MyGL::Render::glLoadMatrix(const float* x)
{
	glLoadMatrixf(x);
}

void MyGL::Render::glMultMatrix(const double* x)
{
	glMultMatrixd(x);
}

void MyGL::Render::glMultMatrix(const float* x)
{
	glMultMatrixf(x);
}

void MyGL::Render::init()
{
	MyGL::RenderState* defState;
	MyGL::RenderState* state;

	this->wInit = 0;
	this->isWork = 0;
	this->currShader = 0LL;
	this->currMaterial = 0LL;
	this->currModel = 0LL;
	(*((void(__fastcall**)(MyGL::Render* const, double, double))this->_vptr_IRender + 29))(this, 0.0, 1.0);
	this->cam = 0LL;
	defState = (MyGL::RenderState*)operator new(0x30uLL);
	MyGL::RenderState::RenderState(defState);
	this->defState = defState;
	state = (MyGL::RenderState*)operator new(0x30uLL);
	MyGL::RenderState::RenderState(state);
	this->state = state;
	this->scene = 0LL;
	this->isGL_ARB_multisampleEnable = 0;
	(*((void(__fastcall**)(MyGL::Render* const))this->_vptr_IRender + 51))(this);
}

bool MyGL::Render::initGL()
{
	MyGL::CGL* glD;
	MyGL::CGL* v2;
	MyGL::CGL* v4;
	MyGL::CGL* v5;
	MyGL::CGL* v6;
	MyGL::CGL* v7;
	MyGL::privateGLSupportClass* v8;

	glD = (MyGL::CGL*)(*((__int64(__fastcall**)(MyGL::Render* const))this->_vptr_IRender + 9))(this);
	MyGL::CGL::createExtObject(glD);
	v2 = (MyGL::CGL*)(*((__int64(__fastcall**)(MyGL::Render* const))this->_vptr_IRender + 9))(this);
	if (!MyGL::CGL::initShaderAPI(v2))
		return 0;
	v4 = (MyGL::CGL*)(*((__int64(__fastcall**)(MyGL::Render* const))this->_vptr_IRender + 9))(this);
	if (!MyGL::CGL::initTextureAPI(v4))
		return 0;
	v5 = (MyGL::CGL*)(*((__int64(__fastcall**)(MyGL::Render* const))this->_vptr_IRender + 9))(this);
	if (!MyGL::CGL::initVBO_API(v5))
		return 0;
	v6 = (MyGL::CGL*)(*((__int64(__fastcall**)(MyGL::Render* const))this->_vptr_IRender + 9))(this);
	if (!MyGL::CGL::initFBO_API(v6))
		return 0;
	v7 = (MyGL::CGL*)(*((__int64(__fastcall**)(MyGL::Render* const))this->_vptr_IRender + 9))(this);
	v8 = MyGL::CGL::ext(v7);
	v8->glGenerateMipmapEXT(3553LL);
	glEnableClientState(32884LL);
	glEnableClientState(32888LL);
	glEnableClientState(32885LL);
	this->isGL_ARB_multisampleEnable = MyGL::CGL::isExtensionSupported(this->glDev, "GL_ARB_multisample");
	this->wInit = 1;
	return 1;
}

bool MyGL::Render::isActive()
{
	return this->isWork;
}

bool MyGL::Render::isShaderCurrent(MyGL::IShader* sh)
{
	return this->currShader == sh;
}

unsigned int MyGL::Render::polyCount()
{
	return this->polyCount_val;
}

MyGL::IRenderState* MyGL::Render::renderState()
{
	return this->state;
}

void MyGL::Render::resetBatchCount()
{
	this->batchCount_val = 0;
}

void MyGL::Render::resetCounters()
{
	(*((void(__fastcall**)(MyGL::Render* const))this->_vptr_IRender + 46))(this);
	(*((void(__fastcall**)(MyGL::Render* const))this->_vptr_IRender + 48))(this);
	(*((void(__fastcall**)(MyGL::Render* const))this->_vptr_IRender + 50))(this);
}

void MyGL::Render::resetDipCount()
{
	this->dipCount_val = 0;
}

void MyGL::Render::resetPolyCount()
{
	this->polyCount_val = 0;
}

void MyGL::Render::resetRenderState()
{
	(*((void(__fastcall**)(MyGL::IRenderState*, MyGL::IRenderState*))this->state->_vptr_IRenderState + 4))(
		this->state,
		this->defState);
}

void MyGL::Render::setCamera(MyGL::ICamera* const c)
{
	this->cam = c;
	(*((void(__fastcall**)(MyGL::Render* const))this->_vptr_IRender + 31))(this);
}

void MyGL::Render::setRenderState(MyGL::IRenderState* r)
{
	(*((void(__fastcall**)(MyGL::IRenderState*, MyGL::IRenderState*))this->state->_vptr_IRenderState + 4))(
		this->state,
		r);
	if (this->isWork)
		upsetRState(this);
}

void MyGL::Render::setScene(MyGL::IScene* const s)
{
	this->scene = s;
}

void MyGL::Render::setViewport(int x, int y, int w, int h)
{
	glViewport((unsigned int)x, (unsigned int)y, (unsigned int)w, (unsigned int)h);
}

void MyGL::Render::setZRange(double, double)
{
	this->zNear = near;
	this->zFar = far;
}

void MyGL::Render::ubindMaterial()
{
	if (this->currMaterial)
		(*((void(__fastcall**)(MyGL::IMaterial*))this->currMaterial->_vptr_IMaterial + 4))(this->currMaterial);
	this->currMaterial = 0LL;
}

void MyGL::Render::ubindModel()
{
	if (this->currModel)
	{
		(*((void(__fastcall**)(MyGL::IModel*))this->currModel->_vptr_IModel + 3))(this->currModel);
		this->currModel = 0LL;
	}
}

void MyGL::Render::ubindTexture(MyGL::IUniformSampler* sampler)
{
	void(__fastcall * v2)(MyGL::Render* const, _QWORD);
	unsigned int v3;

	v2 = (void(__fastcall*)(MyGL::Render* const, _QWORD)) * ((_QWORD*)this->_vptr_IRender + 17);
	v3 = (*((__int64(__fastcall**)(MyGL::IUniformSampler*))sampler->_vptr_IUniform + 7))(sampler);
	v2(this, v3);
}

void MyGL::Render::ubindTexture(MyGL::CGL::TextureUnitHandle tx_unit)
{
	MyGL::CGL* v2;
	MyGL::privateGLSupportClass* v3;

	v2 = (MyGL::CGL*)(*((__int64(__fastcall**)(MyGL::Render* const))this->_vptr_IRender + 9))(this);
	v3 = MyGL::CGL::ext(v2);
	v3->glActiveTextureARB(tx_unit + 33984);
	glBindTexture(3553LL, 0LL);
}

void MyGL::Render::ubindVBO(MyGL::IVBO* vbo)
{
	(*((void(__fastcall**)(MyGL::IVBO*))vbo->_vptr_IVBO + 4))(vbo);
}

void MyGL::Render::upsetRState()
{
	__m128d v1;
	__int64 v2;
	__int64 v3;
	int v4;
	__int64 v5;
	int v6;
	__int64 v7;
	unsigned __int8 v8;
	__int64 v9;
	__int64 v10;
	__int64 v11;
	GLenum v12;
	__int64 v13;
	int v14;
	__int64 v15;
	__int64 v17;
	__int64 v18;
	__int64 v19;
	int v20;
	float v21;
	unsigned int cullMode[4];
	unsigned __int8 clMask[32];

	glEnable(3008LL);
	v2 = (*((__int64(__fastcall**)(MyGL::Render* const))this->_vptr_IRender + 35))(this);
	v1.m128d_f64[0] = (*(double(__fastcall**)(__int64))(*(_QWORD*)v2 + 16LL))(v2);
	v21 = _mm_unpacklo_pd(v1, v1).m128d_f64[0];
	v3 = (*((__int64(__fastcall**)(MyGL::Render* const))this->_vptr_IRender + 35))(this);
	v4 = (*(__int64(__fastcall**)(__int64))(*(_QWORD*)v3 + 48LL))(v3);
	glAlphaFunc(upsetRState(void)::testMode[v4], v21);
	v5 = (*((__int64(__fastcall**)(MyGL::Render* const))this->_vptr_IRender + 35))(this);
	v6 = (*(__int64(__fastcall**)(__int64))(*(_QWORD*)v5 + 120LL))(v5);
	glDepthFunc(upsetRState(void)::testMode[v6]);
	v7 = (*((__int64(__fastcall**)(MyGL::Render* const))this->_vptr_IRender + 35))(this);
	v8 = (*(__int64(__fastcall**)(__int64))(*(_QWORD*)v7 + 72LL))(v7);
	glDepthMask(v8);
	v9 = (*((__int64(__fastcall**)(MyGL::Render* const))this->_vptr_IRender + 35))(this);
	if ((*(unsigned __int8(__fastcall**)(__int64))(*(_QWORD*)v9 + 88LL))(v9))
		glEnable(2929LL);
	else
		glDisable(2929LL);
	v10 = (*((__int64(__fastcall**)(MyGL::Render* const))this->_vptr_IRender + 35))(this);
	if ((*(unsigned __int8(__fastcall**)(__int64))(*(_QWORD*)v10 + 136LL))(v10))
	{
		glEnable(3042LL);
		v11 = (*((__int64(__fastcall**)(MyGL::Render* const))this->_vptr_IRender + 35))(this);
		v12 = upsetRState(void)::abMode[(*(int(__fastcall**)(__int64))(*(_QWORD*)v11 + 176LL))(v11)];
		v13 = (*((__int64(__fastcall**)(MyGL::Render* const))this->_vptr_IRender + 35))(this);
		v14 = (*(__int64(__fastcall**)(__int64))(*(_QWORD*)v13 + 168LL))(v13);
		glBlendFunc(upsetRState(void)::abMode[v14], v12);
	}
	else
	{
		glDisable(3042LL);
	}
	v15 = (*((__int64(__fastcall**)(MyGL::Render* const))this->_vptr_IRender + 35))(this);
	if ((*(unsigned __int8(__fastcall**)(__int64))(*(_QWORD*)v15 + 152LL))(v15) && this->isGL_ARB_multisampleEnable)
		glEnable(32926LL);
	else
		glDisable(32926LL);
	v17 = (*((__int64(__fastcall**)(MyGL::Render* const))this->_vptr_IRender + 35))(this);
	(*(void(__fastcall**)(__int64, unsigned __int8*, unsigned __int8*, unsigned __int8*, unsigned __int8*))(*(_QWORD*)v17 + 64LL))(
		v17,
		clMask,
		&clMask[1],
		&clMask[2],
		&clMask[3]);
	glColorMask(clMask[0], clMask[1], clMask[2], clMask[3]);
	cullMode[0] = 0;
	cullMode[1] = 1028;
	cullMode[2] = 1029;
	v18 = (*((__int64(__fastcall**)(MyGL::Render* const))this->_vptr_IRender + 35))(this);
	if ((*(unsigned int(__fastcall**)(__int64))(*(_QWORD*)v18 + 104LL))(v18))
	{
		glEnable(2884LL);
		v19 = (*((__int64(__fastcall**)(MyGL::Render* const))this->_vptr_IRender + 35))(this);
		v20 = (*(__int64(__fastcall**)(__int64))(*(_QWORD*)v19 + 104LL))(v19);
		glCullFace(cullMode[v20]);
	}
	else
	{
		glDisable(2884LL);
	}
}

void MyGL::Render::useShader(MyGL::IShader* sh)
{
	if (this->currShader != sh)
	{
		if (sh)
			(*((void(__fastcall**)(MyGL::IShader*))sh->_vptr_IShader + 10))(sh);
		else
			(*((void(__fastcall**)(MyGL::IShader*))this->currShader->_vptr_IShader + 11))(this->currShader);
		this->currShader = sh;
		++this->batchCount_val;
	}
}

bool MyGL::Render::wasInit()
{
	return this->wInit;
}
