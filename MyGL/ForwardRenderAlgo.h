#pragma once
#include <vector>
#include <MyGL/IScene.h>
#include <MyGL/IRenderAlgo.h>
#include <MyGL/Adapter.h>
#include <MyGL/IRenderPass.h >



namespace MyGL {
	class IRenderAlgoSettings;
	class IModel;
	class MainPass;
	class GlowPass;
	class BloomPass;
	class LincPass;
	class ShadowPass;
	class VolumetricLightScatteringPass;
	class ForwardRenderAlgo : public IRenderAlgo {
	public:
		ForwardRenderAlgo(IScene& s, const Adapter& adapter, bool autoMake);
		virtual ~ForwardRenderAlgo();
		MainPass* allockMainPass(const Adapter& adapter);
		void buildQuad(int w, int h);
		void exec();
		void freeAlgo();
		bool isBloom();
		bool isShadowPass();
		void makeAlgo(const Adapter& adapter);
		void recreateAlgo(const Adapter& adapter);
		IScene* scene();
		void setBloom(bool use);
		void setPoint(float* p, float x, float y);
		void setShadowPass(bool use);
		IRenderAlgoSettings* settings();
		IRenderPass::Pass::Type type();
	protected:
		MainPass* mainPass;
		GlowPass* glowPass;
		BloomPass* bloomPass;
		LincPass* lincPass;
		ShadowPass* shadowPass;
		VolumetricLightScatteringPass* vlsPass;
		IModel* quad;
		IScene& mscene;
		IRenderAlgoSettings* m_settings;
		std::vector<IRenderPass*> passes;
		bool m_isBloom;
		bool m_shadow;
		// padding byte
	   //0000006B     // padding byte
	   //0000006C     // padding byte
	   //0000006D     // padding byte
	   //0000006E     // padding byte
	   //0000006F     // padding byte
	};
}
