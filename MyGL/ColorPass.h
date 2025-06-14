#pragma once

#include <MyGL/IRenderPass.h>

namespace MyGL {
    class IScene;

    class ColorPass : public IRenderPass {
    public:
        ColorPass(IScene *);

        const IRenderPass::Pass::Type &type() const override;
    };
}