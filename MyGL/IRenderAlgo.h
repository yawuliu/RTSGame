#pragma once

#include "IRenderPass.h"
#include "IRenderAlgoSettings.h"
#include "Adapter.h"
#include "MainPass.h"

namespace MyGL {
    class IRenderAlgo : public IRenderPass {
    public:
        IRenderAlgo() = default;

        virtual ~IRenderAlgo() = default;//0
        //1
        virtual void exec() = 0;//2
        virtual IRenderPass::Pass::Type type() = 0;//3
    };
}