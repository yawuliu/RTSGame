#include "RenderState.h"

 MyGL::RenderState::RenderState()
{
	this->atest = 0.0;
	this->atestType = AlphaTestMode::Type::Always;
	this->zWriting = 1;
	this->zTest = 1;
	this->blend = 0;
	this->sfactor = AlphaBlendMode::Type::one;
	this->dfactor = AlphaBlendMode::Type::zero;
	this->alphaCoverage = 0;
	this->setColorMask(1, 1, 1, 1);
	this->zTestType = ZTestMode::Type::Less;
	this->setCullFaceMode(CullMode::Type::noCull);
}

AlphaTestMode::Type MyGL::RenderState::alphaTestMode()
{
	return this->atestType;
}

 MyGL::Float MyGL::RenderState::alphaTestRef()
{
	return this->atest;
}

 MyGL::IRenderState* MyGL::RenderState::copy(const void* const r)
{
	this->atest = (*(double(__fastcall**)(const void* const))(*(_QWORD*)r + 16LL))(r);
	this->atestType = (*(__int64(__fastcall**)(const void* const))(*(_QWORD*)r + 48LL))(r);
	this->zWriting = (*(__int64(__fastcall**)(const void* const))(*(_QWORD*)r + 72LL))(r);
	this->zTest = (*(__int64(__fastcall**)(const void* const))(*(_QWORD*)r + 88LL))(r);
	this->blend = (*(__int64(__fastcall**)(const void* const))(*(_QWORD*)r + 136LL))(r);
	this->sfactor = (*(__int64(__fastcall**)(const void* const))(*(_QWORD*)r + 168LL))(r);
	this->dfactor = (*(__int64(__fastcall**)(const void* const))(*(_QWORD*)r + 176LL))(r);
	this->alphaCoverage = (*(__int64(__fastcall**)(const void* const))(*(_QWORD*)r + 152LL))(r);
	(*(void(__fastcall**)(const void* const, bool*, bool*, bool*, bool*))(*(_QWORD*)r + 64LL))(
		r,
		this->clMask,
		&this->clMask[1],
		&this->clMask[2],
		&this->clMask[3]);
	this->zTestType = (*(__int64(__fastcall**)(const void* const))(*(_QWORD*)r + 120LL))(r);
	this->cullMode = (*(__int64(__fastcall**)(const void* const))(*(_QWORD*)r + 104LL))(r);
	return this;
}

 CullMode::Type MyGL::RenderState::cullFaceMode()
{
	return this->cullMode;
}

 AlphaBlendMode::Type MyGL::RenderState::getBlendDFactor()
{
	return this->dfactor;
}

 void MyGL::RenderState::getBlendMode(const AlphaBlendMode::Type* const out_sfactor, AlphaBlendMode::Type* const out_dfactor)
{
	*out_sfactor = this->sfactor;
	*out_dfactor = this->dfactor;
}

 AlphaBlendMode::Type MyGL::RenderState::getBlendSFactor()
{
	return this->sfactor;
}

 void MyGL::RenderState::getColorMask(const bool* const r, bool* const g, bool* const b, bool* const a)
{
	*r = this->clMask[0];
	*g = this->clMask[1];
	*b = this->clMask[2];
	*a = this->clMask[3];
}

 ZTestMode::Type MyGL::RenderState::getZTestMode()
{
	return this->zTestType;
}

 bool MyGL::RenderState::isAlphaCoverage()
{
	return this->alphaCoverage;
}

 bool MyGL::RenderState::isBlend()
{
	return this->blend;
}

 bool MyGL::RenderState::isZTest()
{
	return this->zTest;
}

 bool MyGL::RenderState::isZWriting()
{
	return this->zWriting;
}

 void MyGL::RenderState::setAlphaCoverage(bool use)
{
	this->alphaCoverage = use;
}

 void MyGL::RenderState::setAlphaTestMode(AlphaTestMode::Type mode)
{
	this->atestType = mode;
}

 void MyGL::RenderState::setAlphaTestRef(MyGL::Float atest)
{
	this->atest = atest;
}

 void MyGL::RenderState::setBlend(bool use)
{
	this->blend = use;
}

 void MyGL::RenderState::setBlendMode(AlphaBlendMode::Type s, AlphaBlendMode::Type d)
{
	this->sfactor = s;
	this->dfactor = d;
}

 void MyGL::RenderState::setColorMask(bool r, bool g, bool b, bool a)
{
	this->clMask[0] = r;
	this->clMask[1] = g;
	this->clMask[2] = b;
	this->clMask[3] = a;
}

 void MyGL::RenderState::setCullFaceMode(CullMode::Type use)
{
	this->cullMode = use;
}

 void MyGL::RenderState::setZTest(bool use)
{
    this->zTest = use;
}

 void MyGL::RenderState::setZTestMode(ZTestMode::Type use)
{
	this->zTestType = use;
}

 void MyGL::RenderState::setZWriting(bool w)
{
	this->zWriting = w;
}
