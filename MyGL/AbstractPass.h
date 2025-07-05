#pragma once

#include "IRenderPass.h"
#include "IGraphicsObject.h"
#include "ITechnique.h"
#include "IScene.h"

namespace MyGL {
    class AbstractPass : public IRenderPass {
    public:
        AbstractPass(IScene &s);

        virtual IScene &scene();

        template<class T>
        bool drawObject(IGraphicsObject &obj) {
            if (!obj.model())
                return false;
            if (!obj.material()->technique()->passEvent(const_cast<const T *>(this)))
                return false;

            this->scene().render()->draw(obj);
            obj.material()->technique()->completeDraw(this);
            return true;
        }

    protected:
        IScene &mscene;
    };
}

