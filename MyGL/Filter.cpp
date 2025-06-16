#include "Filter.h"
#include "IUniformSampler.h"
#include "IShader.h"

using namespace MyGL;

Filter::Filter(IScene* scene)
	: m_scene(scene), m_shader(nullptr), m_renderState(nullptr), m_quadModel(nullptr) {
}

void Filter::setShader(IShader* shader) {
	m_shader = shader;
}

IShader* Filter::shader() const {
	return m_shader;
}

IRenderState* Filter::renderState() const {
	return m_renderState;
}

IUniformSampler* Filter::setInput(IUniformSampler* sampler, ITexture2d* texture) {
	// 假设sampler有setTexture方法
	if (sampler && texture) {
		sampler->setTexture(texture);
	}
	return sampler;
}

IUniformSampler* Filter::setInput(const char* name, ITexture2d* texture) {
	// 假设shader有getUniformSamplerByName方法
	if (m_shader && name && texture) {
		IUniformSampler* sampler = m_shader->getUniformSamplerByName(name);
		if (sampler) {
			sampler->setTexture(texture);
		}
		return sampler;
	}
	return nullptr;
}

void Filter::exec() {
	if (!m_scene || !m_shader || !m_quadModel) return;
	// 假设有全局渲染器接口
	// 伪代码: Render::useShader(m_shader); Render::drawModel(m_quadModel);
	// 这里需要根据实际渲染流程补充
}

void Filter::setQuadModel(IModel* model) {
	m_quadModel = model;
}


