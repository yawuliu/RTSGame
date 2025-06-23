#include "VolumetricLightScatteringPass.h"
#include "ITextureRectangle.h"
#include "Filter.h"
#include "FBO.h"

namespace MyGL {
	VolumetricLightScatteringPass::VolumetricLightScatteringPass(IScene& s, IModel* quad, const Adapter* const adapter, ITextureRectangle* const d, ITextureRectangle* const c) :AbstractPass(s)
	{
		IScene* s_1;
		Filter* filter;
		IScene* v8;
		IRender* r;
		TextureRectangle* frame;
		IShader* s_2;
		ITextureRectangle* depth;
		ITexture* arg;
		std::string name;
		char v19;
		std::string name_;
		char v21;
		std::string name__1;
		_BYTE v23[17];



		this->depth = d;
		s_1 = AbstractPass::scene(this);
		filter = (Filter*)operator new(0x18uLL);
		Filter::Filter(filter, s_1);
		this->filter = filter;
		v8 = AbstractPass::scene(this);
		r = (IRender*)(*((__int64(__fastcall**)(IScene*))v8->_vptr_IScene + 3))(v8);
		frame = (TextureRectangle*)operator new(0x28uLL);
		TextureRectangle::TextureRectangle(frame, r);
		this->frame = frame;
		s_2 = (IShader*)(*((__int64(__fastcall**)(const Adapter* const))adapter->_vptr_Adapter + 7))(adapter);
		Filter::setShader(this->filter, s_2);
		std::allocator<char>::allocator(&v19);
		std::string::string(&name, "colorBuffer", &v19);
		Filter::setInput(this->filter, &name, c);
		std::string::~string(&name);
		std::allocator<char>::~allocator(&v19);
		depth = this->depth;
		std::allocator<char>::allocator(&v21);
		std::string::string(&name_, "depthBuffer", &v21);
		Filter::setInput(this->filter, &name_, depth);
		std::string::~string(&name_);
		std::allocator<char>::~allocator(&v21);
		arg = (ITexture*)(*((__int64(__fastcall**)(const Adapter* const))adapter->_vptr_Adapter + 9))(adapter);
		std::allocator<char>::allocator(v23);
		std::string::string(&name__1, "shadowMap", v23);
		Filter::setInput(this->filter, &name__1, arg);
		std::string::~string(&name__1);
		std::allocator<char>::~allocator(v23);
		Filter::setQuadModel(this->filter, quad);
		this->frameBuffer = 0LL;
		this->resizeFrame();
	}

	VolumetricLightScatteringPass::~VolumetricLightScatteringPass()
	{

		if (this->frameBuffer)
			(*((void(__fastcall**)(FBO*))this->frameBuffer->_vptr_IFBO + 1))(this->frameBuffer);
		if (this->frame)
			(*((void(__fastcall**)(ITextureRectangle*))this->frame->_vptr_ITexture + 1))(this->frame);

	}

	void VolumetricLightScatteringPass::resizeFrame()
	{
		IScene* v1;
		__int64 v2;
		IScene* v3;
		IRender* r;
		unsigned int theWidth;
		unsigned int theHeight;
		FBO* frameBuffer;
		int v[12];

		v1 = AbstractPass::scene(this);
		v2 = (*((__int64(__fastcall**)(IScene*))v1->_vptr_IScene + 3))(v1);
		(*(void(__fastcall**)(__int64, int*, int*, int*, int*))(*(_QWORD*)v2 + 96LL))(v2, v, &v[1], &v[2], &v[3]);
		(*((void(__fastcall**)(ITextureRectangle*, _QWORD, __int64, _QWORD, _QWORD, __int64))this->frame->_vptr_ITexture
			+ 7))(
				this->frame,
				0LL,
				1LL,
				(unsigned int)v[2],
				(unsigned int)v[3],
				4LL);
		if (this->frameBuffer)
			(*((void(__fastcall**)(FBO*))this->frameBuffer->_vptr_IFBO + 1))(this->frameBuffer);
		v3 = AbstractPass::scene(this);
		r = (IRender*)(*((__int64(__fastcall**)(IScene*))v3->_vptr_IScene + 3))(v3);
		theWidth = (*((__int64(__fastcall**)(ITextureRectangle*))this->frame->_vptr_ITexture + 8))(this->frame);
		theHeight = (*((__int64(__fastcall**)(ITextureRectangle*))this->frame->_vptr_ITexture + 9))(this->frame);
		frameBuffer = (FBO*)operator new(0x28uLL);
		FBO::FBO(frameBuffer, r, theWidth, theHeight, 8);
		this->frameBuffer = frameBuffer;
	}

	void VolumetricLightScatteringPass::exec()
	{
		IScene* v1;
		__int64 v2;
		IScene* v3;
		__int64 v4;
		int v5;
		int v6;
		int v[8];

		v1 = AbstractPass::scene(this);
		v2 = (*((__int64(__fastcall**)(IScene*))v1->_vptr_IScene + 3))(v1);
		(*(void(__fastcall**)(__int64, int*, int*, int*, int*))(*(_QWORD*)v2 + 96LL))(v2, v, &v[1], &v[2], &v[3]);
		v3 = AbstractPass::scene(this);
		v4 = (*((__int64(__fastcall**)(IScene*))v3->_vptr_IScene + 3))(v3);
		(*(void(__fastcall**)(__int64))(*(_QWORD*)v4 + 24LL))(v4);
		v5 = v[2];
		if (v5 != (*((unsigned int(__fastcall**)(ITextureRectangle*))this->frame->_vptr_ITexture + 8))(this->frame)
			|| (v6 = v[3],
				v6 != (*((unsigned int(__fastcall**)(ITextureRectangle*))this->frame->_vptr_ITexture + 9))(this->frame)))
		{
			VolumetricLightScatteringPass::resizeFrame(this);
		}
		(*((void(__fastcall**)(FBO*))this->frameBuffer->_vptr_IFBO + 8))(this->frameBuffer);
		(*((void(__fastcall**)(FBO*, ITextureRectangle*, _QWORD))this->frameBuffer->_vptr_IFBO + 12))(
			this->frameBuffer,
			this->frame,
			0LL);
		(*((void(__fastcall**)(Filter*))this->filter->_vptr_IRenderPass + 2))(this->filter);
		(*((void(__fastcall**)(FBO*))this->frameBuffer->_vptr_IFBO + 9))(this->frameBuffer);
	}

	ITextureRectangle* VolumetricLightScatteringPass::output(VolumetricLightScatteringPass* const vlsPass)
	{
		return vlsPass->frame;
	}

	IRenderPass::Pass::Type VolumetricLightScatteringPass::type()
	{
		return IRenderPass::Pass::Type::None;
	}
}