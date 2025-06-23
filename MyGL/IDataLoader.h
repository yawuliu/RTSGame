#pragma once

#include "DisableCopy.h"

namespace MyGL {
    class IDataLoader : public DisableCopy {
    public:
        template<class T>
        class IAllocator {
        public:
            IAllocator() = default;

            virtual ~IAllocator() = default;
        };

    public:
        IDataLoader() = default;

        virtual  ~IDataLoader() = default;

    };
}



