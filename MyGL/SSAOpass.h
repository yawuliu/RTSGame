
#pragma once

#include <MyGL/IRenderPass.h>


namespace MyGL {
    class IScene;

    class IAdapter;

    class SSAOpass : public IRenderPass {
    public:
        SSAOpass(IScene *, IAdapter *, IRenderPass *);

        const IRenderPass::Pass::Type &type() const override;
    };
}