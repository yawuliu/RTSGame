#include "Scene.h"
#include "IRender.h"

using namespace MyGL;

Scene::Scene(CGL* cgl)
	: m_cgl(cgl),
	m_render(nullptr),
	m_textureLoader(nullptr),
	m_shaderLoader(nullptr),
	m_graph(nullptr) {
}

IScene* Scene::dataControl() {
	return this;
}

ITexture2d* Scene::texture(const std::string& name) {
	auto it = m_textures.find(name);
	return it != m_textures.end() ? it->second : nullptr;
}

IModel* Scene::model(const std::string& name) {
	auto it = m_models.find(name);
	return it != m_models.end() ? it->second : nullptr;
}

IShader* Scene::shader(const std::string& name) {
	auto it = m_shaders.find(name);
	return it != m_shaders.end() ? it->second : nullptr;
}

QList<Light*> Scene::lights() {
	return m_lights;
}

IRender* Scene::render() {
	return m_render;
}

ITextureLoader* Scene::textureLoader() {
	return m_textureLoader;
}

IShaderLoader* Scene::shaderLoader() {
	return m_shaderLoader;
}

IShader* Scene::addShader(const QString& name, const QString& vert, const QString& frag) {
	// ����ֻ�Ǽ�ʾ����ʵ��Ӧ�м��غͱ����߼�
	IShader* shader = nullptr;
	// �����й����������
	if (m_shaderLoader) {
		// α���룺shader = m_shaderLoader->load(name, vert, frag);
	}
	if (shader) {
		m_shaders[name.toStdString()] = shader;
	}
	return shader;
}

void Scene::draw() {
	if (m_render) {
		m_render->begin();
		for (IGraphicsObject* obj : m_objects) {
			// α���룺obj->draw();
		}
		m_render->end();
	}
}

IShaderLoader* Scene::loader() {
	return m_shaderLoader;
}

QList<IGraphicsObject*> Scene::objects() {
	return m_objects;
}

void Scene::createRenderAlgo() {
	// αʵ��
	// m_render = new ...;
}

ISceneGraph* Scene::graph() {
	return m_graph;
}

MyGL::ITexture2d* Scene::addTexture(std::string name, MyGL::ITexture2d* tex) {
	m_textures[name] = tex;
	return tex;
}


