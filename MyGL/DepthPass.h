#pragma once

#include <MyGL/IRenderPass.h>

namespace MyGL {
    class IScene;

    class DepthPass : public IRenderPass {
    public:
        DepthPass(IScene *);

        const IRenderPass::Pass::Type &type() const override;
    };
}