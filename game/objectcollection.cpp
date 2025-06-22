#include "objectcollection.h"
#include "../globject.h"

#include <cmath>

#include "../widgets/unitsgroup.h"
#include "dataCtrl/filestream.h"

#include "game/playler.h"

#include <QDebug>

#include "game/unitbehavior.h"
#include "game/warriorbehavior.h"
#include "ObjectCollection.h"
#include "ObjectCollection.h"
#include "ObjectCollection.h"
#include "ObjectCollection.h"
#include "ObjectCollection.h"
#include "ObjectCollection.h"
#include "ObjectCollection.h"
#include "ObjectCollection.h"
#include "ObjectCollection.h"
#include "ObjectCollection.h"
#include "ObjectCollection.h"
#include "ObjectCollection.h"
#include "ObjectCollection.h"
#include "ObjectCollection.h"
#include "ObjectCollection.h"
#include "ObjectCollection.h"
#include "ObjectCollection.h"
#include "ObjectCollection.h"
#include "ObjectCollection.h"
#include "ObjectCollection.h"
#include "ObjectCollection.h"
#include "ObjectCollection.h"
#include "ObjectCollection.h"
#include "ObjectCollection.h"
#include "ObjectCollection.h"
#include "ObjectCollection.h"
#include "ObjectCollection.h"
#include "ObjectCollection.h"
#include "ObjectCollection.h"
#include "ObjectCollection.h"
#include "ObjectCollection.h"
#include "ObjectCollection.h"
#include "ObjectCollection.h"
#include "ObjectCollection.h"
#include "ObjectCollection.h"
#include "ObjectCollection.h"
#include "ObjectCollection.h"
#include "ObjectCollection.h"
#include "ObjectCollection.h"
#include "ObjectCollection.h"
#include "ObjectCollection.h"
#include "ObjectCollection.h"
#include "ObjectCollection.h"
#include "ObjectCollection.h"
#include "ObjectCollection.h"
#include "ObjectCollection.h"

ObjectCollection::ObjectCollection(){
    m_isGroupControlled = 0;
    needToGuiUpdate     = 0;
    }

ObjectCollection::~ObjectCollection(){
		clear();
		}

void ObjectCollection::clear(){
		for(unsigned i=0u; i<object.size(); ++i)
			delete object[i];

    object. clear();
    mvUnits.clear();
    sunits. clear();
    m_interactive.clear();
    }

GLObject& ObjectCollection::operator [](int id){
    return *object[id];
    }

const GLObject& ObjectCollection::operator [](int id) const{
    return *object[id];
    }

void ObjectCollection::add(GLObject *a){
    object.push_back( a );

    if( a->getClass()->speed > 0 ){
      mvUnits.push_back( a );
      }

    if( !a->getClass()->isInvulnerable ){
      m_interactive.push_back(a);
      }
    }

int ObjectCollection::size() const{
    return object.size();
    }

void ObjectCollection::del( GLObject *& obj ){
    if( obj ){
      removeFrom(obj, object);
      removeFromSets(obj);

      delete obj;
      obj = 0;
      }

    }

void ObjectCollection::removeFromSets( GLObject *obj ){
    removeFrom(obj, sunits);
    UnitsGroup::removeUnit( obj );
    removeFrom(obj, mvUnits);
    removeFrom(obj, m_interactive);
    }

void ObjectCollection::removeFrom( GLObject *obj,
                                   std::vector<GLObject*>& units ){
    for(unsigned i=0; i<units.size(); ++i)
      if( units[i]==obj ){
        units[i] = units.back();
        units.pop_back();
        return;
        }
    }

const std::vector<GLObject*>& ObjectCollection::selected() const{
    return sunits;
    }

std::vector<GLObject*>& ObjectCollection::moviable(){
    return mvUnits;
    }

std::vector<GLObject*>& ObjectCollection::interactive(){
    return m_interactive;
    }

GLObject* ObjectCollection::unitAt( double x, double y ) const{
		GLObject* re = 0;

		enum{
			fNull,
			fBuildings,
			fUnits
			} filter = fNull;

		for(unsigned i=0; i<object.size(); ++i){
			if( object[i]->canSel(x,y) ){
				if( filter < fBuildings &&
						object[i]->getClass()->group=="building" ){
					filter = fBuildings;
					re = object[i];
					}

				if( //filter < fUnits &&
						object[i]->getClass()->group=="unit" ){
					filter = fUnits;
					re = object[i];
					}
				}
			}

		return re;
		}

