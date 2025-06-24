#include "Light.h"
namespace MyGL {
	Light::Data::Data(IScene& s) :object(s)
	{
		Light::Technicue* t_1;
		Light::Material* m;
		ITechnique* t;
		t_1 = (Light::Technicue*)operator new(0x10uLL);
		Light::Technicue::Technicue(t_1, s);
		t = t_1;
		m = (Light::Material*)operator new(0x18uLL);
		m = new Light::Material::Material(s, t);
		object->setMaterial(m);
	}

	Light::Data::~Data()
	{
		IMaterial* v1;

		v1 = GraphicsObject::material(&this->object);
		if (v1)
			(*((void(__fastcall**)(IMaterial*))v1->_vptr_IMaterial + 1))(v1);
		GraphicsObject::~GraphicsObject(&this->object);
	}

	Light::Material::Material(Light::Material* const m, IScene& s, ITechnique* t) :AbstractMaterial(s)
	{
		m->tech = t;
	}

	Light::Material::~Material()
	{
		if (this->tech)
			(*((void(__fastcall**)(ITechnique*))this->tech->_vptr_ITechnique + 1))(this->tech);
		AbstractMaterial::~AbstractMaterial(this);
	}

	void Light::Material::bind()
	{
		__int64 v1;
		__int64 v2;
		IRender* v3;
		void(__fastcall * v4)(IRender*, __int64);
		__int64 v5;

		v1 = (*((__int64(__fastcall**)(Light::Material* const))this->_vptr_IMaterial + 5))(this);
		(*(void(__fastcall**)(__int64))(*(_QWORD*)v1 + 16LL))(v1);
		v2 = (*((__int64(__fastcall**)(Light::Material* const))this->_vptr_IMaterial + 5))(this);
		(*(void(__fastcall**)(__int64))(*(_QWORD*)v2 + 24LL))(v2);
		v3 = this->render();
		v5 = (*((__int64(__fastcall**)(Light::Material* const))this->_vptr_IMaterial + 11))(this);
        v3->setRenderState(v5);
	}

	IRenderState* Light::Material::renderState()
	{
		return &Light::Technicue::rs;
	}

	void Light::Material::setUniforms()
	{
		(*((void(__fastcall**)(Light::Material* const))this->_vptr_IMaterial + 2))(this);
	}

	ITechnique* Light::Material::technique()
	{
		return this->tech;
	}

	void Light::Material::uBind()
	{
		;
	}

	const IRenderState* Light::Material::renderState()
	{
		return &Light::Technicue::rs;
	}

