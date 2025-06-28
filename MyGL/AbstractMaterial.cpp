#include "AbstractMaterial.h"
#include "IScene.h"


namespace MyGL {
	AbstractMaterial::AbstractMaterial(IScene& r) : mscene(r) {

	}

	AbstractMaterial::~AbstractMaterial() {

	}

	bool AbstractMaterial::drawEvent(IGraphicsObject const& o) {
		__int64 v2;

		v2 = this->technique();
		return (*(__int64(__fastcall**)(__int64, const IGraphicsObject* const,
			AbstractMaterial* const)) (*(_QWORD*)v2 + 72LL))(
				v2,
				o,
				this);
	}

	const ITexture* AbstractMaterial::getTexture(uint32_t a2) {
		return 0LL;
	}

	bool AbstractMaterial::greater(ITechnique const& t, ITechnique const& t2) {
		return t.cmpShader() > t2.cmpShader();
	}

	bool AbstractMaterial::less(ITechnique const& t, ITechnique const& t2) {
		return t.cmpShader() < t2.cmpShader();
	}

	bool AbstractMaterial::operator>(IMaterial const& other) {
		if (!other_1.technique())
			return 0;
		if ((*(__int64(__fastcall**)(const void* const)) (*(_QWORD*)other + 48LL))(other))
			return other_1 > other;
		return 1;
	}
	bool AbstractMaterial::operator>(IMaterial const& other) {
		if (!other.technique())
			return 0;
		if ((*(__int64(__fastcall**)(const void* const))(*(_QWORD*)other_1 + 48LL))(other_1))
			return other > other_1;
		return 1;

	}
	IRender* AbstractMaterial::render() {
		return this->mscene.render();
	}

	IScene& AbstractMaterial::scene() {
		return this->mscene;
	}

	bool AbstractMaterial::operator<(const IMaterial& other) {
		const ITechnique* t2_1;
		const ITechnique* t;
		const ITechnique* t2_2;
		const ITechnique* t_1;
		const ITexture* t2;
		const ITexture* t1;
		unsigned int i;

		if (!this->technique()
			&& (*(__int64(__fastcall**)(const void* const)) (*(_QWORD*)other + 48LL))(other)) {
			return 1;
		}
		if (!(*(__int64(__fastcall**)(const void* const)) (*(_QWORD*)other + 48LL))(other))
			return 0;
		t2_1 = (const ITechnique*)(*(__int64(__fastcall**)(const void* const)) (*(_QWORD*)other + 48LL))(other);
		if (this->technique().less(t2_1))
			return 1;
		t2_2 = (const ITechnique*)(*(__int64(__fastcall**)(const void* const)) (*(_QWORD*)other + 48LL))(other);
		if (this->technique().greater(t2_2))
			return 0;
		for (i = 0; i <= 3; ++i) {
			t1 = this->getTexture(i);
			t2 = (const ITexture*)(*(__int64(__fastcall**)(const void* const, _QWORD)) (*(_QWORD*)other + 72LL))(other, i);
			if (t1 < t2)
				return 1;
			if (t1 > t2)
				return 0;
		}
		return 0;
	}
}