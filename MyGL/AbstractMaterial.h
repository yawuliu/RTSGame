#pragma once

#include "IMaterial"
#include "IScene"
#include "ITechnique"
#include "IGraphicsObject"
#include "ITexture"


namespace MyGL {
	class AbstractMaterial : public IMaterial {
	public:
		AbstractMaterial(IScene& r);

		virtual ~AbstractMaterial();

		bool drawEvent(const IGraphicsObject& o);

		ITexture& getTexture(unsigned int a2);

		bool greater(const ITechnique& t, const ITechnique& t2);

		bool less(const ITechnique& t, const ITechnique& t2);

		bool operator<(const IMaterial& other) {
			const ITechnique* t2_1;
			const ITechnique* t;
			const ITechnique* t2_2;
			const ITechnique* t_1;
			const ITexture* t2;
			const ITexture* t1;
			unsigned int i;

			if (!(*((__int64(__fastcall**)(const AbstractMaterial* const)) this->_vptr_IMaterial + 6))(this)
				&& (*(__int64(__fastcall**)(const void* const)) (*(_QWORD*)other + 48LL))(other)) {
				return 1;
			}
			if (!(*(__int64(__fastcall**)(const void* const)) (*(_QWORD*)other + 48LL))(other))
				return 0;
			t2_1 = (const ITechnique*)(*(__int64(__fastcall**)(const void* const)) (*(_QWORD*)other +
				48LL))(other);
			t = (const ITechnique*)(*(
				(__int64(__fastcall**)(const AbstractMaterial* const)) this->_vptr_IMaterial
				+ 6))(this);
			if (AbstractMaterial::less(t, t2_1))
				return 1;
			t2_2 = (const ITechnique*)(*(__int64(__fastcall**)(const void* const)) (*(_QWORD*)other +
				48LL))(other);
			t_1 = (const ITechnique*)(*(
				(__int64(__fastcall**)(const AbstractMaterial* const)) this->_vptr_IMaterial
				+ 6))(this);
			if (AbstractMaterial::greater(t_1, t2_2))
				return 0;
			for (i = 0; i <= 3; ++i) {
				t1 = (const ITexture*)(*(
					(__int64(__fastcall**)(const AbstractMaterial* const, _QWORD)) this->_vptr_IMaterial
					+ 9))(
						this,
						i);
				t2 = (const ITexture*)(*(__int64(__fastcall**)(const void* const, _QWORD)) (
					*(_QWORD*)other + 72LL))(
						other,
						i);
				if (t1 < t2)
					return 1;
				if (t1 > t2)
					return 0;
			}
			return 0;
		}


		IRender* render();

		IScene& scene();

	protected:
		IScene& mscene;
	};
}



