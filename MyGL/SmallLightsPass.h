#pragma once

#include <MyGL/IRenderPass.h>
#include <MyGL/AbstractPass.h>
#include <MyGL/IScene.h>
#include <MyGL/Adapter.h>

namespace MyGL {
    class SmallLightsPass : public AbstractPass {
    public:
        SmallLightsPass(const IScene &s, const Adapter &a3);

        virtual ~SmallLightsPass() = default;

        void exec();

        IRenderPass::Pass::Type type();
    };
}