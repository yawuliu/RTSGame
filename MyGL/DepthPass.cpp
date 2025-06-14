#include "DepthPass.h"

MyGL::DepthPass::DepthPass(MyGL::IScene *s) : IRenderPass(s) {

}

const MyGL::IRenderPass::Pass::Type &MyGL::DepthPass::type() const {
    return IRenderPass::Pass::Depth;
}
