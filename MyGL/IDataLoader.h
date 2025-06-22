#pragma once

#include <MyGL/DisableCopy.h>

namespace MyGL {
    class IDataLoader : public DisableCopy {
    public:
        template<class T>
        class IAllocator {
        public:
            IAllocator() {

            }

            virtual ~IAllocator() {

            }
        };

    public:
        IDataLoader() {


        }

        virtual  ~IDataLoader() {

        }

    };
}



