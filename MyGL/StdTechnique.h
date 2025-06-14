#pragma once


namespace MyGL {
	class IScene;
	class IRenderState;
	class IShader;

	class StdTechnique {
	public:
		StdTechnique(IScene*);

		void storeRenderState();

		void restoreRenderState();

		IShader* colorShader() const;

		IRenderState* renderState() const;

		bool useDepthPass() const;

		IShader* currentShader() const;

		void setCurrentShader(IShader*);

	public:
		IScene* m_scene;
		IRenderState* m_renderState;
		IShader* m_colorShader;
		IShader* m_currentShader;
		bool m_useDepthPass;
	};
}


