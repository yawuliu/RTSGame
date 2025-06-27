#include "AbstractTechnique.h"

namespace MyGL {
    AbstractTechnique::AbstractTechnique(IScene &s) : mscene(s) {
    }


    void AbstractTechnique::completeDraw(AddBlendPass const *a2) {
        ;
    }

    void AbstractTechnique::completeDraw(ColorPass const *a2) {
        ;
    }

    void AbstractTechnique::completeDraw(DepthPass const *a2) {
        ;
    }

    void AbstractTechnique::completeDraw(GlowPass const *a2) {
        ;
    }

    void AbstractTechnique::completeDraw(IRenderPass const *a2) {
        ;
    }

    void AbstractTechnique::completeDraw(ShadowPass const *a2) {
        ;
    }

    void AbstractTechnique::completeDraw(TransparentPass const *a2) {
        ;
    }

    bool AbstractTechnique::drawEvent(const IGraphicsObject &a2, const IMaterial &a3) {
        return 1;
    }

    bool AbstractTechnique::passEvent(AddBlendPass const *a2) {
        return 0;
    }

    bool AbstractTechnique::passEvent(ColorPass const *a2) {
        return 0;
    }

    bool AbstractTechnique::passEvent(DepthPass const *a2) {
        return 0;
    }

    bool AbstractTechnique::passEvent(GlowPass const *a2) {
        return 0;
    }

    bool AbstractTechnique::passEvent(IRenderPass const *a2) {
        return 0;
    }

    bool AbstractTechnique::passEvent(ShadowPass const *a2) {
        return 0;
    }

    bool AbstractTechnique::passEvent(TransparentPass const *a2) {
        return 0;
    }

    IRender *AbstractTechnique::render() {
        return this->mscene.render();
    }

    IScene &AbstractTechnique::scene() {
        return this->mscene;
    }
}