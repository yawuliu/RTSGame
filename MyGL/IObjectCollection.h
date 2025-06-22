#pragma once

namespace MyGL {
    class IObjectCollection {
    public:
        class IIterator {
        public:
            IIterator() = default;

            virtual ~IIterator() = default;
        };

    public:
        IObjectCollection() = default;

        virtual ~IObjectCollection() = default;
    };
}