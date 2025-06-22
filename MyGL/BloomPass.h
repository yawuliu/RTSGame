#pragma once
#include <string>
#include <MyGL/AbstractPass.h>
#include <MyGL/IScene.h>
#include <MyGL/IModel.h>
#include <MyGL/Filter.h>
#include <MyGL/IUniformSampler.h>

namespace MyGL {
	class BloomPass : public AbstractPass {
	public:
		class Data {
		public:
			Data(MyGL::IScene& s, MyGL::IModel* quad) :gausV(s), gausH(s), grab(s) {
				this->gausV.setQuadModel(quad);
				this->gausH.setQuadModel(quad);
				this->grab.setQuadModel(quad);
			}
			virtual ~Data() = default;


		protected:
			MyGL::Filter gausV;
			MyGL::Filter gausH;
			MyGL::Filter grab;
			MyGL::IUniformSampler* textureIn;
			int w;
			int h;
		};
	public:
		BloomPass(MyGL::IScene& s,
			const MyGL::Adapter* const adapter,
			MyGL::ITextureRectangle* in) :AbstractPass(s)
		{
			MyGL::IScene* v4;
			MyGL::IRender* r;
			MyGL::TextureRectangle* frame;
			MyGL::IScene* v7;
			MyGL::IRender* r_1;
			MyGL::TextureRectangle* subFrame;
			MyGL::IScene* v10;
			MyGL::IRender* r_2;
			MyGL::TextureRectangle* v12;
			MyGL::IScene* v13;
			MyGL::IRender* r_3;
			MyGL::Model* v15;
			MyGL::IScene* s_1;
			MyGL::BloomPass::Data* data;
			MyGL::IRenderState* v18;
			MyGL::IRenderState* v19;
			MyGL::IRenderState* v20;
			MyGL::IRenderState* v21;
			int i;
			int i_0;
			this->m_isValid = 1;
			this->input = in;
			this->m_downSamplesCount = -1;
			v4 = this->scene();
			r = (MyGL::IRender*)(*((__int64(__fastcall**)(MyGL::IScene*))v4->_vptr_IScene + 3))(v4);
			frame = (MyGL::TextureRectangle*)operator new(0x28uLL);
			MyGL::TextureRectangle::TextureRectangle(frame, r);
			this->frame = frame;
			v7 = this->scene();
			r_1 = (MyGL::IRender*)(*((__int64(__fastcall**)(MyGL::IScene*))v7->_vptr_IScene + 3))(v7);
			subFrame = (MyGL::TextureRectangle*)operator new(0x28uLL);
			MyGL::TextureRectangle::TextureRectangle(subFrame, r_1);
			this->subFrame = subFrame;
			(*((void(__fastcall**)(MyGL::ITextureRectangle*, __int64, __int64))this->frame->_vptr_ITexture + 6))(
				this->frame,
				1LL,
				1LL);
			(*((void(__fastcall**)(MyGL::ITextureRectangle*, __int64, __int64))this->subFrame->_vptr_ITexture + 6))(
				this->subFrame,
				1LL,
				1LL);
			for (i_0 = 0; i_0 <= 1; ++i_0)
			{
				v10 = this->scene();
				r_2 = (MyGL::IRender*)(*((__int64(__fastcall**)(MyGL::IScene*))v10->_vptr_IScene + 3))(v10);
				v12 = (MyGL::TextureRectangle*)operator new(0x28uLL);
				MyGL::TextureRectangle::TextureRectangle(v12, r_2);
				(&this->input)[i_0 + 1] = v12;
			}
			this->frameBuffer[0] = 0LL;
			this->frameBuffer[1] = 0LL;
			this->frameBuffer[2] = 0LL;
			for (i = 0; i <= 2; ++i)
			{
				v13 = this->scene();
				r_3 = (MyGL::IRender*)(*((__int64(__fastcall**)(MyGL::IScene*))v13->_vptr_IScene + 3))(v13);
				v15 = (MyGL::Model*)operator new(0xC0uLL);
				MyGL::Model::Model(v15, r_3);
				this->quad[i] = v15;
			}
			s_1 = this->scene();
			data = (MyGL::BloomPass::Data*)operator new(0x58uLL);
			MyGL::BloomPass::Data::Data(data, s_1, this->quad[2]);
			this->data = data;
			this->data->w = -1;
			this->data->h = -1;
			v18 = MyGL::Filter::renderState(&this->data->gausH);
			(*((void(__fastcall**)(MyGL::IRenderState*, __int64))v18->_vptr_IRenderState + 18))(v18, 1LL);
			v19 = MyGL::Filter::renderState(&this->data->gausH);
			(*((void(__fastcall**)(MyGL::IRenderState*, __int64, __int64))v19->_vptr_IRenderState + 24))(v19, 1LL, 1LL);
			v20 = MyGL::Filter::renderState(&this->data->gausH);
			(*((void(__fastcall**)(MyGL::IRenderState*, __int64))v20->_vptr_IRenderState + 5))(v20, 1LL);
			v21 = MyGL::Filter::renderState(&this->data->gausH);
			(*((void(__fastcall**)(MyGL::IRenderState*, double))v21->_vptr_IRenderState + 3))(v21, 0.0);
			this->setDownSamplesCount(3);
			this->initShaders(adapter);
		}
		virtual ~BloomPass()
		{
			int i_0;
			int i;
			if (this->data)
			{

				delete this->data;
			}
			if (this->frame)
				(*((void(__fastcall**)(MyGL::ITextureRectangle*))this->frame->_vptr_ITexture + 1))(this->frame);
			for (i = 0; i <= 1; ++i)
			{
				if ((&this->input)[i + 1])
					(*((void(__fastcall**)(MyGL::ITextureRectangle*))(&this->input)[i + 1]->_vptr_ITexture + 1))((&this->input)[i + 1]);
			}
			if (this->subFrame)
				(*((void(__fastcall**)(MyGL::ITextureRectangle*))this->subFrame->_vptr_ITexture + 1))(this->subFrame);
			for (i_0 = 0; i_0 <= 2; ++i_0)
			{
				if (this->quad[i_0])
					(*((void(__fastcall**)(MyGL::IModel*))this->quad[i_0]->_vptr_IModel + 1))(this->quad[i_0]);
				if ((&this->subFrame)[i_0 + 1])
					(*((void(__fastcall**)(MyGL::ITextureRectangle*))(&this->subFrame)[i_0 + 1]->_vptr_ITexture + 1))((&this->subFrame)[i_0 + 1]);
			}
		}

