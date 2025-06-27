#include "ShadowPass.h"
#include "IRenderPass.h"
namespace MyGL {
	ShadowPass::ShadowPass(IScene& s, const Adapter& adapter) : AbstractPass(s)
	{
		IScene* v3;
		IRender* r;
		Model* quad;
		ITexture2d* in;
		IScene* v7;
		IRender* r_1;
		unsigned int theWidth;
		unsigned int theHeight;
		FBO* frameBuffer;
		IScene* s_1;
		Filter* blur;
		IShader* s_2;
		ITexture2d* frame;
		std::string name;
		_BYTE v19[33];

		Camera::Camera(&this->lview);
		ObjectMatrix::ObjectMatrix(&this->lMat);
		v3 = this->scene();
		this->quad = new Model(v3->render());;
		this->frame = this->createFrame(0LL);
		in = adapter->getShadowMapTexture();
		this->tmpFrame = this->createFrame( in);
		v7 = this->scene();
		theWidth = this->frame->width();
		theHeight = this->frame->height();
		this->frameBuffer = new FBO( v7->render(), theWidth, theHeight, 8);
        this->lview->setPrespective(0);
		this->nUpdate = 1;
		this->blur = new Filter(this->scene());
        this->blur->setShader(adapter->getBlurShadowShader());
        this->blur->setQuadModel(this->quad);
		frame = this->frame;
		std::string::string(&name, "texture", v19);
        this->blur->setInput(&name, frame);
		this->lightId = 0;
	}

	ShadowPass::~ShadowPass()
	{

		if (this->frameBuffer)
			(*((void(__fastcall**)(FBO*))this->frameBuffer->_vptr_IFBO + 1))(this->frameBuffer);
		if (this->blur)
			delete this->blur;
		if (this->frame)
            delete this->frame;
		if (this->quad)
            delete this->quad;

	}

	void ShadowPass::buildQuad(int w, int h)
	{
		float* p;
		float* p_1;
		float* p_2;
		float* p_3;
		float* p_4;
		float* p_5;
		float* p_6;
		float* p_7;
		__m128d v11;
		float nx_1;
		__m128d v13;
		float* p_8;
		float* p_9;
		float* p_10;
		float* p_11;
		IOModel m;
		IIOModel::Point retstr_;
		IIOModel::Point retstr__1;
		IIOModel::Point retstr__2;
		IIOModel::Point retstr__3;
		IIOModel::TexCoord retstr__4;
		IIOModel::TexCoord retstr__5;
		IIOModel::TexCoord retstr__6;
		IIOModel::TexCoord retstr__7;
		IOModel::Normal retstr__8;
		IOModel::Normal retstr__9;
		IOModel::Normal retstr__10;
		IOModel::Normal retstr__11;
		float ny;
		float nx;

		IOModel::IOModel(&m);
		IOModel::allock(&m, 4uLL);
		IOModel::point(&retstr_, &m, 0);
		p = IIOModel::Point::data(&retstr_);
		ShadowPass::setPoint(this, p, -1.0, -1.0);
		IOModel::point(&retstr__1, &m, 1);
		p_1 = IIOModel::Point::data(&retstr__1);
		ShadowPass::setPoint(this, p_1, 1.0, -1.0);
		IOModel::point(&retstr__2, &m, 2);
		p_2 = IIOModel::Point::data(&retstr__2);
		ShadowPass::setPoint(this, p_2, 1.0, 1.0);
		IOModel::point(&retstr__3, &m, 3);
		p_3 = IIOModel::Point::data(&retstr__3);
		ShadowPass::setPoint(this, p_3, -1.0, 1.0);
		IOModel::texCoord(&retstr__4, &m, 0);
		p_4 = IIOModel::TexCoord::data(&retstr__4);
		ShadowPass::setPoint(this, p_4, 0.0, 0.0);
		IOModel::texCoord(&retstr__5, &m, 1);
		p_5 = IIOModel::TexCoord::data(&retstr__5);
		ShadowPass::setPoint(this, p_5, 1.0, 0.0);
		IOModel::texCoord(&retstr__6, &m, 2);
		p_6 = IIOModel::TexCoord::data(&retstr__6);
		ShadowPass::setPoint(this, p_6, 1.0, 1.0);
		IOModel::texCoord(&retstr__7, &m, 3);
		p_7 = IIOModel::TexCoord::data(&retstr__7);
		ShadowPass::setPoint(this, p_7, 0.0, 1.0);
		v11 = (__m128d)0x3FF0000000000000uLL;
		v11.m128d_f64[0] = 1.0 / (double)w;
		nx_1 = _mm_unpacklo_pd(v11, v11).m128d_f64[0];
		nx = nx_1;
		v13 = (__m128d)0x3FF0000000000000uLL;
		v13.m128d_f64[0] = 1.0 / (double)h;
		ny = _mm_unpacklo_pd(v13, v13).m128d_f64[0];
		IOModel::normal(&retstr__8, &m, 0);
		p_8 = IIOModel::Point::data(&retstr__8);
		ShadowPass::setPoint(this, p_8, nx, ny);
		IOModel::normal(&retstr__9, &m, 1);
		p_9 = IIOModel::Point::data(&retstr__9);
		ShadowPass::setPoint(this, p_9, nx, ny);
		IOModel::normal(&retstr__10, &m, 2);
		p_10 = IIOModel::Point::data(&retstr__10);
		ShadowPass::setPoint(this, p_10, nx, ny);
		IOModel::normal(&retstr__11, &m, 3);
		p_11 = IIOModel::Point::data(&retstr__11);
		ShadowPass::setPoint(this, p_11, nx, ny);
		this->quad->load(&m);
		this->quad->setPrimitivesType(2LL);
		IOModel::~IOModel(&m);
	}

