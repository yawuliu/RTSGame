#include "AbstractMaterial.h"
#include "IScene.h"


namespace MyGL {
	AbstractMaterial::AbstractMaterial(IScene& r) : mscene(r) {

	}

	AbstractMaterial::~AbstractMaterial() {

	}

	bool AbstractMaterial::drawEvent(const IGraphicsObject& o) {
		__int64 v2;

		v2 = (*((__int64(__fastcall**)(AbstractMaterial* const)) this->_vptr_IMaterial + 5))(this);
		return (*(__int64(__fastcall**)(__int64, const IGraphicsObject* const,
			AbstractMaterial* const)) (*(_QWORD*)v2 + 72LL))(
				v2,
				o,
				this);
	}

	ITexture& AbstractMaterial::getTexture(unsigned int a2) {
		return 0LL;
	}

	bool AbstractMaterial::greater(const ITechnique& t, const ITechnique& t2) {
		unsigned __int64 v2;

		v2 = (*((__int64(__fastcall**)(const ITechnique* const)) t->_vptr_ITechnique + 6))(t);
		return v2 > (*((__int64(__fastcall**)(const ITechnique* const)) t2->_vptr_ITechnique + 6))(t2);
	}

	bool AbstractMaterial::less(const ITechnique const& t, const ITechnique const& t2) {
		unsigned __int64 v2;

		v2 = (*((__int64(__fastcall**)(const ITechnique* const)) t->_vptr_ITechnique + 6))(t);
		return v2 < (*((__int64(__fastcall**)(const ITechnique* const)) t2->_vptr_ITechnique + 6))(t2);
	}

	bool AbstractMaterial::operator>(const IMaterial& other) {
		if (!(*((__int64(__fastcall**)(const AbstractMaterial* const)) other_1->_vptr_IMaterial + 6))(
			other_1))
			return 0;
		if ((*(__int64(__fastcall**)(const void* const)) (*(_QWORD*)other + 48LL))(other))
			return other_1 > other;
		return 1;
	}

	IRender* AbstractMaterial::render() {
		return (IRender*)(*((__int64(__fastcall**)(IScene* const)) this->mscene->_vptr_IScene + 3))(
			this->mscene);
	}

	IScene& AbstractMaterial::scene() {
		return this->mscene;
	}
}