		bool validate()
		{
			return this->m_isValid;
		}
		int downSamplesCount()
		{
			return this->m_downSamplesCount;
		}
		void setDownSamplesCount(int c)
		{
			const int* __a;
			int ca;
			int __b_;
			int __b;

			ca = c;
			__b_ = 1;
			__b = 3;
			__a = std::min<int>(&ca, &__b);
			ca = *std::max<int>(__a, &__b_);
			if (this->m_downSamplesCount != ca)
			{
				this->m_downSamplesCount = ca;
				this->data->gausV.setQuadModel((MyGL::IModel*)this->frameBuffer[ca + 2]);
				this->data->gausH.setQuadModel((MyGL::IModel*)this->frameBuffer[ca + 2]);
				this->data->grab.setQuadModel((MyGL::IModel*)this->frameBuffer[ca + 2]);
				this->resizeFrame();
			}
		}
		void setShader(MyGL::IShader* s)
		{
			MyGL::BloomPass::Data* data;
			MyGL::IShader* v3;
			std::string msg;
			_BYTE v5[17];

			this->m_isValid = 1;
			this->data->grab.setShader(s);
			if (s)
			{
				data = this->data;
				v3 = MyGL::Filter::shader(&data->grab);
				data->textureIn = (MyGL::IUniformSampler*)(*((__int64(__fastcall**)(MyGL::IShader*, const char*))v3->_vptr_IShader
					+ 17))(
						v3,
						"mainPass");
			}
			else
			{
				this->data->textureIn = 0LL;
				std::allocator<char>::allocator(v5);
				std::string::string(&msg, "[BloomPass::setShader]null shader", v5);
				MyGL::BloomPass::incompleteEvent(this, &msg);
				std::string::~string(&msg);
				std::allocator<char>::~allocator(v5);
			}
			if (this->data->textureIn)
				(*((void(__fastcall**)(MyGL::IUniformSampler*, _QWORD))this->data->textureIn->_vptr_IUniform + 6))(
					this->data->textureIn,
					0LL);
		}
		void buildQuad(int w, int h)
		{
			float* p;
			float* p_1;
			float* p_2;
			float* p_3;
			float* p_4;
			float* p_5;
			float* p_6;
			float* p_7;
			float* p_8;
			float* p_9;
			float* p_10;
			float* p_11;
			MyGL::IOModel m;
			MyGL::IIOModel::Point retstr_;
			MyGL::IIOModel::Point retstr__1;
			MyGL::IIOModel::Point retstr__2;
			MyGL::IIOModel::Point retstr__3;
			MyGL::IOModel::Normal retstr__4;
			MyGL::IOModel::Normal retstr__5;
			MyGL::IOModel::Normal retstr__6;
			MyGL::IOModel::Normal retstr__7;
			MyGL::IIOModel::TexCoord retstr__8;
			MyGL::IIOModel::TexCoord retstr__9;
			MyGL::IIOModel::TexCoord retstr__10;
			MyGL::IIOModel::TexCoord retstr__11;
			int i;

			MyGL::IOModel::IOModel(&m);
			MyGL::IOModel::allock(&m, 4uLL);
			MyGL::IOModel::point(&retstr_, &m, 0);
			p = MyGL::IIOModel::Point::data(&retstr_);
			MyGL::BloomPass::setPoint(p, -1.0, -1.0);
			MyGL::IOModel::point(&retstr__1, &m, 1);
			p_1 = MyGL::IIOModel::Point::data(&retstr__1);
			MyGL::BloomPass::setPoint(p_1, 1.0, -1.0);
			MyGL::IOModel::point(&retstr__2, &m, 2);
			p_2 = MyGL::IIOModel::Point::data(&retstr__2);
			MyGL::BloomPass::setPoint(p_2, 1.0, 1.0);
			MyGL::IOModel::point(&retstr__3, &m, 3);
			p_3 = MyGL::IIOModel::Point::data(&retstr__3);
			MyGL::BloomPass::setPoint(p_3, -1.0, 1.0);
			MyGL::IOModel::normal(&retstr__4, &m, 0);
			p_4 = MyGL::IIOModel::Point::data(&retstr__4);
			MyGL::BloomPass::setPoint(p_4, 1.0, 0.0);
			MyGL::IOModel::normal(&retstr__5, &m, 1);
			p_5 = MyGL::IIOModel::Point::data(&retstr__5);
			MyGL::BloomPass::setPoint(p_5, 1.0, 0.0);
			MyGL::IOModel::normal(&retstr__6, &m, 2);
			p_6 = MyGL::IIOModel::Point::data(&retstr__6);
			MyGL::BloomPass::setPoint(p_6, 1.0, 0.0);
			MyGL::IOModel::normal(&retstr__7, &m, 3);
			p_7 = MyGL::IIOModel::Point::data(&retstr__7);
			MyGL::BloomPass::setPoint(p_7, 1.0, 0.0);
			for (i = 0; i <= 2; ++i)
			{
				MyGL::IOModel::texCoord(&retstr__8, &m, 0);
				p_8 = MyGL::IIOModel::TexCoord::data(&retstr__8);
				MyGL::BloomPass::setPoint(p_8, 0.0, 0.0);
				MyGL::IOModel::texCoord(&retstr__9, &m, 1);
				p_9 = MyGL::IIOModel::TexCoord::data(&retstr__9);
				MyGL::BloomPass::setPoint(p_9, (float)w, 0.0);
				MyGL::IOModel::texCoord(&retstr__10, &m, 2);
				p_10 = MyGL::IIOModel::TexCoord::data(&retstr__10);
				MyGL::BloomPass::setPoint(p_10, (float)w, (float)h);
				MyGL::IOModel::texCoord(&retstr__11, &m, 3);
				p_11 = MyGL::IIOModel::TexCoord::data(&retstr__11);
				MyGL::BloomPass::setPoint(p_11, 0.0, (float)h);
				w /= 2;
				h /= 2;
				(*((void(__fastcall**)(MyGL::IModel*, MyGL::IOModel*))this->quad[i]->_vptr_IModel + 8))(this->quad[i], &m);
				(*((void(__fastcall**)(MyGL::IModel*, __int64))this->quad[i]->_vptr_IModel + 4))(this->quad[i], 2LL);
			}
			MyGL::IOModel::~IOModel(&m);
		}
		void setPoint(float* p, float x, float y)
		{
			*p = x;
			p[1] = y;
		}
		void resizeFrame()
		{
			MyGL::IScene* v1;
			__int64 v2;
			MyGL::IScene* v3;
			MyGL::IRender* r;
			MyGL::FBO* v5;
			int v[6];
			int dw;
			int i;

			v1 = MyGL::AbstractPass::scene(this);
			v2 = (*((__int64(__fastcall**)(MyGL::IScene*))v1->_vptr_IScene + 3))(v1);
			(*(void(__fastcall**)(__int64, int*, int*, int*, int*))(*(_QWORD*)v2 + 96LL))(v2, v, &v[1], &v[2], &v[3]);
			this->data->w = v[2];
			this->data->h = v[3];
			(*((void(__fastcall**)(MyGL::ITextureRectangle*, _QWORD, __int64, _QWORD, _QWORD, __int64))this->scale[0]->_vptr_ITexture
				+ 7))(
					this->scale[0],
					0LL,
					1LL,
					(unsigned int)(v[2] / 2),
					(unsigned int)(v[3] / 2),
					4LL);
			(*((void(__fastcall**)(MyGL::ITextureRectangle*, _QWORD, __int64, _QWORD, _QWORD, __int64))this->scale[1]->_vptr_ITexture
				+ 7))(
					this->scale[1],
					0LL,
					1LL,
					(unsigned int)(v[2] / 4),
					(unsigned int)(v[3] / 4),
					4LL);
			dw = 1 << MyGL::BloomPass::downSamplesCount(this);
			(*((void(__fastcall**)(MyGL::ITextureRectangle*, _QWORD, __int64, _QWORD, _QWORD, __int64))this->frame->_vptr_ITexture
				+ 7))(
					this->frame,
					0LL,
					1LL,
					(unsigned int)(v[2] / dw),
					(unsigned int)(v[3] / dw),
					4LL);
			(*((void(__fastcall**)(MyGL::ITextureRectangle*, _QWORD, __int64, _QWORD, _QWORD, __int64))this->subFrame->_vptr_ITexture
				+ 7))(
					this->subFrame,
					0LL,
					1LL,
					(unsigned int)(v[2] / dw),
					(unsigned int)(v[3] / dw),
					4LL);
			MyGL::BloomPass::buildQuad(this, v[2] / 2, v[3] / 2);
			for (i = 0; i <= 2; ++i)
			{
				if ((&this->subFrame)[i + 1])
					(*((void(__fastcall**)(MyGL::ITextureRectangle*))(&this->subFrame)[i + 1]->_vptr_ITexture + 1))((&this->subFrame)[i + 1]);
				v3 = MyGL::AbstractPass::scene(this);
				r = (MyGL::IRender*)(*((__int64(__fastcall**)(MyGL::IScene*))v3->_vptr_IScene + 3))(v3);
				v5 = (MyGL::FBO*)operator new(0x28uLL);
				MyGL::FBO::FBO(v5, r, v[2] / 2, v[3] / 2, 8);
				(&this->subFrame)[i + 1] = (MyGL::ITextureRectangle*)v5;
				v[2] /= 2;
				v[3] /= 2;
			}
		}
		void incompleteEvent(const std::string& msg)
		{
			MyGL::IScene* v2;
			__int64 v3;
			MyGL::CGL* v4;
			MyGL::IErrorControl* v5;
			void(__fastcall * v6)(MyGL::IErrorControl*, _QWORD, __int64);
			__int64 v7;

			v2 = MyGL::AbstractPass::scene(this);
			v3 = (*((__int64(__fastcall**)(MyGL::IScene*))v2->_vptr_IScene + 3))(v2);
			v4 = (MyGL::CGL*)(*(__int64(__fastcall**)(__int64))(*(_QWORD*)v3 + 72LL))(v3);
			v5 = MyGL::CGL::errorCtrl(v4);
			v6 = (void(__fastcall*)(MyGL::IErrorControl*, _QWORD, __int64)) * ((_QWORD*)v5->_vptr_IErrorControl + 4);
			v7 = std::string::data((std::string*)msg);
			v6(v5, 0LL, v7);
			this->m_isValid = 0;
		}
		void initShaders(const MyGL::Adapter& adapter)
		{
			MyGL::IShader* s;
			MyGL::IShader* s_1;
			MyGL::IShader* s_2;
			MyGL::ITextureRectangle* frame;
			MyGL::ITextureRectangle* subFrame;
			MyGL::BloomPass::Data* data;
			MyGL::IShader* v8;
			std::string name;
			char v11;
			std::string name_;
			char v13;
			std::string msg;
			char v15;
			std::string msg_;
			_BYTE v17[17];

			s = (MyGL::IShader*)(*((__int64(__fastcall**)(const MyGL::Adapter* const))adapter->_vptr_Adapter + 1))(adapter);
			MyGL::Filter::setShader(&this->data->gausV, s);
			s_1 = (MyGL::IShader*)(*((__int64(__fastcall**)(const MyGL::Adapter* const))adapter->_vptr_Adapter + 2))(adapter);
			MyGL::Filter::setShader(&this->data->gausH, s_1);
			s_2 = (MyGL::IShader*)(*((__int64(__fastcall**)(const MyGL::Adapter* const))adapter->_vptr_Adapter + 3))(adapter);
			MyGL::Filter::setShader(&this->data->grab, s_2);
			frame = this->frame;
			std::allocator<char>::allocator(&v11);
			std::string::string(&name, "input_texture", &v11);
			MyGL::Filter::setInput(&this->data->gausV, &name, frame);
			std::string::~string(&name);
			std::allocator<char>::~allocator(&v11);
			subFrame = this->subFrame;
			std::allocator<char>::allocator(&v13);
			std::string::string(&name_, "input_texture", &v13);
			MyGL::Filter::setInput(&this->data->gausH, &name_, subFrame);
			std::string::~string(&name_);
			std::allocator<char>::~allocator(&v13);
			if (MyGL::Filter::shader(&this->data->grab))
			{
				data = this->data;
				v8 = MyGL::Filter::shader(&data->grab);
				data->textureIn = (MyGL::IUniformSampler*)(*((__int64(__fastcall**)(MyGL::IShader*, const char*))v8->_vptr_IShader
					+ 17))(
						v8,
						"mainPass");
			}
			else
			{
				this->data->textureIn = 0LL;
				std::allocator<char>::allocator(&v15);
				std::string::string(&msg, "[BloomPass::initShaders]null shader", &v15);
				MyGL::BloomPass::incompleteEvent(this, &msg);
				std::string::~string(&msg);
				std::allocator<char>::~allocator(&v15);
			}
			if (this->data->textureIn)
			{
				(*((void(__fastcall**)(MyGL::IUniformSampler*, _QWORD))this->data->textureIn->_vptr_IUniform + 6))(
					this->data->textureIn,
					0LL);
			}
			else
			{
				std::allocator<char>::allocator(v17);
				std::string::string(&msg_, "[BloomPass::initShaders]no texture sampler in shader", v17);
				MyGL::BloomPass::incompleteEvent(this, &msg_);
				std::string::~string(&msg_);
				std::allocator<char>::~allocator(v17);
			}
		}
		void exec()
		{
			MyGL::IScene* v1;
			__int64 v2;
			MyGL::IScene* v3;
			__int64 v4;
			int v5;
			MyGL::IScene* v6;
			__int64 v7;
			MyGL::IScene* v8;
			__int64 v9;
			double cl_0;
			unsigned int v[8];

			v1 = MyGL::AbstractPass::scene(this);
			v2 = (*((__int64(__fastcall**)(MyGL::IScene*))v1->_vptr_IScene + 3))(v1);
			(*(void(__fastcall**)(__int64, unsigned int*, unsigned int*, unsigned int*, unsigned int*))(*(_QWORD*)v2 + 96LL))(
				v2,
				v,
				&v[1],
				&v[2],
				&v[3]);
			v3 = MyGL::AbstractPass::scene(this);
			v4 = (*((__int64(__fastcall**)(MyGL::IScene*))v3->_vptr_IScene + 3))(v3);
			cl_0 = (*(double(__fastcall**)(__int64))(*(_QWORD*)v4 + 24LL))(v4);
			if (v[2] != this->data->w || v[3] != this->data->h)
				MyGL::BloomPass::resizeFrame(this);
			if (MyGL::BloomPass::downSamplesCount(this) > 1)
				MyGL::BloomPass::downSample(this, this->frameBuffer[0], this->input, this->scale[0], this->quad[0]);
			if (MyGL::BloomPass::downSamplesCount(this) > 2)
				MyGL::BloomPass::downSample(this, this->frameBuffer[1], this->scale[0], this->scale[1], this->quad[1]);
			if (MyGL::BloomPass::downSamplesCount(this) == 3)
				MyGL::BloomPass::downSample(this, this->frameBuffer[2], this->scale[1], this->frame, this->quad[2]);
			if (MyGL::BloomPass::downSamplesCount(this) == 2)
				MyGL::BloomPass::downSample(this, this->frameBuffer[1], this->scale[0], this->frame, this->quad[1]);
			v5 = MyGL::BloomPass::downSamplesCount(this);
			MyGL::BloomPass::postProcess(this, (MyGL::FBO*)(&this->subFrame)[v5]);
			v6 = MyGL::AbstractPass::scene(this);
			v7 = (*((__int64(__fastcall**)(MyGL::IScene*))v6->_vptr_IScene + 3))(v6);
			(*(void(__fastcall**)(__int64, _QWORD, _QWORD, _QWORD, _QWORD))(*(_QWORD*)v7 + 88LL))(v7, v[0], v[1], v[2], v[3]);
			v8 = MyGL::AbstractPass::scene(this);
			v9 = (*((__int64(__fastcall**)(MyGL::IScene*))v8->_vptr_IScene + 3))(v8);
			(*(void(__fastcall**)(__int64, double))(*(_QWORD*)v9 + 16LL))(v9, cl_0);
		}
		void downSample(
			MyGL::FBO* frameBuffer,
			MyGL::ITexture* input,
			MyGL::ITextureRectangle* output,
			MyGL::IModel* quad)
		{
			MyGL::IScene* v5;
			__int64 v6;
			void(__fastcall * v7)(__int64, _QWORD, _QWORD, _QWORD, _QWORD);
			unsigned int v8;
			unsigned int v9;
			MyGL::IScene* v10;
			__int64 v11;

			(*((void(__fastcall**)(MyGL::FBO*))frameBuffer->_vptr_IFBO + 8))(frameBuffer);
			v5 = MyGL::AbstractPass::scene(this);
			v6 = (*((__int64(__fastcall**)(MyGL::IScene*))v5->_vptr_IScene + 3))(v5);
			v7 = *(void(__fastcall**)(__int64, _QWORD, _QWORD, _QWORD, _QWORD))(*(_QWORD*)v6 + 88LL);
			v8 = (*((__int64(__fastcall**)(MyGL::ITextureRectangle*))output->_vptr_ITexture + 9))(output);
			v9 = (*((__int64(__fastcall**)(MyGL::ITextureRectangle*))output->_vptr_ITexture + 8))(output);
			v7(v6, 0LL, 0LL, v9, v8);
			(*((void(__fastcall**)(MyGL::FBO*, MyGL::ITextureRectangle*, _QWORD))frameBuffer->_vptr_IFBO + 12))(
				frameBuffer,
				output,
				0LL);
			v10 = MyGL::AbstractPass::scene(this);
			v11 = (*((__int64(__fastcall**)(MyGL::IScene*))v10->_vptr_IScene + 3))(v10);
			(*(void(__fastcall**)(__int64, MyGL::IUniformSampler*, MyGL::ITexture*))(*(_QWORD*)v11 + 128LL))(
				v11,
				this->data->textureIn,
				input);
			MyGL::Filter::setQuadModel(&this->data->grab, quad);
			MyGL::Filter::exec(&this->data->grab);
			(*((void(__fastcall**)(MyGL::FBO*))frameBuffer->_vptr_IFBO + 9))(frameBuffer);
		}
		void postProcess(MyGL::FBO* frameBuffer)
		{
			(*((void(__fastcall**)(MyGL::FBO*))frameBuffer->_vptr_IFBO + 8))(frameBuffer);
			(*((void(__fastcall**)(MyGL::FBO*, MyGL::ITextureRectangle*, _QWORD))frameBuffer->_vptr_IFBO + 12))(
				frameBuffer,
				this->subFrame,
				0LL);
			MyGL::Filter::exec(&this->data->gausV);
			(*((void(__fastcall**)(MyGL::FBO*, MyGL::ITextureRectangle*, _QWORD))frameBuffer->_vptr_IFBO + 12))(
				frameBuffer,
				this->frame,
				0LL);
			MyGL::Filter::exec(&this->data->gausH);
			(*((void(__fastcall**)(MyGL::FBO*))frameBuffer->_vptr_IFBO + 9))(frameBuffer);
		}
		MyGL::ITextureRectangle* output()
		{
			return this->frame;
		}
		MyGL::IRenderPass::Pass::Type type()
		{
			return 2;
		}

	protected:
		MyGL::ITextureRectangle* input;
		MyGL::ITextureRectangle* scale[2];
		MyGL::ITextureRectangle* frame;
		MyGL::ITextureRectangle* subFrame;
		MyGL::FBO* frameBuffer[3];
		MyGL::IModel* quad[3];
		MyGL::BloomPass::Data* data;
		int m_downSamplesCount;
		bool m_isValid;
	};

}