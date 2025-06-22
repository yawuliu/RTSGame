#include "Filter.h"
#include "IUniformSampler.h"
#include "IShader.h"


MyGL::Filter::Filter(MyGL::IScene& s) : AbstractPass(s) {
	this->data = new MyGL::Filter::Data::Data();
	this->data->renderState->setZTest(0);
	this->data->renderState->etZWriting(0);
	this->data->quad = 0LL;
	this->data->shader = 0LL;
}

MyGL::Filter::~Filter() {
	if (this->data) {
		delete this->data;
	}
}

MyGL::IUniformSampler* MyGL::Filter::addArgs(MyGL::IUniformSampler* sm, MyGL::ITexture* u) {
	void(__fastcall * v3)(MyGL::IUniformSampler*, _QWORD);
	unsigned int v4;
	MyGL::IScene* v6;
	__int64 v7;
	MyGL::CGL* v8;
	MyGL::IErrorControl* v9;
	MyGL::IUniformSampler* sma;
	MyGL::Filter* thisa;
	std::map<MyGL::IUniformSampler*, MyGL::ITexture*>::iterator i;
	std::_Rb_tree_iterator<std::pair<MyGL::IUniformSampler* const, MyGL::ITexture*> >::_Self __x;
	sma = sm;
	if (this->data->shader) {
		i._M_node = std::map<MyGL::IUniformSampler*, MyGL::ITexture*>::find(&thisa->data->args, &sma)._M_node;
		if (sma) {
			__x._M_node = std::map<MyGL::IUniformSampler*, MyGL::ITexture*>::end(&thisa->data->args)._M_node;
			if (std::_Rb_tree_iterator<std::pair<MyGL::IUniformSampler* const, MyGL::ITexture*>>::operator==(
				&i, &__x)) {
				v3 = (void(__fastcall*)(MyGL::IUniformSampler*, _QWORD)) * ((_QWORD*)sma->_vptr_IUniform +
					6);
				v4 = std::map<MyGL::IUniformSampler*, MyGL::ITexture*>::size(&thisa->data->args);
				v3(sma, v4);
			}
			*std::map<MyGL::IUniformSampler*, MyGL::ITexture*>::operator[](&thisa->data->args, &sma) = u;
		}
		return sma;
	}
	else {
		v6 = MyGL::AbstractPass::scene(thisa);
		v7 = (*((__int64(__fastcall**)(MyGL::IScene*)) v6->_vptr_IScene + 3))(v6);
		v8 = (MyGL::CGL*)(*(__int64(__fastcall**)(__int64)) (*(_QWORD*)v7 + 72LL))(v7);
		v9 = MyGL::CGL::errorCtrl(v8);
		(*((void(__fastcall**)(MyGL::IErrorControl*, _QWORD, const char*)) v9->_vptr_IErrorControl + 4))(
			v9,
			0LL,
			"[Filter::addArgs]null shader");
		return 0LL;
	}
}

MyGL::IUniformSampler* MyGL::Filter::addArgs(const std::string& const name, MyGL::ITexture* u) {
	__int64(__fastcall * v3)(MyGL::IShader*, __int64);
	__int64 v4;
	MyGL::IUniformSampler* sm;
	MyGL::IScene* v7;
	__int64 v8;
	MyGL::CGL* v9;
	MyGL::IErrorControl* v10;

	if (thisa->data->shader) {
		v3 = (__int64(__fastcall*)(MyGL::IShader*, __int64)) * (
			(_QWORD*)thisa->data->shader->_vptr_IShader + 17);
		v4 = std::string::data((std::string*)name);
		sm = (MyGL::IUniformSampler*)v3(thisa->data->shader, v4);
		return MyGL::Filter::addArgs(thisa, sm, u);
	}
	else {
		v7 = MyGL::AbstractPass::scene(thisa);
		v8 = (*((__int64(__fastcall**)(MyGL::IScene*)) v7->_vptr_IScene + 3))(v7);
		v9 = (MyGL::CGL*)(*(__int64(__fastcall**)(__int64)) (*(_QWORD*)v8 + 72LL))(v8);
		v10 = MyGL::CGL::errorCtrl(v9);
		(*((void(__fastcall**)(MyGL::IErrorControl*, _QWORD, const char*)) v10->_vptr_IErrorControl + 4))(
			v10,
			0LL,
			"[Filter::addArgs]null shader");
		return 0LL;
	}
}

