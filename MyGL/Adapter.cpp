#include "Adapter.h"
#include "Texture2d.h"
#include "IData.h"

namespace MyGL {
    Adapter::Adapter(IScene &s) : _scene(s) {

    }

    IShader *Adapter::getBloomDownSampleShader() {
        return this->returnShader("BloomDownSample");
    }

    IShader *Adapter::getBlurShadowShader() {
        return this->returnShader("BlurShadowShader");
    }

    IShader *Adapter::getGausHorizontalShader() {
        return this->returnShader("HorizontalShader");
    }

    IShader *Adapter::getGausVerticalShader() {
        return this->returnShader("GausVerticalShader");
    }

    IShader *Adapter::getGlowDownSampleShader() {
        return this->returnShader("GlowDownSample");
    }

    IShader *Adapter::getLincShader() {
        return this->returnShader("LincShader");
    }

    ITexture2d *Adapter::getRandTexture() {
        ITexture2d *re = this->scene().dataControl()->texture("rand4x4");
        this->scene().render()->gl()->errorCtrl()->warning(
                re != 0LL,
                "rand4x4 not found");
        return re;
    }

    IShader *Adapter::getSSAOShader() {
        return this->returnShader("SSAOShader");
    }

    ITexture2d *Adapter::getShadowMapTexture() {
        ITexture2d *re = this->scene().dataControl()->texture("shadow_map_texture");
        if (!re) {
            re = new Texture2d(this->scene().render());
            this->scene().dataControl()->addTexture("shadow_map_texture", re);
        }
        return re;
    }

    IShader *Adapter::getVolumetricLightScatteringShader() {
        return this->returnShader("VolumetricLightScatteringShader");
    }

    IShader *Adapter::returnShader(const std::string &d) {
        IShader *s = this->scene().dataControl()->shader(d);
        this->scene().render()->gl()->errorCtrl()->warning(s != 0LL, "");
        return s;
    }

    IScene &Adapter::scene() {
        return this->_scene;
    }
}


