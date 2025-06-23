#include "RenderState.h"
namespace MyGL {
	RenderState::RenderState()
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

	AlphaTestMode::Type RenderState::alphaTestMode()
	{
		return this->atestType;
	}

	Float RenderState::alphaTestRef()
	{
		return this->atest;
	}

	IRenderState* RenderState::copy(const void* const r)
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

	CullMode::Type RenderState::cullFaceMode()
	{
		return this->cullMode;
	}

	AlphaBlendMode::Type RenderState::getBlendDFactor()
	{
		return this->dfactor;
	}

	void RenderState::getBlendMode(const AlphaBlendMode::Type* const out_sfactor, AlphaBlendMode::Type* const out_dfactor)
	{
		*out_sfactor = this->sfactor;
		*out_dfactor = this->dfactor;
	}

	AlphaBlendMode::Type RenderState::getBlendSFactor()
	{
		return this->sfactor;
	}

	void RenderState::getColorMask(const bool* const r, bool* const g, bool* const b, bool* const a)
	{
		*r = this->clMask[0];
		*g = this->clMask[1];
		*b = this->clMask[2];
		*a = this->clMask[3];
	}

	ZTestMode::Type RenderState::getZTestMode()
	{
		return this->zTestType;
	}

	bool RenderState::isAlphaCoverage()
	{
		return this->alphaCoverage;
	}

	bool RenderState::isBlend()
	{
		return this->blend;
	}

	bool RenderState::isZTest()
	{
		return this->zTest;
	}

	bool RenderState::isZWriting()
	{
		return this->zWriting;
	}

	void RenderState::setAlphaCoverage(bool use)
	{
		this->alphaCoverage = use;
	}

	void RenderState::setAlphaTestMode(AlphaTestMode::Type mode)
	{
		this->atestType = mode;
	}

	void RenderState::setAlphaTestRef(Float atest)
	{
		this->atest = atest;
	}

	void RenderState::setBlend(bool use)
	{
		this->blend = use;
	}

	void RenderState::setBlendMode(AlphaBlendMode::Type s, AlphaBlendMode::Type d)
	{
		this->sfactor = s;
		this->dfactor = d;
	}

	void RenderState::setColorMask(bool r, bool g, bool b, bool a)
	{
		this->clMask[0] = r;
		this->clMask[1] = g;
		this->clMask[2] = b;
		this->clMask[3] = a;
	}

	void RenderState::setCullFaceMode(CullMode::Type use)
	{
		this->cullMode = use;
	}

	void RenderState::setZTest(bool use)
	{
		this->zTest = use;
	}

	void RenderState::setZTestMode(ZTestMode::Type use)
	{
		this->zTestType = use;
	}

	void RenderState::setZWriting(bool w)
	{
		this->zWriting = w;
	}
}