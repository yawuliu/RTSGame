#include "ObjectCollection.h"

namespace MyGL {
    void ObjectCollection::begin() {
        return  new Iterator( c);;
    }

    ObjectCollection::ObjectCollection(IScene &s) : scene(s) {
        this->scene = s;
        this->data = new pimpl();
    }

    size_t ObjectCollection::size() {
        return this->data->size();
    }

    void ObjectCollection::refresh() {
        ;
    }

    IGraphicsObject *ObjectCollection::operator[](size_t i) {
        return this->data[i];
    }

    void ObjectCollection::onChangeMaterialObject(IGraphicsObject &obj, IMaterial &a3) {
       this->delObject(obj);
       this->addObject(obj);
    }

    bool ObjectCollection::less(IGraphicsObject *obj1, IGraphicsObject *obj2) {
        if ( !obj1->delObject() )
            return 0;
        if ( !obj2->delObject() )
            return 1;
        v4 = obj1->delObject();
        v5 = *(unsigned __int8 (__fastcall **)(__int64, __int64))(*(_QWORD *)v4 + 56LL);
        v6 = obj2->delObject();
        if ( v5(v4, v6) )
            return 1;
        v7 = obj2->delObject();
        v8 = *(unsigned __int8 (__fastcall **)(__int64, __int64))(*(_QWORD *)v7 + 56LL);
        v9 = obj1->delObject();
        if ( v8(v7, v9) )
            return 0;
        v10 = obj1->end();
        return v10 < obj2->end();
    }

    IObjectCollection::IIterator *ObjectCollection::end(ObjectCollection &c) {
        v1 = new Iterator(c);
        (*(void (__fastcall **)(ObjectCollection::Iterator *))(*(_QWORD *)&v1->IObjectCollection::IIterator + 80LL))(v1);
        return v1;
    }

    void ObjectCollection::delObject(IGraphicsObject &it) {
        if ( this->data->size())
        {
            mv = 0;
            for (int i = 0;i < this->data->size()- 1; ++i )
            {
                if ( mv )
                {
                    v2 = this->data[i];
                    *v2 =this->data[i + 1];
                }
                else if ( this->data[i] == it )
                {
                    mv = 1;
                    v3 = this->data,[i];
                    *v3 = this->data[i + 1];
                }
            }
            if ( mv || this->data->items.back() == it )
                this->data->items.pop_back();
            data = this->data;
            data->endI._M_current = std::vector<IGraphicsObject *>::end((std::vector<IGraphicsObject*>_0 *const)data)._M_current;
            this->data->beginI._M_current = std::vector<IGraphicsObject *>::begin((std::vector<IGraphicsObject*>_0 *const)this->data)._M_current;
        }
    }

    IObjectCollection::IIterator *ObjectCollection::begin(ObjectCollection &c) {
        return new Iterator(c);
    }

    void ObjectCollection::addObject(IGraphicsObject &it) {
        if ( (*(__int64 (__fastcall **)(IGraphicsObject *const))(*(_QWORD *)it + 24LL))(it) )
        {
            this->data.push_back(it);
            mv = 1;
            for (int i = this->data->size() - 1; i > 0; --i )
            {
                obj2 = this->data[i - 1];
                obj1 = this->data[i];
                mv = this->less(obj1, obj2);
                if ( mv )
                {
                    __b = this->data[i - 1];
                    __a = this->data[i];
                    std::swap<IGraphicsObject *>(__a, __b);
                }
            }
            data = this->data;
            data->endI._M_current = std::vector<IGraphicsObject *>::end((std::vector<IGraphicsObject*>_0 *const)data)._M_current;
            this->data->beginI._M_current = std::vector<IGraphicsObject *>::begin((std::vector<IGraphicsObject*>_0 *const)this->data)._M_current;
        }
    }

    ObjectCollection::~ObjectCollection() {

    }

    ObjectCollection::Iterator::Iterator(ObjectCollection::Iterator &c) {
        this->data = new pimpl();
        this->owner = c.owner;
        this->setBegin();
    }

    ObjectCollection::Iterator::Iterator(ObjectCollection &c) {
        this->data = new pimpl();
        this->owner = c;
        this->setBegin();
    }


    void ObjectCollection::Iterator::dec() {
        this->operator--();
    }

    IGraphicsObject *ObjectCollection::Iterator::get() {
        return *this->data;
    }

    bool ObjectCollection::Iterator::hasNext() {
        return this->data!=
                (const __gnu_cxx::__normal_iterator<IGraphicsObject**,std::vector<IGraphicsObject*> > *const)(*((_QWORD *)this->owner + 2) + 24LL));
    }

    bool ObjectCollection::Iterator::hasPrevious() {
        return this->data !=
                (const __gnu_cxx::__normal_iterator<IGraphicsObject**,std::vector<IGraphicsObject*> > *const)(*((_QWORD *)this->owner + 2) + 32LL));
    }

    void ObjectCollection::Iterator::inc() {
        this->operator++()
    }

    void ObjectCollection::Iterator::operator++() {
        this->data->it.operator++(0);
    }

    void ObjectCollection::Iterator::operator--() {
        this->data->it.operator--(0);
    }

    void ObjectCollection::Iterator::setBegin() {
        this->data->it._M_current = *(IGraphicsObject ***)(*((_QWORD *)this->owner + 2) + 32LL);
    }

    void ObjectCollection::Iterator::setEnd() {
        this->data->it._M_current = *(IGraphicsObject ***)(*((_QWORD *)this->owner + 2) + 24LL);
    }
}
