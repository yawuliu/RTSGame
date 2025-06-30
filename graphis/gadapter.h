#pragma once

#include "MyGL/IShader.h"
#include "MyGL/Adapter.h"

class Adapter : public MyGL::gadapter {
public:
    Adapter(MyGL::IScene *s);

    MyGL::IShader *getLincShader() const;

    bool isBloom() const;

    bool isShadowMapping() const;

private:
    static MyGL::IShader *bloom;
};


