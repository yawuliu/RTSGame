#include "AbstractTechnique.h"

namespace MyGL {
	AbstractTechnique::AbstractTechnique(IScene& s) : mscene(s) {
	}

	AbstractTechnique::~AbstractTechnique() {

	}

	void AbstractTechnique::completeDraw(const AddBlendPass* a2) {
		;
	}

	void AbstractTechnique::completeDraw(const ColorPass* a2) {
		;
	}

	void AbstractTechnique::completeDraw(const DepthPass* a2) {
		;
	}

	void AbstractTechnique::completeDraw(const GlowPass* a2) {
		;
	}

	void AbstractTechnique::completeDraw(const IRenderPass* a2) {
		;
	}

	void AbstractTechnique::completeDraw(const ShadowPass* a2) {
		;
	}

	void AbstractTechnique::completeDraw(const TransparentPass* a2) {
		;
	}

	bool AbstractTechnique::drawEvent(const IGraphicsObject& a2, const IMaterial& a3) {
		return 1;
	}

	bool AbstractTechnique::passEvent(const AddBlendPass* a2) {
		return 0;
	}

	bool AbstractTechnique::passEvent(const ColorPass* a2) {
		return 0;
	}

	bool AbstractTechnique::passEvent(const DepthPass* a2) {
		return 0;
	}

	bool AbstractTechnique::passEvent(const GlowPass* a2) {
		return 0;
	}

	bool AbstractTechnique::passEvent(const IRenderPass* a2) {
		return 0;
	}

	bool AbstractTechnique::passEvent(const ShadowPass* a2) {
		return 0;
	}

	bool AbstractTechnique::passEvent(const TransparentPass* a2) {
		return 0;
	}

	IRender* AbstractTechnique::render() {
		return (IRender*)(*((__int64(__fastcall**)(IScene* const)) this->mscene->_vptr_IScene + 3))(
			this->mscene);
	}

	IScene& AbstractTechnique::scene() {
		return this->mscene;
	}
}