void ObjectCollection::select( double x, double y){
		unSelect();

		enum{
			fNull,
			fBuildings,
			fUnits
			} filter = fNull;

		std::string tagetGroup;
		m_isGroupControlled = 0;

		for(unsigned i=0; i<object.size(); ++i){
			object[i]->computeSel( x, y );
			if( object[i]->isSel() ){
				sunits.push_back( object[i] );

				if( filter < fBuildings &&
						object[i]->getClass()->group=="building" ){
					filter = fBuildings;
					tagetGroup = "building";
					}

				if( //filter < fUnits &&
						object[i]->getClass()->group=="unit" ){
					filter = fUnits;
					tagetGroup = "unit";
					}

				if( object[i]->playlerPtr().isDrived() )
					m_isGroupControlled = 1;

				}
			}

		if( tagetGroup.size() ){
			unsigned nsize = 0;
			for(unsigned i=0; i<sunits.size(); ++i){
				if( sunits[i]->getClass()->group==tagetGroup &&
						 ( !m_isGroupControlled ||
							 sunits[i]->playlerPtr().isDrived() )){
					sunits[nsize] = sunits[i];
					++nsize;
					} else {
					sunits[i]->setSel(0);
					}
				}
			sunits.resize(nsize);
			}

    if( sunits.size() ){
      for(unsigned i=1; i<sunits.size(); ++i){
        sunits[i]->setSel(0);
        }
      sunits.resize(1);
      }

    //updateGUI();
    toGuiUpdate();
    }

void ObjectCollection::select( GLObject* obj){
    unSelect();
    sunits.push_back( obj );
    obj->setSel(1);

    m_isGroupControlled = obj->playlerPtr().isDrived();

    //updateGUI();
    toGuiUpdate();
    }

void ObjectCollection::select( QRectF r ){
		sunits.clear();

		enum{
			fNull,
			fBuildings,
			fUnits
			} filter = fNull;

		std::string tagetGroup;
		m_isGroupControlled = 0;

		for(unsigned i=0; i<object.size(); ++i){
			object[i]->computeSel( r.x(), r.y(), r.width(), r.height() );
			if( object[i]->isSel() ){
				sunits.push_back( object[i] );

				if( filter < fBuildings &&
						object[i]->getClass()->group=="building" ){
					filter = fBuildings;
					tagetGroup = "building";
					}

				if( //filter < fUnits &&
						object[i]->getClass()->group=="unit" ){
					filter = fUnits;
					tagetGroup = "unit";
					}

				if( object[i]->playlerPtr().isDrived() )
					m_isGroupControlled = 1;

				}
			}

		if( tagetGroup.size() ){
			unsigned nsize = 0;
			for(unsigned i=0; i<sunits.size(); ++i){
				if( sunits[i]->getClass()->group==tagetGroup &&
						 ( !m_isGroupControlled ||
							 sunits[i]->playlerPtr().isDrived() )){
					sunits[nsize] = sunits[i];
					++nsize;
					} else {
					sunits[i]->setSel(0);
					}
				}
			sunits.resize(nsize);
			}

    //updateGUI();
    toGuiUpdate();
    }

void ObjectCollection::aClick(float x, float y){
    command(x, y);

    for(size_t i=0; i<sunits.size(); ++i){
      GLObject *obj = sunits[i];
      {

        UnitBehavior *war = (UnitBehavior*)obj->getBehavior("unit");

        if( war ){
          war->getWarrior()->setAtack(1);
          war->getWarrior()->setAClick(1, x, y);
          }
        }
      }
    }

void ObjectCollection::command( GLObject * taget ){
		for(unsigned i=0; i<sunits.size(); ++i){
			sunits[i]->command( taget );
			}
		}

void ObjectCollection::coolMoveCommand(float x, float y){
		int sq = sqrt( sunits.size() );

		float dx = 0, dy = 0, ddy = 0;
		for(unsigned i=0; i<sunits.size(); ++i){
			if( Game::instance().map.existf( x+dx, y+dy ) ||
					Game::instance().map.resCountf( x+dx, y+dy )){
				sunits[i]->command(x+dx, y+dy, 0, 0 );
				dx += sunits[i]->viewSize();
				ddy = std::max(ddy, sunits[i]->viewSize());
				if( i%sq==0 ){
					dy += ddy;
					ddy = 0;
					dx = 0;
					}
				} else
				sunits[i]->command(x, y, 0, 0);
			}
		}

