#include "ObjectCollection.h"

namespace MyGL {
    void ObjectCollection::begin() {
        ObjectCollection::Iterator *v1;

        v1 = (ObjectCollection::Iterator *)operator new(0x18uLL);
        ObjectCollection::Iterator::Iterator(v1, c);
        return v1;
    }

    ObjectCollection::ObjectCollection(IScene &s) : scene(s) {
        ObjectCollection::pimpl *data;
        this->IObjectCollection = (IObjectCollection)((char *)&RTTI_ObjectCollection::vftable + 16);
        this->scene = s;
        data = (ObjectCollection::pimpl *)operator new(0x28uLL);
        data->items._M_impl._M_start = 0LL;
        data->items._M_impl._M_finish = 0LL;
        data->items._M_impl._M_end_of_storage = 0LL;
        data->endI._M_current = 0LL;
        data->beginI._M_current = 0LL;
        ObjectCollection::pimpl::pimpl(data);
        this->data = data;
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
        __int64 v4; 
        unsigned __int8 (__fastcall *v5)(__int64, __int64); 
        __int64 v6; 
        __int64 v7; 
        unsigned __int8 (__fastcall *v8)(__int64, __int64); 
        __int64 v9; 
        unsigned __int64 v10; 

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
        ObjectCollection::Iterator *v1; 

        v1 = (ObjectCollection::Iterator *)operator new(0x18uLL);
        ObjectCollection::Iterator::Iterator(v1, c);
        (*(void (__fastcall **)(ObjectCollection::Iterator *))(*(_QWORD *)&v1->IObjectCollection::IIterator + 80LL))(v1);
        return v1;
    }

    void ObjectCollection::delObject(IGraphicsObject &it) {
        std::vector<IGraphicsObject*>::reference v2; 
        std::vector<IGraphicsObject*>::reference v3; 
        ObjectCollection::pimpl *data; 
        ObjectCollection::pimpl *data_1; 
        unsigned int i; 
        bool mv; 

        if ( std::vector<IGraphicsObject *>::size((const std::vector<IGraphicsObject*>_0 *const)this->data) )
        {
            mv = 0;
            for ( i = 0;
                  i < std::vector<IGraphicsObject *>::size((const std::vector<IGraphicsObject*>_0 *const)this->data)
            - 1;
            ++i )
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
            data_1 = this->data;
            data_1->beginI._M_current = std::vector<IGraphicsObject *>::begin((std::vector<IGraphicsObject*>_0 *const)data_1)._M_current;
        }
    }

    IObjectCollection::IIterator *ObjectCollection::begin(ObjectCollection &c) {
        ObjectCollection::Iterator *v1; 

        v1 = (ObjectCollection::Iterator *)operator new(0x18uLL);
        ObjectCollection::Iterator::Iterator(v1, c);
        return v1;
    }

    void ObjectCollection::addObject(IGraphicsObject &it) {
        IGraphicsObject *obj2; 
        IGraphicsObject *obj1; 
        IGraphicsObject **__b; 
        IGraphicsObject **__a; 
        ObjectCollection::pimpl *data; 
        ObjectCollection::pimpl *data_1; 
        std::vector<IGraphicsObject*>::value_type __x; 
        bool mv; 
        int i; 

        if ( (*(__int64 (__fastcall **)(IGraphicsObject *const))(*(_QWORD *)it + 24LL))(it) )
        {
            __x = it;
            std::vector<IGraphicsObject *>::push_back((std::vector<IGraphicsObject*>_0 *const)this->data, &__x);
            mv = 1;
            for ( i = std::vector<IGraphicsObject *>::size((const std::vector<IGraphicsObject*>_0 *const)this->data)
            - 1; i > 0; --i )
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
            data_1 = this->data;
            data_1->beginI._M_current = std::vector<IGraphicsObject *>::begin((std::vector<IGraphicsObject*>_0 *const)data_1)._M_current;
        }
    }

    ObjectCollection::~ObjectCollection() {

    }

    ObjectCollection::Iterator::Iterator(ObjectCollection::Iterator &c) {
        ObjectCollection::Iterator::pimpl *data; 

        IObjectCollection::IIterator::IIterator(this);
        this->IObjectCollection::IIterator = (IObjectCollection::IIterator)((char *)&RTTI_ObjectCollection::Iterator::vftable
                                                                                        + 16);
        data = (ObjectCollection::Iterator::pimpl *)operator new(8uLL);
        data->it._M_current = 0LL;
        ObjectCollection::Iterator::pimpl::pimpl(data);
        this->data = data;
        this->owner = (void *)*((_QWORD *)i + 2);
        ObjectCollection::Iterator::setBegin(this);
    }

    ObjectCollection::Iterator::Iterator(ObjectCollection &i) {
        ObjectCollection::Iterator::pimpl *data;
        this->IObjectCollection::IIterator = (IObjectCollection::IIterator)((char *)&RTTI_ObjectCollection::Iterator::vftable
                                                                                        + 16);
        data = (ObjectCollection::Iterator::pimpl *)operator new(8uLL);
        data->it._M_current = 0LL;
        ObjectCollection::Iterator::pimpl::pimpl(data);
        this->data = data;
        this->owner = c;
        this->setBegin();
    }

    ObjectCollection::Iterator::~Iterator() {

    }

    void ObjectCollection::Iterator::dec() {
        (*((void (__fastcall **)(ObjectCollection::Iterator *const))this->_vptr_IIterator + 4))(this);
    }

    IGraphicsObject *ObjectCollection::Iterator::get() {
        return *__gnu_cxx::__normal_iterator<IGraphicsObject **,std::vector<IGraphicsObject *>>::operator*((const __gnu_cxx::__normal_iterator<IGraphicsObject**,std::vector<IGraphicsObject*> > *const)this->data);
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
        (*((void (__fastcall **)(ObjectCollection::Iterator *const))this->_vptr_IIterator + 3))(this);
    }

    void ObjectCollection::Iterator::operator++() {
        __gnu_cxx::__normal_iterator<IGraphicsObject **,std::vector<IGraphicsObject *>>::operator++(
                &this->data->it,
                0);
    }

    void ObjectCollection::Iterator::operator--() {
        __gnu_cxx::__normal_iterator<IGraphicsObject **,std::vector<IGraphicsObject *>>::operator--(
                &this->data->it,
                0);
    }

    void ObjectCollection::Iterator::setBegin() {
        this->data->it._M_current = *(IGraphicsObject ***)(*((_QWORD *)this->owner + 2) + 32LL);
    }

    void ObjectCollection::Iterator::setEnd() {
        this->data->it._M_current = *(IGraphicsObject ***)(*((_QWORD *)this->owner + 2) + 24LL);
    }
}
