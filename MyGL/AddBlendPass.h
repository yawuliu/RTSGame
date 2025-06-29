#pragma once

#include "AbstractPass.h"
#include "IScene.h"
#include "IRenderPass.h"
#include "IGraphicsObject.h"


namespace MyGL {
    class AddBlendPass : public AbstractPass {
    public:
        AddBlendPass(IScene &s);

        virtual ~AddBlendPass() = default;

        virtual void exec() override;

        virtual IRenderPass::Pass::Type type() override;

        bool isDrawable(IGraphicsObject &obj);
    };
}