void ObjectCollection::command(float x, float y){
		if( !Game::instance().map.existf( x, y ) ){
			return;
			}

    if( sunits.size()<250  &&
        Game::instance().map.resCountf( x, y )==0 &&
        sunits.size() &&
        sunits[0]->getBehavior("building")==0 &&
        sunits[0]->getBehavior("incomplete_building")==0  ){
      coolMoveCommand(x, y);
      } else {
      int sq = sqrt( sunits.size() )*0.5;
      for(unsigned i=0; i<sunits.size(); ++i){
        sunits[i]->command(x, y, sq, 0);
        }
      }

    }

void ObjectCollection::toGuiUpdate(){
    needToGuiUpdate = 1;
    UnitsGroup::lock();
    }

void ObjectCollection::tick(){
    if( needToGuiUpdate )
      updateGUI();

		for(unsigned i=0; i<object.size(); ++i){
			object[i]->tick();
			}

		destroyDeathUnits();
		}

void ObjectCollection::unSelect(){
		for(unsigned i=0; i<sunits.size(); ++i){
			sunits[i]->setSel(0);
			}
		sunits.clear();

    m_isGroupControlled = 0;
    //updateGUI();
    toGuiUpdate();
    }

void ObjectCollection::updateGUI(){
    UnitsGroup::rebuildData();
    needToGuiUpdate = 0;
    }

void ObjectCollection::serialize(FileStream &f, bool map){
		int s = size();
		f.serialize(s);

		if( f.isIn() ){
			clear();
			}

		// qDebug() << s;
		// return;

		for(int i=0; i<s; ++i){
			if( f.isIn() ){
				std::string cls;
				f >> cls;
				Game::instance().add( cls );//->serialize(f);
				} else {
				f << object[i]->getClass()->name;
				//object[i]->serialize(f);
				}
			}

		if( map ){
			for(int i=0; i<size(); ++i)
				object[i]->serializeMap(f);
			} else {
			for(int i=0; i<size(); ++i)
				object[i]->serialize(f);
			}

		if( f.isIn() ){
			sunits.clear();
			m_isGroupControlled = 0;

			for(unsigned i=0; i<object.size(); ++i){
				if( object[i]->isSel() ){
					sunits.push_back( object[i]);
					m_isGroupControlled |= object[i]->playlerPtr().isDrived();
					}
				}

			updateGUI();
			}

		}

int ObjectCollection::find( const GLObject *obj){
		if( obj==0 )
			return -1;

		for(unsigned i=0; i<object.size(); ++i)
			if( object[i]==obj ){
				return i;
				}

		return -1;
		}


void ObjectCollection::sortPass(){
    for(int i=0; i<(int)object.size()-1; ++i){
      if( object[i]->gridNum() > object[i+1]->gridNum() )
        std::swap(object[i], object[i+1] );
      }
    }

bool ObjectCollection::isGroupControlled(){
    return m_isGroupControlled;
    }

void ObjectCollection::destroyDeathUnits(){
    bool recreateCtrl = 0;
    for(size_t i=0; i<object.size(); /*++i*/){
      if( object[i]->hp()<=0 ){
        if( selected().size() &&( selected()[0]==object[i]) )
          recreateCtrl = 1;

        removeFromSets( object[i] );

        GLObject* dObject = object[i];
        object[i] = object.back();
        object.pop_back();

        for(size_t r=0; r<object.size(); ++r)
          object[r]->deleteUnitEvent( dObject );

        dObject->deathEvent();
        delete dObject;
        } else {
        ++i;
        }
      }

    if( recreateCtrl )
      Game::instance().createController();

    }

inline MyGL::ObjectCollection::Iterator::Iterator(void* const c)
{
	MyGL::ObjectCollection::Iterator::pimpl* data;

	MyGL::IObjectCollection::IIterator::IIterator(this);
	data = (MyGL::ObjectCollection::Iterator::pimpl*)operator new(8uLL);
	data->it._M_current = 0LL;
	MyGL::ObjectCollection::Iterator::pimpl::pimpl(data);
	this->data = data;
	this->owner = c;
	MyGL::ObjectCollection::Iterator::setBegin(this);
}

inline MyGL::ObjectCollection::Iterator::~Iterator()
{
	delete this->data;
}

