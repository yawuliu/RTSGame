#include "Light.h"

MyGL::Light::Data::Data(MyGL::IScene& s) :object(s)
{
	MyGL::Light::Technicue* t_1;
	MyGL::Light::Material* m;
	MyGL::ITechnique* t;
	t_1 = (MyGL::Light::Technicue*)operator new(0x10uLL);
	MyGL::Light::Technicue::Technicue(t_1, s);
	t = t_1;
	m = (MyGL::Light::Material*)operator new(0x18uLL);
	m = new MyGL::Light::Material::Material(s, t);
	object->setMaterial(m);
}

MyGL::Light::Data::~Data()
{
	MyGL::IMaterial* v1;

	v1 = MyGL::GraphicsObject::material(&this->object);
	if (v1)
		(*((void(__fastcall**)(MyGL::IMaterial*))v1->_vptr_IMaterial + 1))(v1);
	MyGL::GraphicsObject::~GraphicsObject(&this->object);
}

MyGL::Light::Material::Material(MyGL::Light::Material* const m, MyGL::IScene& s, MyGL::ITechnique* t) :AbstractMaterial(s)
{
	m->tech = t;
}

MyGL::Light::Material::~Material()
{
	if (this->tech)
		(*((void(__fastcall**)(MyGL::ITechnique*))this->tech->_vptr_ITechnique + 1))(this->tech);
	MyGL::AbstractMaterial::~AbstractMaterial(this);
}

void MyGL::Light::Material::bind()
{
	__int64 v1;
	__int64 v2;
	MyGL::IRender* v3;
	void(__fastcall * v4)(MyGL::IRender*, __int64);
	__int64 v5;

	v1 = (*((__int64(__fastcall**)(MyGL::Light::Material* const))this->_vptr_IMaterial + 5))(this);
	(*(void(__fastcall**)(__int64))(*(_QWORD*)v1 + 16LL))(v1);
	v2 = (*((__int64(__fastcall**)(MyGL::Light::Material* const))this->_vptr_IMaterial + 5))(this);
	(*(void(__fastcall**)(__int64))(*(_QWORD*)v2 + 24LL))(v2);
	v3 = MyGL::AbstractMaterial::render(this);
	v4 = (void(__fastcall*)(MyGL::IRender*, __int64)) * ((_QWORD*)v3->_vptr_IRender + 34);
	v5 = (*((__int64(__fastcall**)(MyGL::Light::Material* const))this->_vptr_IMaterial + 11))(this);
	v4(v3, v5);
}

MyGL::IRenderState* MyGL::Light::Material::renderState()
{
	return &MyGL::Light::Technicue::rs;
}

void MyGL::Light::Material::setUniforms()
{
	(*((void(__fastcall**)(MyGL::Light::Material* const))this->_vptr_IMaterial + 2))(this);
}

MyGL::ITechnique* MyGL::Light::Material::technique()
{
	return this->tech;
}

void MyGL::Light::Material::uBind()
{
	;
}

const MyGL::IRenderState* MyGL::Light::Material::renderState()
{
	return &MyGL::Light::Technicue::rs;
}

