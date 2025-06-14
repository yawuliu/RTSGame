#include "TransparentPass.h"

MyGL::TransparentPass::TransparentPass(MyGL::IScene *s) : IRenderPass(s) {

}

const MyGL::IRenderPass::Pass::Type &MyGL::TransparentPass::type() const {
    return IRenderPass::Pass::Transparent;
}
