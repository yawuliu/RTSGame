#pragma once

namespace MyGL {
    class IScene;

    class IAdapter {
    public:
        virtual void getLincShader() = 0; // 0

        virtual void getGausVerticalShader() = 0; // 1

        virtual void getGausHorizontalShader() = 0;// 2

        virtual void getBloomDownSampleShader() = 0;//3

        virtual void getGlowDownSampleShader() = 0;// 4

        virtual void getSSAOShader() = 0; // 5

        virtual void getRandTexture() = 0; // 6

        virtual void getVolumetricLightScatteringShader() = 0; // 7

        virtual void getBlurShadowShader() = 0; // 8

        virtual void getShadowMapTexture() = 0; // 9
    };
}
