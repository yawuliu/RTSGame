#include "Color.h"

namespace MyGL {
    Color::Color(ChanelType c) {
        set(c);
    }

    Color::Color(ChanelType r, ChanelType g, ChanelType b, ChanelType a) {
        set(r, g, b, a);
    }

    Color::Color() {
        set(1.0);
    }

    Color::ChanelType Color::a() {
        return data()[3];
    }

    Color::ChanelType Color::b() {
        return data()[2];
    }

    const Color::ChanelType *Color::data() {
        return this->cdata;
    }

    Color::ChanelType Color::g() {
        return data()[1];
    }

    void Color::operator+(const Color &other) {
        Color v2;
        for (int i = 0; i <= 3; ++i)
            v2.cdata[i] = other.cdata[i] + this->cdata[i];
    }

    void Color::operator+=(const Color &other) {
        for (int i = 0; i <= 3; ++i)
            this->cdata[i] = other.cdata[i] + this->cdata[i];
    }

    void Color::operator-(const Color &other) {
        Color v2;
        for (int i = 0; i <= 3; ++i)
            v2.cdata[i] = this->cdata[i] - other.cdata[i];
    }

    void Color::operator-=(const Color &other) {
        for (int i = 0; i <= 3; ++i)
            this->cdata[i] = this->cdata[i] - other.cdata[i];
    }

    Color &Color::operator=(const Color &other) {
        for (int i = 0; i <= 3; ++i)
            this->cdata[i] = other.cdata[i];
        return *this;
    }

    Color::ChanelType Color::r() {
        return data()[0];
    }

    void Color::set(ChanelType rgba) {
        int i;

        for (i = 0; i <= 3; ++i)
            this->cdata[i] = rgba;
    }

    void Color::set(ChanelType r, ChanelType g, ChanelType b, ChanelType a) {
        this->cdata[0] = r;
        this->cdata[1] = g;
        this->cdata[2] = b;
        this->cdata[3] = a;
    }
}