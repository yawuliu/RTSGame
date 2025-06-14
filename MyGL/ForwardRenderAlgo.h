#pragma once

#include <MyGL/IRenderAlgo.h>

namespace MyGL {
    class IScene;

    class Adapter;

    class ForwardRenderAlgo : public IRenderAlgo {
    public:
        ForwardRenderAlgo(IScene *s, const MyGL::Adapter *a, int);
    };
}