	ITexture2d* ShadowPass::createFrame(ITexture2d* in)
	{
		IScene* v2;
		IRender* r;
		Texture2d* re;
		void(__fastcall * v5)(ITexture2d*, Color*);
		Color v7;
		int smSize;
		ITexture2d* frame;

		frame = in;
		smSize = 1024;
		if (!in)
		{
			v2 = AbstractPass::scene(this);
			r = v2->render();
			re = (Texture2d*)operator new(0x50uLL);
			Texture2d::Texture2d(re, r);
			frame = re;
		}

		frame->load(
				0LL,
				1LL,
				1024LL,
				1024LL,
				12LL,
				in);
		frame->setFiltration( 1LL, 1LL);
		frame->setAnisotropy(0.0);
		frame->setClamping( 1LL);
		Color::Color(&v7, 1.0);
        frame->setBorderColor(&v7);
        this->buildQuad(1024, 1024);
		return frame;
	}

	int ShadowPass::currentLightId()
	{
		return this->lightId;
	}

	void ShadowPass::draw()
	{
		IScene* v1;
		__int64 v2;
		IScene* v3;
		__int64 v4;
		void(__fastcall * v5)(__int64, _QWORD, _QWORD, _QWORD, _QWORD);
		unsigned int v6;
		unsigned int v7;
		IScene* v8;
		__int64 v9;
		void(__fastcall * v10)(__int64, double, double);
		IScene* v11;
		__int64 v12;
		IScene* v13;
		__int64 v14;
		IScene* v15;
		__int64 v16;
		IScene* v17;
		void* s;
		IScene* v19;
		__int64 v20;
		IGraphicsObject* obj_2;
		IGraphicsObject* obj_1;
		int i_1;
		IScene* v24;
		__int64 v25;
		IScene* v26;
		__int64 v27;
		ISceneGraph::Visibles obj;
		Color v30;
		int i;

		v1 = AbstractPass::scene(this);
		v2 = v1->render();
		(*(void(__fastcall**)(__int64, Camera*))(*(_QWORD*)v2 + 240LL))(v2, &this->lview);
		v3 = AbstractPass::scene(this);
		v4 = v3->render();
		v5 = *(void(__fastcall**)(__int64, _QWORD, _QWORD, _QWORD, _QWORD))(*(_QWORD*)v4 + 88LL);
		v6 = (*((__int64(__fastcall**)(FBO*))this->frameBuffer->_vptr_IFBO + 3))(this->frameBuffer);
		v7 = (*((__int64(__fastcall**)(FBO*))this->frameBuffer->_vptr_IFBO + 2))(this->frameBuffer);
		v5(v4, 0LL, 0LL, v7, v6);
		v8 = AbstractPass::scene(this);
		v9 = v8->render();
		v10 = *(void(__fastcall**)(__int64, double, double))(*(_QWORD*)v9 + 16LL);
		Color::Color(&v30, 1.0, 1.0, 1.0, 0.0);
		v10(v9, *(double*)v30.cdata, *(double*)&v30.cdata[2]);
		v11 = AbstractPass::scene(this);
		v12 = v11->render();
		(*(void(__fastcall**)(__int64, __int64))(*(_QWORD*)v12 + 32LL))(v12, 3LL);
		v13 = AbstractPass::scene(this);
		v14 = v13->render();
		(*(void(__fastcall**)(__int64))(*(_QWORD*)v14 + 248LL))(v14);
		v15 = AbstractPass::scene(this);
		v16 = v15->graph();
		(*(void(__fastcall**)(__int64, ShadowPass* const))(*(_QWORD*)v16 + 40LL))(v16, this);
		v17 = AbstractPass::scene(this);
		s = v17->graph();
		ISceneGraph::Visibles::Visibles(&obj, s);
		v19 = AbstractPass::scene(this);
		v20 = v19->render();
		(*(void(__fastcall**)(__int64))(*(_QWORD*)v20 + 296LL))(v20);
		for (i = 0; ; ++i)
		{
			i_1 = ISceneGraph::Visibles::size(&obj);
			if (i_1 <= i)
				break;
			obj_2 = ISceneGraph::Visibles::operator[](&obj, i);
			if (ShadowPass::isDrawable(this, obj_2))
			{
				obj_1 = ISceneGraph::Visibles::operator[](&obj, i);
				AbstractPass::drawObject<ShadowPass>(this, obj_1);
			}
		}
		v24 = AbstractPass::scene(this);
		v25 = v24->render();
		(*(void(__fastcall**)(__int64))(*(_QWORD*)v25 + 312LL))(v25);
		v26 = AbstractPass::scene(this);
		v27 = v26->graph();
		(*(void(__fastcall**)(__int64))(*(_QWORD*)v27 + 48LL))(v27);
	}

