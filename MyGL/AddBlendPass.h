#pragma once

#include <MyGL/IScene.h>
#include <MyGL/IRenderPass.h>
#include <MyGL/IGraphicsObject.h>
#include <MyGL/AbstractPass.h>

namespace MyGL {
    class AddBlendPass : public AbstractPass {
    public:
        AddBlendPass(IScene &s);

        virtual ~AddBlendPass();
        
        void exec();

        bool isDrawable(IGraphicsObject &obj);

        IRenderPass::Pass::Type type();
    };
}