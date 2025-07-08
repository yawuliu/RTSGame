#pragma once

#include "AbstractPass.h"
#include "IScene.h"
#include "IGraphicsObject.h"

namespace MyGL {
    class DepthPass : public AbstractPass {
    public:
        explicit DepthPass(IScene &s);

        ~DepthPass() override = default;

        void exec() override;

        IRenderPass::Pass::Type type() override;

        bool isDrawable(IGraphicsObject &obj);
    };
}