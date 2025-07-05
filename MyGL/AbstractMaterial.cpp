#include "AbstractMaterial.h"
#include "IScene.h"
#include "ITechnique.h"
#include "IMaterial.h"

namespace MyGL {
    AbstractMaterial::AbstractMaterial(IScene &r) : mscene(r) {

    }


    bool AbstractMaterial::drawEvent(IGraphicsObject const &o) {
        return this->technique()->drawEvent(o, *this);
    }

    const ITexture *AbstractMaterial::getTexture(uint32_t a2) {
        return nullptr;
    }

    bool AbstractMaterial::greater(ITechnique const &t, ITechnique const &t2) {
        return t.cmpShader() > t2.cmpShader();
    }

    bool AbstractMaterial::less(ITechnique const &t, ITechnique const &t2) {
        return t.cmpShader() < t2.cmpShader();
    }


    IRender *AbstractMaterial::render() {
        return this->mscene.render();
    }

    IScene &AbstractMaterial::scene() {
        return this->mscene;
    }

    bool AbstractMaterial::operator>(IMaterial &other) {
        if (!this->technique())
            return 0;
        if (other.technique())
            return this > &other;
        return 1;
    }

    bool AbstractMaterial::operator<(IMaterial &other) {
        if (!this->technique() && other.technique()) {
            return 1;
        }
        if (!other.technique())
            return 0;
        if (this->technique() < other.technique())
            return 1;
        if (this->technique() > other.technique())
            return 0;
        for (int i = 0; i <= 3; ++i) {
            auto &&t1 = this->getTexture(i);
            auto &&t2 = other.getTexture(i);
            if (t1 < t2)
                return 1;
            if (t1 > t2)
                return 0;
        }
        return 0;
    }
}