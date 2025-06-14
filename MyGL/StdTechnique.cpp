#include "StdTechnique.h"

using namespace MyGL;

StdTechnique::StdTechnique(IScene* scene)
	: m_scene(scene),
	m_renderState(nullptr),
	m_colorShader(nullptr),
	m_currentShader(nullptr),
	m_useDepthPass(false) {
}

void StdTechnique::storeRenderState() {
	// 假设m_renderState已分配并实现了保存当前状态的功能
	// 这里可以扩展为保存更多状态
	// 示例：m_renderState->saveCurrentState();
}

void StdTechnique::restoreRenderState() {
	// 假设m_renderState已分配并实现了恢复状态的功能
	// 示例：m_renderState->restoreState();
}

IShader* StdTechnique::colorShader() const {
	return m_colorShader;
}

IRenderState* StdTechnique::renderState() const {
	return m_renderState;
}

bool StdTechnique::useDepthPass() const {
	return m_useDepthPass;
}

IShader* StdTechnique::currentShader() const {
	return m_currentShader;
}

void StdTechnique::setCurrentShader(IShader* shader) {
	m_currentShader = shader;
}


