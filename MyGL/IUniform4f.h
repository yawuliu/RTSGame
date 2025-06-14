#pragma once

namespace MyGL {
    class IUniform4f {
    public:
        virtual void set(int) = 0;

        virtual void set(float x, float y, float w, float h) = 0;
    };

    template<class T>
    T *uniform(int location) {
        return nullptr;
    }
}

