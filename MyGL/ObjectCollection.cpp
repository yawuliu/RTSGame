#include "ObjectCollection.h"

namespace MyGL {
    void ObjectCollection::begin() {
        return  new Iterator( c);;
    }

    ObjectCollection::ObjectCollection(IScene &s) : scene(s) {
        this->IObjectCollection = (IObjectCollection)((char *)&RTTI_ObjectCollection::vftable + 16);
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
        (*((void (__fastcall **)(ObjectCollection *const, IGraphicsObject *const))this->_vptr_IObjectCollection + 3))(
                this,
                obj);
        (*((void (__fastcall **)(ObjectCollection *const, IGraphicsObject *const))this->_vptr_IObjectCollection + 2))(
                this,
                obj);
    }

    bool ObjectCollection::less(IGraphicsObject *obj1, IGraphicsObject *obj2) {


        if ( !(*((__int64 (__fastcall **)(IGraphicsObject *))obj1->_vptr_IGraphicsObject + 3))(obj1) )
            return 0;
        if ( !(*((__int64 (__fastcall **)(IGraphicsObject *))obj2->_vptr_IGraphicsObject + 3))(obj2) )
            return 1;
        v4 = (*((__int64 (__fastcall **)(IGraphicsObject *))obj1->_vptr_IGraphicsObject + 3))(obj1);
        v5 = *(unsigned __int8 (__fastcall **)(__int64, __int64))(*(_QWORD *)v4 + 56LL);
        v6 = (*((__int64 (__fastcall **)(IGraphicsObject *))obj2->_vptr_IGraphicsObject + 3))(obj2);
        if ( v5(v4, v6) )
            return 1;
        v7 = (*((__int64 (__fastcall **)(IGraphicsObject *))obj2->_vptr_IGraphicsObject + 3))(obj2);
        v8 = *(unsigned __int8 (__fastcall **)(__int64, __int64))(*(_QWORD *)v7 + 56LL);
        v9 = (*((__int64 (__fastcall **)(IGraphicsObject *))obj1->_vptr_IGraphicsObject + 3))(obj1);
        if ( v8(v7, v9) )
            return 0;
        v10 = (*((__int64 (__fastcall **)(IGraphicsObject *))obj1->_vptr_IGraphicsObject + 7))(obj1);
        return v10 < (*((__int64 (__fastcall **)(IGraphicsObject *))obj2->_vptr_IGraphicsObject + 7))(obj2);
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
                    v2 = std::vector<IGraphicsObject *>::operator[](
                            (std::vector<IGraphicsObject*>_0 *const)this->data,
                            i);
                    *v2 = *std::vector<IGraphicsObject *>::operator[](
                            (std::vector<IGraphicsObject*>_0 *const)this->data,
                            i + 1);
                }
                else if ( *std::vector<IGraphicsObject *>::operator[](
                        (std::vector<IGraphicsObject*>_0 *const)this->data,
                        i) == it )
                {
                    mv = 1;
                    v3 = std::vector<IGraphicsObject *>::operator[](
                            (std::vector<IGraphicsObject*>_0 *const)this->data,
                            i);
                    *v3 = *std::vector<IGraphicsObject *>::operator[](
                            (std::vector<IGraphicsObject*>_0 *const)this->data,
                            i + 1);
                }
            }
            if ( mv || *std::vector<IGraphicsObject *>::back(&this->data->items) == it )
                std::vector<IGraphicsObject *>::pop_back(&this->data->items);
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
            __x = it;
            std::vector<IGraphicsObject *>::push_back((std::vector<IGraphicsObject*>_0 *const)this->data, &__x);
            mv = 1;
            for (int i = this->data->size() - 1; i > 0; --i )
            {
                obj2 = *std::vector<IGraphicsObject *>::operator[](
                        (std::vector<IGraphicsObject*>_0 *const)this->data,
                        i - 1);
                obj1 = *std::vector<IGraphicsObject *>::operator[](
                        (std::vector<IGraphicsObject*>_0 *const)this->data,
                        i);
                mv = ObjectCollection::less(this, obj1, obj2);
                if ( mv )
                {
                    __b = std::vector<IGraphicsObject *>::operator[](
                            (std::vector<IGraphicsObject*>_0 *const)this->data,
                            i - 1);
                    __a = std::vector<IGraphicsObject *>::operator[](
                            (std::vector<IGraphicsObject*>_0 *const)this->data,
                            i);
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
        this->IIterator();
        this->IObjectCollection::IIterator = (IObjectCollection::IIterator)((char *)&RTTI_ObjectCollection::Iterator::vftable
                                                                                        + 16);
        this->data = new pimpl();
        this->owner = (void *)*((_QWORD *)i + 2);
        this->setBegin();
    }

    ObjectCollection::Iterator::Iterator(ObjectCollection &i) {
        this->IObjectCollection::IIterator = (IObjectCollection::IIterator)((char *)&RTTI_ObjectCollection::Iterator::vftable
                                                                                        + 16);
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
        return __gnu_cxx::operator!=<IGraphicsObject **,std::vector<IGraphicsObject *>>(
                (const __gnu_cxx::__normal_iterator<IGraphicsObject**,std::vector<IGraphicsObject*> > *const)this->data,
                (const __gnu_cxx::__normal_iterator<IGraphicsObject**,std::vector<IGraphicsObject*> > *const)(*((_QWORD *)this->owner + 2) + 24LL));
    }

    bool ObjectCollection::Iterator::hasPrevious() {
        return __gnu_cxx::operator!=<IGraphicsObject **,std::vector<IGraphicsObject *>>(
                (const __gnu_cxx::__normal_iterator<IGraphicsObject**,std::vector<IGraphicsObject*> > *const)this->data,
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
