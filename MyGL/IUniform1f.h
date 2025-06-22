#pragma once

#include <MyGL/IUniform.h>


namespace MyGL {
    class IUniform1f : public IUniform {
    public:
        IUniform1f() = default;

        virtual ~IUniform1f() = default;

        virtual void setValue(float value) = 0;

        virtual float getValue() const = 0;

        virtual int getLocation() const = 0;
    };
}