inline void MyGL::ObjectCollection::Iterator::dec()
{
	(*((void(__fastcall**)(MyGL::ObjectCollection::Iterator* const))this->_vptr_IIterator + 4))(this);
}

inline MyGL::IGraphicsObject* MyGL::ObjectCollection::Iterator::get()
{
	return *__gnu_cxx::__normal_iterator<MyGL::IGraphicsObject**, std::vector<MyGL::IGraphicsObject*>>::operator*((const __gnu_cxx::__normal_iterator<MyGL::IGraphicsObject**, std::vector<MyGL::IGraphicsObject*> > *const)this->data);
}

inline bool MyGL::ObjectCollection::Iterator::hasNext()
{
	return __gnu_cxx::operator!=<MyGL::IGraphicsObject**, std::vector<MyGL::IGraphicsObject*>>(
		(const __gnu_cxx::__normal_iterator<MyGL::IGraphicsObject**, std::vector<MyGL::IGraphicsObject*> > *const)this->data,
		(const __gnu_cxx::__normal_iterator<MyGL::IGraphicsObject**, std::vector<MyGL::IGraphicsObject*> > *const)(*((_QWORD*)this->owner + 2) + 24LL));
}

inline bool MyGL::ObjectCollection::Iterator::hasPrevious()
{
	return __gnu_cxx::operator!=<MyGL::IGraphicsObject**, std::vector<MyGL::IGraphicsObject*>>(
		(const __gnu_cxx::__normal_iterator<MyGL::IGraphicsObject**, std::vector<MyGL::IGraphicsObject*> > *const)this->data,
		(const __gnu_cxx::__normal_iterator<MyGL::IGraphicsObject**, std::vector<MyGL::IGraphicsObject*> > *const)(*((_QWORD*)this->owner + 2) + 32LL));
}

inline void MyGL::ObjectCollection::Iterator::inc()
{
	(*((void(__fastcall**)(MyGL::ObjectCollection::Iterator* const))this->_vptr_IIterator + 3))(this);
}

inline void MyGL::ObjectCollection::Iterator::operator++()
{
	__gnu_cxx::__normal_iterator<MyGL::IGraphicsObject**, std::vector<MyGL::IGraphicsObject*>>::operator++(
		&this->data->it,
		0);
}

inline void MyGL::ObjectCollection::Iterator::operator--()
{
	__gnu_cxx::__normal_iterator<MyGL::IGraphicsObject**, std::vector<MyGL::IGraphicsObject*>>::operator--(
		&this->data->it,
		0);
}

inline void MyGL::ObjectCollection::Iterator::setBegin()
{
	this->data->it._M_current = *(MyGL::IGraphicsObject***)(*((_QWORD*)this->owner + 2) + 32LL);
}

inline void MyGL::ObjectCollection::Iterator::setEnd()
{
	this->data->it._M_current = *(MyGL::IGraphicsObject***)(*((_QWORD*)this->owner + 2) + 24LL);
}

inline MyGL::ObjectCollection::Iterator::Iterator(void* const i)
{
	MyGL::ObjectCollection::Iterator::pimpl* data;

	MyGL::IObjectCollection::IIterator::IIterator(this);

	data = (MyGL::ObjectCollection::Iterator::pimpl*)operator new(8uLL);
	data->it._M_current = 0LL;
	MyGL::ObjectCollection::Iterator::pimpl::pimpl(data);
	this->data = data;
	this->owner = (void*)*((_QWORD*)i + 2);
	MyGL::ObjectCollection::Iterator::setBegin(this);
}

inline MyGL::ObjectCollection::ObjectCollection(MyGL::IScene* const s)
{
	MyGL::ObjectCollection::pimpl* data;
	this->scene = s;
	data = (MyGL::ObjectCollection::pimpl*)operator new(0x28uLL);
	data->items._M_impl._M_start = 0LL;
	data->items._M_impl._M_finish = 0LL;
	data->items._M_impl._M_end_of_storage = 0LL;
	data->endI._M_current = 0LL;
	data->beginI._M_current = 0LL;
	MyGL::ObjectCollection::pimpl::pimpl(data);
	this->data = data;
}

inline MyGL::ObjectCollection::~ObjectCollection()
{
	MyGL::ObjectCollection::pimpl* data;
	data = this->data;
	if (data)
	{
		MyGL::ObjectCollection::pimpl::~pimpl(this->data);
		operator delete(data);
	}
	MyGL::IObjectCollection::~IObjectCollection(this);
}

