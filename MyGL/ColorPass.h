#pragma once

#include "IScene.h"
#include "AbstractPass.h"
#include "IRenderPass.h"
#include "IGraphicsObject.h"

namespace MyGL {
    class ColorPass : public AbstractPass {
    public:
        ColorPass(IScene &s);

        virtual ~ColorPass();

        virtual void exec() override;

        virtual IRenderPass::Pass::Type type() override;

        bool isDrawable(IGraphicsObject &obj);
        
    };
}