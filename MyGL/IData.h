#pragma once

#include <MyGL/IRenderState.h>
#include <QtOpenGL>

namespace MyGL {
    class GameObject {
    public:
        GameObject();
    };

    class GameObjectClass {
    public:
        GameObjectClass();

        class View {
        public:
            View();
        };
    };

    class Float {
    public:
        operator GLdouble() const;

    protected:
        float mVal;
    };

}


