#pragma once

#include <MyGL/IScene.h>
#include <QList>
#include <map>
#include <string>

namespace MyGL {
	class CGL;

	class Scene : public IScene {
	public:
		Scene(CGL*);

		// Í¨¹ý IScene ¼Ì³Ð
		IScene* dataControl() override;
		ITexture2d* texture(const std::string& name) override;
		IModel* model(const std::string& name) override;
		IShader* shader(const std::string& name) override;
		QList<Light*> lights() override;
		IRender* render() override;
		ITextureLoader* textureLoader() override;
		IShaderLoader* shaderLoader() override;
		IShader* addShader(const QString&, const QString&, const QString&) override;
		void draw() override;
		IShaderLoader* loader() override;
		QList<IGraphicsObject*> objects() override;
		void createRenderAlgo() override;
		ISceneGraph* graph() override;
		MyGL::ITexture2d* addTexture(std::string, MyGL::ITexture2d*) override;
	private:
		CGL* m_cgl;
		QList<Light*> m_lights;
		QList<IGraphicsObject*> m_objects;
		IRender* m_render;
		ITextureLoader* m_textureLoader;
		IShaderLoader* m_shaderLoader;
		ISceneGraph* m_graph;
		std::map<std::string, ITexture2d*> m_textures;
		std::map<std::string, IModel*> m_models;
		std::map<std::string, IShader*> m_shaders;
	};
}


