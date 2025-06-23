#include "LightsCollection.h"
namespace MyGL {
	LightsCollection::LightsCollection(IScene& s)
	{
		LightsCollection::pimpl* data;
		this->mscene = s;
		data = (LightsCollection::pimpl*)operator new(0x18uLL);
		data->lights._M_impl._M_start = 0LL;
		data->lights._M_impl._M_finish = 0LL;
		data->lights._M_impl._M_end_of_storage = 0LL;
		LightsCollection::pimpl::pimpl(data);
		this->data = data;
	}

	LightsCollection::~LightsCollection()
	{
		ILight* v1;
		LightsCollection::pimpl* data;
		LightsCollection::pimpl::size_type i


			for (i = 0LL; std::vector<ILight*>::size(&this->data->lights) > i; ++i)
			{
				v1 = *std::vector<ILight*>::operator[](&this->data->lights, i);
				if (v1)
					(*((void(__fastcall**)(ILight*))v1->_vptr_ILight + 1))(v1);
			}
		data = this->data;
		if (data)
		{
			LightsCollection::pimpl::~pimpl(this->data);
			operator delete(data);
		}
		ILightsCollection::~ILightsCollection(this);
	}

	void LightsCollection::add(ILight& l)
	{
		std::vector<ILight*>::value_type __x;

		__x = l;
		std::vector<ILight*>::push_back(&this->data->lights, &__x);
	}

	void LightsCollection::del(ILight& l)
	{
		std::vector<ILight*>::reference v2;
		LightsCollection::pimpl::size_type i;

		for (i = 0LL; std::vector<ILight*>::size(&this->data->lights) > i; ++i)
		{
			if (*std::vector<ILight*>::operator[](&this->data->lights, i) == l)
			{
				v2 = std::vector<ILight*>::operator[](&this->data->lights, i);
				*v2 = *std::vector<ILight*>::back(&this->data->lights);
				std::vector<ILight*>::pop_back(&this->data->lights);
				if (l)
					(*((void(__fastcall**)(ILight* const))l->_vptr_ILight + 1))(l);
				return;
			}
		}
	}

	void LightsCollection::remove(ILight& l)
	{
		std::vector<ILight*>::reference v2;
		LightsCollection::pimpl::size_type i;

		for (i = 0LL; std::vector<ILight*>::size(&this->data->lights) > i; ++i)
		{
			if (*std::vector<ILight*>::operator[](&this->data->lights, i) == l)
			{
				v2 = std::vector<ILight*>::operator[](&this->data->lights, i);
				*v2 = *std::vector<ILight*>::back(&this->data->lights);
				std::vector<ILight*>::pop_back(&this->data->lights);
				return;
			}
		}
	}

	IScene* LightsCollection::scene()
	{
		return this->mscene;
	}

	int LightsCollection::size()
	{
		return this->data->lights.size();
	}

	ILight* LightsCollection::at(unsigned int id)
	{
		return this->data->lights.at(id);
	}
}