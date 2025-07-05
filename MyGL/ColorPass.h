#pragma once

#include "IScene.h"
#include "AbstractPass.h"
#include "IRenderPass.h"
#include "IGraphicsObject.h"

namespace MyGL {
    class ColorPass : public AbstractPass {
    public:
        ColorPass(IScene &s);

        ~ColorPass() = default;

        void exec() override;

        IRenderPass::Pass::Type type() override;

        bool isDrawable(IGraphicsObject &obj);

    };
}