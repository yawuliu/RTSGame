#pragma once

namespace MyGL {

    class Color {
    public:
        typedef float ChanelType;
    public:
        explicit Color(ChanelType c);

        Color(ChanelType r, ChanelType g, ChanelType b, ChanelType a);

        Color();

        ChanelType a();

        ChanelType b();

        const ChanelType *data();

        ChanelType g();

        void operator+(const Color &other);

        void operator+=(const Color &other);

        void operator-(const Color &other);

        void operator-=(const Color &other);

        Color &operator=(const Color &other);

        ChanelType r();

        void set(ChanelType rgba);

        void set(ChanelType r, ChanelType g, ChanelType b, ChanelType a);

    protected:
        ChanelType cdata[4];
    };
}