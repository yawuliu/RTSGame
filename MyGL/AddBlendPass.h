#pragma once

#include <MyGL/IRenderPass.h>

namespace MyGL {
    class IScene;

    class IRenderPass;

    class AddBlendPass : public IRenderPass {
    public:
        AddBlendPass(IScene *);

        const IRenderPass::Pass::Type &type() const override;
    };
}