MyGL::Light::Technicue::Technicue(MyGL::IScene& s)
{
	MyGL::AbstractTechnique::AbstractTechnique(t, s);
	t->_vptr_ITechnique = (int (**)(...))(&`vtable for'MyGL::Light::Technicue + 2);
}

MyGL::Light::Technicue::~Technicue()
{
	this->_vptr_ITechnique = (int (**)(...))(&`vtable for'MyGL::Light::Technicue + 2);
		MyGL::AbstractTechnique::~AbstractTechnique(this);
}

void MyGL::Light::Technicue::bind()
{
	;
}

const MyGL::IShader* MyGL::Light::Technicue::cmpShader(const)
{
	return 0LL;
}

void MyGL::Light::Technicue::completeDraw(const MyGL::IRenderPass* a2)
{
	;
}

const MyGL::IShader* MyGL::Light::Technicue::currentShader(const)
{
	return 0LL;
}

bool MyGL::Light::Technicue::lPass(const MyGL::SmallLightsPass* a2)
{
	return 0;
}

bool MyGL::Light::Technicue::passEvent(const MyGL::IRenderPass* pass)
{
	return (*((unsigned int(__fastcall**)(const MyGL::IRenderPass*))pass->_vptr_IRenderPass + 3))(pass) == 10
		&& MyGL::Light::Technicue::lPass(this, (const MyGL::SmallLightsPass*)pass);
}

MyGL::IRenderState* MyGL::Light::Technicue::renderState()
{
	return &MyGL::Light::Technicue::rs;
}

void MyGL::Light::Technicue::setUniforms()
{
	;
}

void MyGL::Light::Technicue::uBind()
{
	;
}

MyGL::Light::Light(MyGL::ILightsCollection& c)
{
	MyGL::ILight::ILight(this);
	this->_vptr_ILight = (int (**)(...))(&`vtable for'MyGL::Light + 2);
		this->collect = c;
	(*((void(__fastcall**)(MyGL::ILightsCollection* const, MyGL::Light* const))this->collect->_vptr_ILightsCollection + 2))(
		this->collect,
		this);
	MyGL::Light::setPosition(this, 0.0, 0.0, 0.0);
	this->sh = 0;
	this->data = 0LL;
	MyGL::Light::setDirection(this, 1.0, 1.0, 1.0);
	MyGL::Light::setDeferred(this, 0);
}

MyGL::Light::~Light()
{
	MyGL::Light::Data* data;

	this->_vptr_ILight = (int (**)(...))(&`vtable for'MyGL::Light + 2);
		(*((void(__fastcall**)(MyGL::ILightsCollection* const, MyGL::Light* const))this->collect->_vptr_ILightsCollection + 4))(
			this->collect,
			this);
	data = this->data;
	if (data)
	{
		MyGL::Light::Data::~Data(this->data);
		operator delete(data);
	}
	MyGL::ILight::~ILight(this);
}

MyGL::Float* MyGL::Light::dirTransform()
{
	return this->tDir;
}

MyGL::Float MyGL::Light::dirX(const)
{
	return this->dir[0];
}

MyGL::Float MyGL::Light::dirY(const)
{
	return this->dir[1];
}

MyGL::Float MyGL::Light::dirZ(const)
{
	return this->dir[2];
}

bool MyGL::Light::hasOccluder(const)
{
	return 0;
}

bool MyGL::Light::isDeferred(const)
{
	return this->ds;
}

bool MyGL::Light::isShadowCaster(const)
{
	return this->sh;
}

MyGL::IModel* MyGL::Light::occluder()
{
	return 0LL;
}

void MyGL::Light::setDeferred(bool d)
{
	MyGL::Light::Data* data;
	MyGL::IScene* s;
	MyGL::Light::Data* data_1;

	this->ds = d;
	data = this->data;
	if (data)
	{
		MyGL::Light::Data::~Data(this->data);
		operator delete(data);
	}
	if (this->ds)
	{
		s = (MyGL::IScene*)(*((__int64(__fastcall**)(MyGL::ILightsCollection* const))this->collect->_vptr_ILightsCollection
			+ 7))(this->collect);
		data_1 = (MyGL::Light::Data*)operator new(0x80uLL);
		MyGL::Light::Data::Data(data_1, s);
		this->data = data_1;
	}
}

void MyGL::Light::setDirection(MyGL::Float x, MyGL::Float y, MyGL::Float z)
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

void MyGL::Light::setPosition(MyGL::Float x, MyGL::Float y, MyGL::Float z)
{
	this->pos[0] = x;
	this->pos[1] = y;
	this->pos[2] = z;
}

void MyGL::Light::setShadowCast(bool doIt)
{
	this->sh = doIt;
}

void MyGL::Light::upset()
{
	__int64 v1;
	__int64 v2;
	const MyGL::Float* v3;
	const MyGL::Float* v4;
	double v5;
	MyGL::ObjectMatrix m;
	MyGL::Float l;
	int i;
	int r;
	int i_0;

	MyGL::ObjectMatrix::ObjectMatrix(&m);
	v1 = (*((__int64(__fastcall**)(MyGL::ILightsCollection* const))this->collect->_vptr_ILightsCollection + 7))(this->collect);
	v2 = (*(__int64(__fastcall**)(__int64))(*(_QWORD*)v1 + 24LL))(v1);
	(*(void(__fastcall**)(__int64, MyGL::ObjectMatrix*))(*(_QWORD*)v2 + 320LL))(v2, &m);
	for (i_0 = 0; i_0 <= 2; ++i_0)
	{
		v3 = MyGL::ObjectMatrix::data(&m);
		this->tDir[i_0] = v3[4 * i_0 + 3];
		for (r = 0; r <= 2; ++r)
		{
			v5 = this->tDir[i_0];
			v4 = MyGL::ObjectMatrix::data(&m);
			this->tDir[i_0] = this->dir[r] * v4[4 * r + i_0] + v5;
		}
	}
	l = sqrt(this->tDir[2] * this->tDir[2] + this->tDir[0] * this->tDir[0] + this->tDir[1] * this->tDir[1]);
	for (i = 0; i <= 2; ++i)
		this->tDir[i] = this->tDir[i] / -l;
	MyGL::ObjectMatrix::~ObjectMatrix(&m);
}

MyGL::Float MyGL::Light::x(const)
{
	return this->pos[0];
}

MyGL::Float MyGL::Light::y(const)
{
	return this->pos[1];
}

MyGL::Float MyGL::Light::z(const)
{
	return this->pos[2];
}
