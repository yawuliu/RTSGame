#include "SSAOpass.h"

MyGL::SSAOpass::Data::Data(MyGL::IScene& s) :ssao(s) {}

MyGL::SSAOpass::SSAOpass(MyGL::IScene& s, const MyGL::Adapter* const adapter, MyGL::MainPass* mp) : AbstractPass(s)
{
	MyGL::IScene* s_1;
	MyGL::SSAOpass::Data* data;
	MyGL::IShader* s_2;
	MyGL::IModel* m;
	MyGL::ITexture* arg;
	MyGL::ITextureRectangle* arg_1;
	MyGL::ITexture* arg_2;
	MyGL::IRenderState* v11;
	MyGL::IRenderState* v12;
	MyGL::IScene* v13;
	MyGL::IRender* r;
	MyGL::TextureRectangle* out;
	MyGL::IScene* v16;
	MyGL::IRender* r_1;
	MyGL::TextureRectangle* depth;
	std::string name;
	char v22;
	std::string name_;
	char v24;
	std::string name__1;
	_BYTE v26[17];

	s_1 = MyGL::AbstractPass::scene(__x_);
	data = (MyGL::SSAOpass::Data*)operator new(0x18uLL);
	MyGL::SSAOpass::Data::Data(data, s_1);
	__x_->data = data;
	s_2 = (MyGL::IShader*)(*((__int64(__fastcall**)(const MyGL::Adapter* const))adapter->_vptr_Adapter + 5))(adapter);
	MyGL::Filter::setShader(&__x_->data->ssao, s_2);
	m = MyGL::MainPass::quadModel(mp);
	MyGL::Filter::setQuadModel(&__x_->data->ssao, m);
	arg = (MyGL::ITexture*)(*((__int64(__fastcall**)(MyGL::MainPass*))mp->_vptr_IRenderPass + 4))(mp);
	std::allocator<char>::allocator(&v22);
	std::string::string(&name, "mainPass", &v22);
	MyGL::Filter::setInput(&__x_->data->ssao, &name, arg);
	std::string::~string(&name);
	std::allocator<char>::~allocator(&v22);
	arg_1 = MyGL::MainPass::depthBuffer(mp);
	std::allocator<char>::allocator(&v24);
	std::string::string(&name_, "depthBuffer", &v24);
	MyGL::Filter::setInput(&__x_->data->ssao, &name_, arg_1);
	std::string::~string(&name_);
	std::allocator<char>::~allocator(&v24);
	arg_2 = (MyGL::ITexture*)(*((__int64(__fastcall**)(const MyGL::Adapter* const))adapter->_vptr_Adapter + 6))(adapter);
	std::allocator<char>::allocator(v26);
	std::string::string(&name__1, "rand4x4", v26);
	MyGL::Filter::setInput(&__x_->data->ssao, &name__1, arg_2);
	std::string::~string(&name__1);
	std::allocator<char>::~allocator(v26);
	v11 = MyGL::Filter::renderState(&__x_->data->ssao);
	(*((void(__fastcall**)(MyGL::IRenderState*, __int64))v11->_vptr_IRenderState + 18))(v11, 1LL);
	v12 = MyGL::Filter::renderState(&__x_->data->ssao);
	(*((void(__fastcall**)(MyGL::IRenderState*, __int64, _QWORD))v12->_vptr_IRenderState + 24))(v12, 8LL, 0LL);
	v13 = MyGL::AbstractPass::scene(__x_);
	r = (MyGL::IRender*)(*((__int64(__fastcall**)(MyGL::IScene*))v13->_vptr_IScene + 3))(v13);
	out = (MyGL::TextureRectangle*)operator new(0x28uLL);
	MyGL::TextureRectangle::TextureRectangle(out, r);
	__x_->out = out;
	v16 = MyGL::AbstractPass::scene(__x_);
	r_1 = (MyGL::IRender*)(*((__int64(__fastcall**)(MyGL::IScene*))v16->_vptr_IScene + 3))(v16);
	depth = (MyGL::TextureRectangle*)operator new(0x28uLL);
	MyGL::TextureRectangle::TextureRectangle(depth, r_1);
	__x_->depth = depth;
	__x_->mpass = mp;
	__x_->active = 1;
}

MyGL::SSAOpass::~SSAOpass()
{
	MyGL::SSAOpass::Data* data;


	data = this->data;
	if (data)
	{
		MyGL::SSAOpass::Data::~Data(this->data);
		operator delete(data);
	}
	if (this->out)
		(*((void(__fastcall**)(MyGL::ITextureRectangle*))this->out->_vptr_ITexture + 1))(this->out);
	if (this->depth)
		(*((void(__fastcall**)(MyGL::ITextureRectangle*))this->depth->_vptr_ITexture + 1))(this->depth);
}