void MyGL::Filter::exec() {
	MyGL::IScene* v1;
	__int64 v2;
	MyGL::CGL* v3;
	MyGL::IErrorControl* v4;
	MyGL::IScene* v5;
	__int64 v6;
	MyGL::IScene* v7;
	__int64 v8;
	MyGL::IScene* v9;
	__int64 v10;
	MyGL::IScene* v11;
	__int64 v12;
	void(__fastcall * v13)(__int64, MyGL::IUniformSampler* const, MyGL::ITexture*);
	MyGL::ITexture* second;
	std::_Rb_tree_iterator<std::pair<MyGL::IUniformSampler* const, MyGL::ITexture*> >::pointer v15;
	MyGL::IScene* v16;
	__int64 v17;
	MyGL::IScene* v18;
	__int64 v19;
	std::map<MyGL::IUniformSampler*, MyGL::ITexture*>::iterator i;
	std::_Rb_tree_iterator<std::pair<MyGL::IUniformSampler* const, MyGL::ITexture*> >::_Self __x;

	if (this->data->shader && this->data->quad && this->data->shader) {
		v5 = MyGL::AbstractPass::scene(this);
		v6 = (*((__int64(__fastcall**)(MyGL::IScene*)) v5->_vptr_IScene + 3))(v5);
		(*(void(__fastcall**)(__int64, MyGL::Filter::Data*)) (*(_QWORD*)v6 + 272LL))(v6, this->data);
		v7 = MyGL::AbstractPass::scene(this);
		v8 = (*((__int64(__fastcall**)(MyGL::IScene*)) v7->_vptr_IScene + 3))(v7);
		(*(void(__fastcall**)(__int64)) (*(_QWORD*)v8 + 296LL))(v8);
		v9 = MyGL::AbstractPass::scene(this);
		v10 = (*((__int64(__fastcall**)(MyGL::IScene*)) v9->_vptr_IScene + 3))(v9);
		(*(void(__fastcall**)(__int64, MyGL::IShader*)) (*(_QWORD*)v10 + 104LL))(v10, this->data->shader);
		for (i._M_node = std::map<MyGL::IUniformSampler*, MyGL::ITexture*>::begin(&this->data->args)._M_node;;
			std::_Rb_tree_iterator<std::pair<MyGL::IUniformSampler* const, MyGL::ITexture*>>::operator++(
				&i)) {
			__x._M_node = std::map<MyGL::IUniformSampler*, MyGL::ITexture*>::end(&this->data->args)._M_node;
			if (!std::_Rb_tree_iterator<std::pair<MyGL::IUniformSampler* const, MyGL::ITexture*>>::operator!=(
				&i, &__x))
				break;
			v11 = MyGL::AbstractPass::scene(this);
			v12 = (*((__int64(__fastcall**)(MyGL::IScene*)) v11->_vptr_IScene + 3))(v11);
			v13 = *(void(__fastcall**)(__int64, MyGL::IUniformSampler* const, MyGL::ITexture*)) (
				*(_QWORD*)v12 + 128LL);
			second = std::_Rb_tree_iterator<std::pair<MyGL::IUniformSampler* const, MyGL::ITexture*>>::operator->(
				&i)->second;
			v15 = std::_Rb_tree_iterator<std::pair<MyGL::IUniformSampler* const, MyGL::ITexture*>>::operator->(
				&i);
			v13(v12, v15->first, second);
		}
		v16 = MyGL::AbstractPass::scene(this);
		v17 = (*((__int64(__fastcall**)(MyGL::IScene*)) v16->_vptr_IScene + 3))(v16);
		(*(void(__fastcall**)(__int64, MyGL::IModel*)) (*(_QWORD*)v17 + 192LL))(v17, this->data->quad);
		v18 = MyGL::AbstractPass::scene(this);
		v19 = (*((__int64(__fastcall**)(MyGL::IScene*)) v18->_vptr_IScene + 3))(v18);
		(*(void(__fastcall**)(__int64)) (*(_QWORD*)v19 + 312LL))(v19);
	}
	else {
		v1 = MyGL::AbstractPass::scene(this);
		v2 = (*((__int64(__fastcall**)(MyGL::IScene*)) v1->_vptr_IScene + 3))(v1);
		v3 = (MyGL::CGL*)(*(__int64(__fastcall**)(__int64)) (*(_QWORD*)v2 + 72LL))(v2);
		v4 = MyGL::CGL::errorCtrl(v3);
		(*((void(__fastcall**)(MyGL::IErrorControl*, _QWORD, const char*)) v4->_vptr_IErrorControl + 4))(
			v4,
			0LL,
			"Filter is incomplete");
	}
}

MyGL::IModel* MyGL::Filter::quadModel() {
	return this->data->quad;
}

MyGL::IRenderState* MyGL::Filter::renderState() {
	return this->data->renderState;
}

MyGL::IUniformSampler* MyGL::Filter::setInput(MyGL::IUniformSampler* name, MyGL::ITexture* arg) {
	return this->addArgs(name, arg);
}

MyGL::IUniformSampler* MyGL::Filter::setInput(const std::string& const name, MyGL::ITexture* arg) {
	return this->addArgs(name, arg);
}

void MyGL::Filter::setQuadModel(MyGL::IModel* m) {
	this->data->quad = m;
}

void MyGL::Filter::setShader(MyGL::IShader* s) {
	this->data->shader = s;
	this->data->args.clear();
}

MyGL::IShader* MyGL::Filter::shader() {
	return this->data->shader;
}

MyGL::IRenderPass::Pass::Type MyGL::Filter::type() {
	return 0;
}
