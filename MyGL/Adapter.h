#pragma once

#include <string>
#include "IScene.h"

namespace MyGL {
    class IShader;

    class ITexture2d;

    class Adapter {
    public:
        Adapter(IScene &s);

        virtual IShader *getLincShader() = 0; // 0

        virtual IShader *getGausVerticalShader() = 0; // 1

        virtual IShader *getGausHorizontalShader() = 0;// 2

        virtual IShader *getBloomDownSampleShader() = 0;//3

        virtual IShader *getGlowDownSampleShader() = 0;// 4

        virtual IShader *getSSAOShader() = 0; // 5

        virtual ITexture2d *getRandTexture() = 0; // 6

        virtual IShader *getVolumetricLightScatteringShader() = 0; // 7

        virtual IShader *getBlurShadowShader() = 0; // 8

        virtual ITexture2d *getShadowMapTexture() = 0; // 9

        IShader *returnShader(const std::string &d);

        IScene &scene();

    protected:
        IScene &_scene;
    };
}
