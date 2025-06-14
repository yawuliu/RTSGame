#include "AddBlendPass.h"

MyGL::AddBlendPass::AddBlendPass(MyGL::IScene *s) : IRenderPass(s) {

}

const MyGL::IRenderPass::Pass::Type &MyGL::AddBlendPass::type() const {
    return IRenderPass::Pass::AddBlend;
}
