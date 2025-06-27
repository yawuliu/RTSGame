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

        this->data = new Data(this->scene());
		Filter::setShader(&this->data->ssao, adapter->getSSAOShader());
		m = mp->quadModel();
		Filter::setQuadModel(&this->data->ssao, m);
		arg = mp->output();
		std::allocator<char>::allocator(&v22);
		std::string::string(&name, "mainPass", &v22);
		Filter::setInput(&this->data->ssao, &name, arg);
		arg_1 = mp->depthBuffer();
		std::allocator<char>::allocator(&v24);
		std::string::string(&name_, "depthBuffer", &v24);
		Filter::setInput(&this->data->ssao, &name_, arg_1);
		std::allocator<char>::allocator(v26);
		std::string::string(&name__1, "rand4x4", v26);
		Filter::setInput(&this->data->ssao, &name__1, adapter->getRandTexture());
		v11 = this->data->ssao->renderState();
		v11->setBlend(1LL);
		v12 = this->data->ssao->renderState();
		v12->setBlendMode( 8LL, 0LL);
		v13 = this->scene();
		r = v13->render();
        this->out = new TextureRectangle(r);;
		v16 = this->scene();
        this->depth = new TextureRectangle(v16->render());;
        this->mpass = mp;
        this->active = 1;
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
            delete this->out;
		if (this->depth)
            delete this->depth;
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

		v1 = this->out->setClamping();
		v2 = Mthis->mpass->frameBuffer();
		if (v1 != (*((unsigned int(__fastcall**)(FBO*))v2->_vptr_IFBO + 2))(v2)
			|| (v3 = this->out->setClamping(),
				v4 = this->mpass->frameBuffer(),
				v3 != (*((unsigned int(__fastcall**)(FBO*))v4->_vptr_IFBO + 3))(v4)))
		{

			v7 = Mthis->mpass->frameBuffer();
			v8 = (*((__int64(__fastcall**)(FBO*))v7->_vptr_IFBO + 3))(v7);
			v9 = Mthis->mpass->frameBuffer();
			v10 = (*((__int64(__fastcall**)(FBO*))v9->_vptr_IFBO + 2))(v9);
            this->out->setFiltration((0LL, 1LL, v10, v8, 3LL);

			v12 = Mthis->mpass->frameBuffer();
			v13 = (*((__int64(__fastcall**)(FBO*))v12->_vptr_IFBO + 3))(v12);
			v14 = Mthis->mpass->frameBuffer();
			v15 = (*((__int64(__fastcall**)(FBO*))v14->_vptr_IFBO + 2))(v14);
            this->depth->setFiltration( 0LL, 3LL, v15, v13, 21LL);
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