inline void MyGL::ObjectCollection::addObject(MyGL::IGraphicsObject& it)
{
	MyGL::IGraphicsObject* obj2;
	MyGL::IGraphicsObject* obj1;
	MyGL::IGraphicsObject** __b;
	MyGL::IGraphicsObject** __a;
	MyGL::ObjectCollection::pimpl* data;
	MyGL::ObjectCollection::pimpl* data_1;
	std::vector<MyGL::IGraphicsObject*>::value_type __x;
	bool mv;
	int i;

	if ((*((__int64(__fastcall**)(MyGL::IGraphicsObject* const))it->_vptr_IGraphicsObject + 3))(it))
	{
		__x = it;
		std::vector<MyGL::IGraphicsObject*>::push_back((std::vector<MyGL::IGraphicsObject*>_0* const)this->data, &__x);
		mv = 1;
		for (i = std::vector<MyGL::IGraphicsObject*>::size((const std::vector<MyGL::IGraphicsObject*>_0* const)this->data)
			- 1; i > 0; --i)
		{
			obj2 = *std::vector<MyGL::IGraphicsObject*>::operator[](
				(std::vector<MyGL::IGraphicsObject*>_0* const)this->data,
				i - 1);
			obj1 = *std::vector<MyGL::IGraphicsObject*>::operator[](
				(std::vector<MyGL::IGraphicsObject*>_0* const)this->data,
				i);
			mv = MyGL::ObjectCollection::less(this, obj1, obj2);
			if (mv)
			{
				__b = std::vector<MyGL::IGraphicsObject*>::operator[](
					(std::vector<MyGL::IGraphicsObject*>_0* const)this->data,
					i - 1);
				__a = std::vector<MyGL::IGraphicsObject*>::operator[](
					(std::vector<MyGL::IGraphicsObject*>_0* const)this->data,
					i);
				std::swap<MyGL::IGraphicsObject*>(__a, __b);
			}
		}
		data = this->data;
		data->endI._M_current = std::vector<MyGL::IGraphicsObject*>::end((std::vector<MyGL::IGraphicsObject*>_0* const)data)._M_current;
		data_1 = this->data;
		data_1->beginI._M_current = std::vector<MyGL::IGraphicsObject*>::begin((std::vector<MyGL::IGraphicsObject*>_0* const)data_1)._M_current;
	}
}

inline MyGL::IObjectCollection::IIterator* MyGL::ObjectCollection::begin(MyGL::ObjectCollection& c)
{
	MyGL::ObjectCollection::Iterator* v1;

	v1 = (MyGL::ObjectCollection::Iterator*)operator new(0x18uLL);
	MyGL::ObjectCollection::Iterator::Iterator(v1, c);
	return v1;
}

inline void MyGL::ObjectCollection::delObject(MyGL::IGraphicsObject& it)
{
	std::vector<MyGL::IGraphicsObject*>::reference v2;
	std::vector<MyGL::IGraphicsObject*>::reference v3;
	MyGL::ObjectCollection::pimpl* data;
	MyGL::ObjectCollection::pimpl* data_1;
	unsigned int i;
	bool mv;

	if (std::vector<MyGL::IGraphicsObject*>::size((const std::vector<MyGL::IGraphicsObject*>_0* const)this->data))
	{
		mv = 0;
		for (i = 0;
			i < std::vector<MyGL::IGraphicsObject*>::size((const std::vector<MyGL::IGraphicsObject*>_0* const)this->data)
			- 1;
			++i)
		{
			if (mv)
			{
				v2 = std::vector<MyGL::IGraphicsObject*>::operator[](
					(std::vector<MyGL::IGraphicsObject*>_0* const)this->data,
					i);
				*v2 = *std::vector<MyGL::IGraphicsObject*>::operator[](
					(std::vector<MyGL::IGraphicsObject*>_0* const)this->data,
					i + 1);
			}
			else if (*std::vector<MyGL::IGraphicsObject*>::operator[](
				(std::vector<MyGL::IGraphicsObject*>_0* const)this->data,
				i) == it)
			{
				mv = 1;
				v3 = std::vector<MyGL::IGraphicsObject*>::operator[](
					(std::vector<MyGL::IGraphicsObject*>_0* const)this->data,
					i);
				*v3 = *std::vector<MyGL::IGraphicsObject*>::operator[](
					(std::vector<MyGL::IGraphicsObject*>_0* const)this->data,
					i + 1);
			}
		}
		if (mv || *std::vector<MyGL::IGraphicsObject*>::back(&this->data->items) == it)
			std::vector<MyGL::IGraphicsObject*>::pop_back(&this->data->items);
		data = this->data;
		data->endI._M_current = std::vector<MyGL::IGraphicsObject*>::end((std::vector<MyGL::IGraphicsObject*>_0* const)data)._M_current;
		data_1 = this->data;
		data_1->beginI._M_current = std::vector<MyGL::IGraphicsObject*>::begin((std::vector<MyGL::IGraphicsObject*>_0* const)data_1)._M_current;
	}
}

