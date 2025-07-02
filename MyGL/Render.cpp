#include "Render.h"
#include "IUniformSampler.h"

namespace MyGL {
	Render::Render(CGL& glDevice)
	{
		this->glDev = &glDevice;
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
		v2 = v1->errorCtrl();
        v2->warning(
			!this->isWork,
			"Render is already activated");
		this->isWork = 1;
		this->bindCamera();
        this->upsetRState();
	}

	void Render::bindCamera()
	{
        if (this->cam)
		{
			glMatrixMode(5889LL);
			glm::dmat4(&proj);
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
            this->glLoadMatrix(x_1);
			src = glm::gtc::type_ptr::value_ptr<double>(&proj);
			memcpy(this->projectionMat, src, sizeof(this->projectionMat));
			glMatrixMode(5888LL);
			glm::dmat4(&mview);
			v6 = this->camera();
			z = -(*(double(__fastcall**)(__int64))(*(_QWORD*)v6 + 80LL))(v6);
			y = 0;
			x = 0;
			glm::dvec3(&v, &x, &y, &z);
			glm::gtc::matrix_transform::translate<double>(&retstr_, &mview, &v);
			glm::dmat4::operator=(&mview, &retstr_);
			v7 = this->camera();
			s = (*(double(__fastcall**)(__int64))(*(_QWORD*)v7 + 88LL))(v7);
			glm::dvec3(&v29, &s);
			glm::gtc::matrix_transform::scale<double>(&retstr__1, &mview, &v29);
			glm::dmat4::operator=(&mview, &retstr__1);
			z_ = 0;
			y_ = 0;
			x_ = 1;
			glm::dvec3(&v32, &x_, &y_, &z_);
			v8 = this->camera();
			angle = (*(double(__fastcall**)(__int64))(*(_QWORD*)v8 + 96LL))(v8);
			glm::gtc::matrix_transform::rotate<double>(&retstr__2, &mview, &angle, &v32);
			glm::dmat4::operator=(&mview, &retstr__2);
			z__1 = 1;
			y__1 = 0;
			x__1 = 0;
			glm::dvec3(&v38, &x__1, &y__1, &z__1);
			v9 = this->camera();
			angle_ = (*(double(__fastcall**)(__int64))(*(_QWORD*)v9 + 104LL))(v9);
			glm::gtc::matrix_transform::rotate<double>(&retstr__3, &mview, &angle_, &v38);
			glm::dmat4::operator=(&mview, &retstr__3);
			v10 = this->camera();
			s2 = -(*(double(__fastcall**)(__int64))(*(_QWORD*)v10 + 72LL))(v10);
			v11 = this->camera();
			s1 = -(*(double(__fastcall**)(__int64))(*(_QWORD*)v11 + 64LL))(v11);
			v12 = this->camera();
			s0[0] = -(*(double(__fastcall**)(__int64))(*(_QWORD*)v12 + 56LL))(v12);
			glm::dvec3(&v44, s0, &s1, &s2);
			glm::gtc::matrix_transform::translate<double>(&retstr__4, &mview, &v44);
			glm::dmat4::operator=(&mview, &retstr__4);
			x_2 = glm::gtc::type_ptr::value_ptr<double>(&mview);
            this->glLoadMatrix(x_2);
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
			material->setUniforms();
		}
		else
		{
			this->ubindMaterial();
			this->currMaterial = material;
			material->bind();
		}
	}

	void Render::bindModel(IModel* m)
	{
		if (this->currModel != m)
		{
			this->ubindModel();
			this->currModel = m;
			m->bind();
			++this->batchCount_val;
		}
	}

	void Render::bindTexture(IUniformSampler* sampler, ITexture* tex)
	{
        this->bindTexture(sampler->get(), tex);
	}

	void Render::bindTexture(CGL::TextureUnitHandle tx_unit, ITexture* tex)
	{
        this->gl()->ext()->glActiveTextureARB(tx_unit + 33984);
		tex->bind();
	}

