#include "UniformSampler.h"

using namespace MyGL;

UniformSampler::UniformSampler() {
	// ���캯��ʵ�֣�������Ҫ�ɳ�ʼ����Ա������
}

void UniformSampler::Bind(int textureUnit) {
	// �󶨲�������ָ������Ԫ
	// ʾ����glActiveTexture(GL_TEXTURE0 + textureUnit); glBindSampler(textureUnit, samplerId);
}

void UniformSampler::Unbind() {
	// ��������
	// ʾ����glBindSampler(0, 0);
}

const char* UniformSampler::GetName() const {
	// ���ز���������
	return "UniformSampler";
}


