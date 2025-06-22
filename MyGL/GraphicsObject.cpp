#include "GraphicsObject.h"


MyGL::GraphicsObject::GraphicsObject(MyGL::IScene& s) {
	this->init(s);
}

MyGL::GraphicsObject::GraphicsObject(MyGL::IScene* s) {
	this->init(s);
}

MyGL::GraphicsObject::~GraphicsObject() {
	if (this->scene)
		(*((void(__fastcall**)(MyGL::IScene*, GraphicsObject* const)) this->scene->_vptr_IScene + 11))(
			this->scene,
			this);
	if (this->actualInfo)
		(*((void(__fastcall**)(MyGL::ModelInfo*)) this->actualInfo->_vptr_IModelInfo + 1))(this->actualInfo);
}

void MyGL::GraphicsObject::init(MyGL::IScene* s) {
	ModelInfo* mCullInform;
	int i;

	this->scene = s;
	this->gmodel = 0LL;
	this->gmaterial = 0LL;
	this->isVisible = 1;
	(*((void(__fastcall**)(MyGL::GraphicsObject* const, _QWORD)) this->_vptr_IGraphicsObject + 10))(
		this, 0LL);
	for (i = 0; i <= 2; ++i) {
		this->pos[i] = 0.0;
		this->angles[i] = 0.0;
		this->size[i] = 1.0;
	}
	this->upsetMatrix();
	if (this->scene)
		(*((void(__fastcall**)(MyGL::IScene*, GraphicsObject* const)) this->scene->_vptr_IScene +
			10))(
				this->scene,
				this);
	this->actualInfo = newModelInfo::ModelInfo();
}

bool MyGL::GraphicsObject::isAlvaysVisible(const) {
	return this->isAVisible;
}

MyGL::IMaterial* MyGL::GraphicsObject::material() {
	return p_object->gmaterial;
}

MyGL::IModel* MyGL::GraphicsObject::model() {
	return this->gmodel;
}

const MyGL::IModelInfo* MyGL::GraphicsObject::modelInfo() {
	return this->actualInfo;
}

const MyGL::ObjectMatrix* MyGL::GraphicsObject::objectMatrix() {
	return &this->matrix;
}

void MyGL::GraphicsObject::setAlvaysVisible(bool isAVisible) {
	this->isAVisible = isAVisible;
}

void MyGL::GraphicsObject::setMaterial(IMaterial* m) {
	IMaterial* old;

	old = p_object->gmaterial;
	p_object->gmaterial = m;
	if (p_object->scene) {
		if (old)
			(*((void(__fastcall**)(MyGL::IScene*, GraphicsObject* const,
				IMaterial*)) p_object->scene->_vptr_IScene
				+ 12))(
					p_object->scene,
					p_object,
					old);
		else
			(*((void(__fastcall**)(MyGL::IScene*,
				GraphicsObject* const)) p_object->scene->_vptr_IScene + 10))(
					p_object->scene,
					p_object);
	}
}

void MyGL::GraphicsObject::setMatrix(MyGL::ObjectMatrix& m) {
	const Float* data;

	data = m.data();
	this->matrix.setData(data);
}

void MyGL::GraphicsObject::setModel(MyGL::IModel* model) {
	this->gmodel = model;
	this->updateModelInfo();
}

void MyGL::GraphicsObject::setPosition(Float x, Float y, Float z) {
	this->pos[0] = x;
	this->pos[1] = y;
	this->pos[2] = z;
	this->upsetMatrix();
}

void MyGL::GraphicsObject::setRotateY(MyGL::Float angle) {
	this->angles[1] = angle;
}

void MyGL::GraphicsObject::setRotateZ(MyGL::Float angle) {
	this->angles[0] = angle;
	this->upsetMatrix();
}

void MyGL::GraphicsObject::setSize(MyGL::Float s) {
	(*((void(__fastcall**)(MyGL::GraphicsObject* const, Float, Float,
		Float)) this->_vptr_IGraphicsObject
		+ 16))(
			this,
			s,
			s,
			s);
	this->upsetMatrix();
}

void MyGL::GraphicsObject::setSize(MyGL::Float x, Float y, Float z) {
	this->size[0] = x;
	this->size[1] = y;
	this->size[2] = z;
	this->upsetMatrix();
}

void MyGL::GraphicsObject::setVisible(bool isVisible) {
	this->isVisible = isVisible;
}

