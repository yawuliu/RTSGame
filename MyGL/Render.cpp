#include "Render.h"
namespace MyGL {
	Render::Render(CGL& glDevice)
	{
		this->glDev = glDevice;
		this->autoDel = 0;
		this->init();
	}

	Render::Render(CGL* glDevice)
	{
		this->glDev = glDevice;
		this->autoDel = 1;
		this->init();
	}

	Render::~Render()
	{
		if (this->autoDel)
		{
			if (this->glDev)
			{
				delete this->glDev;
			}
		}
		if (this->defState)
			delete this->defState;
		if (this->state)
            delete this->state;
	}

	unsigned int Render::batchCount()
	{
		return this->batchCount_val;
	}

	void Render::begin()
	{
		CGL* v1;
		IErrorControl* v2;

		v1 = this->gl();
		v2 = CGL::errorCtrl(v1);
		(*((void(__fastcall**)(IErrorControl*, bool, const char*))v2->_vptr_IErrorControl + 4))(
			v2,
			!this->isWork,
			"Render is already activated");
		this->isWork = 1;
		this->bindCamera();
        this->upsetRState();
	}

	void Render::bindCamera()
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
			v1 = this->camera();
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
			v6 = this->camera();
			z = -(*(double(__fastcall**)(__int64))(*(_QWORD*)v6 + 80LL))(v6);
			y = 0;
			x = 0;
			glm::detail::tvec3<double>::tvec3<int, int, double>(&v, &x, &y, &z);
			glm::gtc::matrix_transform::translate<double>(&retstr_, &mview, &v);
			glm::detail::tmat4x4<double>::operator=(&mview, &retstr_);
			v7 = this->camera();
			s = (*(double(__fastcall**)(__int64))(*(_QWORD*)v7 + 88LL))(v7);
			glm::detail::tvec3<double>::tvec3(&v29, &s);
			glm::gtc::matrix_transform::scale<double>(&retstr__1, &mview, &v29);
			glm::detail::tmat4x4<double>::operator=(&mview, &retstr__1);
			z_ = 0;
			y_ = 0;
			x_ = 1;
			glm::detail::tvec3<double>::tvec3<int, int, int>(&v32, &x_, &y_, &z_);
			v8 = this->camera();
			angle = (*(double(__fastcall**)(__int64))(*(_QWORD*)v8 + 96LL))(v8);
			glm::gtc::matrix_transform::rotate<double>(&retstr__2, &mview, &angle, &v32);
			glm::detail::tmat4x4<double>::operator=(&mview, &retstr__2);
			z__1 = 1;
			y__1 = 0;
			x__1 = 0;
			glm::detail::tvec3<double>::tvec3<int, int, int>(&v38, &x__1, &y__1, &z__1);
			v9 = this->camera();
			angle_ = (*(double(__fastcall**)(__int64))(*(_QWORD*)v9 + 104LL))(v9);
			glm::gtc::matrix_transform::rotate<double>(&retstr__3, &mview, &angle_, &v38);
			glm::detail::tmat4x4<double>::operator=(&mview, &retstr__3);
			v10 = this->camera();
			s2 = -(*(double(__fastcall**)(__int64))(*(_QWORD*)v10 + 72LL))(v10);
			v11 = this->camera();
			s1 = -(*(double(__fastcall**)(__int64))(*(_QWORD*)v11 + 64LL))(v11);
			v12 = this->camera();
			s0[0] = -(*(double(__fastcall**)(__int64))(*(_QWORD*)v12 + 56LL))(v12);
			glm::detail::tvec3<double>::tvec3(&v44, s0, &s1, &s2);
			glm::gtc::matrix_transform::translate<double>(&retstr__4, &mview, &v44);
			glm::detail::tmat4x4<double>::operator=(&mview, &retstr__4);
			x_2 = glm::gtc::type_ptr::value_ptr<double>(&mview);
			glLoadMatrix(this, x_2);
			src_1 = glm::gtc::type_ptr::value_ptr<double>(&mview);
			memcpy(this->modelView, src_1, sizeof(this->modelView));
			if (this->scene)
				this->scene->upsetCameraEvent(this);
		}
	}

	void Render::bindMaterial(IMaterial* material)
	{
		if (this->currMaterial == material)
		{
			(*((void(__fastcall**)(IMaterial*))material->_vptr_IMaterial + 3))(material);
		}
		else
		{
			this->ubindMaterial();
			this->currMaterial = material;
			(*((void(__fastcall**)(IMaterial*))material->_vptr_IMaterial + 2))(material);
		}
	}

	void Render::bindModel(IModel* m)
	{
		if (this->currModel != m)
		{
			this->ubindModel();
			this->currModel = m;
			(*((void(__fastcall**)(IModel*))m->_vptr_IModel + 2))(m);
			++this->batchCount_val;
		}
	}

	void Render::bindTexture(IUniformSampler* sampler, ITexture* tex)
	{
		void(__fastcall * v3)(Render* const, _QWORD, ITexture*);
		unsigned int v4;
		v4 = (*((__int64(__fastcall**)(IUniformSampler*))sampler->_vptr_IUniform + 7))(sampler);
        this->bindTexture(v4, tex);
	}

	void Render::bindTexture(CGL::TextureUnitHandle tx_unit, ITexture* tex)
	{
		CGL* v3;
		privateGLSupportClass* v4;

		v3 = this->gl();
		v4 = CGL::ext(v3);
		v4->glActiveTextureARB(tx_unit + 33984);
		(*((void(__fastcall**)(ITexture*))tex->_vptr_ITexture + 3))(tex);
	}

	void Render::bindVBO(IVBO* vbo, IVBO::BindMode::Type mode)
	{
		(*((void(__fastcall**)(IVBO*, _QWORD))vbo->_vptr_IVBO + 2))(vbo, (unsigned int)mode);
	}

	ICamera* Render::camera()
	{
		return this->cam;
	}

	void Render::clear(Color c, clear::ClearMode mode)
	{
		double ca;
		double tmp;

		ca = *(double*)c.cdata;
		tmp = this->clearColor();
			this->clearColor(
			ca,
			*(double*)&c.cdata[2]);
		this->clear((unsigned int)mode);
			this->clearColor(
			tmp,
			*(double*)&c.cdata[2]);
	}

	void Render::clear(clear::ClearMode mode)
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

	void Render::clearColor(a_1, Color c)
	{
		float v2;
		float v3;
		float v4;
		float v5;
		Color ca;
		Render* thisa;

		thisa = thisa_1;
		*(_QWORD*)ca.cdata = *(_QWORD*)c.cdata;
		*(_QWORD*)&ca.cdata[2] = *(_QWORD*)&c.cdata[2];
		Color::operator=(&thisa_1->clrColor, &ca);
		v5 = Color::a(&ca);
		v4 = Color::b(&ca);
		v3 = Color::g(&ca);
		v2 = Color::r(&ca);
		glClearColor(v2, v3, v4, v5);
	}

	Color Render::clearColor()
	{
		__int64 v1;
		__int64 v2;
		Color result;

		v1 = *(_QWORD*)this->clrColor.cdata;
		v2 = *(_QWORD*)&this->clrColor.cdata[2];
		*(_QWORD*)&result.cdata[2] = v2;
		*(_QWORD*)result.cdata = v1;
		return result;
	}

	unsigned int Render::dipCount()
	{
		return this->dipCount_val;
	}

	void Render::draw(IGraphicsObject* const obj)
	{
		__int64 v2;
		void(__fastcall * v3)(Render* const, __int64);
		__int64 v4;
		void(__fastcall * v5)(Render* const, __int64, __int64);
		__int64 v6;
		__int64 v7;

		if (obj->visible())
		{
			v2 = obj->material();
			if ((*(unsigned __int8(__fastcall**)(__int64, IGraphicsObject* const))(*(_QWORD*)v2 + 96LL))(v2, obj))
			{
				v4 = obj->material();
                this->bindMaterial(v4);
				v6 = obj->objectMatrix();
				v7 = obj->model();
                this->drawModel(v7, v6);
			}
		}
	}

	void Render::drawModel(IModel* m)
	{
		this->bindModel(m);
		(*((void(__fastcall**)(IModel*, __int64))m->_vptr_IModel + 6))(m, 1LL);
	}

	void Render::drawModel(IModel* m, const ObjectMatrix* const objMatrix)
	{
		const double* x;

		x = ObjectMatrix::data(objMatrix);
		glMultMatrix(this, x);
		this->drawModel(m);
		glLoadMatrix(this, this->modelView);
	}

	void Render::drawVBO(IVBO::PrimitiveType::Type p, CGL::GLsizei size)
	{
		if (p)
		{
			if (p == IVBO::PrimitiveType::Type::TrianglesStrip)
			{
				this->polyCount_val = this->polyCount_val + size - 2;
			}
			else if (p == IVBO::PrimitiveType::Type::Quads)
			{
				this->polyCount_val += size / 2;
			}
		}
		else
		{
			this->polyCount_val += size / 3;
		}
		glDrawArrays(drawVBO(IVBO::PrimitiveType::Type, int)::primitiveT[p], 0LL, (unsigned int)size);
		++this->dipCount_val;
	}

	void Render::end()
	{
		CGL* v1;
		IErrorControl* v2;

		v1 = this->gl();
		v2 = CGL::errorCtrl(v1);
		(*((void(__fastcall**)(IErrorControl*, bool, const char*))v2->_vptr_IErrorControl + 4))(
			v2,
			this->isWork,
			"Render is not activated");
		this->ubindMaterial();
		this->useShader( 0LL);
		this->ubindModel();
		this->isWork = 0;
		this->resetRenderState();
	}

	void Render::finitGL()
	{
		;
	}

	std::string Render::getError()
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

	void Render::getModeViewlMatrix(ObjectMatrix* const out)
	{
		ObjectMatrix::setData(out, this->modelView);
	}

	void Render::getModeViewlMatrix(Float* out)
	{
		memcpy(out, this->modelView, 0x80uLL);
	}

	void Render::getProjectionMatrix(ObjectMatrix* const out)
	{
		ObjectMatrix::setData(out, this->projectionMat);
	}

	void Render::getProjectionMatrix(Float* out)
	{
		memcpy(out, this->projectionMat, 0x80uLL);
	}

	void Render::getTransformMatrix(ObjectMatrix* const out)
	{
		const Float* data;
		ObjectMatrix pm;
		ObjectMatrix mv;

		ObjectMatrix::ObjectMatrix(&mv);
		ObjectMatrix::ObjectMatrix(&pm);
		this->getModeViewlMatrix(&mv);
		this->getProjectionMatrix( &pm);
		ObjectMatrix::mul(&mv, &pm);
		data = ObjectMatrix::data(&mv);
		ObjectMatrix::setData(out, data);
		ObjectMatrix::~ObjectMatrix(&pm);
		ObjectMatrix::~ObjectMatrix(&mv);
	}

	void Render::getViewport(int* const x, int* const y, int* const w, int* const h)
	{
		int v[4];

		glGetIntegerv(2978LL, v);
		*x = v[0];
		*y = v[1];
		*w = v[2];
		*h = v[3];
	}

	CGL* Render::gl()
	{
		return this->glDev;
	}

	void Render::glLoadMatrix(const double* x)
	{
		glLoadMatrixd(x);
	}

	void Render::glLoadMatrix(const float* x)
	{
		glLoadMatrixf(x);
	}

	void Render::glMultMatrix(const double* x)
	{
		glMultMatrixd(x);
	}

	void Render::glMultMatrix(const float* x)
	{
		glMultMatrixf(x);
	}

	void Render::init()
	{
		RenderState* defState;
		RenderState* state;

		this->wInit = 0;
		this->isWork = 0;
		this->currShader = 0LL;
		this->currMaterial = 0LL;
		this->currModel = 0LL;
		this->setZRange(0.0, 1.0);
		this->cam = 0LL;
		defState = (RenderState*)operator new(0x30uLL);
		RenderState::RenderState(defState);
		this->defState = defState;
		state = (RenderState*)operator new(0x30uLL);
		RenderState::RenderState(state);
		this->state = state;
		this->scene = 0LL;
		this->isGL_ARB_multisampleEnable = 0;
		this->resetCounters();
	}

	bool Render::initGL()
	{
		CGL* glD;
		CGL* v2;
		CGL* v4;
		CGL* v5;
		CGL* v6;
		CGL* v7;
		privateGLSupportClass* v8;

		glD = this->gl();
		CGL::createExtObject(glD);
		v2 = this->gl();
		if (!CGL::initShaderAPI(v2))
			return 0;
		v4 = this->gl();
		if (!CGL::initTextureAPI(v4))
			return 0;
		v5 = this->gl();
		if (!CGL::initVBO_API(v5))
			return 0;
		v6 = this->gl();
		if (!CGL::initFBO_API(v6))
			return 0;
		v7 = this->gl();
		v8 = CGL::ext(v7);
		v8->glGenerateMipmapEXT(3553LL);
		glEnableClientState(32884LL);
		glEnableClientState(32888LL);
		glEnableClientState(32885LL);
		this->isGL_ARB_multisampleEnable = CGL::isExtensionSupported(this->glDev, "GL_ARB_multisample");
		this->wInit = 1;
		return 1;
	}

	bool Render::isActive()
	{
		return this->isWork;
	}

	bool Render::isShaderCurrent(IShader* sh)
	{
		return this->currShader == sh;
	}

	unsigned int Render::polyCount()
	{
		return this->polyCount_val;
	}

	IRenderState* Render::renderState()
	{
		return this->state;
	}

	void Render::resetBatchCount()
	{
		this->batchCount_val = 0;
	}

	void Render::resetCounters()
	{
		this->resetPolyCount();
		this->resetBatchCount();
		this->resetDipCount();
	}

	void Render::resetDipCount()
	{
		this->dipCount_val = 0;
	}

	void Render::resetPolyCount()
	{
		this->polyCount_val = 0;
	}

	void Render::resetRenderState()
	{

			this->state->copy(this->defState);
	}

	void Render::setCamera(ICamera* const c)
	{
		this->cam = c;
		this->bindCamera();
	}

	void Render::setRenderState(IRenderState* r)
	{
		this->state->copy(r);
		if (this->isWork)
            this->upsetRState();
	}

	void Render::setScene(IScene* const s)
	{
		this->scene = s;
	}

	void Render::setViewport(int x, int y, int w, int h)
	{
		glViewport((unsigned int)x, (unsigned int)y, (unsigned int)w, (unsigned int)h);
	}

	void Render::setZRange(double, double)
	{
		this->zNear = near;
		this->zFar = far;
	}

	void Render::ubindMaterial()
	{
		if (this->currMaterial)
			(*((void(__fastcall**)(IMaterial*))this->currMaterial->_vptr_IMaterial + 4))(this->currMaterial);
		this->currMaterial = 0LL;
	}

	void Render::ubindModel()
	{
		if (this->currModel)
		{
			(*((void(__fastcall**)(IModel*))this->currModel->_vptr_IModel + 3))(this->currModel);
			this->currModel = 0LL;
		}
	}

	void Render::ubindTexture(IUniformSampler* sampler)
	{
		void(__fastcall * v2)(Render* const, _QWORD);
		unsigned int v3;
		v3 = (*((__int64(__fastcall**)(IUniformSampler*))sampler->_vptr_IUniform + 7))(sampler);
        this->ubindTexture(v3);
	}

	void Render::ubindTexture(CGL::TextureUnitHandle tx_unit)
	{
		CGL* v2;
		privateGLSupportClass* v3;

		v2 = this->gl();
		v3 = CGL::ext(v2);
		v3->glActiveTextureARB(tx_unit + 33984);
		glBindTexture(3553LL, 0LL);
	}

	void Render::ubindVBO(IVBO* vbo)
	{
		(*((void(__fastcall**)(IVBO*))vbo->_vptr_IVBO + 4))(vbo);
	}

	void Render::upsetRState()
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
		v2 = this->renderState();
		v1.m128d_f64[0] = (*(double(__fastcall**)(__int64))(*(_QWORD*)v2 + 16LL))(v2);
		v21 = _mm_unpacklo_pd(v1, v1).m128d_f64[0];
		v3 = this->renderState();
		v4 = (*(__int64(__fastcall**)(__int64))(*(_QWORD*)v3 + 48LL))(v3);
		glAlphaFunc(upsetRState(void)::testMode[v4], v21);
		v5 = this->renderState();
		v6 = (*(__int64(__fastcall**)(__int64))(*(_QWORD*)v5 + 120LL))(v5);
		glDepthFunc(upsetRState(void)::testMode[v6]);
		v7 = this->renderState();
		v8 = (*(__int64(__fastcall**)(__int64))(*(_QWORD*)v7 + 72LL))(v7);
		glDepthMask(v8);
		v9 = this->renderState();
		if ((*(unsigned __int8(__fastcall**)(__int64))(*(_QWORD*)v9 + 88LL))(v9))
			glEnable(2929LL);
		else
			glDisable(2929LL);
		v10 = this->renderState();
		if ((*(unsigned __int8(__fastcall**)(__int64))(*(_QWORD*)v10 + 136LL))(v10))
		{
			glEnable(3042LL);
			v11 = this->renderState();
			v12 = upsetRState(void)::abMode[(*(int(__fastcall**)(__int64))(*(_QWORD*)v11 + 176LL))(v11)];
			v13 = this->renderState();
			v14 = (*(__int64(__fastcall**)(__int64))(*(_QWORD*)v13 + 168LL))(v13);
			glBlendFunc(upsetRState(void)::abMode[v14], v12);
		}
		else
		{
			glDisable(3042LL);
		}
		v15 = this->renderState();
		if ((*(unsigned __int8(__fastcall**)(__int64))(*(_QWORD*)v15 + 152LL))(v15) && this->isGL_ARB_multisampleEnable)
			glEnable(32926LL);
		else
			glDisable(32926LL);
		v17 = this->renderState();
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
		v18 = this->renderState();
		if ((*(unsigned int(__fastcall**)(__int64))(*(_QWORD*)v18 + 104LL))(v18))
		{
			glEnable(2884LL);
			v19 = this->renderState();
			v20 = (*(__int64(__fastcall**)(__int64))(*(_QWORD*)v19 + 104LL))(v19);
			glCullFace(cullMode[v20]);
		}
		else
		{
			glDisable(2884LL);
		}
	}

	void Render::useShader(IShader* sh)
	{
		if (this->currShader != sh)
		{
			if (sh)
				(*((void(__fastcall**)(IShader*))sh->_vptr_IShader + 10))(sh);
			else
				(*((void(__fastcall**)(IShader*))this->currShader->_vptr_IShader + 11))(this->currShader);
			this->currShader = sh;
			++this->batchCount_val;
		}
	}

	bool Render::wasInit()
	{
		return this->wInit;
	}
}