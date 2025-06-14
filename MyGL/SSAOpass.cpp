#include "SSAOpass.h"

MyGL::SSAOpass::SSAOpass(MyGL::IScene *s, MyGL::IAdapter *, MyGL::IRenderPass *) : IRenderPass(s) {

}

const MyGL::IRenderPass::Pass::Type &MyGL::SSAOpass::type() const {
    return IRenderPass::Pass::SSAO;
}
