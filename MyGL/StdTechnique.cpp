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
	// ����m_renderState�ѷ��䲢ʵ���˱��浱ǰ״̬�Ĺ���
	// ���������չΪ�������״̬
	// ʾ����m_renderState->saveCurrentState();
}

void StdTechnique::restoreRenderState() {
	// ����m_renderState�ѷ��䲢ʵ���˻ָ�״̬�Ĺ���
	// ʾ����m_renderState->restoreState();
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


