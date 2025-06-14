#include "IRenderAlgo.h"
#include "Adapter.h"

void MyGL::IRenderAlgo::makeAlgo(const MyGL::Adapter *adapter) {
   
}

void MyGL::IRenderAlgo::setBloom(bool bloom) {
    mBloom = bloom;
}

void MyGL::IRenderAlgo::setShadowPass(bool shadowPass) {
    mShadowPass = shadowPass;
}

MyGL::IScene *MyGL::IRenderAlgo::scene() const {
    return mScene;
}