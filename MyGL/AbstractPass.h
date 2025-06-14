#pragma once

#include <MyGL/IRenderPass.h>

namespace MyGL {
    class IScene;

    class AbstractPass : public IRenderPass {
    public:
        AbstractPass(IScene *s);

        const IRenderPass::Pass::Type &type() const override;
    };


    class Pass {
    public:
        enum Type {
            User
        };
    };
}

