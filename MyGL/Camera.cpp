#include "Camera.h"

MyGL::Camera::Camera()
	: px(0.0), py(0.0), pz(0.0),
	dist(1.0), zm(1.0), vxy(0.0), vxz(0.0) {
	this->setPrespective(1);
}

MyGL::Camera::~Camera()
{


}
MyGL::Float MyGL::Camera::distance()
{
	return this->dist;
}
bool MyGL::Camera::isPrespective()
{
	return this->usePrespective;
}
MyGL::CGL::GLdouble* MyGL::Camera::modelProjectiveMatrix()
{
	return this->model_proj;
}
void MyGL::Camera::move(MyGL::Float x, MyGL::Float y)
{
	double sin_a;
	double cos_a;

	cos_a = cos(3.141592653589793 * this->vxz / 180.0);
	sin_a = sin(3.141592653589793 * this->vxz / 180.0);
	(*((void(__fastcall**)(MyGL::Camera* const, MyGL::Float, MyGL::Float, MyGL::Float, double))this->_vptr_ICamera + 2))(
		this,
		y * cos_a + this->px + x * sin_a,
		x * cos_a + this->py - y * sin_a,
		this->pz,
		1.0);
}
void MyGL::Camera::normalization(
	MyGL::CGL::GLdouble* const X,
	MyGL::CGL::GLdouble* const Y,
	MyGL::CGL::GLdouble* const Z,
	MyGL::CGL::GLdouble* const D)
{
	double v5;

	v5 = sqrt(*Z * *Z + *X * *X + *Y * *Y);
	*X = *X * (1.0 / v5);
	*Y = *Y * (1.0 / v5);
	*Z = *Z * (1.0 / v5);
	*D = *D * (1.0 / v5);
}
MyGL::Camera* MyGL::Camera::operator=(const MyGL::Camera& c)
{
	void(__fastcall * v2)(MyGL::Camera* const, double, double, double, double);
	double v3;
	void(__fastcall * v4)(MyGL::Camera* const, double, double, double);
	double v5;
	void(__fastcall * v6)(MyGL::Camera* const);
	void(__fastcall * v7)(MyGL::Camera* const, double, double);
	double v8;
	void(__fastcall * v9)(MyGL::Camera* const, _QWORD);
	unsigned int v10;
	double v12;
	double v13;
	double v14;

	v2 = (void(__fastcall*)(MyGL::Camera* const, double, double, double, double)) * ((_QWORD*)this->_vptr_ICamera + 2);
	v14 = (*(double(__fastcall**)(const void* const))(*(_QWORD*)c + 72LL))(c);
	v13 = (*(double(__fastcall**)(const void* const))(*(_QWORD*)c + 64LL))(c);
	v3 = (*(double(__fastcall**)(const void* const))(*(_QWORD*)c + 56LL))(c);
	v2(this, v3, v13, v14, 1.0);
	v4 = (void(__fastcall*)(MyGL::Camera* const, double, double, double)) * ((_QWORD*)this->_vptr_ICamera + 3);
	v12 = (*(double(__fastcall**)(const void* const))(*(_QWORD*)c + 104LL))(c);
	v5 = (*(double(__fastcall**)(const void* const))(*(_QWORD*)c + 96LL))(c);
	v4(this, v5, v12, 1.0);
	v6 = (void(__fastcall*)(MyGL::Camera* const)) * ((_QWORD*)this->_vptr_ICamera + 4);
	(*(void(__fastcall**)(const void* const))(*(_QWORD*)c + 88LL))(c);
	v6(this);
	v7 = (void(__fastcall*)(MyGL::Camera* const, double, double)) * ((_QWORD*)this->_vptr_ICamera + 5);
	v8 = (*(double(__fastcall**)(const void* const))(*(_QWORD*)c + 80LL))(c);
	v7(this, v8, 1.0);
	v9 = (void(__fastcall*)(MyGL::Camera* const, _QWORD)) * ((_QWORD*)this->_vptr_ICamera + 15);
	v10 = (*(unsigned __int8(__fastcall**)(const void* const))(*(_QWORD*)c + 112LL))(c);
	v9(this, v10);
	return this;
}
MyGL::CGL::GLdouble MyGL::Camera::po(MyGL::CGL::GLdouble x,
	MyGL::CGL::GLdouble y,
	MyGL::CGL::GLdouble z,
	MyGL::CGL::GLdouble X,
	MyGL::CGL::GLdouble Y,
	MyGL::CGL::GLdouble Z,
	MyGL::CGL::GLdouble D)
{
	return Z * z + X * x + Y * y + D;
}
MyGL::Float MyGL::Camera::rotXY()
{
	return this->vxy;
}
MyGL::Float MyGL::Camera::rotXZ()
{
	return this->vxz;
}
void MyGL::Camera::setAngles(MyGL::Float rotXY, MyGL::Float rotXZ, MyGL::Float ani)
{
	this->vxy = (rotXY - this->vxy) * ani + this->vxy;
	this->vxz = (rotXZ - this->vxz) * ani + this->vxz;
}
void MyGL::Camera::setDistance(MyGL::Float d, MyGL::Float ani)
{
	this->dist = (d - this->dist) * ani + this->dist;
}
void MyGL::Camera::setPos(

	MyGL::Float x1,
	MyGL::Float y1,
	MyGL::Float z1,
	MyGL::Float ani)
{
	this->px = (x1 - this->px) * ani + this->px;
	this->py = (y1 - this->py) * ani + this->py;
	this->pz = (z1 - this->pz) * ani + this->pz;
}
void MyGL::Camera::setPrespective(bool perspective)
{
	this->usePrespective = perspective;
}
void MyGL::Camera::setZoom(MyGL::Float zoom)
{
	this->zm = zoom;
}
void MyGL::Camera::updateCull()
{
	MyGL::CGL::GLdouble* m;
	int i;

	m = this->modelProjectiveMatrix();
	this->cullM[0][0] = m[3] - *m;
	this->cullM[0][1] = m[7] - m[4];
	this->cullM[0][2] = m[11] - m[8];
	this->cullM[0][3] = m[15] - m[12];
	this->cullM[1][0] = *m + m[3];
	this->cullM[1][1] = m[4] + m[7];
	this->cullM[1][2] = m[8] + m[11];
	this->cullM[1][3] = m[12] + m[15];
	this->cullM[2][0] = m[1] + m[3];
	this->cullM[2][1] = m[5] + m[7];
	this->cullM[2][2] = m[9] + m[11];
	this->cullM[2][3] = m[13] + m[15];
	this->cullM[3][0] = m[3] - m[1];
	this->cullM[3][1] = m[7] - m[5];
	this->cullM[3][2] = m[11] - m[9];
	this->cullM[3][3] = m[15] - m[13];
	this->cullM[4][0] = m[3] - m[2];
	this->cullM[4][1] = m[7] - m[6];
	this->cullM[4][2] = m[11] - m[10];
	this->cullM[4][3] = m[15] - m[14];
	this->cullM[5][0] = m[2] + m[3];
	this->cullM[5][1] = m[6] + m[7];
	this->cullM[5][2] = m[10] + m[11];
	this->cullM[5][3] = m[14] + m[15];
	for (i = 0; i <= 5; ++i)
		this->normalization(this->cullM[i], &this->cullM[i][1], &this->cullM[i][2], &this->cullM[i][3]);
}
void MyGL::Camera::updateGL()
{
	double modl[16];
	double proj[16];

	glGetDoublev(2983LL, proj);
	glGetDoublev(2982LL, modl);
	this->model_proj[0] = proj[12] * modl[3] + modl[0] * proj[0] + proj[4] * modl[1] + proj[8] * modl[2];
	this->model_proj[1] = proj[13] * modl[3] + modl[0] * proj[1] + proj[5] * modl[1] + proj[9] * modl[2];
	this->model_proj[2] = proj[14] * modl[3] + modl[0] * proj[2] + proj[6] * modl[1] + proj[10] * modl[2];
	this->model_proj[3] = proj[15] * modl[3] + modl[0] * proj[3] + proj[7] * modl[1] + proj[11] * modl[2];
	this->model_proj[4] = proj[12] * modl[7] + modl[4] * proj[0] + proj[4] * modl[5] + proj[8] * modl[6];
	this->model_proj[5] = proj[13] * modl[7] + modl[4] * proj[1] + proj[5] * modl[5] + proj[9] * modl[6];
	this->model_proj[6] = proj[14] * modl[7] + modl[4] * proj[2] + proj[6] * modl[5] + proj[10] * modl[6];
	this->model_proj[7] = proj[15] * modl[7] + modl[4] * proj[3] + proj[7] * modl[5] + proj[11] * modl[6];
	this->model_proj[8] = proj[12] * modl[11] + modl[8] * proj[0] + proj[4] * modl[9] + proj[8] * modl[10];
	this->model_proj[9] = proj[13] * modl[11] + modl[8] * proj[1] + proj[5] * modl[9] + proj[9] * modl[10];
	this->model_proj[10] = proj[14] * modl[11] + modl[8] * proj[2] + proj[6] * modl[9] + proj[10] * modl[10];
	this->model_proj[11] = proj[15] * modl[11] + modl[8] * proj[3] + proj[7] * modl[9] + proj[11] * modl[10];
	this->model_proj[12] = proj[12] * modl[15] + modl[12] * proj[0] + proj[4] * modl[13] + proj[8] * modl[14];
	this->model_proj[13] = proj[13] * modl[15] + modl[12] * proj[1] + proj[5] * modl[13] + proj[9] * modl[14];
	this->model_proj[14] = proj[14] * modl[15] + modl[12] * proj[2] + proj[6] * modl[13] + proj[10] * modl[14];
	this->model_proj[15] = proj[15] * modl[15] + modl[12] * proj[3] + proj[7] * modl[13] + proj[11] * modl[14];
	this->updateCull();
}
MyGL::Float MyGL::Camera::x()
{
	return this->px;
}
MyGL::Float MyGL::Camera::y()
{
	return this->py;
}
MyGL::Float MyGL::Camera::z()
{
	return this->pz;
}
MyGL::Float MyGL::Camera::zoom()
{
	return this->zm;
}