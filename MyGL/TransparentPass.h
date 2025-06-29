#pragma once

#include "AbstractPass.h"
#include "IGraphicsObject.h"
#include "IScene.h"
#include "IRenderPass.h"

namespace MyGL {
    class TransparentPass : public AbstractPass {
    public:
        TransparentPass(IScene &s);

        virtual ~TransparentPass() = default;

        virtual void exec() override;

        virtual IRenderPass::Pass::Type type() override;

        bool isColorPass();

        bool isDepthPass();

        bool isDrawable(IGraphicsObject &obj);

    protected:
        bool depthP;
    };
}