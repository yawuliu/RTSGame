#pragma once
#include <map>
#include <string>
#include "IScene.h"
#include "AbstractPass.h"
#include "IRenderPass.h"
#include "RenderState.h"

namespace MyGL {
	class IModel;

	class IScene;

	class IShader;
	class ITexture;

	class IRenderState;

	class IUniformSampler;

	class Filter : public AbstractPass {
	public:
		class Data {
		public:
			typedef std::map<MyGL::IUniformSampler*, MyGL::ITexture*> Args;
		public:
			Data() = default;

			virtual ~Data() = default;

		public:
			MyGL::RenderState renderState;
			MyGL::IModel* quad;
			MyGL::IShader* shader;
			Args args;
		};

	public:
		Filter(MyGL::IScene& s);

		virtual ~Filter();

		MyGL::IUniformSampler* addArgs(MyGL::IUniformSampler* sm, MyGL::ITexture* u);

		MyGL::IUniformSampler* addArgs(const std::string& const name, MyGL::ITexture* u);

		void exec();

		MyGL::IModel* quadModel();

		MyGL::IRenderState* renderState();

		MyGL::IUniformSampler* setInput(MyGL::IUniformSampler* name, MyGL::ITexture* arg);

		MyGL::IUniformSampler* setInput(const std::string& const name, MyGL::ITexture* arg);

		void setQuadModel(MyGL::IModel* m);

		void setShader(MyGL::IShader* s);

		MyGL::IShader* shader();

		MyGL::IRenderPass::Pass::Type type();

	private:
		Data* data;
	};
}