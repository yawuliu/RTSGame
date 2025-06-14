#include "MyGL/AbstractShader.h"

MyGL::AbstractShader::AbstractShader(MyGL::IRender *r) : mRender(r) {

}


MyGL::IRender *MyGL::AbstractShader::render() {
    return mRender;
}
