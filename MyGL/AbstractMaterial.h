#pragma once

#include "IMaterial.h"
#include "IScene.h"

namespace MyGL {
    class IRender;

    class AbstractMaterial : public IMaterial {
    public:
        AbstractMaterial(IScene &r);

        virtual ~AbstractMaterial() = default;

        bool drawEvent(IGraphicsObject const &o) override;

        bool operator<(IMaterial &other) override;

        bool operator>(IMaterial &other) override;

        const ITexture *getTexture(uint32_t a2) override;

        static bool greater(ITechnique const &t, ITechnique const &t2);

        bool less(ITechnique const &t, ITechnique const &t2);

        IRender *render();

        IScene &scene();

    protected:
        IScene &mscene;
    };
}



