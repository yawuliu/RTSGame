#include "MyGL/AbstractPass.h"


MyGL::AbstractPass::AbstractPass(IScene *s) : IRenderPass(s) {

}

const MyGL::IRenderPass::Pass::Type &MyGL::AbstractPass::type() const {
    return IRenderPass::Pass::Abstract;
}
