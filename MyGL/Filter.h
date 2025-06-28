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

	typedef std::map<IUniformSampler*, ITexture*> Args;

	class Filter : public AbstractPass {
	public:
		class Data {
		public:
			Data() = default;

			virtual ~Data() = default;

		public:
			RenderState renderState;
			IModel* quad;
			IShader* shader;
			Args args;
		};

	public:
		Filter(IScene& s);

		virtual ~Filter();

		virtual void exec() override;

		virtual IRenderPass::Pass::Type type() override;

		IUniformSampler* addArgs(IUniformSampler* sm, ITexture* u);

		IUniformSampler* addArgs(const std::string& name, ITexture* u);


		IModel* quadModel();

		IRenderState* renderState();

		IUniformSampler* setInput(IUniformSampler* name, ITexture* arg);

		IUniformSampler* setInput(const std::string& name, ITexture* arg);

		void setQuadModel(IModel* m);

		void setShader(IShader* s);

		IShader* shader();


	private:
		Data* data;
	};
}