#include "ShaderEnvironment.h"
namespace MyGL {
	ShaderEnvironment::pimpl::def::def(const pimpl::def& a2) {
		this->str = a2.str;
		this->count = a2.count;
	}

	ShaderEnvironment::pimpl& ShaderEnvironment::pimpl::operator=(const pimpl& a2)
	{
		this->src = a2.src;
		this->map = a2.map;
		return *this;
	}

	ShaderEnvironment::ShaderEnvironment(const ShaderEnvironment& other)
	{
        *this = other;
	}

	ShaderEnvironment::ShaderEnvironment()
	{
		this->data = new pimpl();
		this->needToUpdate = 1;
	}

	ShaderEnvironment::~ShaderEnvironment()
	{
		if (this->data) {
			delete this->data;
		}
	}

	const std::string& ShaderEnvironment::getPrecompileSource()
	{
		if (this->needToUpdate)
		{
            this->data = i;
			for (i._M_node = std::map<std::string, ShaderEnvironment::pimpl::def>::begin(&this->data->map)._M_node;
				;
				std::_Rb_tree_iterator<std::pair<std::string const, ShaderEnvironment::pimpl::def>>::operator++(&i))
			{
				__x._M_node = std::map<std::string, ShaderEnvironment::pimpl::def>::end(&this->data->map)._M_node;
				if (!std::_Rb_tree_iterator<std::pair<std::string const, ShaderEnvironment::pimpl::def>>::operator!=(
					&i,
					&__x))
					break;
				std::_Rb_tree_iterator<std::pair<std::string const, ShaderEnvironment::pimpl::def>>::operator*(&i);
				std::_Rb_tree_iterator<std::pair<std::string const, ShaderEnvironment::pimpl::def>>::operator*(&i);
				std::operator+<char>((const char*)__lhs, &_rhs__0);
				std::operator+<char>(&__rhs, (const char*)__lhs);
				std::operator+<char>(&__lhs_, &__rhs);
				std::operator+<char>(&__lhs__1, (const char*)&__lhs_);
				std::string::operator+=(this->data, &__lhs__1);
			}
			std::string::operator+=(this->data, "
				std::string::operator+=(this->data, "\n#line 0\n");
			this->needToUpdate = 0;
		}
		return &this->data->src;
	}

	IShaderEnvironment* ShaderEnvironment::operator<<(const std::string& def)
	{
		return this->push( def, unk_4D2E74);
	}

    ShaderEnvironment& ShaderEnvironment::operator=(const IShaderEnvironment& other)
	{
        this->data =  other.data;
		this->needToUpdate = 1;
		return *this;
	}

	IShaderEnvironment* ShaderEnvironment::operator>>(const std::string& def)
	{
		return this->pop(def);
	}

	IShaderEnvironment* ShaderEnvironment::pop(const std::string& name)
	{
		if (name.size())
		{
			i._M_node = std::map<std::string, ShaderEnvironment::pimpl::def>::find(&this->data->map, name)._M_node;
			__x._M_node = std::map<std::string, ShaderEnvironment::pimpl::def>::end(&this->data->map)._M_node;
			if (std::_Rb_tree_iterator<std::pair<std::string const, ShaderEnvironment::pimpl::def>>::operator!=(&i, &__x))
			{
				v2 = std::_Rb_tree_iterator<std::pair<std::string const, ShaderEnvironment::pimpl::def>>::operator->(&i);
				--v2->second.count;
				if (!std::_Rb_tree_iterator<std::pair<std::string const, ShaderEnvironment::pimpl::def>>::operator->(&i)->second.count)
					std::map<std::string, ShaderEnvironment::pimpl::def>::erase(&this->data->map, name);
			}
		}
		this->needToUpdate = 1;
		return this;
	}

	IShaderEnvironment* ShaderEnvironment::push(const std::string& name, const std::string& def)
	{
		if (name.size())
		{
			i = this->data->map.find(name);
			__x._M_node = this->data->map.end();
			if (i != __x
				&& (p_second = &i->second,
                    p_second->str==def))
			{
				v5 = i;
				++v5->second.count;
			}
			else
			{
                this->data->map[name] = def;
                this->data->map[name].count = 1;
				this->needToUpdate = 1;
			}
		}
		return this;
	}
}

