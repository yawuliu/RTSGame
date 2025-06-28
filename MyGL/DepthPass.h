#pragma once

#include "AbstractPass.h"

namespace MyGL {
    class IScene;

    class IGraphicsObject;

    class DepthPass : public AbstractPass {
    public:
        DepthPass(IScene &s);

        virtual ~DepthPass() = default;

        virtual void exec() override;

        virtual IRenderPass::Pass::Type type() override;

        bool isDrawable(IGraphicsObject &obj);


    };
}