	Light::Technicue::Technicue(IScene& s)
	{
		AbstractTechnique::AbstractTechnique(t, s);
		t->_vptr_ITechnique = (int (**)(...))(&`vtable for'Light::Technicue + 2);
	}

	Light::Technicue::~Technicue()
	{
		this->_vptr_ITechnique = (int (**)(...))(&`vtable for'Light::Technicue + 2);
			AbstractTechnique::~AbstractTechnique(this);
	}

	void Light::Technicue::bind()
	{
		;
	}

	const IShader* Light::Technicue::cmpShader(const)
	{
		return 0LL;
	}

	void Light::Technicue::completeDraw(const IRenderPass* a2)
	{
		;
	}

	const IShader* Light::Technicue::currentShader(const)
	{
		return 0LL;
	}

	bool Light::Technicue::lPass(const SmallLightsPass* a2)
	{
		return 0;
	}

	bool Light::Technicue::passEvent(const IRenderPass* pass)
	{
		return pass->type() == 10
			&& Light::Technicue::lPass(this, (const SmallLightsPass*)pass);
	}

	IRenderState* Light::Technicue::renderState()
	{
		return &Light::Technicue::rs;
	}

	void Light::Technicue::setUniforms()
	{
		;
	}

	void Light::Technicue::uBind()
	{
		;
	}

	Light::Light(ILightsCollection& c)
	{
		ILight::ILight(this);

			this->collect = c;
		(*((void(__fastcall**)(ILightsCollection* const, Light* const))this->collect->_vptr_ILightsCollection + 2))(
			this->collect,
			this);
		Light::setPosition(this, 0.0, 0.0, 0.0);
		this->sh = 0;
		this->data = 0LL;
		Light::setDirection(this, 1.0, 1.0, 1.0);
		Light::setDeferred(this, 0);
	}

	Light::~Light()
	{
		Light::Data* data;
			(*((void(__fastcall**)(ILightsCollection* const, Light* const))this->collect->_vptr_ILightsCollection + 4))(
				this->collect,
				this);
		if (this->data)
		{
			delete this->data;
		}
	}

	Float* Light::dirTransform()
	{
		return this->tDir;
	}

	Float Light::dirX(const)
	{
		return this->dir[0];
	}

	Float Light::dirY(const)
	{
		return this->dir[1];
	}

	Float Light::dirZ(const)
	{
		return this->dir[2];
	}

	bool Light::hasOccluder(const)
	{
		return 0;
	}

	bool Light::isDeferred(const)
	{
		return this->ds;
	}

	bool Light::isShadowCaster(const)
	{
		return this->sh;
	}

	IModel* Light::occluder()
	{
		return 0LL;
	}

	void Light::setDeferred(bool d)
	{
		Light::Data* data;
		IScene* s;
		Light::Data* data_1;

		this->ds = d;
		data = this->data;
		if (data)
		{
			Light::Data::~Data(this->data);
			operator delete(data);
		}
		if (this->ds)
		{
			s = (IScene*)(*((__int64(__fastcall**)(ILightsCollection* const))this->collect->_vptr_ILightsCollection
				+ 7))(this->collect);
			data_1 = (Light::Data*)operator new(0x80uLL);
			Light::Data::Data(data_1, s);
			this->data = data_1;
		}
	}

	void Light::setDirection(Float x, Float y, Float z)
	{
		double l;
		int i;

		this->dir[0] = x;
		this->dir[1] = y;
		this->dir[2] = z;
		l = sqrt(z * z + x * x + y * y);
		for (i = 0; i <= 2; ++i)
			this->dir[i] = this->dir[i] / l;
	}

	void Light::setPosition(Float x, Float y, Float z)
	{
		this->pos[0] = x;
		this->pos[1] = y;
		this->pos[2] = z;
	}

	void Light::setShadowCast(bool doIt)
	{
		this->sh = doIt;
	}

	void Light::upset()
	{
		__int64 v1;
		__int64 v2;
		const Float* v3;
		const Float* v4;
		double v5;
		ObjectMatrix m;
		Float l;
		int i;
		int r;
		int i_0;

		ObjectMatrix::ObjectMatrix(&m);
		v1 = (*((__int64(__fastcall**)(ILightsCollection* const))this->collect->_vptr_ILightsCollection + 7))(this->collect);
		v2 = (*(__int64(__fastcall**)(__int64))(*(_QWORD*)v1 + 24LL))(v1);
		(*(void(__fastcall**)(__int64, ObjectMatrix*))(*(_QWORD*)v2 + 320LL))(v2, &m);
		for (i_0 = 0; i_0 <= 2; ++i_0)
		{
			v3 = ObjectMatrix::data(&m);
			this->tDir[i_0] = v3[4 * i_0 + 3];
			for (r = 0; r <= 2; ++r)
			{
				v5 = this->tDir[i_0];
				v4 = ObjectMatrix::data(&m);
				this->tDir[i_0] = this->dir[r] * v4[4 * r + i_0] + v5;
			}
		}
		l = sqrt(this->tDir[2] * this->tDir[2] + this->tDir[0] * this->tDir[0] + this->tDir[1] * this->tDir[1]);
		for (i = 0; i <= 2; ++i)
			this->tDir[i] = this->tDir[i] / -l;
		ObjectMatrix::~ObjectMatrix(&m);
	}

	Float Light::x(const)
	{
		return this->pos[0];
	}

	Float Light::y(const)
	{
		return this->pos[1];
	}

	Float Light::z(const)
	{
		return this->pos[2];
	}
}