void MyGL::GraphicsObject::updateModelInfo() {
	double v1;
	__m128d v2;
	double v3;
	__m128d v4;
	double v5;
	__m128d v6;
	double v7;
	__m128d v8;
	double v9;
	__m128d v10;
	double v11;
	__m128d v12;
	float y;
	float z;
	float X;
	float Y;
	float Z;
	constIModelInfo* m;

	if (this->gmodel) {
		m = (constIModelInfo*)(*((__int64(__fastcall**)(MyGL::IModel*)) this->gmodel->_vptr_IModel +
			10))(this->gmodel);
		v1 = (*((double(__fastcall**)(constIModelInfo*)) m->_vptr_IModelInfo + 7))(m);
		v2 = (__m128d) * (unsigned __int64*)&this->size[2];
		v2.m128d_f64[0] = v2.m128d_f64[0] * v1;
		*(float*)v2.m128d_f64 = _mm_unpacklo_pd(v2, v2).m128d_f64[0];
		Z = *(float*)v2.m128d_f64;
		v3 = (*((double(__fastcall**)(constIModelInfo*)) m->_vptr_IModelInfo + 6))(m);
		v4 = (__m128d) * (unsigned __int64*)&this->size[1];
		v4.m128d_f64[0] = v4.m128d_f64[0] * v3;
		*(float*)v4.m128d_f64 = _mm_unpacklo_pd(v4, v4).m128d_f64[0];
		Y = *(float*)v4.m128d_f64;
		v5 = (*((double(__fastcall**)(constIModelInfo*)) m->_vptr_IModelInfo + 5))(m);
		v6 = (__m128d) * (unsigned __int64*)&this->size[0];
		v6.m128d_f64[0] = v6.m128d_f64[0] * v5;
		*(float*)v6.m128d_f64 = _mm_unpacklo_pd(v6, v6).m128d_f64[0];
		X = *(float*)v6.m128d_f64;
		v7 = (*((double(__fastcall**)(constIModelInfo*)) m->_vptr_IModelInfo + 4))(m);
		v8 = (__m128d) * (unsigned __int64*)&this->size[2];
		v8.m128d_f64[0] = v8.m128d_f64[0] * v7;
		*(float*)v8.m128d_f64 = _mm_unpacklo_pd(v8, v8).m128d_f64[0];
		z = *(float*)v8.m128d_f64;
		v9 = (*((double(__fastcall**)(constIModelInfo*)) m->_vptr_IModelInfo + 3))(m);
		v10 = (__m128d) * (unsigned __int64*)&this->size[1];
		v10.m128d_f64[0] = v10.m128d_f64[0] * v9;
		y = _mm_unpacklo_pd(v10, v10).m128d_f64[0];
		v11 = (*((double(__fastcall**)(constIModelInfo*)) m->_vptr_IModelInfo + 2))(m);
		v12 = (__m128d) * (unsigned __int64*)&this->size[0];
		v12.m128d_f64[0] = v12.m128d_f64[0] * v11;
		ModelInfo::setBox(this->actualInfo, _mm_unpacklo_pd(v12, v12).m128d_f64[0], y, z, X, Y, Z);
	}
}

void MyGL::GraphicsObject::upsetMatrix() {
	this->matrix.identity();
	this->matrix.translate(this->pos);
	this->matrix.rotateOZ(this->angles[0]);
	this->matrix.rotate(this->angles[1], 0.0, 1.0, 0.0);
	this->matrix.scale(this->size[0], this->size[1], this->size[2]);
	this->updateModelInfo();
}

bool MyGL::GraphicsObject::visible() {
	return this->isVisible
		||
		(*((unsigned __int8(__fastcall**)(const GraphicsObject* const)) this->_vptr_IGraphicsObject +
			11))(this);
}

MyGL::Float MyGL::GraphicsObject::x() {
	return this->pos[0];
}

MyGL::Float MyGL::GraphicsObject::xSize() {
	return this->size[0];
}

MyGL::Float MyGL::GraphicsObject::y() {
	return this->pos[1];
}

MyGL::Float MyGL::GraphicsObject::yRotation() {
	return this->angles[1];
}

MyGL::Float MyGL::GraphicsObject::ySize() {
	return this->size[1];
}

MyGL::Float MyGL::GraphicsObject::z() {
	return this->pos[2];
}

MyGL::Float MyGL::GraphicsObject::zRotation() {
	return this->angles[0];
}

MyGL::Float MyGL::GraphicsObject::zSize() {
	return this->size[2];
}