	void ShadowPass::exec()
	{
		__int64 v1;
		IScene* v2;
		__int64 v3;
		IScene* v4;
		__int64 v5;
		IScene* v6;
		__int64 v7;
		IScene* v8;
		__int64 v9;
		IScene* v10;
		__int64 v11;
		IScene* v12;
		__int64 v13;
		IScene* v14;
		__int64 v15;
		IScene* v16;
		__int64 v17;
		int view[4];
		Color cl_0;
		ICamera* c;

		if (this->nUpdate)
		{
			v2 = AbstractPass::scene(this);
			v3 = v2->lights();
			if ((*(unsigned int(__fastcall**)(__int64))(*(_QWORD*)v3 + 40LL))(v3))
			{
				ShadowPass::initLight(this, 0);
				(*((void(__fastcall**)(FBO*))this->frameBuffer->_vptr_IFBO + 8))(this->frameBuffer);
				(*((void(__fastcall**)(FBO*, ITexture2d*, _QWORD))this->frameBuffer->_vptr_IFBO + 10))(
					this->frameBuffer,
					this->frame,
					0LL);
				v4 = AbstractPass::scene(this);
				v5 = v4->render();
				c = (ICamera*)(*(__int64(__fastcall**)(__int64))(*(_QWORD*)v5 + 256LL))(v5);
				v6 = AbstractPass::scene(this);
				v7 = v6->render();
				*(_QWORD*)cl_0.cdata = (*(double(__fastcall**)(__int64))(*(_QWORD*)v7 + 24LL))(v7);
				*(_QWORD*)&cl_0.cdata[2] = v1;
				v8 = AbstractPass::scene(this);
				v9 = v8->render();
				(*(void(__fastcall**)(__int64, int*, int*, int*, int*))(*(_QWORD*)v9 + 96LL))(
					v9,
					view,
					&view[1],
					&view[2],
					&view[3]);
				v10 = AbstractPass::scene(this);
				v11 = v10->render();
				(*(void(__fastcall**)(__int64, ObjectMatrix*))(*(_QWORD*)v11 + 336LL))(v11, &this->lMat);
				ShadowPass::draw(this);
				(*((void(__fastcall**)(FBO*, ITexture2d*, _QWORD))this->frameBuffer->_vptr_IFBO + 10))(
					this->frameBuffer,
					this->tmpFrame,
					0LL);
				this->blur->clearColor();
				(*((void(__fastcall**)(FBO*))this->frameBuffer->_vptr_IFBO + 9))(this->frameBuffer);
				v12 = AbstractPass::scene(this);
				v13 = v12->render();
				(*(void(__fastcall**)(__int64, ICamera*))(*(_QWORD*)v13 + 240LL))(v13, c);
				v14 = AbstractPass::scene(this);
				v15 = v14->render();
				(*(void(__fastcall**)(__int64, _QWORD, _QWORD, _QWORD, _QWORD))(*(_QWORD*)v15 + 88LL))(
					v15,
					(unsigned int)view[0],
					(unsigned int)view[1],
					(unsigned int)view[2],
					(unsigned int)view[3]);
				v16 = AbstractPass::scene(this);
				v17 = v16->render();
				(*(void(__fastcall**)(__int64, double, double))(*(_QWORD*)v17 + 16LL))(
					v17,
					*(double*)cl_0.cdata,
					*(double*)&cl_0.cdata[2]);
				this->nUpdate = 1;
				this->lightId = -1;
			}
		}
	}

