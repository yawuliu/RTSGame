#include "MainPass.h"


MyGL::MainPass::MainPass(MyGL::IScene *s, const MyGL::Adapter *adapter, MyGL::IModel *quad, int) : IRenderPass(s) {
    mQuad = quad;
}

void MyGL::MainPass::makeAlgo(std::vector<IRenderPass *> &out, const MyGL::Adapter *adapter) {

}

void MyGL::MainPass::makeAlgo(const MyGL::Adapter *adapter) {

}

MyGL::IFrameBuffer *MyGL::MainPass::frameBuffer() {
    return nullptr;
}

MyGL::IModel *MyGL::MainPass::quadModel() {
    return mQuad;
}

const MyGL::IRenderPass::Pass::Type &MyGL::MainPass::type() const {
    return IRenderPass::Pass::Main;
}

