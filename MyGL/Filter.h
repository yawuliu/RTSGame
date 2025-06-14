#pragma once

#include <QScreen>

namespace MyGL {
	class IModel;

	class IScene;

	class IShader;

	class ITexture2d;

	class IRenderState;

	class IUniformSampler;

	class Filter {
	public:
		Filter(IScene* scene);

		void setShader(IShader*);

		IShader* shader() const;

		IRenderState* renderState() const;

		IUniformSampler* setInput(IUniformSampler*, ITexture2d*);

		IUniformSampler* setInput(const char*, ITexture2d*);

		void exec();

		void setQuadModel(IModel*);

	private:
		IScene* m_scene;
		IShader* m_shader;
		IRenderState* m_renderState;
		IModel* m_quadModel;
	};
}