#include "SSAOpass.h"
namespace MyGL {
	SSAOpass::Data::Data(IScene& s) :ssao(s) {}

	SSAOpass::SSAOpass(IScene& s, const Adapter* const adapter, MainPass* mp) : AbstractPass(s)
	{
		IScene* s_1;
		SSAOpass::Data* data;
		IShader* s_2;
		IModel* m;
		ITexture* arg;
		ITextureRectangle* arg_1;
		ITexture* arg_2;
		IRenderState* v11;
		IRenderState* v12;
		IScene* v13;
		IRender* r;
		TextureRectangle* out;
		IScene* v16;
		IRender* r_1;
		TextureRectangle* depth;
		std::string name;
		char v22;
		std::string name_;
		char v24;
		std::string name__1;
		_BYTE v26[17];

		s_1 = AbstractPass::scene(__x_);
		data = (SSAOpass::Data*)operator new(0x18uLL);
		SSAOpass::Data::Data(data, s_1);
		__x_->data = data;
		s_2 = (IShader*)(*((__int64(__fastcall**)(const Adapter* const))adapter->_vptr_Adapter + 5))(adapter);
		Filter::setShader(&__x_->data->ssao, s_2);
		m = MainPass::quadModel(mp);
		Filter::setQuadModel(&__x_->data->ssao, m);
		arg = mp->output();
		std::allocator<char>::allocator(&v22);
		std::string::string(&name, "mainPass", &v22);
		Filter::setInput(&__x_->data->ssao, &name, arg);
		std::string::~string(&name);
		std::allocator<char>::~allocator(&v22);
		arg_1 = MainPass::depthBuffer(mp);
		std::allocator<char>::allocator(&v24);
		std::string::string(&name_, "depthBuffer", &v24);
		Filter::setInput(&__x_->data->ssao, &name_, arg_1);
		std::string::~string(&name_);
		std::allocator<char>::~allocator(&v24);
		arg_2 = (ITexture*)(*((__int64(__fastcall**)(const Adapter* const))adapter->_vptr_Adapter + 6))(adapter);
		std::allocator<char>::allocator(v26);
		std::string::string(&name__1, "rand4x4", v26);
		Filter::setInput(&__x_->data->ssao, &name__1, arg_2);
		std::string::~string(&name__1);
		std::allocator<char>::~allocator(v26);
		v11 = Filter::renderState(&__x_->data->ssao);
		v11->setBlend(1LL);
		v12 = Filter::renderState(&__x_->data->ssao);
		v12->setBlendMode( 8LL, 0LL);
		v13 = AbstractPass::scene(__x_);
		r = v13->render();
		out = (TextureRectangle*)operator new(0x28uLL);
		TextureRectangle::TextureRectangle(out, r);
		__x_->out = out;
		v16 = AbstractPass::scene(__x_);
		r_1 = v16->render();
		depth = (TextureRectangle*)operator new(0x28uLL);
		TextureRectangle::TextureRectangle(depth, r_1);
		__x_->depth = depth;
		__x_->mpass = mp;
		__x_->active = 1;
	}

	SSAOpass::~SSAOpass()
	{
		SSAOpass::Data* data;


		data = this->data;
		if (data)
		{
			SSAOpass::Data::~Data(this->data);
			operator delete(data);
		}
		if (this->out)
			(*((void(__fastcall**)(ITextureRectangle*))this->out->_vptr_ITexture + 1))(this->out);
		if (this->depth)
			(*((void(__fastcall**)(ITextureRectangle*))this->depth->_vptr_ITexture + 1))(this->depth);
	}

	void SSAOpass::exec()
	{
		FBO* v1;
		FBO* v2;
		void(__fastcall * v3)(FBO*, ITextureRectangle*);
		ITextureRectangle* v4;

		if (this->active)
		{
			SSAOpass::resizeFrame(this);
			v1 = Mthis->mpass->frameBuffer();
			(*((void(__fastcall**)(FBO*, ITextureRectangle*))v1->_vptr_IFBO + 13))(v1, this->depth);
			Filter::exec(&this->data->ssao);
			v2 = Mthis->mpass->frameBuffer();
			v3 = (void(__fastcall*)(FBO*, ITextureRectangle*)) * ((_QWORD*)v2->_vptr_IFBO + 13);
			v4 = MainPass::depthBuffer(this->mpass);
			v3(v2, v4);
		}
	}

	bool SSAOpass::isActive()
	{
		return this->active;
	}

	ITextureRectangle* SSAOpass::output()
	{
		if (this->active)
			return this->out;
		else
			return this->mpass->output();
	}

	void SSAOpass::resizeFrame()
	{
		int v1
			FBO* v2;
		int v3;
		FBO* v4;
		void(__fastcall * v6)(ITextureRectangle*, _QWORD, __int64, _QWORD, _QWORD, __int64);
		FBO* v7;
		unsigned int v8;
		FBO* v9;
		unsigned int v10;
		void(__fastcall * v11)(ITextureRectangle*, _QWORD, __int64, _QWORD, _QWORD, __int64);
		FBO* v12;
		unsigned int v13;
		FBO* v14;
		unsigned int v15;

		v1 = (*((__int64(__fastcall**)(ITextureRectangle*))this->out->_vptr_ITexture + 8))(this->out);
		v2 = Mthis->mpass->frameBuffer();
		if (v1 != (*((unsigned int(__fastcall**)(FBO*))v2->_vptr_IFBO + 2))(v2)
			|| (v3 = (*((__int64(__fastcall**)(ITextureRectangle*))this->out->_vptr_ITexture + 9))(this->out),
				v4 = Mthis->mpass->frameBuffer(),
				v3 != (*((unsigned int(__fastcall**)(FBO*))v4->_vptr_IFBO + 3))(v4)))
		{
			v6 = (void(__fastcall*)(ITextureRectangle*, _QWORD, __int64, _QWORD, _QWORD, __int64)) * ((_QWORD*)this->out->_vptr_ITexture + 7);
			v7 = Mthis->mpass->frameBuffer();
			v8 = (*((__int64(__fastcall**)(FBO*))v7->_vptr_IFBO + 3))(v7);
			v9 = Mthis->mpass->frameBuffer();
			v10 = (*((__int64(__fastcall**)(FBO*))v9->_vptr_IFBO + 2))(v9);
			v6(this->out, 0LL, 1LL, v10, v8, 3LL);
			v11 = (void(__fastcall*)(ITextureRectangle*, _QWORD, __int64, _QWORD, _QWORD, __int64)) * ((_QWORD*)this->depth->_vptr_ITexture + 7);
			v12 = Mthis->mpass->frameBuffer();
			v13 = (*((__int64(__fastcall**)(FBO*))v12->_vptr_IFBO + 3))(v12);
			v14 = Mthis->mpass->frameBuffer();
			v15 = (*((__int64(__fastcall**)(FBO*))v14->_vptr_IFBO + 2))(v14);
			v11(this->depth, 0LL, 3LL, v15, v13, 21LL);
		}
	}

	void SSAOpass::setActive(bool active)
	{
		this->active = active;
	}

	IRenderPass::Pass::Type SSAOpass::type()
	{
		return 9;
	}
}