	void ShadowPass::initLight(int id)
	{
		IScene* v2;
		__int64 v3;
		Float x1;
		__m128d v5;
		double v6;
		__m128d v7;
		__m128d v8;
		double v9;
		__m128d v10;
		IScene* v11;
		__int64 v12;
		__int64 v13;
		double v14;
		double x;
		double v16;
		double v17;
		double v18;
		Float y1;
		Float z1;
		float l2;
		float l;
		ILight* light;
		float ax_0;

		v2 = AbstractPass::scene(this);
		v3 = v2->lights();
		light = (ILight*)(*(__int64(__fastcall**)(__int64, _QWORD))(*(_QWORD*)v3 + 48LL))(v3, (unsigned int)id);
		z1 = light->z();
		y1 = light->y();
		x1 = light->x();
		Camera::setPos(&this->lview, x1, y1, z1, 1.0);
		v5 = (__m128d)0xBFE0000000000000LL;
		Camera::setDistance(&this->lview, -0.5, 1.0);
		v18 = light->dirX();
		v17 = v18 * light->dirX();
		v16 = light->dirY();
		v5.m128d_f64[0] = light->dirY();
		v5.m128d_f64[0] = sqrt(v5.m128d_f64[0] * v16 + v17);
		*(float*)v5.m128d_f64 = _mm_unpacklo_pd(v5, v5).m128d_f64[0];
		l = *(float*)v5.m128d_f64;
		if (*(float*)v5.m128d_f64 <= 0.0)
		{
			ax_0 = 0.0;
		}
		else
		{
			v6 = light->dirX();
			v7 = _mm_cvtps_pd((__m128)LODWORD(l));
			x = v6 / v7.m128d_f64[0];
			v7.m128d_f64[0] = light->dirY();
			v8 = _mm_xor_pd((__m128d)0x8000000000000000LL, v7);
			v8.m128d_f64[0] = atan2(v8.m128d_f64[0] / l, x);
			ax_0 = _mm_unpacklo_pd(v8, v8).m128d_f64[0];
		}
		v14 = light->dirZ();
		v9 = light->dirZ();
		v10.m128d_f64[1] = (float)(l * l);
		v10.m128d_f64[0] = sqrt(v10.m128d_f64[1] + v14 * v9);
		l2 = _mm_unpacklo_pd(v10, v10).m128d_f64[0];
		v10.m128d_f64[0] = light->dirZ();
		v10.m128d_f64[1] = (float)(l / l2);
		v10.m128d_f64[0] = atan2(v10.m128d_f64[1], v10.m128d_f64[0] / l2);
		*(float*)v10.m128d_f64 = _mm_unpacklo_pd(v10, v10).m128d_f64[0];
		Camera::setAngles(
			&this->lview,
			*(float*)v10.m128d_f64 * 180.0 / 3.141592653589793,
			ax_0 * 180.0 / 3.141592653589793 + 90.0,
			1.0);
		v11 = AbstractPass::scene(this);
		v12 = v11->render();
		v13 = (*(__int64(__fastcall**)(__int64))(*(_QWORD*)v12 + 256LL))(v12);
		v10.m128d_f64[0] = (*(double(__fastcall**)(__int64))(*(_QWORD*)v13 + 80LL))(v13);
		v10.m128d_f64[0] = sqrt(v10.m128d_f64[0]);
		Camera::setZoom(&this->lview, 0.25 / v10.m128d_f64[0]);
	}

	bool ShadowPass::isDrawable(IGraphicsObject& obj)
	{
		return obj->visible() == 1;
	}

	void ShadowPass::setPoint(float* p, float x, float y)
	{
		*p = x;
		p[1] = y;
	}

	ITexture2d* ShadowPass::shadowMap()
	{
		return this->frame;
	}

	IRenderPass::Pass::Type ShadowPass::type()
	{
		return 7;
	}
}