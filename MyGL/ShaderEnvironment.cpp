#include "ShaderEnvironment.h"

MyGL::ShaderEnvironment::pimpl::def::def(const pimpl::def& a2) {
	this->str = a2.str;
	this->count = a2.count;
}

MyGL::ShaderEnvironment::pimpl* MyGL::ShaderEnvironment::pimpl::operator=(const pimpl& a2)
{
	this->src = a2.src;
	this->map = a2.map;
	return this;
}

MyGL::ShaderEnvironment::ShaderEnvironment(const ShaderEnvironment& other)
{
	operator=(this, other);
}

MyGL::ShaderEnvironment::ShaderEnvironment()
{
	__int64 data;
	data = operator new(0x38uLL);
	*(_QWORD*)data = 0LL;
	*(_DWORD*)(data + 16) = 0;
	*(_QWORD*)(data + 24) = 0LL;
	*(_QWORD*)(data + 32) = 0LL;
	*(_QWORD*)(data + 40) = 0LL;
	*(_QWORD*)(data + 48) = 0LL;
	MyGL::ShaderEnvironment::pimpl::pimpl((MyGL::ShaderEnvironment::pimpl* const)data);
	this->data = (MyGL::ShaderEnvironment::pimpl*)data;
	this->needToUpdate = 1;
}

MyGL::ShaderEnvironment::~ShaderEnvironment()
{
	if (this->data) {
		delete this->data;
	}
}

