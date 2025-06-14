#pragma once

#include "MyGL/IScene.h"

namespace MyGL {
    class Adapter;

    class IRenderAlgo : public IScene {
    public:
        void makeAlgo(const MyGL::Adapter *adapter);

        void setBloom(bool);

        void setShadowPass(bool);

        IScene *scene() const;

    protected:
        IScene *mScene;
        bool mBloom;
        bool mShadowPass;
    };
}