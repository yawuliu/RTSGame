#pragma once

#include <vector>
#include <MyGL/MainPass.h>
#include "MyGL/StdMaterial.h"
#include "MyGL/Adapter.h"
#include "MyGL/TextureRectangle.h"
#include <MyGL/IRenderPass.h>

class RenderMainPass : public MyGL::MainPass {
public:
    RenderMainPass(MyGL::IScene *s, MyGL::IModel *quad,
                   const MyGL::gadapter *adapter);

    MyGL::IScene *scene();

    MyGL::ITextureRectangle *output();

private:
    void makeAlgo(std::vector<MyGL::IRenderPass *> &out,
                  const MyGL::gadapter *adapter);

    void makeAlgo(const MyGL::gadapter *adapter);

};


