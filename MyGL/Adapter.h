#pragma once

#include <string>
#include "IScene.h"

namespace MyGL {
    class IShader;

    class ITexture2d;

    class Adapter {
    public:
        Adapter(IScene &s);

        virtual IShader *getLincShader(); // 0

        virtual IShader *getGausVerticalShader(); // 1

        virtual IShader *getGausHorizontalShader();// 2

        virtual IShader *getBloomDownSampleShader();//3

        virtual IShader *getGlowDownSampleShader();// 4

        virtual IShader *getSSAOShader(); // 5

        virtual ITexture2d *getRandTexture(); // 6

        virtual IShader *getVolumetricLightScatteringShader(); // 7

        virtual IShader *getBlurShadowShader(); // 8

        virtual ITexture2d *getShadowMapTexture(); // 9

        IShader *returnShader(const std::string &d);

        IScene &scene();

    protected:
        IScene &_scene;
    };
}

