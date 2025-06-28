#pragma once
#include "IRender.h"
#include "IMaterial.h"
#include "IScene.h"
#include "ITechnique.h"
#include "IGraphicsObject.h"
#include "ITexture.h"
#include "Render.h"


namespace MyGL {
	class AbstractMaterial : public IMaterial {
	public:
		AbstractMaterial(IScene& r);

		virtual ~AbstractMaterial();

		bool drawEvent(IGraphicsObject const& o) override;

		const ITexture* getTexture(uint32_t a2);

		bool greater(ITechnique const& t, ITechnique const& t2);

		bool less(ITechnique const& t, ITechnique const& t2);

		bool operator<(IMaterial const& other) override;
		bool operator>(IMaterial const& other) override;

		IRender* render();

		IScene& scene();

	protected:
		IScene& mscene;
	};
}



