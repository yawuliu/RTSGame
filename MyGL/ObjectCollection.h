#pragma once

#include <vector>
#include "IScene.h"
#include "IGraphicsObject.h"
#include "IObjectCollection.h"

namespace MyGL {
    class ObjectCollection : public IObjectCollection {
    public:
        class pimpl {
        public:
            typedef std::vector<IGraphicsObject *> ObjMap;
        public:
            pimpl() = default;

            virtual ~pimpl() = default;

        public:
            ObjectCollection::pimpl::ObjMap items;
            std::vector<IGraphicsObject *>::iterator endI;
            std::vector<IGraphicsObject *>::iterator beginI;
        };

        class Iterator : public IIterator {
        public:
            class pimpl {
            public:
                pimpl() = default;


            public:
                std::vector<IGraphicsObject *>::iterator it;
            };

        public:
            Iterator(Iterator &c);

            explicit Iterator(ObjectCollection &i);

            ~Iterator() override = default; //0
            // virtual ~Iterator() = default; // 1
            void get() override; // 2

            void operator++() override; // 3

            void operator--() override; // 4

            void inc() override; // 5

            void dec() override; // 6

            void hasNext() override; // 7

            void hasPrevious() override; // 8

            void setBegin() override; // 9

            void setEnd() override; // 10

//            virtual ~Iterator();
//
//            void dec();
//
//            IGraphicsObject *get();
//
//            bool hasNext();
//
//            bool hasPrevious();
//
//            void inc();
//
//            void operator++();
//
//            void operator--();
//
//            void setBegin();
//
//            void setEnd();

        public:
            ObjectCollection::Iterator::pimpl *data;
            void *owner;
        };

    public:
        explicit ObjectCollection(IScene &s);

        ~ObjectCollection() override;

        void begin() override;

        void addObject(IGraphicsObject &it) override;

        IObjectCollection::IIterator *begin(ObjectCollection &c);

        void delObject(IGraphicsObject &it) override;

        IObjectCollection::IIterator *end(ObjectCollection &c);

        bool less(IGraphicsObject *obj1, IGraphicsObject *obj2);

        void onChangeMaterialObject(IGraphicsObject &obj, IMaterial &a3) override;

        IGraphicsObject *operator[](size_t i) override;

        void refresh() override;

        size_t size() override;

    protected:
        IScene &scene;
        pimpl *data;
    };

}