const std::string* MyGL::ShaderEnvironment::getPrecompileSource()
{
	std::map<std::string, MyGL::ShaderEnvironment::pimpl::def>::iterator i;
	std::_Rb_tree_iterator<std::pair<const std::string, MyGL::ShaderEnvironment::pimpl::def> >::_Self __x;
	std::string __lhs__1;
	std::string __lhs_;
	std::string __rhs;
	std::string __lhs[4];

	if (this->needToUpdate)
	{
		std::string::operator=(this->data, "
			std::_Rb_tree_iterator<std::pair<std::string const, MyGL::ShaderEnvironment::pimpl::def>>::_Rb_tree_iterator(&i);
		for (i._M_node = std::map<std::string, MyGL::ShaderEnvironment::pimpl::def>::begin(&this->data->map)._M_node;
			;
			std::_Rb_tree_iterator<std::pair<std::string const, MyGL::ShaderEnvironment::pimpl::def>>::operator++(&i))
		{
			__x._M_node = std::map<std::string, MyGL::ShaderEnvironment::pimpl::def>::end(&this->data->map)._M_node;
			if (!std::_Rb_tree_iterator<std::pair<std::string const, MyGL::ShaderEnvironment::pimpl::def>>::operator!=(
				&i,
				&__x))
				break;
			std::_Rb_tree_iterator<std::pair<std::string const, MyGL::ShaderEnvironment::pimpl::def>>::operator*(&i);
			std::_Rb_tree_iterator<std::pair<std::string const, MyGL::ShaderEnvironment::pimpl::def>>::operator*(&i);
			std::operator+<char>((const char*)__lhs, &_rhs__0);
			std::operator+<char>(&__rhs, (const char*)__lhs);
			std::operator+<char>(&__lhs_, &__rhs);
			std::operator+<char>(&__lhs__1, (const char*)&__lhs_);
			std::string::operator+=(this->data, &__lhs__1);
			std::string::~string(&__lhs__1);
			std::string::~string(&__lhs_);
			std::string::~string(&__rhs);
			std::string::~string(__lhs);
		}
		std::string::operator+=(this->data, "
			std::string::operator+=(this->data, "\n#line 0\n");
		this->needToUpdate = 0;
	}
	return &this->data->src;
}

MyGL::IShaderEnvironment* MyGL::ShaderEnvironment::operator<<(const std::string& def)
{
	__int64(__fastcall * v2)(MyGL::ShaderEnvironment* const, const std::string* const, std::string*);
	MyGL::IShaderEnvironment* v3;
	std::string v5;
	_BYTE v6[17];

	v2 = (__int64(__fastcall*)(MyGL::ShaderEnvironment* const, const std::string* const, std::string*)) * ((_QWORD*)this->_vptr_IShaderEnvironment + 5);
	std::allocator<char>::allocator(v6);
	std::string::string(&v5, &unk_4D2E74, v6);
	v3 = (MyGL::IShaderEnvironment*)v2(this, def, &v5);
	std::string::~string(&v5);
	std::allocator<char>::~allocator(v6);
	return v3;
}

MyGL::ShaderEnvironment* MyGL::ShaderEnvironment::operator=(const MyGL::ShaderEnvironment& other)
{
	MyGL::ShaderEnvironment::pimpl::operator=(this->data, *((const MyGL::ShaderEnvironment::pimpl* const*)other + 2));
	this->needToUpdate = 1;
	return this;
}

MyGL::IShaderEnvironment* MyGL::ShaderEnvironment::operator>>(const std::string& def)
{
	return (MyGL::IShaderEnvironment*)(*((__int64(__fastcall**)(MyGL::ShaderEnvironment* const, const std::string* const))this->_vptr_IShaderEnvironment
		+ 6))(
			this,
			def);
}

MyGL::IShaderEnvironment* MyGL::ShaderEnvironment::pop(const std::string& name)
{
	std::_Rb_tree_iterator<std::pair<const std::string, MyGL::ShaderEnvironment::pimpl::def> >::pointer v2;
	std::map<std::string, MyGL::ShaderEnvironment::pimpl::def>::iterator i;
	std::_Rb_tree_iterator<std::pair<const std::string, MyGL::ShaderEnvironment::pimpl::def> >::_Self __x;

	if (std::string::size((std::string*)name))
	{
		i._M_node = std::map<std::string, MyGL::ShaderEnvironment::pimpl::def>::find(&this->data->map, name)._M_node;
		__x._M_node = std::map<std::string, MyGL::ShaderEnvironment::pimpl::def>::end(&this->data->map)._M_node;
		if (std::_Rb_tree_iterator<std::pair<std::string const, MyGL::ShaderEnvironment::pimpl::def>>::operator!=(&i, &__x))
		{
			v2 = std::_Rb_tree_iterator<std::pair<std::string const, MyGL::ShaderEnvironment::pimpl::def>>::operator->(&i);
			--v2->second.count;
			if (!std::_Rb_tree_iterator<std::pair<std::string const, MyGL::ShaderEnvironment::pimpl::def>>::operator->(&i)->second.count)
				std::map<std::string, MyGL::ShaderEnvironment::pimpl::def>::erase(&this->data->map, name);
		}
	}
	this->needToUpdate = 1;
	return this;
}

MyGL::IShaderEnvironment* MyGL::ShaderEnvironment::push(const std::string& name, const std::string& def)
{
	MyGL::ShaderEnvironment::pimpl::def* p_second;
	std::_Rb_tree_iterator<std::pair<const std::string, MyGL::ShaderEnvironment::pimpl::def> >::pointer v5;
	std::map<std::string, MyGL::ShaderEnvironment::pimpl::def>::mapped_type* v6;
	std::map<std::string, MyGL::ShaderEnvironment::pimpl::def>::iterator i;
	std::_Rb_tree_iterator<std::pair<const std::string, MyGL::ShaderEnvironment::pimpl::def> >::_Self __x;

	if (std::string::size((std::string*)name))
	{
		i._M_node = std::map<std::string, MyGL::ShaderEnvironment::pimpl::def>::find(&this->data->map, name)._M_node;
		__x._M_node = std::map<std::string, MyGL::ShaderEnvironment::pimpl::def>::end(&this->data->map)._M_node;
		if (std::_Rb_tree_iterator<std::pair<std::string const, MyGL::ShaderEnvironment::pimpl::def>>::operator!=(&i, &__x)
			&& (p_second = &std::_Rb_tree_iterator<std::pair<std::string const, MyGL::ShaderEnvironment::pimpl::def>>::operator->(&i)->second,
				std::operator==<char>(&p_second->str, def)))
		{
			v5 = std::_Rb_tree_iterator<std::pair<std::string const, MyGL::ShaderEnvironment::pimpl::def>>::operator->(&i);
			++v5->second.count;
		}
		else
		{
			v6 = std::map<std::string, MyGL::ShaderEnvironment::pimpl::def>::operator[](&this->data->map, name);
			std::string::operator=(v6, def);
			std::map<std::string, MyGL::ShaderEnvironment::pimpl::def>::operator[](&this->data->map, name)->count = 1;
			this->needToUpdate = 1;
		}
	}
	return this;
}
