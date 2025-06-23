#pragma once

#include "IMaterial.h"
#include "IScene.h"
#include "ITechnique.h"
#include "IGraphicsObject.h"
#include "ITexture.h"


namespace MyGL {
    class AbstractMaterial : public IMaterial {
    public:
        AbstractMaterial(IScene &r);

        virtual ~AbstractMaterial();

        bool drawEvent(const IGraphicsObject &o);

        ITexture &getTexture(unsigned int a2);

        bool greater(const ITechnique &t, const ITechnique &t2);

        bool less(const ITechnique &t, const ITechnique &t2);

        bool operator<(const IMaterial &other);

        IRender *render();

        IScene &scene();

    protected:
        IScene &mscene;
    };
}



