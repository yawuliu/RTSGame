#pragma once

#include "MyGL/IRenderPass.h"

namespace MyGL {
    class IScene;

    class TransparentPass : public IRenderPass {
    public:
        TransparentPass(IScene *);

        const IRenderPass::Pass::Type &type() const override;
    };
}