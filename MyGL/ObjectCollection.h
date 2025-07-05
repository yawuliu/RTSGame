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

        class Iterator {
        public:
            class pimpl {
            public:
                pimpl() = default;

            public:
                std::vector<IGraphicsObject *>::iterator it;
            };

        public:
            Iterator(Iterator &c);

            Iterator(ObjectCollection &i);

            virtual ~Iterator();

            void dec();

            IGraphicsObject *get();

            bool hasNext();

            bool hasPrevious();

            void inc();

            void operator++();

            void operator--();

            void setBegin();

            void setEnd();

        public:
            ObjectCollection::Iterator::pimpl *data;
            void *owner;
        };

    public:
        ObjectCollection(IScene &s);

        virtual ~ObjectCollection();

        void begin() override;

        void addObject(IGraphicsObject &it);

        IObjectCollection::IIterator *begin(ObjectCollection &c);

        void delObject(IGraphicsObject &it);

        IObjectCollection::IIterator *end(ObjectCollection &c);

        bool less(IGraphicsObject *obj1, IGraphicsObject *obj2);

        void onChangeMaterialObject(IGraphicsObject &obj, IMaterial &a3);

        IGraphicsObject *operator[](size_t i);

        void refresh();

        size_t size();

    protected:
        IScene &scene;
        pimpl *data;
    };

}
