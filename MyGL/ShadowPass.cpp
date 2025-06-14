#include "ShadowPass.h"

MyGL::ShadowPass::ShadowPass(IScene *s) : IRenderPass(s) {

}

const MyGL::IRenderPass::Pass::Type &MyGL::ShadowPass::type() const {
    return IRenderPass::Pass::Shadow;
}