void MyGL::SSAOpass::exec()
{
	MyGL::FBO* v1;
	MyGL::FBO* v2;
	void(__fastcall * v3)(MyGL::FBO*, MyGL::ITextureRectangle*);
	MyGL::ITextureRectangle* v4;

	if (this->active)
	{
		MyGL::SSAOpass::resizeFrame(this);
		v1 = MyGL::MainPass::frameBuffer(this->mpass);
		(*((void(__fastcall**)(MyGL::FBO*, MyGL::ITextureRectangle*))v1->_vptr_IFBO + 13))(v1, this->depth);
		MyGL::Filter::exec(&this->data->ssao);
		v2 = MyGL::MainPass::frameBuffer(this->mpass);
		v3 = (void(__fastcall*)(MyGL::FBO*, MyGL::ITextureRectangle*)) * ((_QWORD*)v2->_vptr_IFBO + 13);
		v4 = MyGL::MainPass::depthBuffer(this->mpass);
		v3(v2, v4);
	}
}

bool MyGL::SSAOpass::isActive()
{
	return this->active;
}

MyGL::ITextureRectangle* MyGL::SSAOpass::output()
{
	if (this->active)
		return this->out;
	else
		return (MyGL::ITextureRectangle*)(*((__int64(__fastcall**)(MyGL::MainPass*))this->mpass->_vptr_IRenderPass + 4))(this->mpass);
}

void MyGL::SSAOpass::resizeFrame()
{
	int v1
		MyGL::FBO* v2;
	int v3;
	MyGL::FBO* v4;
	void(__fastcall * v6)(MyGL::ITextureRectangle*, _QWORD, __int64, _QWORD, _QWORD, __int64);
	MyGL::FBO* v7;
	unsigned int v8;
	MyGL::FBO* v9;
	unsigned int v10;
	void(__fastcall * v11)(MyGL::ITextureRectangle*, _QWORD, __int64, _QWORD, _QWORD, __int64);
	MyGL::FBO* v12;
	unsigned int v13;
	MyGL::FBO* v14;
	unsigned int v15;

	v1 = (*((__int64(__fastcall**)(MyGL::ITextureRectangle*))this->out->_vptr_ITexture + 8))(this->out);
	v2 = MyGL::MainPass::frameBuffer(this->mpass);
	if (v1 != (*((unsigned int(__fastcall**)(MyGL::FBO*))v2->_vptr_IFBO + 2))(v2)
		|| (v3 = (*((__int64(__fastcall**)(MyGL::ITextureRectangle*))this->out->_vptr_ITexture + 9))(this->out),
			v4 = MyGL::MainPass::frameBuffer(this->mpass),
			v3 != (*((unsigned int(__fastcall**)(MyGL::FBO*))v4->_vptr_IFBO + 3))(v4)))
	{
		v6 = (void(__fastcall*)(MyGL::ITextureRectangle*, _QWORD, __int64, _QWORD, _QWORD, __int64)) * ((_QWORD*)this->out->_vptr_ITexture + 7);
		v7 = MyGL::MainPass::frameBuffer(this->mpass);
		v8 = (*((__int64(__fastcall**)(MyGL::FBO*))v7->_vptr_IFBO + 3))(v7);
		v9 = MyGL::MainPass::frameBuffer(this->mpass);
		v10 = (*((__int64(__fastcall**)(MyGL::FBO*))v9->_vptr_IFBO + 2))(v9);
		v6(this->out, 0LL, 1LL, v10, v8, 3LL);
		v11 = (void(__fastcall*)(MyGL::ITextureRectangle*, _QWORD, __int64, _QWORD, _QWORD, __int64)) * ((_QWORD*)this->depth->_vptr_ITexture + 7);
		v12 = MyGL::MainPass::frameBuffer(this->mpass);
		v13 = (*((__int64(__fastcall**)(MyGL::FBO*))v12->_vptr_IFBO + 3))(v12);
		v14 = MyGL::MainPass::frameBuffer(this->mpass);
		v15 = (*((__int64(__fastcall**)(MyGL::FBO*))v14->_vptr_IFBO + 2))(v14);
		v11(this->depth, 0LL, 3LL, v15, v13, 21LL);
	}
}

void MyGL::SSAOpass::setActive(bool active)
{
	this->active = active;
}

MyGL::IRenderPass::Pass::Type MyGL::SSAOpass::type()
{
	return 9;
}
