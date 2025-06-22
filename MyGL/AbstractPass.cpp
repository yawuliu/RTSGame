#include "MyGL/AbstractPass.h"


MyGL::AbstractPass::AbstractPass(IScene &s) : mscene(s) {

}


MyGL::IScene &MyGL::AbstractPass::scene() {
    return this->mscene;
}
