#include "SSAO.h"
#include <random>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
//#include <glad/glad.h>

using namespace MyGL;

SSAO::SSAO()
	: m_width(0), m_height(0), m_ssaoFBO(0), m_ssaoTexture(0), m_noiseTexture(0), m_kernelSize(64) {
}

SSAO::~SSAO() {
	/*if (m_ssaoFBO) glDeleteFramebuffers(1, &m_ssaoFBO);
	if (m_ssaoTexture) glDeleteTextures(1, &m_ssaoTexture);
	if (m_noiseTexture) glDeleteTextures(1, &m_noiseTexture);*/
}

void SSAO::Initialize(int width, int height) {
	//m_width = width;
	//m_height = height;

	//// 创建SSAO纹理
	//if (m_ssaoTexture) glDeleteTextures(1, &m_ssaoTexture);
	//glGenTextures(1, &m_ssaoTexture);
	//glBindTexture(GL_TEXTURE_2D, m_ssaoTexture);
	//glTexImage2D(GL_TEXTURE_2D, 0, GL_RED, m_width, m_height, 0, GL_RED, GL_FLOAT, nullptr);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	//// 创建FBO
	//if (m_ssaoFBO) glDeleteFramebuffers(1, &m_ssaoFBO);
	//glGenFramebuffers(1, &m_ssaoFBO);
	//glBindFramebuffer(GL_FRAMEBUFFER, m_ssaoFBO);
	//glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, m_ssaoTexture, 0);
	//glBindFramebuffer(GL_FRAMEBUFFER, 0);

	//GenerateKernel();
	//GenerateNoiseTexture();
}

void SSAO::GenerateKernel() {
	/*m_kernel.clear();
	std::uniform_real_distribution<float> randomFloats(0.0f, 1.0f);
	std::default_random_engine generator;

	for (unsigned int i = 0; i < m_kernelSize; ++i) {
		glm::vec3 sample(
			randomFloats(generator) * 2.0f - 1.0f,
			randomFloats(generator) * 2.0f - 1.0f,
			randomFloats(generator)
		);
		sample = glm::normalize(sample);
		sample *= randomFloats(generator);
		float scale = float(i) / float(m_kernelSize);
		scale = 0.1f + 0.9f * (scale * scale);
		sample *= scale;
		m_kernel.push_back(sample);
	}*/
}

void SSAO::GenerateNoiseTexture() {
	/*m_noise.clear();
	std::uniform_real_distribution<float> randomFloats(0.0f, 1.0f);
	std::default_random_engine generator;

	for (unsigned int i = 0; i < 16; i++) {
		glm::vec3 noise(
			randomFloats(generator) * 2.0f - 1.0f,
			randomFloats(generator) * 2.0f - 1.0f,
			0.0f
		);
		m_noise.push_back(noise);
	}

	if (m_noiseTexture) glDeleteTextures(1, &m_noiseTexture);
	glGenTextures(1, &m_noiseTexture);
	glBindTexture(GL_TEXTURE_2D, m_noiseTexture);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB16F, 4, 4, 0, GL_RGB, GL_FLOAT, glm::value_ptr(m_noise[0]));
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);*/
}

void SSAO::RenderSSAO() {
	//// 这里只是FBO绑定，实际渲染需在外部调用shader并传递相关参数
	//glBindFramebuffer(GL_FRAMEBUFFER, m_ssaoFBO);
	//glClear(GL_COLOR_BUFFER_BIT);
	//// ... 渲染全屏四边形，使用SSAO shader
	//glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

void SSAO::Resize(int width, int height) {
	/*if (width == m_width && height == m_height) return;
	Initialize(width, height);*/
}

unsigned int SSAO::GetSSAOTexture() const {
	return m_ssaoTexture;
}

