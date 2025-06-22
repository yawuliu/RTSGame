#pragma once

#include <MyGL/IUniform.h>

namespace MyGL {
    class IUniformMatrix4x4 : public IUniform {
    public:
        IUniformMatrix4x4() = default;

        virtual ~IUniformMatrix4x4() = default;

        virtual void SetMatrix(const float *matrix) = 0;

        virtual const float *GetMatrix() const = 0;;
    };
}