	void Render::bindVBO(IVBO* vbo, IVBO::BindMode::Type mode)
	{
		vbo->bind(mode);
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

	void Render::clearColor(Color c)
	{
		float v2;
		float v3;
		float v4;
		float v5;
		Color ca;
		*(_QWORD*)ca.cdata = *(_QWORD*)c.cdata;
		*(_QWORD*)&ca.cdata[2] = *(_QWORD*)&c.cdata[2];
        this->clrColor =  ca;
		v5 = ca.a();
		v4 = ca.b();
		v3 = ca.g();
		v2 = ca.r();
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
                this->bindMaterial(obj->material());
                this->drawModel(obj->model(), obj->objectMatrix());
			}
		}
	}

	void Render::drawModel(IModel* m)
	{
		this->bindModel(m);
		m->draw(1LL);
	}

	void Render::drawModel(IModel* m, const ObjectMatrix& objMatrix)
	{
        this->glMultMatrix(objMatrix.data());
		this->drawModel(m);
        this->glLoadMatrix(this->modelView);
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
		this->gl()->errorCtrl()->warning(this->isWork, "Render is not activated");
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
        GLenum err = glGetError();
        if (err)
        {
            switch (err)
            {
                case 0x500u:
                    return  "GL_INVALID_ENUM";
                    break;
                case 0x501u:
                    return  "GL_INVALID_VALUE";
                    break;
                case 0x502u:
                    return  "GL_INVALID_OPERATION";
                    break;
                case 0x503u:
                    return  "GL_STACK_OVERFLOW";
                    break;
                case 0x504u:
                    return  "GL_STACK_UNDERFLOW";
                    break;
                case 0x505u:
                    return  "GL_OUT_OF_MEMORY";
                    break;
                default:
                    return  "";
                    break;
            }
        }
        else
        {
            return "";
        }
        return "";
    }

	void Render::getModeViewlMatrix(ObjectMatrix& out)
	{
        out.setData(this->modelView);
	}

	void Render::getModeViewlMatrix(Float* out)
	{
		memcpy(out, this->modelView, 0x80uLL);
	}

	void Render::getProjectionMatrix(ObjectMatrix&  out)
	{
        out.setData(this->projectionMat);
	}

	void Render::getProjectionMatrix(Float* out)
	{
		memcpy(out, this->projectionMat, 0x80uLL);
	}

	void Render::getTransformMatrix(ObjectMatrix& out)
	{
		ObjectMatrix pm;
		ObjectMatrix mv;
		this->getModeViewlMatrix(mv);
		this->getProjectionMatrix(pm);
        mv.mul(pm);
        out.setData(mv.data());
	}

	void Render::getViewport(int & x, int& y, int& w, int& h)
	{
		int v[4];

		glGetIntegerv(2978LL, v);
		x = v[0];
		y = v[1];
		w = v[2];
		h = v[3];
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
		this->wInit = 0;
		this->isWork = 0;
		this->currShader = 0LL;
		this->currMaterial = 0LL;
		this->currModel = 0LL;
		this->setZRange(0.0, 1.0);
		this->cam = 0LL;
		this->defState = new RenderState();
		this->state = new RenderState();
		this->scene = 0LL;
		this->isGL_ARB_multisampleEnable = 0;
		this->resetCounters();
	}

	bool Render::initGL()
	{
        this->gl()->createExtObject();
		if (!this->gl()->initShaderAPI())
			return 0;
		if (!this->gl()->initTextureAPI())
			return 0;
		if (!this->gl()->initVBO_API())
			return 0;
		if (!this->gl()->initFBO_API())
			return 0;
        this->gl()->ext()->glGenerateMipmapEXT(3553LL);
		glEnableClientState(32884LL);
		glEnableClientState(32888LL);
		glEnableClientState(32885LL);
		this->isGL_ARB_multisampleEnable = this->glDev->isExtensionSupported("GL_ARB_multisample");
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

	void Render::setCamera(ICamera& c)
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

	void Render::setScene(IScene& s)
	{
		this->scene = &s;
	}

	void Render::setViewport(int x, int y, int w, int h)
	{
		glViewport((unsigned int)x, (unsigned int)y, (unsigned int)w, (unsigned int)h);
	}

	void Render::setZRange(double near, double far)
	{
		this->zNear = near;
		this->zFar = far;
	}

	void Render::ubindMaterial()
	{
		if (this->currMaterial)
			this->currMaterial->uBind();
		this->currMaterial = 0LL;
	}

	void Render::ubindModel()
	{
		if (this->currModel)
		{
			this->currModel->uBind();
			this->currModel = 0LL;
		}
	}

	void Render::ubindTexture(IUniformSampler* sampler)
	{
        this->ubindTexture(sampler->get());
	}

	void Render::ubindTexture(CGL::TextureUnitHandle tx_unit)
	{
        this->gl()->ext()->glActiveTextureARB(tx_unit + 33984);
		glBindTexture(3553LL, 0LL);
	}

	void Render::ubindVBO(IVBO* vbo)
	{
		vbo->uBind()
	}

	void Render::upsetRState()
	{
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
				sh->use();
			else
				this->currShader->unUse();
			this->currShader = sh;
			++this->batchCount_val;
		}
	}

	bool Render::wasInit()
	{
		return this->wInit;
	}
}