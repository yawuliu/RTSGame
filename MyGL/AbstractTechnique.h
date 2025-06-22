#pragma once

#include <MyGL/IScene.h>
#include <MyGL/ITechnique.h>

namespace MyGL {

	class AbstractTechnique : public ITechnique {
	public:
		AbstractTechnique(IScene& s);

		virtual ~AbstractTechnique();

		void completeDraw(const AddBlendPass* a2);

		void completeDraw(const ColorPass* a2);

		void completeDraw(const DepthPass* a2);

		void completeDraw(const GlowPass* a2);

		void completeDraw(const IRenderPass* a2);

		void completeDraw(const ShadowPass* a2);

		void completeDraw(
			const TransparentPass* a2);

		bool drawEvent(
			const IGraphicsObject* const a2,
			const IMaterial* const a3);

		bool passEvent(const AddBlendPass* a2);

		bool passEvent(const ColorPass* a2);

		bool passEvent(const DepthPass* a2);

		bool passEvent(const GlowPass* a2);

		bool passEvent(const IRenderPass* a2);

		bool passEvent(const ShadowPass* a2);

		bool passEvent(const TransparentPass* a2);

		IRender* render();

		IScene* scene();

	protected:
		IScene& mscene;
	};

}
