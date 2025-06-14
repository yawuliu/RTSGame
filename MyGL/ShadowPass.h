#pragma once

#include "IRenderPass.h"

namespace MyGL {
    class ShadowPass : public IRenderPass {
    public:
        ShadowPass(IScene *s);

        const IRenderPass::Pass::Type &type() const override;
    };
}