inline MyGL::IObjectCollection::IIterator* MyGL::ObjectCollection::end(MyGL::ObjectCollection& c)
{
	MyGL::ObjectCollection::Iterator* v1;

	v1 = (MyGL::ObjectCollection::Iterator*)operator new(0x18uLL);
	MyGL::ObjectCollection::Iterator::Iterator(v1, c);
	(*((void(__fastcall**)(MyGL::ObjectCollection::Iterator*))v1->_vptr_IIterator + 10))(v1);
	return v1;
}

inline bool MyGL::ObjectCollection::less(MyGL::IGraphicsObject* obj1, MyGL::IGraphicsObject* obj2)
{
	__int64 v4;
	unsigned __int8(__fastcall * v5)(__int64, __int64);
	__int64 v6;
	__int64 v7;
	unsigned __int8(__fastcall * v8)(__int64, __int64);
	__int64 v9;
	unsigned __int64 v10;

	if (!(*((__int64(__fastcall**)(MyGL::IGraphicsObject*))obj1->_vptr_IGraphicsObject + 3))(obj1))
		return 0;
	if (!(*((__int64(__fastcall**)(MyGL::IGraphicsObject*))obj2->_vptr_IGraphicsObject + 3))(obj2))
		return 1;
	v4 = (*((__int64(__fastcall**)(MyGL::IGraphicsObject*))obj1->_vptr_IGraphicsObject + 3))(obj1);
	v5 = *(unsigned __int8(__fastcall**)(__int64, __int64))(*(_QWORD*)v4 + 56LL);
	v6 = (*((__int64(__fastcall**)(MyGL::IGraphicsObject*))obj2->_vptr_IGraphicsObject + 3))(obj2);
	if (v5(v4, v6))
		return 1;
	v7 = (*((__int64(__fastcall**)(MyGL::IGraphicsObject*))obj2->_vptr_IGraphicsObject + 3))(obj2);
	v8 = *(unsigned __int8(__fastcall**)(__int64, __int64))(*(_QWORD*)v7 + 56LL);
	v9 = (*((__int64(__fastcall**)(MyGL::IGraphicsObject*))obj1->_vptr_IGraphicsObject + 3))(obj1);
	if (v8(v7, v9))
		return 0;
	v10 = (*((__int64(__fastcall**)(MyGL::IGraphicsObject*))obj1->_vptr_IGraphicsObject + 7))(obj1);
	return v10 < (*((__int64(__fastcall**)(MyGL::IGraphicsObject*))obj2->_vptr_IGraphicsObject + 7))(obj2);
}

inline void MyGL::ObjectCollection::onChangeMaterialObject(MyGL::IGraphicsObject& obj, MyGL::IMaterial* const a3)
{
	(*((void(__fastcall**)(MyGL::ObjectCollection* const, MyGL::IGraphicsObject* const))this->_vptr_IObjectCollection + 3))(
		this,
		obj);
	(*((void(__fastcall**)(MyGL::ObjectCollection* const, MyGL::IGraphicsObject* const))this->_vptr_IObjectCollection + 2))(
		this,
		obj);
}

inline MyGL::IGraphicsObject* MyGL::ObjectCollection::operator[](size_t i)
{
	return *std::vector<MyGL::IGraphicsObject*>::operator[]((std::vector<MyGL::IGraphicsObject*>_0* const)this->data, i);
}

inline void MyGL::ObjectCollection::refresh()
{
	;
}

inline size_t MyGL::ObjectCollection::size()
{
	return std::vector<MyGL::IGraphicsObject*>::size((const std::vector<MyGL::IGraphicsObject*>_0* const)this->data);
}
