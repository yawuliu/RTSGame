#pragma once

#include "IRenderPass.h"
#include "AbstractPass.h"
#include "IScene.h"
#include "Adapter.h"

namespace MyGL {
    class SmallLightsPass : public AbstractPass {
    public:
        SmallLightsPass(const IScene &s, const Adapter &a3);

        virtual ~SmallLightsPass() = default;

        virtual void exec() override;

        virtual IRenderPass::Pass::Type type() override;
    };
}