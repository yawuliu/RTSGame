#include "ColorPass.h"

MyGL::ColorPass::ColorPass(MyGL::IScene *s) : IRenderPass(s) {

}

const MyGL::IRenderPass::Pass::Type &MyGL::ColorPass::type() const {
    return IRenderPass::Pass::Color;
}
