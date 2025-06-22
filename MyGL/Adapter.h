#pragma once
#include <string>
#include "MyGL/IAdapter.h"
#include <MyGL/IScene.h>
#include <MyGL/IShader.h>

namespace MyGL {
	class Adapter {
	public:
		Adapter(IScene& s);

		IShader& getBloomDownSampleShader();

		IShader& getBlurShadowShader();

		IShader& getGausHorizontalShader();

		IShader& getGausVerticalShader();

		IShader& getGlowDownSampleShader();

		IShader& getLincShader();

		ITexture2d* getRandTexture();

		IShader& getSSAOShader();

		ITexture2d* getShadowMapTexture();

		IShader& getVolumetricLightScatteringShader();

		IShader& returnShader(const std::string* const d);

		IScene& scene();

	protected:
		IScene& _scene;
	};
}
