#pragma once

#include <cstdint>
#include "IGraphicsObject.h"
#include "IMaterial.h"

namespace MyGL {
    class IObjectCollection {
    public:
        class IIterator {
        public:
            IIterator() = default;

            virtual ~IIterator() = default; //0
            // virtual ~IIterator() = default; // 1
            virtual void get() = 0; // 2

            virtual void operator++() = 0; // 3

            virtual void operator--() = 0; // 4

            virtual void inc() = 0; // 5

            virtual void dec() = 0; // 6

            virtual void hasNext() = 0; // 7

            virtual void hasPrevious() = 0; // 8

            virtual void setBegin() = 0; // 9

            virtual void setEnd() = 0; // 10
        };

    public:
        IObjectCollection() = default;

        virtual ~IObjectCollection() = default; // 0
        // virtual ~IObjectCollection() = default; // 1
        virtual void addObject(IGraphicsObject &) = 0; // 2
        virtual void delObject(IGraphicsObject &) = 0; // 3
        virtual void onChangeMaterialObject(IGraphicsObject &, IMaterial &) = 0; // 4
        virtual void refresh() = 0; // 5
        virtual void begin() = 0; // 6
        virtual void end() = 0; // 7
        virtual size_t size() = 0; // 8
        virtual IGraphicsObject *operator[](size_t) = 0; // 9
    };
}